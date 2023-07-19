/*
 * Generated by Bluespec Compiler (build 14ff62d)
 * 
 * On Sat Jul  1 22:03:18 CST 2023
 * 
 */

/* Generation options: */
#ifndef __mkFftCombinational_h__
#define __mkFftCombinational_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkBfly4.h"


/* Class declaration for the mkFftCombinational module */
class MOD_mkFftCombinational : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_mkBfly4 INST_bfly_0_0;
  MOD_mkBfly4 INST_bfly_0_1;
  MOD_mkBfly4 INST_bfly_0_10;
  MOD_mkBfly4 INST_bfly_0_11;
  MOD_mkBfly4 INST_bfly_0_12;
  MOD_mkBfly4 INST_bfly_0_13;
  MOD_mkBfly4 INST_bfly_0_14;
  MOD_mkBfly4 INST_bfly_0_15;
  MOD_mkBfly4 INST_bfly_0_2;
  MOD_mkBfly4 INST_bfly_0_3;
  MOD_mkBfly4 INST_bfly_0_4;
  MOD_mkBfly4 INST_bfly_0_5;
  MOD_mkBfly4 INST_bfly_0_6;
  MOD_mkBfly4 INST_bfly_0_7;
  MOD_mkBfly4 INST_bfly_0_8;
  MOD_mkBfly4 INST_bfly_0_9;
  MOD_mkBfly4 INST_bfly_1_0;
  MOD_mkBfly4 INST_bfly_1_1;
  MOD_mkBfly4 INST_bfly_1_10;
  MOD_mkBfly4 INST_bfly_1_11;
  MOD_mkBfly4 INST_bfly_1_12;
  MOD_mkBfly4 INST_bfly_1_13;
  MOD_mkBfly4 INST_bfly_1_14;
  MOD_mkBfly4 INST_bfly_1_15;
  MOD_mkBfly4 INST_bfly_1_2;
  MOD_mkBfly4 INST_bfly_1_3;
  MOD_mkBfly4 INST_bfly_1_4;
  MOD_mkBfly4 INST_bfly_1_5;
  MOD_mkBfly4 INST_bfly_1_6;
  MOD_mkBfly4 INST_bfly_1_7;
  MOD_mkBfly4 INST_bfly_1_8;
  MOD_mkBfly4 INST_bfly_1_9;
  MOD_mkBfly4 INST_bfly_2_0;
  MOD_mkBfly4 INST_bfly_2_1;
  MOD_mkBfly4 INST_bfly_2_10;
  MOD_mkBfly4 INST_bfly_2_11;
  MOD_mkBfly4 INST_bfly_2_12;
  MOD_mkBfly4 INST_bfly_2_13;
  MOD_mkBfly4 INST_bfly_2_14;
  MOD_mkBfly4 INST_bfly_2_15;
  MOD_mkBfly4 INST_bfly_2_2;
  MOD_mkBfly4 INST_bfly_2_3;
  MOD_mkBfly4 INST_bfly_2_4;
  MOD_mkBfly4 INST_bfly_2_5;
  MOD_mkBfly4 INST_bfly_2_6;
  MOD_mkBfly4 INST_bfly_2_7;
  MOD_mkBfly4 INST_bfly_2_8;
  MOD_mkBfly4 INST_bfly_2_9;
  MOD_Reg<tUInt32> INST_combinationCount;
  MOD_Reg<tUInt32> INST_cycle;
  MOD_Fifo<tUWide> INST_inFifo;
  MOD_Fifo<tUWide> INST_outFifo;
 
 /* Constructor */
 public:
  MOD_mkFftCombinational(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUWide PORT_enq_in;
  tUWide PORT_deq;
 
 /* Publicly accessible definitions */
 public:
 
 /* Local definitions */
 private:
  tUInt32 DEF_b__h3005;
  tUWide DEF_inFifo_first____d9;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d361;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d358;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d355;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d352;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d349;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d346;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d343;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d340;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d337;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d334;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d331;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d328;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d325;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d322;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d319;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d316;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d313;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d303;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d293;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d283;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d273;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d263;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d253;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d243;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d233;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d209;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d185;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d161;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d137;
  tUWide DEF_bfly_2_15_bfly4_2251552690364292668_bfly_1_15__ETC___d105;
  tUWide DEF_deq__avValue1;
 
 /* Rules */
 public:
  void RL_counter();
  void RL_doFftIn();
 
 /* Methods */
 public:
  void METH_enq(tUWide ARG_enq_in);
  tUInt8 METH_RDY_enq();
  tUWide METH_deq();
  tUInt8 METH_RDY_deq();
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkFftCombinational &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkFftCombinational &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkFftCombinational &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkFftCombinational &backing);
};

#endif /* ifndef __mkFftCombinational_h__ */
