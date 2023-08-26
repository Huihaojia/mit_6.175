// Two stage

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
import Btb::*;
import Scoreboard::*;

import DelayedMemory::*;

// Data structure for Fetch to Execute stage
typedef struct {
    Addr 			pc;
    Addr 			f2ePredPc;
    Bool 			epoch;
} Fetch2Decode deriving (Bits, Eq, FShow);

typedef struct {
	Addr 			pc;
	Addr 			d2rPredPc;
	DecodedInst 	inst;
	Bool 			epoch;
} Decode2Rfetch deriving (Bits, Eq, FShow);

typedef struct {
	Addr 			pc;
	Addr 			r2ePredPc;
	DecodedInst 	inst;
	Data 			rVal1;
	Data 			rVal2;
	Data			csrVal;
	Bool 			epoch;
} Rfetch2Execute deriving (Bits, Eq, FShow);

typedef struct {
	IType			iType;
	Maybe#(CsrIndx)  csr;
	Addr			addr;
	Data			data;
	Maybe#(RIndx) 	dst;
	Bool			poision;
} Execute2Memory deriving (Bits, Eq, FShow);

typedef struct {
	IType			iType;
	Bool			ldFlag;
	Maybe#(CsrIndx)  csr;
	Maybe#(RIndx) 	dst;
	Data			data;
	Bool			poision;
} Memory2Writeback deriving (Bits, Eq, FShow);

typedef struct {
	Addr			pc;
	Addr 			nextPc;
} ExeRedirect deriving (Bits, Eq);

