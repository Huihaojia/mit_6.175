import Ehr::*;
import Vector::*;
import FIFO::*;

interface Fifo#(numeric type n, type t);
    method Action enq(t x);
    method Action deq;
    method t first;
    method Bool notEmpty;
    method Bool notFull;
    // method Action connectionTwo(Integer i);
endinterface

// Exercise 1
// Completes the code in Fifo.bsv to implements a 3-elements fifo with properly
// guarded methods. Feel free to take inspiration from the class slides.
// The interface defined in Fifo.bsv tells you the type of the methods
// (enq, deq, first) that your module should define.

// Demend:
// Bypass FIFO, Pipeline FIFO, Conflict Free FIFO, no length under BSV
// The above three types fifo is related to valid-ready protcol
// valid打拍，ready打拍，均打拍，Verilog implementation
// Compare ready-valid and FIFO in Bluespec
// Searching for critical path
// Combination logic is increasing with FIFO depth
// How to deal with the Back-pressure
// Valid Ready均打拍，基于上述两种实现，要求，slave寄存器输出
//
// Reference:
// 精读Stream
// https://github.com/SpinalHDL/SpinalHDL/blob/master/lib/src/main/scala/spinal/lib/Stream.scala#L375
// SpinalHDL Valid-m2sPipe() Ready-s2mPipe()

// Additional Lab: SKID Buffer----Ready Back Pressure
// SKID Buffer Optimization, SpinalHDL S2M

module mkFifo(Fifo#(3,t)) provisos (Bits#(t,tSz));
    Vector#(3, Reg#(t)) regs <- replicateM(mkReg(?));
    Vector#(3, Ehr#(2, Bool)) ehrs <- replicateM(mkEhr(False));

    // rule connection;
    //     for(Integer i = 0; i < 2; i = i + 1) begin
    //         // connectionTwo(i);
    //     end
    // endrule

    rule connect01 if(ehrs[0][1] && !ehrs[1][1]);
        regs[1] <= regs[0];
        ehrs[0][1] <= False;
        ehrs[1][1] <= True;
    endrule

    rule connect12 if(ehrs[1][1] && !ehrs[2][1]);
        regs[2] <= regs[1];
        ehrs[1][1] <= False;
        ehrs[2][1] <= True;
    endrule

    // Answer: addRules

    //---How to reuse the method?
    // method Action connectionTwo(Integer i) if(ehrs[i][1] && !ehrs[i+1][1]);
    //     regs[i+1] <= regs[i];
    //     ehrs[i][1] <= False;
    //     ehrs[i+1][1] <= True;
    // endmethod

    method Action enq(t x) if(!ehrs[0][1]);
        ehrs[0][1] <= True;
        regs[0] <= x;
    endmethod

    // peek

    method Action deq if(ehrs[2][0]);
        ehrs[2][0] <= False;
    endmethod

    method t first if(ehrs[2][0]);
        return regs[2];
    endmethod

    method Bool notEmpty;
        return ehrs[0][0] || ehrs[1][0] || ehrs[2][0];
    endmethod

    method Bool notFull;
        return !(ehrs[0][0] && ehrs[1][0] && ehrs[2][0]);
    endmethod
endmodule


// Two elements conflict-free fifo given as black box
module mkCFFifo( Fifo#(2, t) ) provisos (Bits#(t, tSz));
    Ehr#(2, t) da <- mkEhr(?);
    Ehr#(2, Bool) va <- mkEhr(False);
    Ehr#(2, t) db <- mkEhr(?);
    Ehr#(2, Bool) vb <- mkEhr(False);

    rule canonicalize;
        if( vb[1] && !va[1] ) begin
            da[1] <= db[1];
            va[1] <= True;
            vb[1] <= False;
        end
    endrule

    method Action enq(t x) if(!vb[0]);
        db[0] <= x;
        vb[0] <= True;
    endmethod

    method Action deq() if(va[0]);
        va[0] <= False;
    endmethod

    method t first if (va[0]);
        return da[0];
    endmethod

    method Bool notEmpty();
        return va[0];
    endmethod

    method Bool notFull();
        return !vb[0];
    endmethod

endmodule

module mkCF3Fifo(Fifo#(3,t)) provisos (Bits#(t, tSz));
    FIFO#(t) bsfif <-  mkSizedFIFO(3);
    method Action enq( t x);
        bsfif.enq(x);
    endmethod

    method Action deq();
        bsfif.deq();
    endmethod

    method t first();
        return bsfif.first();
    endmethod

    method Bool notEmpty();
        return True;
    endmethod

    method Bool notFull();
        return True;
    endmethod

endmodule
