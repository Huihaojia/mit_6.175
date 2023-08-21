import Types::*;
import ProcTypes::*;
import RegFile::*;
import Vector::*;

interface Bht#(numeric type bhtIndex);
    method Addr ppcDP(Addr pc, Addr targetPC);
    method Action update(Addr pc, Bool taken);
endinterface

module mkBht(Bht#(bhtIndex)) provisos( Add#(bhtIndex, a__, 32), NumAlias#(TExp#(bhtIndex), bhtEntries) );
    Vector#(bhtEntries, Reg#(Bit#(2))) bhtArr <- replicateM(mkReg(2'b01));

    Bit#(2) maxDP = 2'b11;
    Bit#(2) minDP = 2'b00;

    function Bit#(bhtIndex) getBhtIndex(Addr pc);
        return truncate(pc >> 2);
    endfunction

    function Bit#(2) getBhtEntry(Addr pc);
        return bhtArr[getBhtIndex(pc)];
    endfunction

    function Bit#(2) newDPBits(Bit#(2) oldDPBits, Bool taken);
        let newDP = oldDPBits;
        if (taken) begin
            newDP = newDP + 1;
            newDP = newDP == minDP ? maxDP : newDP;
        end
        else begin
            newDP = newDP - 1;
            newDP = newDP == maxDP ? minDP : newDP;
        end
        return newDP;
    endfunction

    method Addr ppcDP(Addr pc, Addr targetPC);
        let dpBits = getBhtEntry(pc);
        let taken = (dpBits == 2'b11 || dpBits == 2'b10) ? True : False;
        let pred_pc = taken ? targetPC : pc + 4;
        return pred_pc;
    endmethod
    
    method Action update(Addr pc, Bool taken);
        let index  = getBhtIndex(pc);
        let dpBits = getBhtEntry(pc);
        bhtArr[index] <= newDPBits(dpBits, taken);
    endmethod
endmodule