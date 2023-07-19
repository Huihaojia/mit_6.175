/*
 * Generated by Bluespec Compiler (build 14ff62d)
 * 
 * On Sat Jul  1 04:51:55 CST 2023
 * 
 */
#include "bluesim_primitives.h"
#include "mkTbEx3.h"
#include "imported_BDPI_functions.h"


/* String declarations */
static std::string const __str_literal_3("    if signed: %0d * %0d test function gave %0d", 47u);
static std::string const __str_literal_6("    if signed: %0d * %0d test function gave %0d instead of %0d",
					 62u);
static std::string const __str_literal_4("    if unsigned: %0d * %0d test function gave %0d", 49u);
static std::string const __str_literal_7("    if unsigned: %0d * %0d test function gave %0d instead of %0d",
					 64u);
static std::string const __str_literal_5("FAILED:", 7u);
static std::string const __str_literal_1("PASSED", 6u);
static std::string const __str_literal_2("PASSED case %0d", 15u);


/* Constructor */
MOD_mkTbEx3::MOD_mkTbEx3(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_tb_cycle(simHdl, "tb_cycle", this, 32u, 0u, (tUInt8)0u),
    INST_tb_randomA_ignore(simHdl, "tb_randomA_ignore", this, 8u, (tUInt8)0u),
    INST_tb_randomA_initialized(simHdl, "tb_randomA_initialized", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_tb_randomA_zaz(simHdl, "tb_randomA_zaz", this, 8u, (tUInt8)0u),
    INST_tb_randomB_ignore(simHdl, "tb_randomB_ignore", this, 8u, (tUInt8)0u),
    INST_tb_randomB_initialized(simHdl, "tb_randomB_initialized", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_tb_randomB_zaz(simHdl, "tb_randomB_zaz", this, 8u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u),
    DEF_v__h719(2863311530u),
    DEF_v__h329(2863311530u)
{
  symbol_count = 23u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTbEx3::init_symbols_0()
{
  init_symbol(&symbols[0u],
	      "CAN_FIRE_RL_tb_randomA_every",
	      SYM_DEF,
	      &DEF_CAN_FIRE_RL_tb_randomA_every,
	      1u);
  init_symbol(&symbols[1u],
	      "CAN_FIRE_RL_tb_randomA_every_1",
	      SYM_DEF,
	      &DEF_CAN_FIRE_RL_tb_randomA_every_1,
	      1u);
  init_symbol(&symbols[2u],
	      "CAN_FIRE_RL_tb_randomB_every",
	      SYM_DEF,
	      &DEF_CAN_FIRE_RL_tb_randomB_every,
	      1u);
  init_symbol(&symbols[3u],
	      "CAN_FIRE_RL_tb_randomB_every_1",
	      SYM_DEF,
	      &DEF_CAN_FIRE_RL_tb_randomB_every_1,
	      1u);
  init_symbol(&symbols[4u], "CAN_FIRE_RL_tb_test", SYM_DEF, &DEF_CAN_FIRE_RL_tb_test, 1u);
  init_symbol(&symbols[5u], "RL_tb_randomA_every", SYM_RULE);
  init_symbol(&symbols[6u], "RL_tb_randomA_every_1", SYM_RULE);
  init_symbol(&symbols[7u], "RL_tb_randomB_every", SYM_RULE);
  init_symbol(&symbols[8u], "RL_tb_randomB_every_1", SYM_RULE);
  init_symbol(&symbols[9u], "RL_tb_test", SYM_RULE);
  init_symbol(&symbols[10u], "tb_cycle", SYM_MODULE, &INST_tb_cycle);
  init_symbol(&symbols[11u], "tb_randomA_ignore", SYM_MODULE, &INST_tb_randomA_ignore);
  init_symbol(&symbols[12u], "tb_randomA_initialized", SYM_MODULE, &INST_tb_randomA_initialized);
  init_symbol(&symbols[13u], "tb_randomA_zaz", SYM_MODULE, &INST_tb_randomA_zaz);
  init_symbol(&symbols[14u], "tb_randomB_ignore", SYM_MODULE, &INST_tb_randomB_ignore);
  init_symbol(&symbols[15u], "tb_randomB_initialized", SYM_MODULE, &INST_tb_randomB_initialized);
  init_symbol(&symbols[16u], "tb_randomB_zaz", SYM_MODULE, &INST_tb_randomB_zaz);
  init_symbol(&symbols[17u],
	      "WILL_FIRE_RL_tb_randomA_every",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_tb_randomA_every,
	      1u);
  init_symbol(&symbols[18u],
	      "WILL_FIRE_RL_tb_randomA_every_1",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_tb_randomA_every_1,
	      1u);
  init_symbol(&symbols[19u],
	      "WILL_FIRE_RL_tb_randomB_every",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_tb_randomB_every,
	      1u);
  init_symbol(&symbols[20u],
	      "WILL_FIRE_RL_tb_randomB_every_1",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_tb_randomB_every_1,
	      1u);
  init_symbol(&symbols[21u], "WILL_FIRE_RL_tb_test", SYM_DEF, &DEF_WILL_FIRE_RL_tb_test, 1u);
  init_symbol(&symbols[22u], "x__h970", SYM_DEF, &DEF_x__h970, 32u);
}


/* Rule actions */

void MOD_mkTbEx3::RL_tb_randomA_every()
{
  tUInt8 DEF_new_value__h371;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h329 = rand32();
  DEF_new_value__h371 = (tUInt8)((tUInt8)255u & DEF_v__h329);
  INST_tb_randomA_zaz.METH_wset(DEF_new_value__h371);
}

void MOD_mkTbEx3::RL_tb_randomA_every_1()
{
  DEF_x_wget__h264 = INST_tb_randomA_zaz.METH_wget();
  DEF_v__h410 = INST_tb_randomA_zaz.METH_whas() ? DEF_x_wget__h264 : (tUInt8)0u;
  INST_tb_randomA_ignore.METH_wset(DEF_v__h410);
}

void MOD_mkTbEx3::RL_tb_randomB_every()
{
  tUInt8 DEF_new_value__h761;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h719 = rand32();
  DEF_new_value__h761 = (tUInt8)((tUInt8)255u & DEF_v__h719);
  INST_tb_randomB_zaz.METH_wset(DEF_new_value__h761);
}

void MOD_mkTbEx3::RL_tb_randomB_every_1()
{
  DEF_x_wget__h662 = INST_tb_randomB_zaz.METH_wget();
  DEF_v__h799 = INST_tb_randomB_zaz.METH_whas() ? DEF_x_wget__h662 : (tUInt8)0u;
  INST_tb_randomB_ignore.METH_wset(DEF_v__h799);
}

void MOD_mkTbEx3::RL_tb_test()
{
  tUInt32 DEF_sum__h1283;
  tUInt32 DEF_x__h2424;
  tUInt8 DEF_NOT_tb_cycle_5_EQ_0_6_1_AND_NOT_tb_cycle_5_EQ__ETC___d86;
  tUInt8 DEF_NOT_tb_cycle_5_EQ_0_6_1_AND_NOT_tb_cycle_5_EQ__ETC___d93;
  tUInt32 DEF__0_CONCAT_IF_tb_randomA_zaz_whas_THEN_tb_random_ETC___d29;
  tUInt32 DEF_sum__h1367;
  tUInt8 DEF_x__h1366;
  tUInt32 DEF_sum__h1355;
  tUInt8 DEF_x__h1354;
  tUInt32 DEF_sum__h1343;
  tUInt8 DEF_x__h1342;
  tUInt32 DEF_sum__h1331;
  tUInt8 DEF_x__h1330;
  tUInt32 DEF_sum__h1319;
  tUInt8 DEF_x__h1318;
  tUInt32 DEF_sum__h1307;
  tUInt8 DEF_x__h1306;
  tUInt32 DEF_sum__h1295;
  tUInt8 DEF_x__h1294;
  tUInt8 DEF_signed_IF_tb_randomA_zaz_whas_THEN_tb_randomA_ETC___d87;
  tUInt8 DEF_signed_IF_tb_randomB_zaz_whas__2_THEN_tb_rand_ETC___d88;
  tUInt32 DEF_signed_0_CONCAT_0_CONCAT_0_CONCAT_0_CONCAT_0__ETC___d89;
  tUInt32 DEF_expected__h1178;
  tUInt32 DEF_signed_0_CONCAT_IF_tb_randomA_zaz_whas_THEN_t_ETC___d94;
  tUInt8 DEF__0_CONCAT_0_CONCAT_0_CONCAT_0_CONCAT_0_CONCAT_0_ETC___d83;
  tUInt8 DEF_NOT_IF_tb_randomA_zaz_whas_THEN_tb_randomA_zaz_ETC___d27;
  tUInt8 DEF_NOT_tb_cycle_5_EQ_128_7___d22;
  tUInt8 DEF_NOT_tb_cycle_5_EQ_0_6___d21;
  tUInt32 DEF_test__h1177;
  DEF_x__h970 = INST_tb_cycle.METH_read();
  DEF_x_wget__h662 = INST_tb_randomB_zaz.METH_wget();
  DEF_v__h799 = INST_tb_randomB_zaz.METH_whas() ? DEF_x_wget__h662 : (tUInt8)0u;
  DEF_x_wget__h264 = INST_tb_randomA_zaz.METH_wget();
  DEF_v__h410 = INST_tb_randomA_zaz.METH_whas() ? DEF_x_wget__h264 : (tUInt8)0u;
  DEF_tb_cycle_5_EQ_128___d17 = DEF_x__h970 == 128u;
  DEF_tb_cycle_5_EQ_0___d16 = DEF_x__h970 == 0u;
  DEF_NOT_tb_cycle_5_EQ_0_6___d21 = !DEF_tb_cycle_5_EQ_0___d16;
  DEF_NOT_tb_cycle_5_EQ_128_7___d22 = !DEF_tb_cycle_5_EQ_128___d17;
  DEF_NOT_IF_tb_randomA_zaz_whas_THEN_tb_randomA_zaz_ETC___d27 = !(DEF_v__h410 == (tUInt8)128u) && !(DEF_v__h799 == (tUInt8)128u);
  DEF_expected__h1178 = (tUInt32)(65535u & ((65535u & ((((tUInt32)((tUInt8)0u)) << 8u) | (tUInt32)(DEF_v__h410))) * (65535u & ((((tUInt32)((tUInt8)0u)) << 8u) | (tUInt32)(DEF_v__h799)))));
  DEF_signed_0_CONCAT_IF_tb_randomA_zaz_whas_THEN_t_ETC___d94 = DEF_expected__h1178;
  DEF_signed_IF_tb_randomB_zaz_whas__2_THEN_tb_rand_ETC___d88 = DEF_v__h799;
  DEF_signed_IF_tb_randomA_zaz_whas_THEN_tb_randomA_ETC___d87 = DEF_v__h410;
  DEF__0_CONCAT_IF_tb_randomA_zaz_whas_THEN_tb_random_ETC___d29 = 511u & ((((tUInt32)((tUInt8)0u)) << 8u) | (tUInt32)(DEF_v__h410));
  DEF_sum__h1367 = (tUInt8)((tUInt8)1u & DEF_v__h799) ? DEF__0_CONCAT_IF_tb_randomA_zaz_whas_THEN_tb_random_ETC___d29 : 0u;
  DEF_x__h1366 = (tUInt8)(DEF_sum__h1367 >> 1u);
  DEF_sum__h1355 = 511u & ((511u & ((((tUInt32)((tUInt8)0u)) << 8u) | (tUInt32)(DEF_x__h1366))) + ((tUInt8)((tUInt8)1u & (DEF_v__h799 >> 1u)) ? DEF__0_CONCAT_IF_tb_randomA_zaz_whas_THEN_tb_random_ETC___d29 : 0u));
  DEF_x__h1354 = (tUInt8)(DEF_sum__h1355 >> 1u);
  DEF_sum__h1343 = 511u & ((511u & ((((tUInt32)((tUInt8)0u)) << 8u) | (tUInt32)(DEF_x__h1354))) + ((tUInt8)((tUInt8)1u & (DEF_v__h799 >> 2u)) ? DEF__0_CONCAT_IF_tb_randomA_zaz_whas_THEN_tb_random_ETC___d29 : 0u));
  DEF_x__h1342 = (tUInt8)(DEF_sum__h1343 >> 1u);
  DEF_sum__h1331 = 511u & ((511u & ((((tUInt32)((tUInt8)0u)) << 8u) | (tUInt32)(DEF_x__h1342))) + ((tUInt8)((tUInt8)1u & (DEF_v__h799 >> 3u)) ? DEF__0_CONCAT_IF_tb_randomA_zaz_whas_THEN_tb_random_ETC___d29 : 0u));
  DEF_x__h1330 = (tUInt8)(DEF_sum__h1331 >> 1u);
  DEF_sum__h1319 = 511u & ((511u & ((((tUInt32)((tUInt8)0u)) << 8u) | (tUInt32)(DEF_x__h1330))) + ((tUInt8)((tUInt8)1u & (DEF_v__h799 >> 4u)) ? DEF__0_CONCAT_IF_tb_randomA_zaz_whas_THEN_tb_random_ETC___d29 : 0u));
  DEF_x__h1318 = (tUInt8)(DEF_sum__h1319 >> 1u);
  DEF_sum__h1307 = 511u & ((511u & ((((tUInt32)((tUInt8)0u)) << 8u) | (tUInt32)(DEF_x__h1318))) + ((tUInt8)((tUInt8)1u & (DEF_v__h799 >> 5u)) ? DEF__0_CONCAT_IF_tb_randomA_zaz_whas_THEN_tb_random_ETC___d29 : 0u));
  DEF_x__h1306 = (tUInt8)(DEF_sum__h1307 >> 1u);
  DEF_sum__h1295 = 511u & ((511u & ((((tUInt32)((tUInt8)0u)) << 8u) | (tUInt32)(DEF_x__h1306))) + ((tUInt8)((tUInt8)1u & (DEF_v__h799 >> 6u)) ? DEF__0_CONCAT_IF_tb_randomA_zaz_whas_THEN_tb_random_ETC___d29 : 0u));
  DEF_x__h1294 = (tUInt8)(DEF_sum__h1295 >> 1u);
  DEF_x__h2424 = DEF_x__h970 + 1u;
  DEF_sum__h1283 = 511u & ((511u & ((((tUInt32)((tUInt8)0u)) << 8u) | (tUInt32)(DEF_x__h1294))) + ((tUInt8)(DEF_v__h799 >> 7u) ? DEF__0_CONCAT_IF_tb_randomA_zaz_whas_THEN_tb_random_ETC___d29 : 0u));
  DEF_test__h1177 = 65535u & ((((((((DEF_sum__h1283 << 7u) | (((tUInt32)((tUInt8)((tUInt8)1u & DEF_sum__h1295))) << 6u)) | (((tUInt32)((tUInt8)((tUInt8)1u & DEF_sum__h1307))) << 5u)) | (((tUInt32)((tUInt8)((tUInt8)1u & DEF_sum__h1319))) << 4u)) | (((tUInt32)((tUInt8)((tUInt8)1u & DEF_sum__h1331))) << 3u)) | (((tUInt32)((tUInt8)((tUInt8)1u & DEF_sum__h1343))) << 2u)) | (((tUInt32)((tUInt8)((tUInt8)1u & DEF_sum__h1355))) << 1u)) | (tUInt32)((tUInt8)((tUInt8)1u & ((tUInt8)((tUInt8)1u & DEF_sum__h1367) ? (tUInt8)1u : (tUInt8)0u))));
  DEF__0_CONCAT_0_CONCAT_0_CONCAT_0_CONCAT_0_CONCAT_0_ETC___d83 = DEF_test__h1177 == DEF_expected__h1178;
  DEF_signed_0_CONCAT_0_CONCAT_0_CONCAT_0_CONCAT_0__ETC___d89 = DEF_test__h1177;
  DEF_NOT_tb_cycle_5_EQ_0_6_1_AND_NOT_tb_cycle_5_EQ__ETC___d93 = DEF_NOT_tb_cycle_5_EQ_0_6___d21 && (DEF_NOT_tb_cycle_5_EQ_128_7___d22 && (DEF_NOT_IF_tb_randomA_zaz_whas_THEN_tb_randomA_zaz_ETC___d27 && !DEF__0_CONCAT_0_CONCAT_0_CONCAT_0_CONCAT_0_CONCAT_0_ETC___d83));
  DEF_NOT_tb_cycle_5_EQ_0_6_1_AND_NOT_tb_cycle_5_EQ__ETC___d86 = DEF_NOT_tb_cycle_5_EQ_0_6___d21 && (DEF_NOT_tb_cycle_5_EQ_128_7___d22 && (DEF_NOT_IF_tb_randomA_zaz_whas_THEN_tb_randomA_zaz_ETC___d27 && DEF__0_CONCAT_0_CONCAT_0_CONCAT_0_CONCAT_0_CONCAT_0_ETC___d83));
  if (DEF_tb_cycle_5_EQ_0___d16)
    INST_tb_randomA_initialized.METH_write((tUInt8)1u);
  if (!(PORT_RST_N == (tUInt8)0u))
    if (DEF_tb_cycle_5_EQ_128___d17)
      dollar_display(sim_hdl, this, "s", &__str_literal_1);
  if (DEF_tb_cycle_5_EQ_0___d16)
    INST_tb_randomB_initialized.METH_write((tUInt8)1u);
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    if (DEF_tb_cycle_5_EQ_128___d17)
      dollar_finish(sim_hdl, "32", 1u);
    if (DEF_NOT_tb_cycle_5_EQ_0_6_1_AND_NOT_tb_cycle_5_EQ__ETC___d86)
      dollar_display(sim_hdl, this, "s,32", &__str_literal_2, DEF_x__h970);
    if (DEF_NOT_tb_cycle_5_EQ_0_6_1_AND_NOT_tb_cycle_5_EQ__ETC___d86)
      dollar_display(sim_hdl,
		     this,
		     "s,-8,-8,-16",
		     &__str_literal_3,
		     DEF_signed_IF_tb_randomA_zaz_whas_THEN_tb_randomA_ETC___d87,
		     DEF_signed_IF_tb_randomB_zaz_whas__2_THEN_tb_rand_ETC___d88,
		     DEF_signed_0_CONCAT_0_CONCAT_0_CONCAT_0_CONCAT_0__ETC___d89);
    if (DEF_NOT_tb_cycle_5_EQ_0_6_1_AND_NOT_tb_cycle_5_EQ__ETC___d86)
      dollar_display(sim_hdl,
		     this,
		     "s,8,8,16",
		     &__str_literal_4,
		     DEF_v__h410,
		     DEF_v__h799,
		     DEF_test__h1177);
    if (DEF_NOT_tb_cycle_5_EQ_0_6_1_AND_NOT_tb_cycle_5_EQ__ETC___d93)
      dollar_display(sim_hdl, this, "s", &__str_literal_5);
    if (DEF_NOT_tb_cycle_5_EQ_0_6_1_AND_NOT_tb_cycle_5_EQ__ETC___d93)
      dollar_display(sim_hdl,
		     this,
		     "s,-8,-8,-16,-16",
		     &__str_literal_6,
		     DEF_signed_IF_tb_randomA_zaz_whas_THEN_tb_randomA_ETC___d87,
		     DEF_signed_IF_tb_randomB_zaz_whas__2_THEN_tb_rand_ETC___d88,
		     DEF_signed_0_CONCAT_0_CONCAT_0_CONCAT_0_CONCAT_0__ETC___d89,
		     DEF_signed_0_CONCAT_IF_tb_randomA_zaz_whas_THEN_t_ETC___d94);
    if (DEF_NOT_tb_cycle_5_EQ_0_6_1_AND_NOT_tb_cycle_5_EQ__ETC___d93)
      dollar_display(sim_hdl,
		     this,
		     "s,8,8,16,16",
		     &__str_literal_7,
		     DEF_v__h410,
		     DEF_v__h799,
		     DEF_test__h1177,
		     DEF_expected__h1178);
    if (DEF_NOT_tb_cycle_5_EQ_0_6_1_AND_NOT_tb_cycle_5_EQ__ETC___d93)
      dollar_finish(sim_hdl, "32", 1u);
  }
  INST_tb_cycle.METH_write(DEF_x__h2424);
}


/* Methods */


/* Reset routines */

void MOD_mkTbEx3::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_tb_randomB_initialized.reset_RST(ARG_rst_in);
  INST_tb_randomA_initialized.reset_RST(ARG_rst_in);
  INST_tb_cycle.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTbEx3::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTbEx3::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_tb_cycle.dump_state(indent + 2u);
  INST_tb_randomA_ignore.dump_state(indent + 2u);
  INST_tb_randomA_initialized.dump_state(indent + 2u);
  INST_tb_randomA_zaz.dump_state(indent + 2u);
  INST_tb_randomB_ignore.dump_state(indent + 2u);
  INST_tb_randomB_initialized.dump_state(indent + 2u);
  INST_tb_randomB_zaz.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTbEx3::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 27u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_tb_randomA_every", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_tb_randomA_every_1", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_tb_randomB_every", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_tb_randomB_every_1", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_tb_test", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_tb_randomA_every", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_tb_randomA_every_1", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_tb_randomB_every", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_tb_randomB_every_1", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_tb_test", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "tb_cycle_5_EQ_0___d16", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "tb_cycle_5_EQ_128___d17", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h329", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h410", 8u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h719", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h799", 8u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x__h970", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x_wget__h264", 8u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x_wget__h662", 8u);
  num = INST_tb_cycle.dump_VCD_defs(num);
  num = INST_tb_randomA_ignore.dump_VCD_defs(num);
  num = INST_tb_randomA_initialized.dump_VCD_defs(num);
  num = INST_tb_randomA_zaz.dump_VCD_defs(num);
  num = INST_tb_randomB_ignore.dump_VCD_defs(num);
  num = INST_tb_randomB_initialized.dump_VCD_defs(num);
  num = INST_tb_randomB_zaz.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTbEx3::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbEx3 &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTbEx3::vcd_defs(tVCDDumpType dt, MOD_mkTbEx3 &backing)
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
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 8u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 8u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 8u);
    vcd_write_x(sim_hdl, num++, 8u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.DEF_CAN_FIRE_RL_tb_randomA_every) != DEF_CAN_FIRE_RL_tb_randomA_every)
      {
	vcd_write_val(sim_hdl, num, DEF_CAN_FIRE_RL_tb_randomA_every, 1u);
	backing.DEF_CAN_FIRE_RL_tb_randomA_every = DEF_CAN_FIRE_RL_tb_randomA_every;
      }
      ++num;
      if ((backing.DEF_CAN_FIRE_RL_tb_randomA_every_1) != DEF_CAN_FIRE_RL_tb_randomA_every_1)
      {
	vcd_write_val(sim_hdl, num, DEF_CAN_FIRE_RL_tb_randomA_every_1, 1u);
	backing.DEF_CAN_FIRE_RL_tb_randomA_every_1 = DEF_CAN_FIRE_RL_tb_randomA_every_1;
      }
      ++num;
      if ((backing.DEF_CAN_FIRE_RL_tb_randomB_every) != DEF_CAN_FIRE_RL_tb_randomB_every)
      {
	vcd_write_val(sim_hdl, num, DEF_CAN_FIRE_RL_tb_randomB_every, 1u);
	backing.DEF_CAN_FIRE_RL_tb_randomB_every = DEF_CAN_FIRE_RL_tb_randomB_every;
      }
      ++num;
      if ((backing.DEF_CAN_FIRE_RL_tb_randomB_every_1) != DEF_CAN_FIRE_RL_tb_randomB_every_1)
      {
	vcd_write_val(sim_hdl, num, DEF_CAN_FIRE_RL_tb_randomB_every_1, 1u);
	backing.DEF_CAN_FIRE_RL_tb_randomB_every_1 = DEF_CAN_FIRE_RL_tb_randomB_every_1;
      }
      ++num;
      if ((backing.DEF_CAN_FIRE_RL_tb_test) != DEF_CAN_FIRE_RL_tb_test)
      {
	vcd_write_val(sim_hdl, num, DEF_CAN_FIRE_RL_tb_test, 1u);
	backing.DEF_CAN_FIRE_RL_tb_test = DEF_CAN_FIRE_RL_tb_test;
      }
      ++num;
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_tb_randomA_every) != DEF_WILL_FIRE_RL_tb_randomA_every)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_tb_randomA_every, 1u);
	backing.DEF_WILL_FIRE_RL_tb_randomA_every = DEF_WILL_FIRE_RL_tb_randomA_every;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_tb_randomA_every_1) != DEF_WILL_FIRE_RL_tb_randomA_every_1)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_tb_randomA_every_1, 1u);
	backing.DEF_WILL_FIRE_RL_tb_randomA_every_1 = DEF_WILL_FIRE_RL_tb_randomA_every_1;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_tb_randomB_every) != DEF_WILL_FIRE_RL_tb_randomB_every)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_tb_randomB_every, 1u);
	backing.DEF_WILL_FIRE_RL_tb_randomB_every = DEF_WILL_FIRE_RL_tb_randomB_every;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_tb_randomB_every_1) != DEF_WILL_FIRE_RL_tb_randomB_every_1)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_tb_randomB_every_1, 1u);
	backing.DEF_WILL_FIRE_RL_tb_randomB_every_1 = DEF_WILL_FIRE_RL_tb_randomB_every_1;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_tb_test) != DEF_WILL_FIRE_RL_tb_test)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_tb_test, 1u);
	backing.DEF_WILL_FIRE_RL_tb_test = DEF_WILL_FIRE_RL_tb_test;
      }
      ++num;
      if ((backing.DEF_tb_cycle_5_EQ_0___d16) != DEF_tb_cycle_5_EQ_0___d16)
      {
	vcd_write_val(sim_hdl, num, DEF_tb_cycle_5_EQ_0___d16, 1u);
	backing.DEF_tb_cycle_5_EQ_0___d16 = DEF_tb_cycle_5_EQ_0___d16;
      }
      ++num;
      if ((backing.DEF_tb_cycle_5_EQ_128___d17) != DEF_tb_cycle_5_EQ_128___d17)
      {
	vcd_write_val(sim_hdl, num, DEF_tb_cycle_5_EQ_128___d17, 1u);
	backing.DEF_tb_cycle_5_EQ_128___d17 = DEF_tb_cycle_5_EQ_128___d17;
      }
      ++num;
      if ((backing.DEF_v__h329) != DEF_v__h329)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h329, 32u);
	backing.DEF_v__h329 = DEF_v__h329;
      }
      ++num;
      if ((backing.DEF_v__h410) != DEF_v__h410)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h410, 8u);
	backing.DEF_v__h410 = DEF_v__h410;
      }
      ++num;
      if ((backing.DEF_v__h719) != DEF_v__h719)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h719, 32u);
	backing.DEF_v__h719 = DEF_v__h719;
      }
      ++num;
      if ((backing.DEF_v__h799) != DEF_v__h799)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h799, 8u);
	backing.DEF_v__h799 = DEF_v__h799;
      }
      ++num;
      if ((backing.DEF_x__h970) != DEF_x__h970)
      {
	vcd_write_val(sim_hdl, num, DEF_x__h970, 32u);
	backing.DEF_x__h970 = DEF_x__h970;
      }
      ++num;
      if ((backing.DEF_x_wget__h264) != DEF_x_wget__h264)
      {
	vcd_write_val(sim_hdl, num, DEF_x_wget__h264, 8u);
	backing.DEF_x_wget__h264 = DEF_x_wget__h264;
      }
      ++num;
      if ((backing.DEF_x_wget__h662) != DEF_x_wget__h662)
      {
	vcd_write_val(sim_hdl, num, DEF_x_wget__h662, 8u);
	backing.DEF_x_wget__h662 = DEF_x_wget__h662;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_tb_randomA_every, 1u);
      backing.DEF_CAN_FIRE_RL_tb_randomA_every = DEF_CAN_FIRE_RL_tb_randomA_every;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_tb_randomA_every_1, 1u);
      backing.DEF_CAN_FIRE_RL_tb_randomA_every_1 = DEF_CAN_FIRE_RL_tb_randomA_every_1;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_tb_randomB_every, 1u);
      backing.DEF_CAN_FIRE_RL_tb_randomB_every = DEF_CAN_FIRE_RL_tb_randomB_every;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_tb_randomB_every_1, 1u);
      backing.DEF_CAN_FIRE_RL_tb_randomB_every_1 = DEF_CAN_FIRE_RL_tb_randomB_every_1;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_tb_test, 1u);
      backing.DEF_CAN_FIRE_RL_tb_test = DEF_CAN_FIRE_RL_tb_test;
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_tb_randomA_every, 1u);
      backing.DEF_WILL_FIRE_RL_tb_randomA_every = DEF_WILL_FIRE_RL_tb_randomA_every;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_tb_randomA_every_1, 1u);
      backing.DEF_WILL_FIRE_RL_tb_randomA_every_1 = DEF_WILL_FIRE_RL_tb_randomA_every_1;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_tb_randomB_every, 1u);
      backing.DEF_WILL_FIRE_RL_tb_randomB_every = DEF_WILL_FIRE_RL_tb_randomB_every;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_tb_randomB_every_1, 1u);
      backing.DEF_WILL_FIRE_RL_tb_randomB_every_1 = DEF_WILL_FIRE_RL_tb_randomB_every_1;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_tb_test, 1u);
      backing.DEF_WILL_FIRE_RL_tb_test = DEF_WILL_FIRE_RL_tb_test;
      vcd_write_val(sim_hdl, num++, DEF_tb_cycle_5_EQ_0___d16, 1u);
      backing.DEF_tb_cycle_5_EQ_0___d16 = DEF_tb_cycle_5_EQ_0___d16;
      vcd_write_val(sim_hdl, num++, DEF_tb_cycle_5_EQ_128___d17, 1u);
      backing.DEF_tb_cycle_5_EQ_128___d17 = DEF_tb_cycle_5_EQ_128___d17;
      vcd_write_val(sim_hdl, num++, DEF_v__h329, 32u);
      backing.DEF_v__h329 = DEF_v__h329;
      vcd_write_val(sim_hdl, num++, DEF_v__h410, 8u);
      backing.DEF_v__h410 = DEF_v__h410;
      vcd_write_val(sim_hdl, num++, DEF_v__h719, 32u);
      backing.DEF_v__h719 = DEF_v__h719;
      vcd_write_val(sim_hdl, num++, DEF_v__h799, 8u);
      backing.DEF_v__h799 = DEF_v__h799;
      vcd_write_val(sim_hdl, num++, DEF_x__h970, 32u);
      backing.DEF_x__h970 = DEF_x__h970;
      vcd_write_val(sim_hdl, num++, DEF_x_wget__h264, 8u);
      backing.DEF_x_wget__h264 = DEF_x_wget__h264;
      vcd_write_val(sim_hdl, num++, DEF_x_wget__h662, 8u);
      backing.DEF_x_wget__h662 = DEF_x_wget__h662;
    }
}

void MOD_mkTbEx3::vcd_prims(tVCDDumpType dt, MOD_mkTbEx3 &backing)
{
  INST_tb_cycle.dump_VCD(dt, backing.INST_tb_cycle);
  INST_tb_randomA_ignore.dump_VCD(dt, backing.INST_tb_randomA_ignore);
  INST_tb_randomA_initialized.dump_VCD(dt, backing.INST_tb_randomA_initialized);
  INST_tb_randomA_zaz.dump_VCD(dt, backing.INST_tb_randomA_zaz);
  INST_tb_randomB_ignore.dump_VCD(dt, backing.INST_tb_randomB_ignore);
  INST_tb_randomB_initialized.dump_VCD(dt, backing.INST_tb_randomB_initialized);
  INST_tb_randomB_zaz.dump_VCD(dt, backing.INST_tb_randomB_zaz);
}
