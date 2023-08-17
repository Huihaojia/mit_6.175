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
import Ehr::*;
import GetPut::*;

(* synthesize *)
module mkProc(Proc);
    Reg#(Addr) pc <- mkRegU;
    RFile      rf <- mkRFile;
    IMemory  iMem <- mkIMemory;
    DMemory  dMem <- mkDMemory;
    CsrFile  csrf <- mkCsrFile;

    Reg#(Addr) lastPc <- mkRegU;
    Reg#(Maybe#(Instruction)) f2e <- mkReg(tagged Invalid);

    Bool memReady = iMem.init.done() && dMem.init.done();
    rule test (!memReady);
        let e = tagged InitDone;
        iMem.init.request.put(e);
        dMem.init.request.put(e);
    endrule

    rule doPipeline if (csrf.started);
        // Record last PC for calculating branch pc
        lastPc <= pc;

        Maybe#(Instruction) newInst;
        newInst = tagged Valid iMem.req(pc);
        // Predicate next PC
        let newPc = pc + 4;

        if (isValid(f2e)) begin
            let inst = fromMaybe(?, f2e);
            DecodedInst dInst = decode(inst);
            Data rVal1 = rf.rd1(fromMaybe(?, dInst.src1));
            Data rVal2 = rf.rd2(fromMaybe(?, dInst.src2));

            Data csrVal = csrf.rd(fromMaybe(?, dInst.csr));

            ExecInst eInst = exec(dInst, rVal1, rVal2, lastPc, pc, csrVal);  
            if(eInst.iType == Ld) begin
                eInst.data <- dMem.req(MemReq{op: Ld, addr: eInst.addr, data: ?});
            end else if(eInst.iType == St) begin
                let d <- dMem.req(MemReq{op: St, addr: eInst.addr, data: eInst.data});
            end

            $display("pc: %h inst: (%h) expanded: ", pc, inst, showInst(inst));
            $fflush(stdout);

            if(eInst.iType == Unsupported) begin
                $fwrite(stderr, "ERROR: Executing unsupported instruction at pc: %x. Exiting\n", pc);
                $finish;
            end

            if(isValid(eInst.dst)) begin
                rf.wr(fromMaybe(?, eInst.dst), eInst.data);
            end

            csrf.wr(eInst.iType == Csrw ? eInst.csr : Invalid, eInst.data);

            if (eInst.mispredict) newInst = tagged Invalid;
            if (eInst.mispredict && eInst.brTaken) newPc = eInst.addr;
        end

        pc <= newPc;
        f2e <= newInst;

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

