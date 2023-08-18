import Ehr::*;
import Vector::*;
import GetPut::*;

//////////////////
// Fifo interface 

interface Fifo#(numeric type n, type t);
    method Bool notFull;
    method Action enq(t x);
    method Bool notEmpty;
    method Action deq;
    method t first;
    method Action clear;
endinterface

/////////////////
// Conflict FIFO

module mkConflictFifo( Fifo#(n, t) ) provisos (Bits#(t,tSz));
    // n is size of fifo
    // t is data type of fifo
    Vector#(n, Reg#(t))     data     <- replicateM(mkRegU());
    Reg#(Bit#(TLog#(n)))    enqP     <- mkReg(0);
    Reg#(Bit#(TLog#(n)))    deqP     <- mkReg(0);
    Reg#(Bool)              empty    <- mkReg(True);
    Reg#(Bool)              full     <- mkReg(False);
    Bit#(TLog#(n))          max_index = fromInteger(valueOf(n)-1);

    method Bool notFull = !full;

    method Action enq(t x) if( !full );
        data[enqP] <= x;
        empty <= False;
        let next_enqP = (enqP == max_index) ? 0 : enqP + 1;
        if( next_enqP == deqP ) begin
            full <= True;
        end
        enqP <= next_enqP;
    endmethod

    method Bool notEmpty = !empty;

    method Action deq if( !empty );
        // Tell later stages a dequeue was requested
        full <= False;
        let next_deqP = (deqP == max_index) ? 0 : deqP + 1;
        if( next_deqP == enqP ) begin
            empty <= True;
        end
        deqP <= next_deqP;
    endmethod

    method t first if( !empty );
        return data[deqP];
    endmethod

    method Action clear;
        enqP <= 0;
        deqP <= 0;
        empty <= True;
        full <= False;
    endmethod
endmodule

/////////////////
// Pipeline FIFO

module mkPipelineFifo( Fifo#(n, t) ) provisos (Bits#(t,tSz));
    // n is size of fifo
    // t is data type of fifo
    Vector#(n, Reg#(t))     data     <- replicateM(mkRegU());
    Ehr#(2, Bit#(TLog#(n))) enqP     <- mkEhr(0);
    Ehr#(2, Bit#(TLog#(n))) deqP     <- mkEhr(0);
    Ehr#(3, Bool)           empty    <- mkEhr(True);
    Ehr#(3, Bool)           full     <- mkEhr(False);
    Bit#(TLog#(n))          max_index = fromInteger(valueOf(n)-1);

    method Bool notFull = !full[1];

    method Action enq(t x) if( !full[1] );
        data[enqP[0]] <= x;
        empty[1] <= False;
        enqP[0] <= (enqP[0] == max_index) ? 0 : enqP[0] + 1;
        if( enqP[1] == deqP[1] ) begin
            full[1] <= True;
        end
    endmethod

    method Bool notEmpty = !empty[0];

    method Action deq if( !empty[0] );
        // Tell later stages a dequeue was requested
        full[0] <= False;
        deqP[0] <= (deqP[0] == max_index) ? 0 : deqP[0] + 1;
        if( deqP[1] == enqP[0] ) begin
            empty[0] <= True;
        end
    endmethod

    method t first if( !empty[0] );
        return data[deqP[0]];
    endmethod

    method Action clear;
        enqP[1] <= 0;
        deqP[1] <= 0;
        empty[2] <= True;
        full[2] <= False;
    endmethod
endmodule

///////////////
// Bypass FIFO

module mkBypassFifo( Fifo#(n, t) ) provisos (Bits#(t,tSz));
    // n is size of fifo
    // t is data type of fifo
    Vector#(n, Ehr#(2,t))   data     <- replicateM(mkEhr(?));
    Ehr#(2, Bit#(TLog#(n))) enqP     <- mkEhr(0);
    Ehr#(2, Bit#(TLog#(n))) deqP     <- mkEhr(0);
    Ehr#(3, Bool)           empty    <- mkEhr(True);
    Ehr#(3, Bool)           full     <- mkEhr(False);
    Bit#(TLog#(n))          max_index = fromInteger(valueOf(n)-1);

    method Bool notFull = !full[0];

    method Action enq(t x) if( !full[0] );
        data[enqP[0]][0] <= x;
        empty[0] <= False;
        enqP[0] <= (enqP[0] == max_index) ? 0 : enqP[0] + 1;
        if( enqP[1] == deqP[0] ) begin
            full[0] <= True;
        end
    endmethod

    method Bool notEmpty = !empty[1];

    method Action deq if( !empty[1] );
        // Tell later stages a dequeue was requested
        full[1] <= False;
        deqP[0] <= (deqP[0] == max_index) ? 0 : deqP[0] + 1;
        if( deqP[1] == enqP[1] ) begin
            empty[1] <= True;
        end
    endmethod

    method t first if( !empty[1] );
        return data[deqP[0]][1];
    endmethod

    method Action clear;
        enqP[1] <= 0;
        deqP[1] <= 0;
        empty[2] <= True;
        full[2] <= False;
    endmethod
endmodule

//////////////////////
// Conflict free fifo

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

////////////////////////////////
// instances of ToGet and ToPut

instance ToGet#( Fifo#(n, t), t ) provisos (Bits#(t, tsz));
    function Get#(t) toGet( Fifo#(n, t) fifo );
        return (interface Get#(t);
                    method ActionValue#(t) get();
                        let x = fifo.first;
                        fifo.deq;
                        return x;
                    endmethod
                endinterface);
    endfunction
endinstance

instance ToPut#( Fifo#(n, t), t ) provisos (Bits#(t, tsz));
    function Put#(t) toPut( Fifo#(n, t) fifo );
        return (interface Put#(t);
                    method Action put(t x);
                        fifo.enq(x);
                    endmethod
                endinterface);
    endfunction
endinstance

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

    (* fire_when_enabled *)         // WILL_FIRE == CAN_FIRE
    (* no_implicit_conditions *)    // CAN_FIRE == guard (True)
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