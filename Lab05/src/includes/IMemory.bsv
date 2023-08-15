import Types::*;
import CMemTypes::*;
import RegFile::*;
import MemInit::*;

interface IMemory;
    method MemResp req(Addr a);
    interface MemInitIfc init;
endinterface


// interface RegFile #(type index_t, type data_t);
//     method Action upd(index_t addr, data_t d); // Change or update an element within the register file.
//     method data_t sub(index_t addr);           // Read an element fromthe register file and return it.
// endinterface

    
(* synthesize *)
module mkIMemory(IMemory);
	// In simulation we always init memory from a fixed VMH file (for speed)
	RegFile#(Bit#(16), Data) mem <- mkRegFileFullLoad("mem.vmh");
	MemInitIfc memInit <- mkDummyMemInit;
   // RegFile#(Bit#(16), Data) mem <- mkRegFileFull();
   // MemInitIfc memInit <- mkMemInitRegFile(mem);

    method MemResp req(Addr a) if (memInit.done());
        return mem.sub(truncate(a>>2));
    endmethod

    interface MemInitIfc init = memInit;
endmodule

// RegFile != RFile
// mkRegFileFullLoad
// Create a RegFile from min to max index using the file to provide the initial contents of the array. The min and max are specified by the Bounded typeclass instance (0 to N-1 for N-bit numbers).
