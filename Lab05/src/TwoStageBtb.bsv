// TwoStage.bsv
//
// This is a one cycle implementation of the RISC-V processor.

import Types::*;
import ProcTypes::*;
import CMemTypes::*;
import RFile::*;
import IMemory::*;
import DMemory::*;
import Decode::*;
import Exec::*;
import CsrFile::*;
import Vector::*;
import Fifo::*;
import FIFO::*;
import Ehr::*;
import GetPut::*;
import Btb::*;

(* synthesize *)
module mkProc(Proc);
    Reg#(Addr) pc <- mkReg(0);
    RFile      rf <- mkRFile;
    IMemory  iMem <- mkIMemory;
    DMemory  dMem <- mkDMemory;
    CsrFile  csrf <- mkCsrFile;
    Btb#(6) btbf <- mkBtb();

    Fifo#(4, Fetch2ExecuteEpoch) f2e <- mkCFFifo();
    Fifo#(4, Execute2FetchBtb) e2f <- mkCFFifo();
    Reg#(EpochSz) fEpoch <- mkReg(False);
    Reg#(EpochSz) eEpoch <- mkReg(False);

    Bool memReady = iMem.init.done() && dMem.init.done();
    rule test (!memReady);
        let e = tagged InitDone;
        iMem.init.request.put(e);
        dMem.init.request.put(e);
    endrule

    rule doFetch if (csrf.started);
        // Record last PC for calculating branch pc
        let newInst = iMem.req(pc);
        Addr newPc = btbf.predPc(pc);
        let redirect = e2f.first;

        if(e2f.notEmpty) begin
            fEpoch <= !fEpoch;
            newPc = redirect.correctPc;
            e2f.deq;
        end else begin
            f2e.enq(Fetch2ExecuteEpoch{lastPc: pc, nextPc: newPc, inst: newInst, fEpoch: fEpoch});
        end

        pc <= newPc;
    endrule

    rule doExecute if (csrf.started);
        let fetch = f2e.first();
        let inst = fetch.inst;
        DecodedInst dInst = decode(inst);
        Data rVal1 = rf.rd1(fromMaybe(?, dInst.src1));
        Data rVal2 = rf.rd2(fromMaybe(?, dInst.src2));

        Data csrVal = csrf.rd(fromMaybe(?, dInst.csr));
		
        $display("# rval1 = %x, rval2 = %x", rVal1, rVal2);

        ExecInst eInst = exec(dInst, rVal1, rVal2, fetch.lastPc, fetch.nextPc, csrVal);  
        if(eInst.iType == Ld) begin
            eInst.data <- dMem.req(MemReq{op: Ld, addr: eInst.addr, data: ?});
        end else if(eInst.iType == St) begin
            let d <- dMem.req(MemReq{op: St, addr: eInst.addr, data: eInst.data});
        end

        $display("pc: %h inst: (%h) expanded: ", fetch.lastPc, inst, showInst(inst));
        $fflush(stdout);

        if(eInst.iType == Unsupported) begin
            $fwrite(stderr, "ERROR: Executing unsupported instruction at pc: %x. Exiting\n", fetch.lastPc);
            $finish;
        end

        if(isValid(eInst.dst)) begin
            rf.wr(fromMaybe(?, eInst.dst), eInst.data);
        end

        csrf.wr(eInst.iType == Csrw ? eInst.csr : Invalid, eInst.data);

        if (eInst.mispredict) begin
            $display("# Mispredict at PC: %x, rVal1: %x", fetch.lastPc, eInst.addr);
            eEpoch <= !eEpoch;
            btbf.update(fetch.lastPc, eInst.addr);
            e2f.enq(Execute2FetchBtb{correctPc: eInst.addr});
            f2e.clear;
        end else begin
			$display("# Execute Work at PC = %x, result = %x", fetch.lastPc, eInst.data);
            f2e.deq;
        end
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

