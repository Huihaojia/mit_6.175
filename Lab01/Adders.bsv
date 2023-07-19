import Multiplexer::*;

function Bit#(1) fa_sum(Bit#(1) a, Bit#(1) b, Bit#(1) c);
    return a ^ b ^ c;
endfunction

function Bit#(1) fa_carry(Bit#(1) a, Bit#(1) b, Bit#(1) c);
    return (a&b) | (a&c) | (b&c);
endfunction

typedef 4 N;

function Bit#(TAdd#(N,1)) addN(Bit#(N) a, Bit#(N) b, Bit#(1) cin);
    //为什么cins要赋初值,Haskell的检查
    Bit#(TAdd#(N,1)) cins = 0;
    cins[0] = cin;
    Bit#(N) sum;
    for(Integer i=0; i<valueOf(N); i=i+1) begin
        sum[i] = fa_sum(a[i], b[i], cins[i]);
        cins[i+1] = fa_carry(a[i], b[i], cins[i]);
    end
    return {cins[valueOf(N)], sum};
endfunction

function Bit#(5) add4(Bit#(4) a, Bit#(4) b, Bit#(1) cin);
    return addN(a, b, cin);
endfunction

//lint format
interface Adder8;
    method ActionValue#(Bit#(9)) sum(Bit#(8) a,Bit#(8) b, Bit#(1) c_in);
endinterface

module mkRCAdder(Adder8);
    method ActionValue#(Bit#(9)) sum(Bit#(8) a,Bit#(8) b,Bit#(1) c_in);
        let low = add4(a[3:0], b[3:0], c_in);
        let high = add4(a[7:4], b[7:4], low[4]);
        return { high, low[3:0] };
    endmethod
endmodule

// Exercise 5
// Complete the code for the carry-select adder in the module mkCSAdder.
// Use Figure 3 as a guide for the required hardware and connections.
// This module can be tested by running the following:

module mkCSAdder(Adder8);
    method ActionValue#(Bit#(9)) sum(Bit#(8) a,Bit#(8) b,Bit#(1) c_in);
        let low = add4(a[3:0], b[3:0], c_in);
        let high0 = add4(a[7:4], b[7:4], 1'b0);
        let high1 = add4(a[7:4], b[7:4], 1'b1);
        let high = multiplexer5(low[4], high0, high1);
        return { high, low[3:0] };
    endmethod
endmodule
