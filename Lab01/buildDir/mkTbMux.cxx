/*
 * Generated by Bluespec Compiler (build 14ff62d)
 * 
 * On Wed Jun 21 21:36:54 CST 2023
 * 
 */
#include "bluesim_primitives.h"
#include "mkTbMux.h"
#include "imported_BDPI_functions.h"


/* String declarations */
static std::string const __str_literal_2("FAILED Sel %b from %d, %d gave %d instead of %d", 47u);
static std::string const __str_literal_1("PASSED", 6u);


/* Constructor */
MOD_mkTbMux::MOD_mkTbMux(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_cycle(simHdl, "cycle", this, 32u, 0u, (tUInt8)0u),
    INST_randomSel_ignore(simHdl, "randomSel_ignore", this, 1u, (tUInt8)0u),
    INST_randomSel_initialized(simHdl, "randomSel_initialized", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_randomSel_zaz(simHdl, "randomSel_zaz", this, 1u, (tUInt8)0u),
    INST_randomVal1_ignore(simHdl, "randomVal1_ignore", this, 5u, (tUInt8)0u),
    INST_randomVal1_initialized(simHdl, "randomVal1_initialized", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_randomVal1_zaz(simHdl, "randomVal1_zaz", this, 5u, (tUInt8)0u),
    INST_randomVal2_ignore(simHdl, "randomVal2_ignore", this, 5u, (tUInt8)0u),
    INST_randomVal2_initialized(simHdl, "randomVal2_initialized", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_randomVal2_zaz(simHdl, "randomVal2_zaz", this, 5u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u),
    DEF_v__h704(2863311530u),
    DEF_v__h315(2863311530u),
    DEF_v__h1090(2863311530u)
{
  symbol_count = 18u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTbMux::init_symbols_0()
{
  init_symbol(&symbols[0u], "cycle", SYM_MODULE, &INST_cycle);
  init_symbol(&symbols[1u], "RL_randomSel_every", SYM_RULE);
  init_symbol(&symbols[2u], "RL_randomSel_every_1", SYM_RULE);
  init_symbol(&symbols[3u], "RL_randomVal1_every", SYM_RULE);
  init_symbol(&symbols[4u], "RL_randomVal1_every_1", SYM_RULE);
  init_symbol(&symbols[5u], "RL_randomVal2_every", SYM_RULE);
  init_symbol(&symbols[6u], "RL_randomVal2_every_1", SYM_RULE);
  init_symbol(&symbols[7u], "RL_test", SYM_RULE);
  init_symbol(&symbols[8u], "randomSel_ignore", SYM_MODULE, &INST_randomSel_ignore);
  init_symbol(&symbols[9u], "randomSel_initialized", SYM_MODULE, &INST_randomSel_initialized);
  init_symbol(&symbols[10u], "randomSel_zaz", SYM_MODULE, &INST_randomSel_zaz);
  init_symbol(&symbols[11u], "randomVal1_ignore", SYM_MODULE, &INST_randomVal1_ignore);
  init_symbol(&symbols[12u], "randomVal1_initialized", SYM_MODULE, &INST_randomVal1_initialized);
  init_symbol(&symbols[13u], "randomVal1_zaz", SYM_MODULE, &INST_randomVal1_zaz);
  init_symbol(&symbols[14u], "randomVal2_ignore", SYM_MODULE, &INST_randomVal2_ignore);
  init_symbol(&symbols[15u], "randomVal2_initialized", SYM_MODULE, &INST_randomVal2_initialized);
  init_symbol(&symbols[16u], "randomVal2_zaz", SYM_MODULE, &INST_randomVal2_zaz);
  init_symbol(&symbols[17u], "x__h1369", SYM_DEF, &DEF_x__h1369, 32u);
}


/* Rule actions */

void MOD_mkTbMux::RL_randomVal1_every()
{
  tUInt8 DEF_new_value__h357;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h315 = rand32();
  DEF_new_value__h357 = (tUInt8)((tUInt8)31u & DEF_v__h315);
  INST_randomVal1_zaz.METH_wset(DEF_new_value__h357);
}

void MOD_mkTbMux::RL_randomVal1_every_1()
{
  DEF_x_wget__h250 = INST_randomVal1_zaz.METH_wget();
  DEF_v__h396 = INST_randomVal1_zaz.METH_whas() ? DEF_x_wget__h250 : (tUInt8)0u;
  INST_randomVal1_ignore.METH_wset(DEF_v__h396);
}

void MOD_mkTbMux::RL_randomVal2_every()
{
  tUInt8 DEF_new_value__h746;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h704 = rand32();
  DEF_new_value__h746 = (tUInt8)((tUInt8)31u & DEF_v__h704);
  INST_randomVal2_zaz.METH_wset(DEF_new_value__h746);
}

void MOD_mkTbMux::RL_randomVal2_every_1()
{
  DEF_x_wget__h647 = INST_randomVal2_zaz.METH_wget();
  DEF_v__h784 = INST_randomVal2_zaz.METH_whas() ? DEF_x_wget__h647 : (tUInt8)0u;
  INST_randomVal2_ignore.METH_wset(DEF_v__h784);
}

void MOD_mkTbMux::RL_randomSel_every()
{
  tUInt8 DEF_new_value__h1132;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h1090 = rand32();
  DEF_new_value__h1132 = (tUInt8)((tUInt8)1u & DEF_v__h1090);
  INST_randomSel_zaz.METH_wset(DEF_new_value__h1132);
}

void MOD_mkTbMux::RL_randomSel_every_1()
{
  DEF_randomSel_zaz_wget____d20 = INST_randomSel_zaz.METH_wget();
  DEF_randomSel_zaz_whas____d19 = INST_randomSel_zaz.METH_whas();
  DEF_v__h1546 = DEF_randomSel_zaz_whas____d19 && DEF_randomSel_zaz_wget____d20;
  INST_randomSel_ignore.METH_wset(DEF_v__h1546);
}

void MOD_mkTbMux::RL_test()
{
  tUInt32 DEF_x__h2113;
  tUInt8 DEF_b__h1772;
  tUInt8 DEF_a__h1771;
  tUInt8 DEF_b__h1724;
  tUInt8 DEF_a__h1723;
  tUInt8 DEF_b__h1820;
  tUInt8 DEF_a__h1819;
  tUInt8 DEF_b__h1868;
  tUInt8 DEF_a__h1867;
  tUInt8 DEF_b__h1916;
  tUInt8 DEF_a__h1915;
  tUInt8 DEF_a__h1725;
  tUInt8 DEF_NOT_cycle_2_EQ_0_3_4_AND_NOT_cycle_2_EQ_128_4__ETC___d68;
  tUInt8 DEF_test__h1588;
  tUInt8 DEF_realAns__h1589;
  tUInt8 DEF_b__h1914;
  tUInt8 DEF_b__h1866;
  tUInt8 DEF_b__h1818;
  tUInt8 DEF_b__h1770;
  tUInt8 DEF_a__h1913;
  tUInt8 DEF_a__h1865;
  tUInt8 DEF_a__h1817;
  tUInt8 DEF_a__h1769;
  tUInt8 DEF_b__h1722;
  tUInt8 DEF_a__h1721;
  DEF_x_wget__h647 = INST_randomVal2_zaz.METH_wget();
  DEF_x_wget__h250 = INST_randomVal1_zaz.METH_wget();
  DEF_v__h396 = INST_randomVal1_zaz.METH_whas() ? DEF_x_wget__h250 : (tUInt8)0u;
  DEF_a__h1721 = (tUInt8)(DEF_v__h396 >> 4u);
  DEF_v__h784 = INST_randomVal2_zaz.METH_whas() ? DEF_x_wget__h647 : (tUInt8)0u;
  DEF_b__h1722 = (tUInt8)(DEF_v__h784 >> 4u);
  DEF_randomSel_zaz_wget____d20 = INST_randomSel_zaz.METH_wget();
  DEF_randomSel_zaz_whas____d19 = INST_randomSel_zaz.METH_whas();
  DEF_x__h1369 = INST_cycle.METH_read();
  DEF_a__h1769 = (tUInt8)((tUInt8)1u & (DEF_v__h396 >> 3u));
  DEF_a__h1817 = (tUInt8)((tUInt8)1u & (DEF_v__h396 >> 2u));
  DEF_a__h1865 = (tUInt8)((tUInt8)1u & (DEF_v__h396 >> 1u));
  DEF_b__h1770 = (tUInt8)((tUInt8)1u & (DEF_v__h784 >> 3u));
  DEF_a__h1913 = (tUInt8)((tUInt8)1u & DEF_v__h396);
  DEF_b__h1818 = (tUInt8)((tUInt8)1u & (DEF_v__h784 >> 2u));
  DEF_b__h1914 = (tUInt8)((tUInt8)1u & DEF_v__h784);
  DEF_b__h1866 = (tUInt8)((tUInt8)1u & (DEF_v__h784 >> 1u));
  DEF_NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27 = !DEF_randomSel_zaz_whas____d19 || !DEF_randomSel_zaz_wget____d20;
  DEF_realAns__h1589 = DEF_NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27 ? DEF_v__h396 : DEF_v__h784;
  DEF_cycle_2_EQ_128___d24 = DEF_x__h1369 == 128u;
  DEF_cycle_2_EQ_0___d23 = DEF_x__h1369 == 0u;
  DEF_v__h1546 = DEF_randomSel_zaz_whas____d19 && DEF_randomSel_zaz_wget____d20;
  DEF_a__h1725 = (tUInt8)1u & ~DEF_v__h1546;
  DEF_a__h1915 = DEF_a__h1725 & DEF_a__h1913;
  DEF_b__h1916 = DEF_v__h1546 & DEF_b__h1914;
  DEF_a__h1867 = DEF_a__h1725 & DEF_a__h1865;
  DEF_b__h1868 = DEF_v__h1546 & DEF_b__h1866;
  DEF_a__h1819 = DEF_a__h1725 & DEF_a__h1817;
  DEF_a__h1723 = DEF_a__h1725 & DEF_a__h1721;
  DEF_b__h1820 = DEF_v__h1546 & DEF_b__h1818;
  DEF_b__h1724 = DEF_v__h1546 & DEF_b__h1722;
  DEF_a__h1771 = DEF_a__h1725 & DEF_a__h1769;
  DEF_b__h1772 = DEF_v__h1546 & DEF_b__h1770;
  DEF_test__h1588 = (tUInt8)31u & ((((((DEF_a__h1723 | DEF_b__h1724) << 4u) | ((DEF_a__h1771 | DEF_b__h1772) << 3u)) | ((DEF_a__h1819 | DEF_b__h1820) << 2u)) | ((DEF_a__h1867 | DEF_b__h1868) << 1u)) | (DEF_a__h1915 | DEF_b__h1916));
  DEF_NOT_cycle_2_EQ_0_3_4_AND_NOT_cycle_2_EQ_128_4__ETC___d68 = !DEF_cycle_2_EQ_0___d23 && (!DEF_cycle_2_EQ_128___d24 && !(DEF_test__h1588 == DEF_realAns__h1589));
  DEF_x__h2113 = DEF_x__h1369 + 1u;
  if (DEF_cycle_2_EQ_0___d23)
    INST_randomVal1_initialized.METH_write((tUInt8)1u);
  if (DEF_cycle_2_EQ_0___d23)
    INST_randomSel_initialized.METH_write((tUInt8)1u);
  if (DEF_cycle_2_EQ_0___d23)
    INST_randomVal2_initialized.METH_write((tUInt8)1u);
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    if (DEF_cycle_2_EQ_128___d24)
      dollar_display(sim_hdl, this, "s", &__str_literal_1);
    if (DEF_cycle_2_EQ_128___d24)
      dollar_finish(sim_hdl, "32", 1u);
    if (DEF_NOT_cycle_2_EQ_0_3_4_AND_NOT_cycle_2_EQ_128_4__ETC___d68)
      dollar_display(sim_hdl,
		     this,
		     "s,1,5,5,5,5",
		     &__str_literal_2,
		     DEF_v__h1546,
		     DEF_v__h396,
		     DEF_v__h784,
		     DEF_test__h1588,
		     DEF_realAns__h1589);
    if (DEF_NOT_cycle_2_EQ_0_3_4_AND_NOT_cycle_2_EQ_128_4__ETC___d68)
      dollar_finish(sim_hdl, "32", 1u);
  }
  INST_cycle.METH_write(DEF_x__h2113);
}


/* Methods */


/* Reset routines */

void MOD_mkTbMux::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_randomVal2_initialized.reset_RST(ARG_rst_in);
  INST_randomVal1_initialized.reset_RST(ARG_rst_in);
  INST_randomSel_initialized.reset_RST(ARG_rst_in);
  INST_cycle.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTbMux::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTbMux::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_cycle.dump_state(indent + 2u);
  INST_randomSel_ignore.dump_state(indent + 2u);
  INST_randomSel_initialized.dump_state(indent + 2u);
  INST_randomSel_zaz.dump_state(indent + 2u);
  INST_randomVal1_ignore.dump_state(indent + 2u);
  INST_randomVal1_initialized.dump_state(indent + 2u);
  INST_randomVal1_zaz.dump_state(indent + 2u);
  INST_randomVal2_ignore.dump_state(indent + 2u);
  INST_randomVal2_initialized.dump_state(indent + 2u);
  INST_randomVal2_zaz.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTbMux::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 25u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "cycle_2_EQ_0___d23", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "cycle_2_EQ_128___d24", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "randomSel_zaz_wget____d20", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "randomSel_zaz_whas____d19", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h1090", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h1546", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h315", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h396", 5u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h704", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h784", 5u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x__h1369", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x_wget__h250", 5u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x_wget__h647", 5u);
  num = INST_cycle.dump_VCD_defs(num);
  num = INST_randomSel_ignore.dump_VCD_defs(num);
  num = INST_randomSel_initialized.dump_VCD_defs(num);
  num = INST_randomSel_zaz.dump_VCD_defs(num);
  num = INST_randomVal1_ignore.dump_VCD_defs(num);
  num = INST_randomVal1_initialized.dump_VCD_defs(num);
  num = INST_randomVal1_zaz.dump_VCD_defs(num);
  num = INST_randomVal2_ignore.dump_VCD_defs(num);
  num = INST_randomVal2_initialized.dump_VCD_defs(num);
  num = INST_randomVal2_zaz.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTbMux::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbMux &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTbMux::vcd_defs(tVCDDumpType dt, MOD_mkTbMux &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 5u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 5u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 5u);
    vcd_write_x(sim_hdl, num++, 5u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.DEF_NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27) != DEF_NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27)
      {
	vcd_write_val(sim_hdl, num, DEF_NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27, 1u);
	backing.DEF_NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27 = DEF_NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27;
      }
      ++num;
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
      if ((backing.DEF_cycle_2_EQ_0___d23) != DEF_cycle_2_EQ_0___d23)
      {
	vcd_write_val(sim_hdl, num, DEF_cycle_2_EQ_0___d23, 1u);
	backing.DEF_cycle_2_EQ_0___d23 = DEF_cycle_2_EQ_0___d23;
      }
      ++num;
      if ((backing.DEF_cycle_2_EQ_128___d24) != DEF_cycle_2_EQ_128___d24)
      {
	vcd_write_val(sim_hdl, num, DEF_cycle_2_EQ_128___d24, 1u);
	backing.DEF_cycle_2_EQ_128___d24 = DEF_cycle_2_EQ_128___d24;
      }
      ++num;
      if ((backing.DEF_randomSel_zaz_wget____d20) != DEF_randomSel_zaz_wget____d20)
      {
	vcd_write_val(sim_hdl, num, DEF_randomSel_zaz_wget____d20, 1u);
	backing.DEF_randomSel_zaz_wget____d20 = DEF_randomSel_zaz_wget____d20;
      }
      ++num;
      if ((backing.DEF_randomSel_zaz_whas____d19) != DEF_randomSel_zaz_whas____d19)
      {
	vcd_write_val(sim_hdl, num, DEF_randomSel_zaz_whas____d19, 1u);
	backing.DEF_randomSel_zaz_whas____d19 = DEF_randomSel_zaz_whas____d19;
      }
      ++num;
      if ((backing.DEF_v__h1090) != DEF_v__h1090)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h1090, 32u);
	backing.DEF_v__h1090 = DEF_v__h1090;
      }
      ++num;
      if ((backing.DEF_v__h1546) != DEF_v__h1546)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h1546, 1u);
	backing.DEF_v__h1546 = DEF_v__h1546;
      }
      ++num;
      if ((backing.DEF_v__h315) != DEF_v__h315)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h315, 32u);
	backing.DEF_v__h315 = DEF_v__h315;
      }
      ++num;
      if ((backing.DEF_v__h396) != DEF_v__h396)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h396, 5u);
	backing.DEF_v__h396 = DEF_v__h396;
      }
      ++num;
      if ((backing.DEF_v__h704) != DEF_v__h704)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h704, 32u);
	backing.DEF_v__h704 = DEF_v__h704;
      }
      ++num;
      if ((backing.DEF_v__h784) != DEF_v__h784)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h784, 5u);
	backing.DEF_v__h784 = DEF_v__h784;
      }
      ++num;
      if ((backing.DEF_x__h1369) != DEF_x__h1369)
      {
	vcd_write_val(sim_hdl, num, DEF_x__h1369, 32u);
	backing.DEF_x__h1369 = DEF_x__h1369;
      }
      ++num;
      if ((backing.DEF_x_wget__h250) != DEF_x_wget__h250)
      {
	vcd_write_val(sim_hdl, num, DEF_x_wget__h250, 5u);
	backing.DEF_x_wget__h250 = DEF_x_wget__h250;
      }
      ++num;
      if ((backing.DEF_x_wget__h647) != DEF_x_wget__h647)
      {
	vcd_write_val(sim_hdl, num, DEF_x_wget__h647, 5u);
	backing.DEF_x_wget__h647 = DEF_x_wget__h647;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, DEF_NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27, 1u);
      backing.DEF_NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27 = DEF_NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27;
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_cycle_2_EQ_0___d23, 1u);
      backing.DEF_cycle_2_EQ_0___d23 = DEF_cycle_2_EQ_0___d23;
      vcd_write_val(sim_hdl, num++, DEF_cycle_2_EQ_128___d24, 1u);
      backing.DEF_cycle_2_EQ_128___d24 = DEF_cycle_2_EQ_128___d24;
      vcd_write_val(sim_hdl, num++, DEF_randomSel_zaz_wget____d20, 1u);
      backing.DEF_randomSel_zaz_wget____d20 = DEF_randomSel_zaz_wget____d20;
      vcd_write_val(sim_hdl, num++, DEF_randomSel_zaz_whas____d19, 1u);
      backing.DEF_randomSel_zaz_whas____d19 = DEF_randomSel_zaz_whas____d19;
      vcd_write_val(sim_hdl, num++, DEF_v__h1090, 32u);
      backing.DEF_v__h1090 = DEF_v__h1090;
      vcd_write_val(sim_hdl, num++, DEF_v__h1546, 1u);
      backing.DEF_v__h1546 = DEF_v__h1546;
      vcd_write_val(sim_hdl, num++, DEF_v__h315, 32u);
      backing.DEF_v__h315 = DEF_v__h315;
      vcd_write_val(sim_hdl, num++, DEF_v__h396, 5u);
      backing.DEF_v__h396 = DEF_v__h396;
      vcd_write_val(sim_hdl, num++, DEF_v__h704, 32u);
      backing.DEF_v__h704 = DEF_v__h704;
      vcd_write_val(sim_hdl, num++, DEF_v__h784, 5u);
      backing.DEF_v__h784 = DEF_v__h784;
      vcd_write_val(sim_hdl, num++, DEF_x__h1369, 32u);
      backing.DEF_x__h1369 = DEF_x__h1369;
      vcd_write_val(sim_hdl, num++, DEF_x_wget__h250, 5u);
      backing.DEF_x_wget__h250 = DEF_x_wget__h250;
      vcd_write_val(sim_hdl, num++, DEF_x_wget__h647, 5u);
      backing.DEF_x_wget__h647 = DEF_x_wget__h647;
    }
}

void MOD_mkTbMux::vcd_prims(tVCDDumpType dt, MOD_mkTbMux &backing)
{
  INST_cycle.dump_VCD(dt, backing.INST_cycle);
  INST_randomSel_ignore.dump_VCD(dt, backing.INST_randomSel_ignore);
  INST_randomSel_initialized.dump_VCD(dt, backing.INST_randomSel_initialized);
  INST_randomSel_zaz.dump_VCD(dt, backing.INST_randomSel_zaz);
  INST_randomVal1_ignore.dump_VCD(dt, backing.INST_randomVal1_ignore);
  INST_randomVal1_initialized.dump_VCD(dt, backing.INST_randomVal1_initialized);
  INST_randomVal1_zaz.dump_VCD(dt, backing.INST_randomVal1_zaz);
  INST_randomVal2_ignore.dump_VCD(dt, backing.INST_randomVal2_ignore);
  INST_randomVal2_initialized.dump_VCD(dt, backing.INST_randomVal2_initialized);
  INST_randomVal2_zaz.dump_VCD(dt, backing.INST_randomVal2_zaz);
}
