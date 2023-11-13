import CacheTypes::*;
import Vector::*;
import FShow::*;
import MemTypes::*;
import Types::*;
import ProcTypes::*;
import Fifo::*;
import Ehr::*;
import RefTypes::*;
import Printf::*;


typedef enum { Rdy, StrtMiss, SndFillReq, WaitFillResp, Resp } CacheStatus
deriving(Eq, Bits);

function Bool isStateM(MSI s);
    return s == M;
endfunction

function Bool isStateS(MSI s);
    return s == S;
endfunction

function Bool isStateI(MSI s);
    return s == I;
endfunction

module mkDCache#(CoreID id)(
    MessageGet fromMem,
    MessagePut toMem,
    RefDMem refDMem,
    DCache ifc
);

    Vector#(CacheRows, Reg#(CacheLine)) dataVec <- replicateM(mkRegU);
    Vector#(CacheRows, Reg#(CacheTag))  tagVec <- replicateM(mkRegU);
    Vector#(CacheRows, Reg#(MSI))       msiVec <- replicateM(mkReg(I));

    Reg#(CacheStatus) mshr <- mkReg(Rdy);

    Fifo#(8, Data)      respFifo <- mkBypassFifo;
    Fifo#(8, MemReq)    reqFifo <- mkBypassFifo;
    Reg#(MemReq)        reqBuffer <- mkRegU;
    Reg#(Maybe#(CacheLineAddr)) lineAddr <- mkReg(Invalid);

    Reg#(File) file <- mkReg(InvalidFile);
	Reg#(Bool) initDone <- mkReg(False);

	rule doInit(!initDone);
		// open log file
		String name = sprintf("driver_%d.out", id);
		let f <- $fopen(name, "w+");
		if(f == InvalidFile) begin
			$fwrite(stderr, "ERROR: fail to open %s\n", name);
			$finish;
		end
		file <= f;

		initDone <= True;
	endrule


    // Tag Fetch and Judge Hit
    rule doReady if (mshr == Rdy && initDone);
    	Fmt ret = $format("# Ready__");

        MemReq req = reqFifo.first;
        reqFifo.deq;
        // Addr Decode
        let wordSel = getWordSelect(req.addr);
        let lineSel = getIndex(req.addr);
        let tag     = getTag(req.addr);
        let hit     = tagVec[lineSel] == tag && msiVec[lineSel] > I;

        let proceed =   (req.op != Sc) || 
                        (req.op == Sc && isValid(lineAddr) && fromMaybe(?, lineAddr) == getLineAddr(req.addr));

        if (req.op == Fence) begin
            refDMem.commit(req, Invalid, Invalid);
        end
        else if (!proceed) begin
            respFifo.enq(scFail);
            refDMem.commit(req, Invalid, Valid(scFail));
            lineAddr <= Invalid;
        end
        else begin
            if (!hit) begin
                reqBuffer <= req;
                mshr <= StrtMiss;

                ret = ret + $format("Miss_");
            end
            else begin
                if (req.op == Ld || req.op == Lr) begin
                    respFifo.enq(dataVec[lineSel][wordSel]);
                    refDMem.commit(req, Valid(dataVec[lineSel]), Valid(dataVec[lineSel][wordSel]));
                    if (req.op == Lr) begin
                        lineAddr <= tagged Valid getLineAddr(req.addr);
                    end
                    ret = ret + $format("Load_");
                end
                else begin
                    ret = ret + $format("Store_");

                    if (isStateM(msiVec[lineSel])) begin
                        dataVec[lineSel][wordSel] <= req.data;
                        if (req.op == Sc) begin
                            respFifo.enq(scSucc);
                            refDMem.commit(req, Valid(dataVec[lineSel]), Valid(scSucc));
                            lineAddr <= Invalid;
                        end
                        else begin
                            refDMem.commit(req, Valid(dataVec[lineSel]), Invalid);
                        end

                        ret = ret + $format("M_");
                    end
                    else begin
                        // 在Store命中并且为I态或S态响应
                        mshr <= SndFillReq;
                        reqBuffer <= req;

                        ret = ret + $format("I/S_");
                    end
                end
            end
            ret = ret + $format("0x%0x", req.addr);
        end
        // File operation
        ret = ret + $format("\n");
        $fwrite(file, ret);
        // File operation
    endrule

    // set MSI to I, invalid cacheline, update cacheline to Memory
    rule doStrtMiss if (mshr == StrtMiss);
    	Fmt ret = $format("# StartMiss__");

        let wordSel = getWordSelect(reqBuffer.addr);
        let lineSel = getIndex(reqBuffer.addr);
        let tag     = tagVec[lineSel];

        // 发生写miss，需要写回M状态的line
        if (!isStateI(msiVec[lineSel])) begin
            ret = ret + (isStateM(msiVec[lineSel]) ?
                                    $format("WriteBack") : $format(""));

            msiVec[lineSel] <= I;
            Maybe#(CacheLine) line = isStateM(msiVec[lineSel]) ?
                                        Valid(dataVec[lineSel]) : Invalid;
            let addr = {tag, lineSel, wordSel, 2'b0};
            toMem.enq_resp(CacheMemResp {
                child:  id,
                addr:   addr,
                state:  I,
                data:   line
            });
        end

        if (isValid(lineAddr) && fromMaybe(?, lineAddr) == getLineAddr(reqBuffer.addr)) begin
            lineAddr <= Invalid;
        end

        mshr <= SndFillReq;

        ret = ret + $format("\n");
        $fwrite(file, ret);
    endrule

    // send Req to Memory for new line
    rule doSndFillReq if (mshr == SndFillReq);
        let state = (reqBuffer.op == Ld || reqBuffer.op == Lr) ? S : M;
        Fmt ret = $format("# Req2Mem__");

        ret = ret + ((reqBuffer.op == Ld || reqBuffer.op == Lr) ? $format("S") : $format("M"));

        // 向主存发起状态改变的申请，Ld指令取S态，St指令取M态
        toMem.enq_req(CacheMemReq {
            child: id,
            addr: reqBuffer.addr,
            state: state
        });
        mshr <= WaitFillResp;

        ret = ret + $format("\n");
        $fwrite(file, ret);
    endrule

    // update new line
    rule doWaitFillResp if (mshr == WaitFillResp && fromMem.hasResp);
        Fmt ret = $format("# WaitMem__");

        let wordSel = getWordSelect(reqBuffer.addr);
        let lineSel = getIndex(reqBuffer.addr);
        let tag     = getTag(reqBuffer.addr);
        CacheMemResp resp = ?;
        if (fromMem.first matches tagged Resp .r) begin
            resp = r;
        end
        fromMem.deq;
        CacheLine line = isValid(resp.data) ? fromMaybe(?, resp.data) : dataVec[lineSel];
        if (reqBuffer.op == St) begin
            refDMem.commit(reqBuffer, Valid(line), Invalid);
            line[wordSel] = reqBuffer.data;
        end
        else if (reqBuffer.op == Sc) begin
            if (isValid(lineAddr) && fromMaybe(?, lineAddr) == getLineAddr(reqBuffer.addr)) begin
                refDMem.commit(reqBuffer, Valid(line), Valid(scSucc));
                line[wordSel] = reqBuffer.data;
                respFifo.enq(scSucc);
            end
            else begin
                respFifo.enq(scFail);
                refDMem.commit(reqBuffer, Invalid, Valid(scFail));
            end
            lineAddr <= Invalid;
        end
        dataVec[lineSel] <= line;
        tagVec[lineSel] <= tag;
        msiVec[lineSel] <= resp.state;
        mshr <= Resp;

        ret = ret + $format("\n");
        $fwrite(file, ret);
    endrule

    // get Response
    rule doResp if (mshr == Resp);
        Fmt ret = $format("# Response__");

        let lineSel = getIndex(reqBuffer.addr);
        let wordSel = getWordSelect(reqBuffer.addr);
        if (reqBuffer.op == Ld || reqBuffer.op == Lr) begin
            respFifo.enq(dataVec[lineSel][wordSel]);
            refDMem.commit(reqBuffer, Valid(dataVec[lineSel]), Valid(dataVec[lineSel][wordSel]));
            if (reqBuffer.op == Lr) begin
                lineAddr <= tagged Valid getLineAddr(reqBuffer.addr);
            end
        end
        mshr <= Rdy;

        ret = ret + $format("\n");
        $fwrite(file, ret);
    endrule

    // update Memory
    rule doDng if (mshr != Resp && !fromMem.hasResp && fromMem.hasReq);
        Fmt ret = $format("@ Coherence Feedback__");

        CacheMemReq req = ?;
        if (fromMem.first matches tagged Req .r) begin
            req = r;
        end
        let wordSel = getWordSelect(req.addr);
        let lineSel = getIndex(req.addr);
        let tag = getTag(req.addr);
        if (msiVec[lineSel] > req.state) begin
            Maybe#(CacheLine) line = (msiVec[lineSel] == M) ? Valid(dataVec[lineSel]) : Invalid;
            let addr = { tag, lineSel, wordSel, 2'b0 };
            ret = ret + $format("id:%d_0x%0x", id, addr);
            toMem.enq_resp(CacheMemResp {
                child: id,
                addr: addr,
                state: req.state,
                data: line
            });
            msiVec[lineSel] <= req.state;
            if (req.state == I) begin
                lineAddr <= Invalid;
            end
        end
        fromMem.deq;

        ret = ret + $format("\n");
        $fwrite(file, ret);
    endrule


    method Action req(MemReq r) if (initDone);
        refDMem.issue(r);
        reqFifo.enq(r);
        $fwrite(file, ">> Have a Request\n");
    endmethod

    method ActionValue#(MemResp) resp if (initDone);
        respFifo.deq;
        $fwrite(file, "<< Have a Response\n");
        return respFifo.first;
    endmethod

endmodule
