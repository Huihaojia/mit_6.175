// OneCycle.bsv
//
// This is a one cycle implementation of the RISC-V processor.

import FIFOF::*;
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
import Ehr::*;
import GetPut::*;

typedef struct {
    DecodedInst dInst;
    Addr pc;
} F2E deriving(Bits, Eq);

(* synthesize *)
module mkProc(Proc);
    Ehr#(2, Addr) pc <- mkEhr(0);
    // Reg#(Addr) pc <- mkRegU;
    RFile      rf <- mkRFile;
    IMemory  iMem <- mkIMemory;
    DMemory  dMem <- mkDMemory;
    CsrFile  csrf <- mkCsrFile;

    FIFOF#(F2E) f2e <- mkFIFOF;

    Bool memReady = iMem.init.done() && dMem.init.done();
    rule test (!memReady);
        let e = tagged InitDone;
        iMem.init.request.put(e);
        dMem.init.request.put(e);
    endrule

    rule doFetch(csrf.started);
        let inst  = iMem.req(pc[0]);
        let dInst = decode(inst);
        f2e.enq(F2E{ dInst: dInst, pc: pc[0] }); //传的就是当前的pc，pc+4要在下一个周期

        // trace - print the instruction
        $display("pc: %h inst: (%h) expanded: ", pc[0], inst, showInst(inst));
        $fflush(stdout);

        pc[0] <= pc[0] + 4;
    endrule

    rule doExecute(csrf.started);
        let x       = f2e.first;
        let dInst   = x.dInst;
        let x_pc    = x.pc;
        let ppc     = x_pc + 4;
        // 此处没有出现教材中说的data hazard，因为读寄存器并不是在decode阶段
        let rVal1   = rf.rd1(fromMaybe(?, dInst.src1));
        let rVal2   = rf.rd2(fromMaybe(?, dInst.src2));
        let csrVal  = csrf.rd(fromMaybe(?, dInst.csr));
        let eInst   = exec(dInst, rVal1, rVal2, x_pc, ppc, csrVal);  
        // memory
        if(eInst.iType == Ld) begin
            eInst.data <- dMem.req(MemReq{op: Ld, addr: eInst.addr, data: ?});
        end else if(eInst.iType == St) begin
            let d <- dMem.req(MemReq{op: St, addr: eInst.addr, data: eInst.data});
        end

        // write back to reg file
        if(isValid(eInst.dst)) begin
            rf.wr(fromMaybe(?, eInst.dst), eInst.data);
        end
        // CSR write for sending data to host & stats
        csrf.wr(eInst.iType == Csrw ? eInst.csr : Invalid, eInst.data);

        if (eInst.mispredict) begin
            pc[1] <= eInst.addr;
            f2e.clear;
        end
        else begin
            f2e.deq;
        end   

        // check unsupported instruction at commit time. Exiting
        if(eInst.iType == Unsupported) begin
            $fwrite(stderr, "ERROR: Executing unsupported instruction at pc: %x. Exiting\n", x_pc);
            $finish;
        end

    endrule

    method ActionValue#(CpuToHostData) cpuToHost;
        let ret <- csrf.cpuToHost;
        return ret;
    endmethod

    method Action hostToCpu(Bit#(32) startpc) if ( !csrf.started && memReady );
        csrf.start(0); // only 1 core, id = 0
        // $display("Start at pc 200\n");
        // $fflush(stdout);
        pc[0] <= startpc;
    endmethod

    interface iMemInit = iMem.init;
    interface dMemInit = dMem.init;
endmodule