(* synthesize *)
module mkProc(Proc);
    Ehr#(2, Addr) pcReg <- mkEhr(?);
    RFile            rf <- mkRFile;
	Scoreboard#(8)   sb <- mkCFScoreboard;

	DelayedMemory  iMem <- mkDelayedIMemory;
    DelayedMemory  dMem <- mkDelayedMemory;

    CsrFile        csrf <- mkCsrFile;
    Btb#(6)         btb <- mkBtb;

	Reg#(Bool) exeEpoch <- mkReg(False);

	Fifo#(2, ExeRedirect)		e2fFifo		<- mkCFFifo;

	// FIFO between two stages
	Fifo#(4, Fetch2Decode) 		f2dFifo		<- mkCFFifo;
	Fifo#(4, Decode2Rfetch) 	d2rfFifo 	<- mkCFFifo;
	Fifo#(4, Rfetch2Execute) 	rf2eFifo 	<- mkCFFifo;
	Fifo#(4, Execute2Memory) 	e2mFifo 	<- mkCFFifo;
	Fifo#(4, Memory2Writeback) 	m2wFifo 	<- mkCFFifo;


    Bool memReady = iMem.init.done && dMem.init.done;
    rule test (!memReady);
        let e = tagged InitDone;
        iMem.init.request.put(e);
        dMem.init.request.put(e);
    endrule

	rule doFetch if (csrf.started);
		Addr newPc = btb.predPc(pcReg[0]);
		if (e2fFifo.notEmpty) begin
			let redirect = e2fFifo.first;
			e2fFifo.deq;
			newPc = redirect.nextPc;
		end else begin
			iMem.req(MemReq {op: Ld, addr: pcReg[0], data: ?});
			f2dFifo.enq( Fetch2Decode{
					pc:		pcReg[0],
					f2ePredPc:	newPc,
					epoch:	exeEpoch
				});
			// $display("# Fetch Work at PC = %x", pcReg[0]);
		end
		pcReg[0] <= newPc;
	endrule

	rule doDecode if (csrf.started);
		let f2d = f2dFifo.first;
		Instruction fetchInst <- iMem.resp;
		if (exeEpoch == f2d.epoch) begin
			DecodedInst inst = decode(fetchInst);
			d2rfFifo.enq( Decode2Rfetch {
				pc:		f2d.pc,
				d2rPredPc:	f2d.f2ePredPc,
				inst:	inst,
				epoch:	f2d.epoch
				}
			);
			$display("Decode: PC = %x, inst = %x, expanded = ", f2d.pc, fetchInst, showInst(fetchInst));
			f2dFifo.deq;
			// $display("# Decode Work at PC = %x", f2d.pc);
		end else begin
			f2dFifo.clear;
			// $display("Decode: Mispredict, redirected by Execute");
		end
	endrule

	rule doRfetch if (csrf.started);
		let d2r = d2rfFifo.first;
		let decodeInst = d2r.inst;

		if (exeEpoch == d2r.epoch) begin
			Data rval1 = rf.rd1(fromMaybe(?, decodeInst.src1));
			Data rval2 = rf.rd2(fromMaybe(?, decodeInst.src2));
			Data csrVal = csrf.rd(fromMaybe(?, decodeInst.csr));

			if (!sb.search1(decodeInst.src1) && !sb.search2(decodeInst.src2)) begin
				rf2eFifo.enq( Rfetch2Execute {
					pc:		d2r.pc,
					r2ePredPc:	d2r.d2rPredPc,
					inst: 	d2r.inst,
					rVal1:	rval1,
					rVal2:	rval2,
					csrVal:	csrVal,
					epoch:	d2r.epoch
				});
				sb.insert(decodeInst.dst);
				d2rfFifo.deq;
			end else begin
				// $display("RFetch Stalled: PC = %x", d2r.pc);
			end
        	$display("# rval1 = %x, rval2 = %x", rval1, rval2);
			// $display("# Rfetch Work at PC = %x, rval1 = %x, rval2 = %x", d2r.pc, rval1, rval2);
		end else begin
			d2rfFifo.clear;
		end
	endrule

	rule doExecute if (csrf.started);
		let r2e = rf2eFifo.first;
		Bool poision = False;

		ExecInst inst = exec(
			r2e.inst,
			r2e.rVal1,
			r2e.rVal2,
			r2e.pc,
			r2e.r2ePredPc,
			r2e.csrVal
		);

		if (exeEpoch == r2e.epoch) begin
			rf2eFifo.deq;

			if(inst.iType == Unsupported) begin
				$fwrite(stderr, "ERROR: Executing unsupported instruction at pc: %x. Exiting\n", r2e.pc);
				$finish;
			end

			if (inst.mispredict) begin
				// $display("Execute finds misprediction: PC = %x, correctPc = %x", r2e.pc, inst.addr);
				if (inst.brTaken) begin
					btb.update(r2e.pc, inst.addr);
				end
				e2fFifo.enq( ExeRedirect {
					pc: 	r2e.pc,
					nextPc: inst.addr
				});
				exeEpoch <= !exeEpoch;
			end else begin
				$display("# Execute Work at PC = %x, result = %x", r2e.pc, inst.data);
			end
		end else begin
			poision = True;
			rf2eFifo.deq;
			// $display("Execute: Kill instruction");
		end
		e2mFifo.enq( Execute2Memory {
			iType:		inst.iType,
			csr:		inst.csr,
			addr:		inst.addr,
			data:		inst.data,
			dst:		inst.dst,
			poision:	poision
		});
	endrule

	rule doMemory if (csrf.started);
		let e2m = e2mFifo.first;
		Bool ldFlag = False;
		e2mFifo.deq;

		if (!e2m.poision) begin
			if (e2m.iType == Ld) begin
				ldFlag = True;
				dMem.req( MemReq{
					op: 	Ld,
					addr:	e2m.addr,
					data:	?
				});
			end else if (e2m.iType == St) begin
				dMem.req( MemReq{
					op:		St,
					addr:	e2m.addr,
					data:	e2m.data
				});
			end
			// $display("# Memory Work");
		end else begin
			// $display("@ Memory Poision");
		end

		m2wFifo.enq( Memory2Writeback {
			iType:		e2m.iType,
			csr:		e2m.csr,
			ldFlag:		ldFlag,
			dst:		e2m.dst,
			data:		e2m.data,
			poision:	e2m.poision
		});
	endrule

	rule doWriteback if (csrf.started);
		let m2w = m2wFifo.first;
		let data = m2w.data;
		m2wFifo.deq;
		sb.remove;

		if (!m2w.poision) begin
			if (m2w.ldFlag) begin
				let t <- dMem.resp;
				data = t;
			end 
			csrf.wr(m2w.iType == Csrw ? m2w.csr : Invalid, m2w.data);

			if (isValid(m2w.dst)) begin
				rf.wr(fromMaybe(?, m2w.dst), data);
			end
			// $display("# Writeback Work");
		end else begin
			// if (m2w.iType == J || m2w.iType == Jr || m2w.iType == Br) begin
			// 	if (isValid(m2w.dst)) begin
			// 		rf.wr(fromMaybe(?, m2w.dst), data);
			// 	end
			// end
			// $display("@ Writeback Poision");
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
        pcReg[0] <= startpc;
    endmethod

	interface iMemInit = iMem.init;
    interface dMemInit = dMem.init;
endmodule

