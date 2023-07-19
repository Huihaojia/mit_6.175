/*
 * Generated by Bluespec Compiler (build 14ff62d)
 * 
 * On Tue Jul  4 01:30:10 CST 2023
 * 
 */

/* Generation options: keep-fires */
#ifndef __mkTbEx9a_h__
#define __mkTbEx9a_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkTbEx9a module */
class MOD_mkTbEx9a : public Module {
 
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
  MOD_Reg<tUInt8> INST_mod_i;
  MOD_Reg<tUWide> INST_mod_m_neg;
  MOD_Reg<tUWide> INST_mod_m_pos;
  MOD_Reg<tUWide> INST_mod_p;
  MOD_Reg<tUInt32> INST_tb_cycle;
  MOD_Reg<tUInt32> INST_tb_feed_count;
  MOD_Fifo<tUInt64> INST_tb_operands_fifo;
  MOD_Wire<tUInt32> INST_tb_randomA_ignore;
  MOD_Reg<tUInt8> INST_tb_randomA_initialized;
  MOD_Wire<tUInt32> INST_tb_randomA_zaz;
  MOD_Wire<tUInt32> INST_tb_randomB_ignore;
  MOD_Reg<tUInt8> INST_tb_randomB_initialized;
  MOD_Wire<tUInt32> INST_tb_randomB_zaz;
  MOD_Reg<tUInt32> INST_tb_read_count;
 
 /* Constructor */
 public:
  MOD_mkTbEx9a(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_WILL_FIRE_RL_tb_randomB_every_1;
  tUInt8 DEF_CAN_FIRE_RL_tb_randomB_every_1;
  tUInt8 DEF_WILL_FIRE_RL_tb_randomB_every;
  tUInt8 DEF_CAN_FIRE_RL_tb_randomB_every;
  tUInt8 DEF_WILL_FIRE_RL_tb_randomA_every_1;
  tUInt8 DEF_CAN_FIRE_RL_tb_randomA_every_1;
  tUInt8 DEF_WILL_FIRE_RL_tb_randomA_every;
  tUInt8 DEF_CAN_FIRE_RL_tb_randomA_every;
  tUInt8 DEF_WILL_FIRE_RL_tb_monitor_test;
  tUInt8 DEF_CAN_FIRE_RL_tb_monitor_test;
  tUInt8 DEF_WILL_FIRE_RL_tb_read;
  tUInt8 DEF_CAN_FIRE_RL_tb_read;
  tUInt8 DEF_WILL_FIRE_RL_tb_feed;
  tUInt8 DEF_CAN_FIRE_RL_tb_feed;
  tUInt8 DEF_WILL_FIRE_RL_mod_mul_step;
  tUInt8 DEF_CAN_FIRE_RL_mod_mul_step;
  tUInt32 DEF_x__h2771;
  tUInt32 DEF_x__h2242;
  tUInt32 DEF_x_wget__h1193;
  tUInt32 DEF_x_wget__h766;
  tUInt8 DEF_x__h347;
  tUInt8 DEF_tb_randomA_zaz_whas____d32;
  tUInt32 DEF_v__h941;
  tUInt32 DEF_v__h1367;
  tUInt8 DEF_tb_read_count_9_EQ_128___d70;
  tUInt8 DEF_IF_tb_randomA_zaz_whas__2_THEN_tb_randomA_zaz__ETC___d41;
  tUInt8 DEF_IF_tb_randomB_zaz_whas__8_THEN_tb_randomB_zaz__ETC___d42;
 
 /* Local definitions */
 private:
  tUInt32 DEF_new_value__h1329;
  tUInt32 DEF_new_value__h902;
  tUWide DEF_mod_p__h2342;
  tUWide DEF_y__h322;
  tUWide DEF_y__h288;
  tUWide DEF_mod_m_neg_BITS_64_TO_0___h334;
  tUWide DEF_mod_m_pos_BITS_64_TO_0___h310;
  tUWide DEF_SEXT_tb_operands_fifo_first__4_BITS_63_TO_32_5_ETC___d79;
  tUWide DEF_temp_p__h175;
  tUWide DEF_mod_p_PLUS_mod_m_pos___d9;
  tUWide DEF_mod_p_PLUS_mod_m_pos_BITS_64_TO_0_1_CONCAT_0_2___d13;
  tUWide DEF_mod_p_PLUS_mod_m_neg_7_BITS_64_TO_0_0_CONCAT_0_1___d22;
  tUWide DEF_mod_p_PLUS_mod_m_neg_7___d18;
  tUWide DEF_x__h189;
  tUWide DEF_y__h330;
  tUWide DEF_y__h296;
  tUInt8 DEF_x__h343;
  tUWide DEF_x__h2194;
  tUWide DEF_x__h1620;
  tUWide DEF_x__h1904;
 
 /* Rules */
 public:
  void RL_mod_mul_step();
  void RL_tb_randomA_every();
  void RL_tb_randomA_every_1();
  void RL_tb_randomB_every();
  void RL_tb_randomB_every_1();
  void RL_tb_feed();
  void RL_tb_read();
  void RL_tb_monitor_test();
 
 /* Methods */
 public:
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbEx9a &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTbEx9a &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTbEx9a &backing);
};

#endif /* ifndef __mkTbEx9a_h__ */