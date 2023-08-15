// OneCycle.bsv
//
// This is a one cycle implementation of the RISC-V processor.

import Types::*;
import ProcTypes::*;
import CMemTypes::*;
import RFile::*;
import DelayedMemory::*;
import Decode::*;
import Exec::*;
import CsrFile::*;
import Vector::*;
import Fifo::*;
import Ehr::*;
import GetPut::*;

typedef enum {
    Fetch,
    Decode,
    Execute,
    Writeback
} State deriving(Bits, Eq, FShow);

(* synthesize *)
module mkProc(Proc);
    Reg#(Addr) pc <- mkRegU;
    RFile      rf <- mkRFile;
    DelayedMemory iMem <- mkDelayedMemory;
    DelayedMemory dMem <- mkDelayedMemory;
    CsrFile  csrf <- mkCsrFile;

    Reg#(State)         stage       <- mkReg(Fetch);
    Reg#(DecodedInst)   dInst_stage <- mkRegU;
    Reg#(ExecInst)      eInst_stage <- mkRegU;

    Bool memReady = iMem.init.done() && dMem.init.done();
    rule test (!memReady);
        let e = tagged InitDone;
        iMem.init.request.put(e);
        dMem.init.request.put(e);
    endrule

    rule doFetch(csrf.started && stage == Fetch);
        iMem.req(MemReq{ op: Ld, addr: pc, data: ? });
        stage <= Decode;
    endrule
    
    rule doDecode(csrf.started && stage == Decode);
        let inst <- iMem.resp;
        let dInst = decode(inst);

        $display("pc: %h inst: (%h) expanded: ", pc, inst, showInst(inst));
        $fflush(stdout);

        dInst_stage <= dInst;
        stage <= Execute;
    endrule
    

    rule doExecute(csrf.started && stage == Execute);
        let dInst = dInst_stage;

        Data rVal1 = rf.rd1(fromMaybe(?, dInst.src1));
        Data rVal2 = rf.rd2(fromMaybe(?, dInst.src2));
        Data csrVal = csrf.rd(fromMaybe(?, dInst.csr));

        let eInst = exec(dInst, rVal1, rVal2, pc, ?, csrVal);  

        // memory
        if(eInst.iType == Ld) begin
            dMem.req(MemReq{op: Ld, addr: eInst.addr, data: ?});
        end else if(eInst.iType == St) begin
            let d <- dMem.req(MemReq{op: St, addr: eInst.addr, data: eInst.data});
        end

        pc <= eInst.brTaken ? eInst.addr : pc + 4;

        eInst_stage <= eInst;
        stage <= Writeback;

        if(eInst.iType == Unsupported) begin
            $fwrite(stderr, "ERROR: Executing unsupported instruction at pc: %x. Exiting\n", pc);
            $finish;
        end

    endrule

    rule doWriteback(csrf.started && stage == Writeback);
        let eInst = eInst_stage;
        
        if(eInst.iType == Ld) begin
            eInst.data <- dMem.resp;
        end
        
        if(isValid(eInst.dst)) begin
            rf.wr(fromMaybe(?, eInst.dst), eInst.data);
        end

        csrf.wr(eInst.iType == Csrw ? eInst.csr : Invalid, eInst.data);
        
        stage <= Fetch;
    endrule

    method ActionValue#(CpuToHostData) cpuToHost;
        let ret <- csrf.cpuToHost;
        return ret;
    endmethod

    method Action hostToCpu(Bit#(32) startpc) if ( !csrf.started && memReady );
        csrf.start(0); // only 1 core, id = 0
        $display("Start at pc 200\n");
        $fflush(stdout);
        pc <= startpc;
    endmethod

    interface iMemInit = iMem.init;
    interface dMemInit = dMem.init;
endmodule

