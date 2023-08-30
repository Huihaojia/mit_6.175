import ProcTypes::*;

`ifdef WITHOUTCACHE
import WithoutCache::*;
`endif

`ifdef WITHCACHE
import WithCache::*;
`endif



import Ifc::*;
import ProcTypes::*;
import Types::*;
import Ehr::*;

import SimMem::*;

interface ConnectalWrapper;
   interface ConnectalProcRequest connectProc;
endinterface

module [Module] mkConnectalWrapper#(ConnectalProcIndication ind)(ConnectalWrapper);
   Proc m <- mkProc();
   mkSimMem(m.ddr3Client);

   rule relayMessage;
	   let mess <- m.cpuToHost();
        ind.sendMessage(pack(mess));	
   endrule
   
   interface ConnectalProcRequest connectProc;
      method Action hostToCpu(Bit#(32) startpc);
         $display("Received software req to start pc\n");
         $fflush(stdout);
	      m.hostToCpu(unpack(startpc));
      endmethod
   endinterface
endmodule
