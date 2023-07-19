/*
 * Generated by Bluespec Compiler (build 14ff62d)
 * 
 * On Wed Jun 21 19:33:47 CST 2023
 * 
 */
#include "bluesim_primitives.h"
#include "mkTbMuxSimple.h"


/* String declarations */
static std::string const __str_literal_3("FAILED Sel %b from %d, %d gave %d instead of %d", 47u);
static std::string const __str_literal_1("PASSED", 6u);
static std::string const __str_literal_2("Sel %b from %d, %d is %d", 24u);


/* Constructor */
MOD_mkTbMuxSimple::MOD_mkTbMuxSimple(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_cycle(simHdl, "cycle", this, 32u, 0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 2u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTbMuxSimple::init_symbols_0()
{
  init_symbol(&symbols[0u], "cycle", SYM_MODULE, &INST_cycle);
  init_symbol(&symbols[1u], "RL_test", SYM_RULE);
}


/* Rule actions */

void MOD_mkTbMuxSimple::RL_test()
{
  tUInt32 DEF_x__h1557;
  tUInt8 DEF_b__h1220;
  tUInt8 DEF_a__h1219;
  tUInt8 DEF_b__h239;
  tUInt8 DEF_a__h238;
  tUInt8 DEF_b__h1268;
  tUInt8 DEF_a__h1267;
  tUInt8 DEF_b__h1316;
  tUInt8 DEF_a__h1315;
  tUInt8 DEF_b__h1364;
  tUInt8 DEF_a__h1363;
  tUInt8 DEF_a__h240;
  tUInt8 DEF_NOT_cycle_EQ_8_AND_INV_SEL_ARR_0_1_0_1_0_0_1_1_ETC___d40;
  tUInt8 DEF_NOT_cycle_EQ_8___d3;
  tUInt8 DEF_NOT_cycle_EQ_8_AND_NOT_INV_SEL_ARR_0_1_0_1_0_0_ETC___d42;
  tUInt8 DEF_test__h82;
  tUInt8 DEF_INV_SEL_ARR_0_1_0_1_0_0_1_1_cycle_AND_SEL_ARR__ETC___d39;
  tUInt8 DEF_cycle_EQ_8___d2;
  tUInt8 DEF_realAns__h83;
  tUInt8 DEF_sel__h81;
  tUInt8 DEF_b__h1362;
  tUInt8 DEF_b__h1314;
  tUInt8 DEF_b__h1266;
  tUInt8 DEF_b__h1218;
  tUInt8 DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12;
  tUInt8 DEF_b__h237;
  tUInt8 DEF_a__h1361;
  tUInt8 DEF_a__h1313;
  tUInt8 DEF_a__h1265;
  tUInt8 DEF_a__h1217;
  tUInt8 DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8;
  tUInt8 DEF_a__h236;
  tUInt32 DEF_x__h907;
  DEF_x__h907 = INST_cycle.METH_read();
  switch (DEF_x__h907) {
  case 0u:
  case 3u:
  case 4u:
    DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8 = (tUInt8)0u;
    break;
  case 1u:
    DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8 = (tUInt8)4u;
    break;
  case 2u:
    DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8 = (tUInt8)31u;
    break;
  case 5u:
    DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8 = (tUInt8)8u;
    break;
  case 6u:
    DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8 = (tUInt8)11u;
    break;
  case 7u:
    DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8 = (tUInt8)21u;
    break;
  default:
    DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8 = (tUInt8)10u;
  }
  DEF_a__h236 = (tUInt8)(DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8 >> 4u);
  DEF_a__h1217 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8 >> 3u));
  DEF_a__h1265 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8 >> 2u));
  DEF_a__h1313 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8 >> 1u));
  DEF_a__h1361 = (tUInt8)((tUInt8)1u & DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8);
  switch (DEF_x__h907) {
  case 0u:
    DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12 = (tUInt8)1u;
    break;
  case 1u:
    DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12 = (tUInt8)7u;
    break;
  case 2u:
  case 3u:
  case 4u:
    DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12 = (tUInt8)31u;
    break;
  case 5u:
    DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12 = (tUInt8)0u;
    break;
  case 6u:
    DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12 = (tUInt8)29u;
    break;
  case 7u:
    DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12 = (tUInt8)22u;
    break;
  default:
    DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12 = (tUInt8)10u;
  }
  DEF_b__h237 = (tUInt8)(DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12 >> 4u);
  DEF_b__h1218 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12 >> 3u));
  DEF_b__h1266 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12 >> 2u));
  DEF_b__h1362 = (tUInt8)((tUInt8)1u & DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12);
  DEF_b__h1314 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12 >> 1u));
  switch (DEF_x__h907) {
  case 1u:
  case 3u:
  case 6u:
  case 7u:
    DEF_sel__h81 = (tUInt8)1u;
    break;
  default:
    DEF_sel__h81 = (tUInt8)0u;
  }
  DEF_realAns__h83 = DEF_sel__h81 ? DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12 : DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8;
  DEF_cycle_EQ_8___d2 = DEF_x__h907 == 8u;
  DEF_NOT_cycle_EQ_8___d3 = !DEF_cycle_EQ_8___d2;
  DEF_a__h240 = (tUInt8)1u & ~DEF_sel__h81;
  DEF_a__h1363 = DEF_a__h240 & DEF_a__h1361;
  DEF_b__h1364 = DEF_sel__h81 & DEF_b__h1362;
  DEF_a__h1315 = DEF_a__h240 & DEF_a__h1313;
  DEF_b__h1316 = DEF_sel__h81 & DEF_b__h1314;
  DEF_a__h1267 = DEF_a__h240 & DEF_a__h1265;
  DEF_b__h1268 = DEF_sel__h81 & DEF_b__h1266;
  DEF_a__h238 = DEF_a__h240 & DEF_a__h236;
  DEF_b__h239 = DEF_sel__h81 & DEF_b__h237;
  DEF_a__h1219 = DEF_a__h240 & DEF_a__h1217;
  DEF_b__h1220 = DEF_sel__h81 & DEF_b__h1218;
  DEF_test__h82 = (tUInt8)31u & ((((((DEF_a__h238 | DEF_b__h239) << 4u) | ((DEF_a__h1219 | DEF_b__h1220) << 3u)) | ((DEF_a__h1267 | DEF_b__h1268) << 2u)) | ((DEF_a__h1315 | DEF_b__h1316) << 1u)) | (DEF_a__h1363 | DEF_b__h1364));
  DEF_INV_SEL_ARR_0_1_0_1_0_0_1_1_cycle_AND_SEL_ARR__ETC___d39 = DEF_test__h82 == DEF_realAns__h83;
  DEF_NOT_cycle_EQ_8_AND_NOT_INV_SEL_ARR_0_1_0_1_0_0_ETC___d42 = DEF_NOT_cycle_EQ_8___d3 && !DEF_INV_SEL_ARR_0_1_0_1_0_0_1_1_cycle_AND_SEL_ARR__ETC___d39;
  DEF_NOT_cycle_EQ_8_AND_INV_SEL_ARR_0_1_0_1_0_0_1_1_ETC___d40 = DEF_NOT_cycle_EQ_8___d3 && DEF_INV_SEL_ARR_0_1_0_1_0_0_1_1_cycle_AND_SEL_ARR__ETC___d39;
  DEF_x__h1557 = DEF_x__h907 + 1u;
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    if (DEF_cycle_EQ_8___d2)
      dollar_display(sim_hdl, this, "s", &__str_literal_1);
    if (DEF_cycle_EQ_8___d2)
      dollar_finish(sim_hdl, "32", 1u);
    if (DEF_NOT_cycle_EQ_8_AND_INV_SEL_ARR_0_1_0_1_0_0_1_1_ETC___d40)
      dollar_display(sim_hdl,
		     this,
		     "s,1,5,5,5",
		     &__str_literal_2,
		     DEF_sel__h81,
		     DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8,
		     DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12,
		     DEF_test__h82);
    if (DEF_NOT_cycle_EQ_8_AND_NOT_INV_SEL_ARR_0_1_0_1_0_0_ETC___d42)
      dollar_display(sim_hdl,
		     this,
		     "s,1,5,5,5,5",
		     &__str_literal_3,
		     DEF_sel__h81,
		     DEF_SEL_ARR_0_4_31_0_0_8_11_21_cycle___d8,
		     DEF_SEL_ARR_1_7_31_31_31_0_29_22_1_cycle___d12,
		     DEF_test__h82,
		     DEF_realAns__h83);
    if (DEF_NOT_cycle_EQ_8_AND_NOT_INV_SEL_ARR_0_1_0_1_0_0_ETC___d42)
      dollar_finish(sim_hdl, "32", 1u);
  }
  if (DEF_NOT_cycle_EQ_8___d3)
    INST_cycle.METH_write(DEF_x__h1557);
}


/* Methods */


/* Reset routines */

void MOD_mkTbMuxSimple::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_cycle.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTbMuxSimple::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTbMuxSimple::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_cycle.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTbMuxSimple::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 2u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  num = INST_cycle.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTbMuxSimple::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbMuxSimple &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTbMuxSimple::vcd_defs(tVCDDumpType dt, MOD_mkTbMuxSimple &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
    }
}

void MOD_mkTbMuxSimple::vcd_prims(tVCDDumpType dt, MOD_mkTbMuxSimple &backing)
{
  INST_cycle.dump_VCD(dt, backing.INST_cycle);
}