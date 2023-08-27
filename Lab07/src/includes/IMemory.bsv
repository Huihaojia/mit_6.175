import Types::*;
import CMemTypes::*;
import MemInit::*;
import Fifo::*;
import RegFile::*;
import Vector::*;
import DelayedMemory::*;



// interface IMemory;
//     method MemResp req(Addr a);
//     interface MemInitIfc init;
// endinterface


// // interface RegFile #(type index_t, type data_t);
// //     method Action upd(index_t addr, data_t d); // Change or update an element within the register file.
// //     method data_t sub(index_t addr);           // Read an element fromthe register file and return it.
// // endinterface

    
// (* synthesize *)
// module mkIMemory(IMemory);
// 	// In simulation we always init memory from a fixed VMH file (for speed)
// 	RegFile#(Bit#(16), Data) mem <- mkRegFileFullLoad("mem.vmh");
//     // Why there is a DummyMemInit
// 	MemInitIfc memInit <- mkDummyMemInit;
//     // RegFile#(Bit#(16), Data) mem <- mkRegFileFull();
//     // MemInitIfc memInit <- mkMemInitRegFile(mem);

//     method MemResp req(Addr a) if (memInit.done());
//         return mem.sub(truncate(a>>2));
//     endmethod

//     interface MemInitIfc init = memInit;
// endmodule

// RegFile != RFile
// mkRegFileFullLoad
// Create a RegFile from min to max index using the file to provide the initial contents of the array. The min and max are specified by the Bounded typeclass instance (0 to N-1 for N-bit numbers).

/*

Copyright (C) 2012 Muralidaran Vijayaraghavan <vmurali@csail.mit.edu>
Edited 2013 by Andy Wright <acwright@mit.edu>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/


// Read Delayed
module mkDelayedIMemory(DelayedMemory);
    Fifo#(2, MemResp) outFifo <- mkCFFifo();
	RegFile#(Bit#(16), Data) mem <- mkRegFileFullLoad("mem.vmh");
	MemInitIfc memInit <- mkDummyMemInit;

    method Action req(MemReq r) if (memInit.done());
        Bit#(16) index = truncate(r.addr>>2);
        let data = mem.sub(index);
        if(r.op==St) begin
            mem.upd(index, r.data);
        end else begin
            outFifo.enq( data );
        end
    endmethod

    method ActionValue#(MemResp) resp() if (memInit.done());
        let data = outFifo.first();
        outFifo.deq();
        return data;
    endmethod

    interface MemInitIfc init = memInit;
endmodule

