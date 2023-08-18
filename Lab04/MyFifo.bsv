import Ehr::*;
import Vector::*;

interface Fifo#(numeric type n, type t);
    method Bool notFull;
    method Action enq(t x);
    method Bool notEmpty;
    method Action deq;
    method t first;
    method Action clear;
endinterface

module mkMyConflictFifo( Fifo#(n, t) ) provisos (Bits#(t,tSz));
    // n is size of fifo
    // t is data type of fifo
    Vector#(n, Reg#(t)) regs <- replicateM(mkReg(?));
    Reg#(Bit#(TLog#(n))) enqPtr <- mkReg(0);
    Reg#(Bit#(TLog#(n))) deqPtr <- mkReg(0);
    Reg#(Bool) nEmpty <- mkReg(False);
    Reg#(Bool) nFull <- mkReg(True);
    Bit#(TLog#(n)) depth = fromInteger(valueOf(n));

    method Action enq (t x) if (nFull);
        nEmpty <= True;
        regs[enqPtr] <= x;
        let nextEnqPtr = enqPtr+ 1;
        if (nextEnqPtr == depth) begin
            nextEnqPtr = 0;
        end
        if (nextEnqPtr == deqPtr) begin
            nFull <= False;
        end
        else begin
            nFull <= True;
        end
        enqPtr <= nextEnqPtr;
    endmethod

    method Action deq() if (nEmpty);
        nFull <= True;
        let nextDeqPtr = deqPtr + 1;
        if (nextDeqPtr == depth) begin
            nextDeqPtr = 0;
        end
        if (nextDeqPtr == enqPtr) begin
            nEmpty <= False;
        end
        else begin
            nEmpty <= True;
        end
        deqPtr <= nextDeqPtr;
    endmethod

    method t first() if (nEmpty);
        return regs[deqPtr];
    endmethod

    method Bool notFull();
        return nFull;
    endmethod

    method Bool notEmpty();
        return nEmpty;
    endmethod

    method Action clear();
        enqPtr <= 0;
        deqPtr <= 0;
        nEmpty <= False;
        nFull <= True;
    endmethod

endmodule

// {notEmpty, first, deq} < {notFull, enq} < clear
module mkMyPipelineFifo( Fifo#(n, t) ) provisos (Bits#(t,tSz));
    // n is size of fifo
    // t is data type of fifo
    Vector#(n, Reg#(t)) regs <- replicateM(mkReg(?));
    Ehr#(3, Bit#(TLog#(n))) enqPtr <- mkEhr(0);
    Ehr#(3, Bit#(TLog#(n))) deqPtr <- mkEhr(0);
    // What is the difference between Ehr Empty and Reg Empty
    Ehr#(3, Bool) nEmpty <- mkEhr(False);
    Ehr#(3, Bool) nFull <- mkEhr(True);
    Bit#(TLog#(n)) depth = fromInteger(valueOf(n));

    method Action enq (t x) if (nFull[1]);
        nEmpty[1] <= True;
        regs[enqPtr[1]] <= x;
        let nextEnqPtr = enqPtr[1]+ 1;
        if (nextEnqPtr == depth) begin
            nextEnqPtr = 0;
        end
        if (nextEnqPtr == deqPtr[1]) begin
            nFull[1] <= False;
        end
        else begin
            nFull[1] <= True;
        end
        enqPtr[1] <= nextEnqPtr;
    endmethod

    method Action deq() if(nEmpty[0]);
        nFull[0] <= True;
        let nextDeqPtr = deqPtr[0] + 1;
        if (nextDeqPtr == depth) begin
            nextDeqPtr = 0;
        end
        if (nextDeqPtr == enqPtr[1]) begin
            nEmpty[0] <= False;
        end
        else begin
            nEmpty[0] <= True;
        end
        deqPtr[0] <= nextDeqPtr;

    endmethod

    method Bool notFull();
        return nFull[1];
    endmethod

    method Bool notEmpty();
        return nEmpty[0];
    endmethod

    method t first();
        return regs[deqPtr[0]];
    endmethod

    method Action clear();
        enqPtr[2] <= 0;
        deqPtr[2] <= 0;
        nEmpty[2] <= False;
        nFull[2] <= True;
    endmethod

endmodule

// {notFull, enq} < {notEmpty, first, deq} < clear
module mkMyBypassFifo( Fifo#(n, t) ) provisos (Bits#(t,tSz));
    // n is size of fifo
    // t is data type of fifo
    Vector#(n, Reg#(t)) regs <- replicateM(mkReg(?));
    Ehr#(3, Bit#(TLog#(n))) enqPtr <- mkEhr(0);
    Ehr#(3, Bit#(TLog#(n))) deqPtr <- mkEhr(0);
    // What is the difference between Ehr Empty and Reg Empty
    Ehr#(3, Bool) nEmpty <- mkEhr(False);
    Ehr#(3, Bool) nFull <- mkEhr(True);
    Bit#(TLog#(n)) depth = fromInteger(valueOf(n));

    method Action enq (t x) if (nFull[0]);
        nEmpty[0] <= True;
        regs[enqPtr[0]] <= x;
        let nextEnqPtr = enqPtr[0]+ 1;
        if (nextEnqPtr == depth) begin
            nextEnqPtr = 0;
        end
        if (nextEnqPtr == deqPtr[0]) begin
            nFull[0] <= False;
        end
        else begin
            nFull[0] <= True;
        end
        enqPtr[0] <= nextEnqPtr;
    endmethod

    method Action deq() if (nEmpty[1]);
        nFull[1] <= True;
        let nextDeqPtr = deqPtr[1] + 1;
        if (nextDeqPtr == depth) begin
            nextDeqPtr = 0;
        end
        if (nextDeqPtr == enqPtr[0]) begin
            nEmpty[1] <= False;
        end
        else begin
            nEmpty[1] <= True;
        end
        deqPtr[1] <= nextDeqPtr;

    endmethod

    method Bool notFull();
        return nFull[0];
    endmethod

    method Bool notEmpty();
        return nEmpty[1];
    endmethod

    method t first();
        return regs[deqPtr[1]];
    endmethod

    method Action clear();
        enqPtr[2] <= 0;
        deqPtr[2] <= 0;
        nEmpty[2] <= False;
        nFull[2] <= True;
    endmethod

endmodule

// Bit a, b;
// Reg c, d;

// a = b * 2;
// c <= a;
// a = a * 2;
// d <= a;

// {notFull, enq, notEmpty, first, deq} < clear
// Attention, clear cannot be in the same rule with enq and deq
module mkMyCFFifo( Fifo#(n, t) ) provisos (Bits#(t,tSz));
    // n is size of fifo
    // t is data type of fifo
    Vector#(n, Reg#(t)) regs <- replicateM(mkReg(?));
    Ehr#(2, Bit#(TAdd#(TLog#(n), 1))) enqPtr <- mkEhr(0);
    Ehr#(2, Bit#(TAdd#(TLog#(n), 1))) deqPtr <- mkEhr(0);
    Ehr#(2, Bool) deqBuf <- mkEhr(False);
    Ehr#(2, Maybe#(t)) enqBuf <- mkEhr(tagged Invalid);
    Ehr#(2, Bool) nEmpty <- mkEhr(False);
    Ehr#(2, Bool) nFull <- mkEhr(True);
    Bit#(TAdd#(TLog#(n), 1)) depth = fromInteger(valueOf(n));

    (* no_implicit_conditions, fire_when_enabled *)
    rule canonicalize;
        let nextEnqPtr = enqPtr[0] + 1;
        let nextDeqPtr = deqPtr[0] + 1;

        if (nextEnqPtr == depth) nextEnqPtr = 0;
        if (nextDeqPtr == depth) nextDeqPtr = 0;


        if (deqBuf[1] && isValid(enqBuf[1]) && nEmpty[0] && nFull[0]) begin
            nFull[0] <= True;
            nEmpty[0] <= True;
            deqPtr[0] <= nextDeqPtr;
            enqPtr[0] <= nextEnqPtr;
            regs[enqPtr[0]] <= fromMaybe(?, enqBuf[1]);
        end else if (nEmpty[0] && deqBuf[1]) begin
            if (nextDeqPtr == enqPtr[0]) begin
                nEmpty[0] <= False;
            end
            nFull[0] <= True;
            deqPtr[0] <= nextDeqPtr;
        end else if (nFull[0] && isValid(enqBuf[1])) begin
            if (nextEnqPtr == deqPtr[0]) begin
                nFull[0] <= False;
            end
            nEmpty[0] <= True;
            enqPtr[0] <= nextEnqPtr;
            regs[enqPtr[0]] <= fromMaybe(?, enqBuf[1]);
        end

        enqBuf[1] <= tagged Invalid;
        deqBuf[1] <= False;
    endrule

    method Action enq (t x) if(nFull[0]);
        enqBuf[0] <= tagged Valid (x);
    endmethod

    method Action deq() if(nEmpty[0]);
        deqBuf[0] <= True;
    endmethod

    method Bool notFull();
        return nFull[0];
    endmethod

    method Bool notEmpty();
        return nEmpty[0];
    endmethod

    method t first();
        return regs[deqPtr[0]];
    endmethod

    method Action clear();
        // enqBuf[1] <= tagged Invalid;
        // deqBuf[1] <= False;
        enqPtr[1] <= 0;
        deqPtr[1] <= 0;
        nEmpty[1] <= False;
        nFull[1] <= True;
    endmethod

endmodule

module mkCFFifo( Fifo#(n, t) ) provisos (Bits#(t,tSz));
    // n is size of fifo
    // t is data type of fifo

    // storage elements
    Vector#(n, Reg#(t))     data     <- replicateM(mkRegU());
    Reg#(Bit#(TLog#(n)))    enqP     <- mkReg(0);
    Reg#(Bit#(TLog#(n)))    deqP     <- mkReg(0);
    Reg#(Bool)              empty    <- mkReg(True);
    Reg#(Bool)              full     <- mkReg(False);

    // requests
    Ehr#(3, Maybe#(t))      enqReq   <- mkEhr(tagged Invalid);
    Ehr#(3, Maybe#(Bit#(0)))   deqReq   <- mkEhr(tagged Invalid);
    Ehr#(2, Maybe#(Bit#(0)))   clearReq <- mkEhr(tagged Invalid);

    // useful value
    Bit#(TLog#(n))          max_index = fromInteger(valueOf(n)-1);

    // Update the state of the fifo to match any enqueue, dequeue, or clear
    // These attributes are statically checked by the compiler
    (* fire_when_enabled *)         // WILL_FIRE == CAN_FIRE
    (* no_implicit_conditions *)    // CAN_FIRE == guard (True)
    rule canonicalize;
        if( isValid(clearReq[1]) ) begin
            enqP <= 0;
            deqP <= 0;
            full <= False;
            empty <= True;
        end else begin
            let next_enqP = enqP;
            let next_deqP = deqP;
            let next_full = full;
            let next_empty = empty;

            if( isValid(enqReq[2]) ) begin
                data[enqP] <= fromMaybe(?, enqReq[2]);
                next_enqP = (enqP == max_index) ? 0 : enqP + 1;
            end
            if( isValid(deqReq[2]) ) begin
                next_deqP = (deqP == max_index) ? 0 : deqP + 1;
            end

            // compute next_full and next_empty
            if( next_deqP == next_enqP ) begin
                if( isValid(enqReq[2]) ) begin
                    // enqueued to full
                    next_full = True;
                end else if( isValid(deqReq[2]) ) begin
                    // dequeued to empty
                    next_empty = True;
                end else begin
                    // no deq or enq, so no change
                end
            end else begin
                // next_deqP != next_enqP so neither full nor empty
                next_full = False;
                next_empty = False;
            end

            enqP <= next_enqP;
            deqP <= next_deqP;
            full <= next_full;
            empty <= next_empty;
        end

        // clear pending requests
        clearReq[1] <= tagged Invalid;
        enqReq[2] <= tagged Invalid;
        deqReq[2] <= tagged Invalid;
    endrule

    method Bool notFull = !full;

    method Action enq(t x) if( !full );
        // Tell later stages an enqueue was requested
        enqReq[0] <= tagged Valid x;
    endmethod

    method Bool notEmpty = !empty;

    method Action deq if( !empty );
        // Tell later stages a dequeue was requested
        deqReq[0] <= tagged Valid 0;
    endmethod

    method t first if( !empty );
        return data[deqP];
    endmethod

    method Action clear;
        // Clear any existing enq/deq requests
        // gets desired {enq, deq} < clear schedule
        enqReq[1] <= tagged Invalid;
        deqReq[1] <= tagged Invalid;
        // Tell later stages a clear was requested
        clearReq[0] <= tagged Valid 0;
    endmethod
endmodule
