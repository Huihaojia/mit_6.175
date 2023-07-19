// package Fifos

// import Vector::*;
// import Ehr::*;

// interface MyFifo#(numeric type n, type t);
//     method Action enq(t x);
//     method Action deq;
//     method t first;
//     method Bool notEmpty;
//     method Bool notFull;
// endinterface

// module mkPipeFifo(MyFifo#(n, t)) provisos (Bits#(t, tSz));
//     Vector#(n, Reg#(t)) regs <- replicateM(mkReg(?));
//     Vector#(n, Ehr#(n, Bool)) ehrs <- replicateM(mkEhr(False));

//     function Rules addConnect(Integer i);
//         return ( rules
//             rule connect2 if (ehrs[i][0] & !ehrs[i+1][1]);
//                 ehrs[i][0] <= False;
//                 ehrs[i+1][1] <= True;
//                 regs[i+1] <= regs[i];
//             endrule
//         endrules );
//     endfunction

//     rule connections
//     endrule

//     //ehrs的1能够接收当前时刻对出队的判断，能够在入队的同时出队
//     method Action enq(t x) if (!ehrs[0][1]);
//         ehrs[0][1] <= True;
//         regs[0] <= x;
//     endmethod

//     method Action deq if(ehrs[n-1][0]);
//         ehrs[n-1][0] <= False;
//     endmethod

//     method t first if(ehrs[n-1][0]);
//         return regs[n-1];
//     endmethod

//     method Bool notEmpty;

//     endmethod

//     method Bool notFull;

//     endmethod
// endmodule

// endpackage: Fifos