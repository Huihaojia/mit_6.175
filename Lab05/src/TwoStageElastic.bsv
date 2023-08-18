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

function Addr predicatePC(Addr pc);
    return pc + 4;
endfunction

(* synthesize *)
module mkProc(Proc);
    Ehr#(2, Addr) pc <- mkEhr(0);
    RFile      rf <- mkRFile;
    IMemory  iMem <- mkIMemory;
    DMemory  dMem <- mkDMemory;
    CsrFile  csrf <- mkCsrFile;

    // Why my FIFO not push until full?
    Fifo#(16, Fetch2Execute) f2e <- mkCFFifo();

    Bool memReady = iMem.init.done() && dMem.init.done();
    rule test (!memReady);
        let e = tagged InitDone;
        iMem.init.request.put(e);
        dMem.init.request.put(e);
    endrule

    rule doFetch if (csrf.started);
        // Record last PC for calculating branch pc
        let newInst = iMem.req(pc[0]);
        let newPc = predicatePC(pc[0]);
        pc[0] <= newPc;
        f2e.enq(Fetch2Execute{lastPc: pc[0], nextPc: newPc, inst: newInst});
        $display("Put data into FIFO\n");
        $display("notFull: %h, notEmpty: %h\n", f2e.notFull, f2e.notEmpty);
    endrule

    // As for EHR[i], you must not use the same i in one rule.
    rule doExecute;
        let fetch = f2e.first();
        $display("notFull: %h, notEmpty: %h\n", f2e.notFull, f2e.notEmpty);
        $display("Get data from FIFO\n");
        let inst = fetch.inst;
        DecodedInst dInst = decode(inst);
        Data rVal1 = rf.rd1(fromMaybe(?, dInst.src1));
        Data rVal2 = rf.rd2(fromMaybe(?, dInst.src2));

        Data csrVal = csrf.rd(fromMaybe(?, dInst.csr));

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
            pc[1] <= eInst.brTaken ? eInst.addr : fetch.nextPc;
            f2e.clear;
            $display("FIFO cleared\n");
        end else begin
            $display("Push Data from FIFO\n");
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
        pc[0] <= startpc;
    endmethod

    interface iMemInit = iMem.init;
    interface dMemInit = dMem.init;
endmodule

