import ProcTypes::*;
import MemTypes::*;
import Types::*;
import CacheTypes::*;
import MessageFifo::*;
import Vector::*;
import FShow::*;

import Printf::*;


function Bool isStateM(MSI s);
    return s == M;
endfunction

function Bool isStateS(MSI s);
    return s == S;
endfunction

function Bool isStateI(MSI s);
    return s == I;
endfunction

function Bool isCompatible(MSI a, MSI b);
    return a == I || b == I || (a == S && b == S);
endfunction

module mkPPP(MessageGet c2m, MessagePut m2c, WideMem mem, Empty ifc);
    Vector#(CoreNum, Vector#(CacheRows, Reg#(MSI)))      childState <- replicateM(replicateM(mkReg(I)));
    Vector#(CoreNum, Vector#(CacheRows, Reg#(CacheTag)))   childTag <- replicateM(replicateM(mkRegU));
    Vector#(CoreNum, Vector#(CacheRows, Reg#(Bool)))      waitState <- replicateM(replicateM(mkReg(False)));

    Reg#(Bool)  missReg <- mkReg(False);
    Reg#(Bool) readyReg <- mkReg(False);

    Reg#(File) file <- mkReg(InvalidFile);
	Reg#(Bool) initDone <- mkReg(False);

    rule doInit if (!initDone);
		// open log file
		String name = sprintf("PPP_trace.out");
		let f <- $fopen(name, "w+");
		if(f == InvalidFile) begin
			$fwrite(stderr, "ERROR: fail to open %s\n", name);
			$finish;
		end
		file <= f;

		initDone <= True;
	endrule

    rule parentResp if (!c2m.hasResp && !missReg && readyReg && initDone);
        let           req = c2m.first.Req;
        let           idx = getIndex(req.addr);
        let           tag = getTag(req.addr);
        let         child = req.child;
        Bool willConflict = False;

        Fmt ret = $format("# Get Req from Core %d_", req.child);

        ret = ret + $format("0x%0x_", req.addr);

        for (Integer i = 0; i < valueOf(CoreNum); i = i + 1) begin
            if (fromInteger(i) != child) begin
                // get msi state from other children
                MSI s = (childTag[i][idx] == tag) ? childState[i][idx] : I;
                // Every children is Steady or Only one is Invalid is compatible
                if (!isCompatible(s, req.state) || waitState[child][idx]) begin
                    ret = ret + $format("conflict happens_");
                    willConflict = True;
                end
            end
        end
        if (!willConflict) begin
            // get msi state from the child which is requesting
            MSI state = (childTag[child][idx] == tag) ? childState[child][idx] : I;
            if (!isStateI(state)) begin
                ret = ret + $format("updata global msi");
                // update msi state in parent
                m2c.enq_resp(CacheMemResp {
                    child: child,
                    addr: req.addr,
                    state: req.state,
                    data: Invalid
                });
                childState[child][idx] <= req.state;
                childTag[child][idx] <= tag;
                c2m.deq;
            end
            else begin
                // When cacheline is Invalid, send read request to Main memory
                // cache miss happens
                ret = ret + $format("fetch from main mem");
                mem.req(WideMemReq {
                    write_en: '0,
                    addr: req.addr,
                    data: ?
                });
                missReg <= True;
            end
            // making downstream response
            readyReg <= False;
        end

        ret = ret + $format("\n");
		$fwrite(file, ret);
    endrule

    // process every request from children
    rule dwn if (!c2m.hasResp && !missReg && !readyReg);
        Fmt ret = $format("# Dealing with coherence_");

        let   req = c2m.first.Req;
        let   idx = getIndex(req.addr);
        let   tag = getTag(req.addr);
        let child = req.child;

        Maybe#(Integer) sendCore = tagged Invalid;
        // Arbiter
        for (Integer i = 0; i < valueOf(CoreNum); i = i + 1) begin
            if (fromInteger(i) != child) begin
                MSI state = (childTag[i][idx] == tag)? childState[i][idx] : I;
                if (!isCompatible(state, req.state) && !waitState[i][idx]) begin
                    if (!isValid(sendCore)) begin
                        sendCore = tagged Valid i;
                    end
                end
            end
        end
        if (!isValid(sendCore)) begin
            readyReg <= True;
        end
        else begin
        // 为什么不只在state为M的时候更新？
            ret = ret + $format("req from %d change child_%d", child, fromMaybe(?, sendCore));
            waitState[fromMaybe(?, sendCore)][idx] <= True;
            m2c.enq_req(CacheMemReq {
                child: fromInteger(fromMaybe(?, sendCore)),
                addr:req.addr,
                state: (req.state == M ? I : S)
            });
        end

        ret = ret + $format("\n");
		$fwrite(file, ret);
    endrule

    rule parentDataResp if (!c2m.hasResp && missReg);
        // cache miss happens and send data as a response
        let req = c2m.first.Req;
        let idx = getIndex(req.addr);
        let tag = getTag(req.addr);
        let child = req.child;
        let line <- mem.resp();

        Fmt ret = $format("# Response to child: %d", req.child);

        m2c.enq_resp(CacheMemResp {
            child: child,
            addr: req.addr,
            state: req.state,
            data: Valid(line)
        });
        childState[child][idx] <= req.state;
        childTag[child][idx] <= tag;
        c2m.deq;
        missReg <= False;

        ret = ret + $format("\n---\n");
		$fwrite(file, ret);
    endrule

    rule dwnRsp if (c2m.hasResp);
        let resp = c2m.first.Resp;
        c2m.deq;
        let idx = getIndex(resp.addr);
        let tag = getTag(resp.addr);
        let child = resp.child;

        Fmt ret = $format("# Update from child: %d", resp.child);

        MSI status = (childTag[child][idx] == tag) ? childState[child][idx] : I;
        // update cacheline in Main memory
        if (isStateM(status)) begin
            mem.req(WideMemReq{
                write_en: '1,
                addr: resp.addr,
                data: fromMaybe(?, resp.data)
            });
        end
        childState[child][idx] <= resp.state;
        waitState[child][idx] <= False;
        childTag[child][idx] <= tag;

        ret = ret + $format("\n");
		$fwrite(file, ret);
    endrule
endmodule
