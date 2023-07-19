/*
 * Generated by Bluespec Compiler (build 14ff62d)
 * 
 * On Wed Jun 21 21:04:46 CST 2023
 * 
 */
#include "bluesim_primitives.h"
#include "mkTbRCASimple.h"


/* String declarations */
static std::string const __str_literal_2("%d + %d = %d", 12u);
static std::string const __str_literal_3("FAILED %d + %d gave %d instead of %d", 36u);
static std::string const __str_literal_1("PASSED", 6u);


/* Constructor */
MOD_mkTbRCASimple::MOD_mkTbRCASimple(tSimStateHdl simHdl, char const *name, Module *parent)
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

void MOD_mkTbRCASimple::init_symbols_0()
{
  init_symbol(&symbols[0u], "cycle", SYM_MODULE, &INST_cycle);
  init_symbol(&symbols[1u], "RL_test", SYM_RULE);
}


/* Rule actions */

void MOD_mkTbRCASimple::RL_test()
{
  tUInt8 DEF_high__h180;
  tUInt32 DEF_x__h3076;
  tUInt8 DEF_y__h1311;
  tUInt8 DEF_x__h1310;
  tUInt8 DEF_y__h1309;
  tUInt8 DEF_x__h1308;
  tUInt8 DEF_y__h1422;
  tUInt8 DEF_x__h1421;
  tUInt8 DEF_y__h1420;
  tUInt8 DEF_x__h1419;
  tUInt8 DEF_y__h1532;
  tUInt8 DEF_x__h1531;
  tUInt8 DEF_y__h1530;
  tUInt8 DEF_x__h1529;
  tUInt8 DEF_y__h2036;
  tUInt8 DEF_x__h2035;
  tUInt8 DEF_y__h2034;
  tUInt8 DEF_x__h2033;
  tUInt8 DEF_y__h2187;
  tUInt8 DEF_x__h2186;
  tUInt8 DEF_y__h2185;
  tUInt8 DEF_x__h2184;
  tUInt8 DEF_y__h2297;
  tUInt8 DEF_x__h2296;
  tUInt8 DEF_y__h2295;
  tUInt8 DEF_x__h2294;
  tUInt8 DEF_y__h2407;
  tUInt8 DEF_x__h2406;
  tUInt8 DEF_y__h2405;
  tUInt8 DEF_x__h2404;
  tUInt8 DEF_c__h2393;
  tUInt8 DEF_x__h2570;
  tUInt8 DEF_c__h2283;
  tUInt8 DEF_x__h2647;
  tUInt8 DEF_c__h2173;
  tUInt8 DEF_x__h2724;
  tUInt8 DEF_x__h2801;
  tUInt8 DEF_c__h1518;
  tUInt8 DEF_x__h1695;
  tUInt8 DEF_c__h1408;
  tUInt8 DEF_x__h1772;
  tUInt8 DEF_x__h1849;
  tUInt8 DEF_NOT_cycle_EQ_8_AND_SEL_ARR_1_8_63_102_177_128__ETC___d87;
  tUInt8 DEF_NOT_cycle_EQ_8_AND_NOT_SEL_ARR_1_8_63_102_177__ETC___d89;
  tUInt32 DEF_realAns__h2891;
  tUInt8 DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle_BIT_7_ETC___d86;
  tUInt8 DEF_c__h1297;
  tUInt8 DEF_c__h2022;
  tUInt8 DEF_b__h1915;
  tUInt8 DEF_b__h1296;
  tUInt8 DEF_b__h1407;
  tUInt8 DEF_b__h1517;
  tUInt8 DEF_b__h2021;
  tUInt8 DEF_b__h2172;
  tUInt8 DEF_b__h2282;
  tUInt8 DEF_b__h2392;
  tUInt8 DEF_a__h1914;
  tUInt8 DEF_a__h1295;
  tUInt8 DEF_a__h1406;
  tUInt8 DEF_a__h1516;
  tUInt8 DEF_a__h2020;
  tUInt8 DEF_a__h2171;
  tUInt8 DEF_a__h2281;
  tUInt8 DEF_a__h2391;
  tUInt32 DEF_x__h937;
  tUInt8 DEF_NOT_cycle_EQ_8___d3;
  tUInt32 DEF_v__h175;
  tUInt8 DEF_cycle_EQ_8___d2;
  tUInt8 DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8;
  tUInt8 DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5;
  DEF_x__h937 = INST_cycle.METH_read();
  switch (DEF_x__h937) {
  case 0u:
    DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 = (tUInt8)1u;
    break;
  case 1u:
    DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 = (tUInt8)8u;
    break;
  case 2u:
    DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 = (tUInt8)63u;
    break;
  case 3u:
    DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 = (tUInt8)102u;
    break;
  case 4u:
    DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 = (tUInt8)177u;
    break;
  case 5u:
    DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 = (tUInt8)128u;
    break;
  case 6u:
  case 7u:
    DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 = (tUInt8)255u;
    break;
  default:
    DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 = (tUInt8)170u;
  }
  switch (DEF_x__h937) {
  case 0u:
  case 6u:
    DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 = (tUInt8)1u;
    break;
  case 1u:
    DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 = (tUInt8)8u;
    break;
  case 2u:
    DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 = (tUInt8)27u;
    break;
  case 3u:
    DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 = (tUInt8)92u;
    break;
  case 4u:
    DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 = (tUInt8)202u;
    break;
  case 5u:
    DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 = (tUInt8)128u;
    break;
  case 7u:
    DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 = (tUInt8)255u;
    break;
  default:
    DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 = (tUInt8)170u;
  }
  DEF_cycle_EQ_8___d2 = DEF_x__h937 == 8u;
  DEF_NOT_cycle_EQ_8___d3 = !DEF_cycle_EQ_8___d2;
  DEF_a__h2391 = (tUInt8)(DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 >> 7u);
  DEF_a__h2171 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 >> 5u));
  DEF_a__h2281 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 >> 6u));
  DEF_a__h2020 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 >> 4u));
  DEF_a__h1516 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 >> 3u));
  DEF_a__h1295 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 >> 1u));
  DEF_a__h1406 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5 >> 2u));
  DEF_a__h1914 = (tUInt8)((tUInt8)1u & DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5);
  DEF_b__h2392 = (tUInt8)(DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 >> 7u);
  DEF_b__h2282 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 >> 6u));
  DEF_b__h2021 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 >> 4u));
  DEF_b__h2172 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 >> 5u));
  DEF_b__h1517 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 >> 3u));
  DEF_b__h1407 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 >> 2u));
  DEF_b__h1296 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8 >> 1u));
  DEF_b__h1915 = (tUInt8)((tUInt8)1u & DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8);
  DEF_c__h1297 = (tUInt8)((tUInt8)1u & ((DEF_a__h1914 & DEF_b__h1915 ? (tUInt8)2u : (tUInt8)0u) >> 1u));
  DEF_realAns__h2891 = 511u & ((511u & ((((tUInt32)((tUInt8)0u)) << 8u) | (tUInt32)(DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5))) + (511u & ((((tUInt32)((tUInt8)0u)) << 8u) | (tUInt32)(DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8))));
  DEF_x__h1849 = DEF_a__h1295 ^ DEF_b__h1296;
  DEF_x__h1772 = DEF_a__h1406 ^ DEF_b__h1407;
  DEF_x__h1695 = DEF_a__h1516 ^ DEF_b__h1517;
  DEF_x__h2801 = DEF_a__h2020 ^ DEF_b__h2021;
  DEF_x__h2724 = DEF_a__h2171 ^ DEF_b__h2172;
  DEF_x__h2647 = DEF_a__h2281 ^ DEF_b__h2282;
  DEF_x__h2570 = DEF_a__h2391 ^ DEF_b__h2392;
  DEF_x__h2406 = DEF_a__h2391 & DEF_b__h2392;
  DEF_x__h2296 = DEF_a__h2281 & DEF_b__h2282;
  DEF_x__h2186 = DEF_a__h2171 & DEF_b__h2172;
  DEF_x__h2035 = DEF_a__h2020 & DEF_b__h2021;
  DEF_x__h1531 = DEF_a__h1516 & DEF_b__h1517;
  DEF_x__h1421 = DEF_a__h1406 & DEF_b__h1407;
  DEF_y__h1309 = DEF_b__h1296 & DEF_c__h1297;
  DEF_x__h1310 = DEF_a__h1295 & DEF_b__h1296;
  DEF_y__h1311 = DEF_a__h1295 & DEF_c__h1297;
  DEF_x__h1308 = DEF_x__h1310 | DEF_y__h1311;
  DEF_c__h1408 = DEF_x__h1308 | DEF_y__h1309;
  DEF_y__h1420 = DEF_b__h1407 & DEF_c__h1408;
  DEF_y__h1422 = DEF_a__h1406 & DEF_c__h1408;
  DEF_x__h1419 = DEF_x__h1421 | DEF_y__h1422;
  DEF_c__h1518 = DEF_x__h1419 | DEF_y__h1420;
  DEF_y__h1530 = DEF_b__h1517 & DEF_c__h1518;
  DEF_y__h1532 = DEF_a__h1516 & DEF_c__h1518;
  DEF_x__h1529 = DEF_x__h1531 | DEF_y__h1532;
  DEF_c__h2022 = (tUInt8)((tUInt8)1u & (DEF_x__h1529 | DEF_y__h1530 ? (tUInt8)1u : (tUInt8)0u));
  DEF_y__h2034 = DEF_b__h2021 & DEF_c__h2022;
  DEF_y__h2036 = DEF_a__h2020 & DEF_c__h2022;
  DEF_x__h2033 = DEF_x__h2035 | DEF_y__h2036;
  DEF_c__h2173 = DEF_x__h2033 | DEF_y__h2034;
  DEF_y__h2185 = DEF_b__h2172 & DEF_c__h2173;
  DEF_y__h2187 = DEF_a__h2171 & DEF_c__h2173;
  DEF_x__h2184 = DEF_x__h2186 | DEF_y__h2187;
  DEF_c__h2283 = DEF_x__h2184 | DEF_y__h2185;
  DEF_y__h2295 = DEF_b__h2282 & DEF_c__h2283;
  DEF_y__h2297 = DEF_a__h2281 & DEF_c__h2283;
  DEF_x__h2294 = DEF_x__h2296 | DEF_y__h2297;
  DEF_c__h2393 = DEF_x__h2294 | DEF_y__h2295;
  DEF_y__h2405 = DEF_b__h2392 & DEF_c__h2393;
  DEF_y__h2407 = DEF_a__h2391 & DEF_c__h2393;
  DEF_x__h2404 = DEF_x__h2406 | DEF_y__h2407;
  DEF_x__h3076 = DEF_x__h937 + 1u;
  DEF_high__h180 = (tUInt8)31u & ((((((DEF_x__h2404 | DEF_y__h2405) << 4u) | ((DEF_x__h2570 ^ DEF_c__h2393) << 3u)) | ((DEF_x__h2647 ^ DEF_c__h2283) << 2u)) | ((DEF_x__h2724 ^ DEF_c__h2173) << 1u)) | (DEF_x__h2801 ^ DEF_c__h2022));
  DEF_v__h175 = 511u & (((((((tUInt32)(DEF_high__h180)) << 4u) | (((tUInt32)(DEF_x__h1695 ^ DEF_c__h1518)) << 3u)) | (((tUInt32)(DEF_x__h1772 ^ DEF_c__h1408)) << 2u)) | (((tUInt32)(DEF_x__h1849 ^ DEF_c__h1297)) << 1u)) | (tUInt32)(DEF_a__h1914 ^ DEF_b__h1915));
  DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle_BIT_7_ETC___d86 = DEF_v__h175 == DEF_realAns__h2891;
  DEF_NOT_cycle_EQ_8_AND_NOT_SEL_ARR_1_8_63_102_177__ETC___d89 = DEF_NOT_cycle_EQ_8___d3 && !DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle_BIT_7_ETC___d86;
  DEF_NOT_cycle_EQ_8_AND_SEL_ARR_1_8_63_102_177_128__ETC___d87 = DEF_NOT_cycle_EQ_8___d3 && DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle_BIT_7_ETC___d86;
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    if (DEF_cycle_EQ_8___d2)
      dollar_display(sim_hdl, this, "s", &__str_literal_1);
    if (DEF_cycle_EQ_8___d2)
      dollar_finish(sim_hdl, "32", 1u);
    if (DEF_NOT_cycle_EQ_8_AND_SEL_ARR_1_8_63_102_177_128__ETC___d87)
      dollar_display(sim_hdl,
		     this,
		     "s,8,8,9",
		     &__str_literal_2,
		     DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5,
		     DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8,
		     DEF_v__h175);
    if (DEF_NOT_cycle_EQ_8_AND_NOT_SEL_ARR_1_8_63_102_177__ETC___d89)
      dollar_display(sim_hdl,
		     this,
		     "s,8,8,9,9",
		     &__str_literal_3,
		     DEF_SEL_ARR_1_8_63_102_177_128_255_255_cycle___d5,
		     DEF_SEL_ARR_1_8_27_92_202_128_1_255_cycle___d8,
		     DEF_v__h175,
		     DEF_realAns__h2891);
    if (DEF_NOT_cycle_EQ_8_AND_NOT_SEL_ARR_1_8_63_102_177__ETC___d89)
      dollar_finish(sim_hdl, "32", 1u);
  }
  INST_cycle.METH_write(DEF_x__h3076);
}


/* Methods */


/* Reset routines */

void MOD_mkTbRCASimple::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_cycle.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTbRCASimple::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTbRCASimple::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_cycle.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTbRCASimple::dump_VCD_defs(unsigned int levels)
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

void MOD_mkTbRCASimple::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbRCASimple &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTbRCASimple::vcd_defs(tVCDDumpType dt, MOD_mkTbRCASimple &backing)
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

void MOD_mkTbRCASimple::vcd_prims(tVCDDumpType dt, MOD_mkTbRCASimple &backing)
{
  INST_cycle.dump_VCD(dt, backing.INST_cycle);
}
