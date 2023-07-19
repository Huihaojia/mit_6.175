/*
 * Generated by Bluespec Compiler (build 14ff62d)
 * 
 * On Sun Jul  2 02:04:47 CST 2023
 * 
 */
#include "bluesim_primitives.h"
#include "mkTbEx7a.h"
#include "imported_BDPI_functions.h"


/* String declarations */
static std::string const __str_literal_2("    if signed: %0d * %0d DUT gave %0d", 37u);
static std::string const __str_literal_5("    if signed: %0d * %0d DUT gave %0d instead of %0d",
					 52u);
static std::string const __str_literal_3("    if unsigned: %0d * %0d DUT gave %0d", 39u);
static std::string const __str_literal_6("    if unsigned: %0d * %0d DUT gave %0d instead of %0d",
					 54u);
static std::string const __str_literal_4("FAILED case %0d", 15u);
static std::string const __str_literal_8("FAILED due to cycle limit", 25u);
static std::string const __str_literal_7("PASSED %0d test cases in %0d cycles", 35u);
static std::string const __str_literal_1("PASSED case %0d", 15u);


/* Constructor */
MOD_mkTbEx7a::MOD_mkTbEx7a(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_mod_i(simHdl, "mod_i", this, 4u, (tUInt8)9u, (tUInt8)0u),
    INST_mod_m_neg(simHdl, "mod_m_neg", this, 17u),
    INST_mod_m_pos(simHdl, "mod_m_pos", this, 17u),
    INST_mod_p(simHdl, "mod_p", this, 17u),
    INST_tb_cycle(simHdl, "tb_cycle", this, 32u, 0u, (tUInt8)0u),
    INST_tb_feed_count(simHdl, "tb_feed_count", this, 32u, 0u, (tUInt8)0u),
    INST_tb_operands_fifo(simHdl, "tb_operands_fifo", this, 16u, 4u, 1u, 0u),
    INST_tb_randomA_ignore(simHdl, "tb_randomA_ignore", this, 8u, (tUInt8)0u),
    INST_tb_randomA_initialized(simHdl, "tb_randomA_initialized", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_tb_randomA_zaz(simHdl, "tb_randomA_zaz", this, 8u, (tUInt8)0u),
    INST_tb_randomB_ignore(simHdl, "tb_randomB_ignore", this, 8u, (tUInt8)0u),
    INST_tb_randomB_initialized(simHdl, "tb_randomB_initialized", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_tb_randomB_zaz(simHdl, "tb_randomB_zaz", this, 8u, (tUInt8)0u),
    INST_tb_read_count(simHdl, "tb_read_count", this, 32u, 0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u),
    DEF_v__h1147(2863311530u),
    DEF_v__h757(2863311530u)
{
  symbol_count = 45u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTbEx7a::init_symbols_0()
{
  init_symbol(&symbols[0u], "_read__h136", SYM_DEF, &DEF__read__h136, 4u);
  init_symbol(&symbols[1u], "CAN_FIRE_RL_mod_mul_step", SYM_DEF, &DEF_CAN_FIRE_RL_mod_mul_step, 1u);
  init_symbol(&symbols[2u], "CAN_FIRE_RL_tb_feed", SYM_DEF, &DEF_CAN_FIRE_RL_tb_feed, 1u);
  init_symbol(&symbols[3u],
	      "CAN_FIRE_RL_tb_monitor_test",
	      SYM_DEF,
	      &DEF_CAN_FIRE_RL_tb_monitor_test,
	      1u);
  init_symbol(&symbols[4u],
	      "CAN_FIRE_RL_tb_randomA_every",
	      SYM_DEF,
	      &DEF_CAN_FIRE_RL_tb_randomA_every,
	      1u);
  init_symbol(&symbols[5u],
	      "CAN_FIRE_RL_tb_randomA_every_1",
	      SYM_DEF,
	      &DEF_CAN_FIRE_RL_tb_randomA_every_1,
	      1u);
  init_symbol(&symbols[6u],
	      "CAN_FIRE_RL_tb_randomB_every",
	      SYM_DEF,
	      &DEF_CAN_FIRE_RL_tb_randomB_every,
	      1u);
  init_symbol(&symbols[7u],
	      "CAN_FIRE_RL_tb_randomB_every_1",
	      SYM_DEF,
	      &DEF_CAN_FIRE_RL_tb_randomB_every_1,
	      1u);
  init_symbol(&symbols[8u], "CAN_FIRE_RL_tb_read", SYM_DEF, &DEF_CAN_FIRE_RL_tb_read, 1u);
  init_symbol(&symbols[9u], "mod_i", SYM_MODULE, &INST_mod_i);
  init_symbol(&symbols[10u], "mod_m_neg", SYM_MODULE, &INST_mod_m_neg);
  init_symbol(&symbols[11u], "mod_m_pos", SYM_MODULE, &INST_mod_m_pos);
  init_symbol(&symbols[12u], "mod_p", SYM_MODULE, &INST_mod_p);
  init_symbol(&symbols[13u], "RL_mod_mul_step", SYM_RULE);
  init_symbol(&symbols[14u], "RL_tb_feed", SYM_RULE);
  init_symbol(&symbols[15u], "RL_tb_monitor_test", SYM_RULE);
  init_symbol(&symbols[16u], "RL_tb_randomA_every", SYM_RULE);
  init_symbol(&symbols[17u], "RL_tb_randomA_every_1", SYM_RULE);
  init_symbol(&symbols[18u], "RL_tb_randomB_every", SYM_RULE);
  init_symbol(&symbols[19u], "RL_tb_randomB_every_1", SYM_RULE);
  init_symbol(&symbols[20u], "RL_tb_read", SYM_RULE);
  init_symbol(&symbols[21u], "tb_cycle", SYM_MODULE, &INST_tb_cycle);
  init_symbol(&symbols[22u], "tb_feed_count", SYM_MODULE, &INST_tb_feed_count);
  init_symbol(&symbols[23u], "tb_operands_fifo", SYM_MODULE, &INST_tb_operands_fifo);
  init_symbol(&symbols[24u], "tb_randomA_ignore", SYM_MODULE, &INST_tb_randomA_ignore);
  init_symbol(&symbols[25u], "tb_randomA_initialized", SYM_MODULE, &INST_tb_randomA_initialized);
  init_symbol(&symbols[26u], "tb_randomA_zaz", SYM_MODULE, &INST_tb_randomA_zaz);
  init_symbol(&symbols[27u], "tb_randomB_ignore", SYM_MODULE, &INST_tb_randomB_ignore);
  init_symbol(&symbols[28u], "tb_randomB_initialized", SYM_MODULE, &INST_tb_randomB_initialized);
  init_symbol(&symbols[29u], "tb_randomB_zaz", SYM_MODULE, &INST_tb_randomB_zaz);
  init_symbol(&symbols[30u], "tb_read_count", SYM_MODULE, &INST_tb_read_count);
  init_symbol(&symbols[31u], "v__h1227", SYM_DEF, &DEF_v__h1227, 8u);
  init_symbol(&symbols[32u], "v__h838", SYM_DEF, &DEF_v__h838, 8u);
  init_symbol(&symbols[33u],
	      "WILL_FIRE_RL_mod_mul_step",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_mod_mul_step,
	      1u);
  init_symbol(&symbols[34u], "WILL_FIRE_RL_tb_feed", SYM_DEF, &DEF_WILL_FIRE_RL_tb_feed, 1u);
  init_symbol(&symbols[35u],
	      "WILL_FIRE_RL_tb_monitor_test",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_tb_monitor_test,
	      1u);
  init_symbol(&symbols[36u],
	      "WILL_FIRE_RL_tb_randomA_every",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_tb_randomA_every,
	      1u);
  init_symbol(&symbols[37u],
	      "WILL_FIRE_RL_tb_randomA_every_1",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_tb_randomA_every_1,
	      1u);
  init_symbol(&symbols[38u],
	      "WILL_FIRE_RL_tb_randomB_every",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_tb_randomB_every,
	      1u);
  init_symbol(&symbols[39u],
	      "WILL_FIRE_RL_tb_randomB_every_1",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_tb_randomB_every_1,
	      1u);
  init_symbol(&symbols[40u], "WILL_FIRE_RL_tb_read", SYM_DEF, &DEF_WILL_FIRE_RL_tb_read, 1u);
  init_symbol(&symbols[41u], "x__h1575", SYM_DEF, &DEF_x__h1575, 32u);
  init_symbol(&symbols[42u], "x__h2085", SYM_DEF, &DEF_x__h2085, 32u);
  init_symbol(&symbols[43u], "x_wget__h1090", SYM_DEF, &DEF_x_wget__h1090, 8u);
  init_symbol(&symbols[44u], "x_wget__h700", SYM_DEF, &DEF_x_wget__h700, 8u);
}


/* Rule actions */

void MOD_mkTbEx7a::RL_mod_mul_step()
{
  tUInt32 DEF_x__h170;
  tUInt32 DEF_temp_p__h156;
  tUInt8 DEF_part_r__h154;
  tUInt32 DEF_y__h263;
  tUInt32 DEF_y__h271;
  DEF_x__h1655 = INST_mod_p.METH_read();
  DEF_y__h271 = INST_mod_m_neg.METH_read();
  DEF_y__h263 = INST_mod_m_pos.METH_read();
  DEF__read__h136 = INST_mod_i.METH_read();
  DEF_part_r__h154 = (tUInt8)((tUInt8)3u & DEF_x__h1655);
  switch (DEF_part_r__h154) {
  case (tUInt8)1u:
    DEF_temp_p__h156 = 131071u & (DEF_x__h1655 + DEF_y__h263);
    break;
  case (tUInt8)2u:
    DEF_temp_p__h156 = 131071u & (DEF_x__h1655 + DEF_y__h271);
    break;
  default:
    DEF_temp_p__h156 = DEF_x__h1655;
  }
  DEF_x__h170 = primShiftRA32(17u, 17u, (tUInt32)(DEF_temp_p__h156), 32u, 1u);
  DEF_x__h279 = (tUInt8)15u & (DEF__read__h136 + (tUInt8)1u);
  INST_mod_p.METH_write(DEF_x__h170);
  INST_mod_i.METH_write(DEF_x__h279);
}

void MOD_mkTbEx7a::RL_tb_randomA_every()
{
  tUInt8 DEF_new_value__h799;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h757 = rand32();
  DEF_new_value__h799 = (tUInt8)((tUInt8)255u & DEF_v__h757);
  INST_tb_randomA_zaz.METH_wset(DEF_new_value__h799);
}

void MOD_mkTbEx7a::RL_tb_randomA_every_1()
{
  DEF_x_wget__h700 = INST_tb_randomA_zaz.METH_wget();
  DEF_tb_randomA_zaz_whas____d19 = INST_tb_randomA_zaz.METH_whas();
  DEF_v__h838 = DEF_tb_randomA_zaz_whas____d19 ? DEF_x_wget__h700 : (tUInt8)0u;
  INST_tb_randomA_ignore.METH_wset(DEF_v__h838);
}

void MOD_mkTbEx7a::RL_tb_randomB_every()
{
  tUInt8 DEF_new_value__h1189;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h1147 = rand32();
  DEF_new_value__h1189 = (tUInt8)((tUInt8)255u & DEF_v__h1147);
  INST_tb_randomB_zaz.METH_wset(DEF_new_value__h1189);
}

void MOD_mkTbEx7a::RL_tb_randomB_every_1()
{
  DEF_x_wget__h1090 = INST_tb_randomB_zaz.METH_wget();
  DEF_v__h1227 = INST_tb_randomB_zaz.METH_whas() ? DEF_x_wget__h1090 : (tUInt8)0u;
  INST_tb_randomB_ignore.METH_wset(DEF_v__h1227);
}

void MOD_mkTbEx7a::RL_tb_feed()
{
  tUInt32 DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d45;
  tUInt32 DEF_x__h1478;
  tUInt32 DEF_x__h1503;
  tUInt32 DEF_x__h1527;
  tUInt32 DEF_x__h1556;
  tUInt8 DEF_NOT_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA__ETC___d44;
  DEF_x__h1575 = INST_tb_feed_count.METH_read();
  DEF_x_wget__h1090 = INST_tb_randomB_zaz.METH_wget();
  DEF_x_wget__h700 = INST_tb_randomA_zaz.METH_wget();
  DEF_tb_randomA_zaz_whas____d19 = INST_tb_randomA_zaz.METH_whas();
  DEF_v__h838 = DEF_tb_randomA_zaz_whas____d19 ? DEF_x_wget__h700 : (tUInt8)0u;
  DEF_v__h1227 = INST_tb_randomB_zaz.METH_whas() ? DEF_x_wget__h1090 : (tUInt8)0u;
  DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d29 = DEF_v__h838 == (tUInt8)128u;
  DEF_IF_tb_randomB_zaz_whas__6_THEN_tb_randomB_zaz__ETC___d30 = DEF_v__h1227 == (tUInt8)128u;
  DEF_NOT_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA__ETC___d44 = !DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d29 && !DEF_IF_tb_randomB_zaz_whas__6_THEN_tb_randomB_zaz__ETC___d30;
  DEF_x__h1556 = DEF_x__h1575 + 1u;
  DEF_x__h1527 = 131071u & (((((tUInt32)((tUInt8)0u)) << 9u) | (((tUInt32)(DEF_v__h1227)) << 1u)) | (tUInt32)((tUInt8)0u));
  DEF_x__h1478 = 131071u & (((tUInt32)(DEF_v__h838)) << 9u);
  DEF_x__h1503 = 131071u & (((tUInt32)(DEF_tb_randomA_zaz_whas____d19 ? (tUInt8)255u & -DEF_x_wget__h700 : (tUInt8)0u)) << 9u);
  DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d45 = 65535u & ((((tUInt32)(DEF_v__h838)) << 8u) | (tUInt32)(DEF_v__h1227));
  if (DEF_NOT_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA__ETC___d44)
    INST_tb_operands_fifo.METH_enq(DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d45);
  if (DEF_NOT_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA__ETC___d44)
    INST_mod_m_pos.METH_write(DEF_x__h1478);
  if (DEF_NOT_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA__ETC___d44)
    INST_mod_m_neg.METH_write(DEF_x__h1503);
  if (DEF_NOT_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA__ETC___d44)
    INST_mod_p.METH_write(DEF_x__h1527);
  if (DEF_NOT_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA__ETC___d44)
    INST_mod_i.METH_write((tUInt8)0u);
  if (DEF_NOT_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA__ETC___d44)
    INST_tb_feed_count.METH_write(DEF_x__h1556);
}

void MOD_mkTbEx7a::RL_tb_read()
{
  tUInt32 DEF_x__h1958;
  tUInt8 DEF_NOT_mod_p_BITS_16_TO_1_9_EQ_SEXT_tb_operands_f_ETC___d71;
  tUInt32 DEF_tb_operands_fifo_first____d60;
  tUInt8 DEF_b__h1596;
  tUInt8 DEF_signed_tb_operands_fifo_first__0_BITS_7_TO_0_3___d69;
  tUInt8 DEF_a__h1595;
  tUInt8 DEF_signed_tb_operands_fifo_first__0_BITS_15_TO_8_1___d68;
  tUInt32 DEF_v__h1626;
  tUInt32 DEF_signed_mod_p_BITS_16_TO_1_9___d70;
  tUInt32 DEF_expected__h1661;
  tUInt32 DEF_signed_SEXT_tb_operands_fifo_first__0_BITS_15_ETC___d72;
  tUInt8 DEF_mod_p_BITS_16_TO_1_9_EQ_SEXT_tb_operands_fifo__ETC___d67;
  DEF_x__h2085 = INST_tb_read_count.METH_read();
  DEF_x__h1655 = INST_mod_p.METH_read();
  DEF_v__h1626 = (tUInt32)(DEF_x__h1655 >> 1u);
  DEF_signed_mod_p_BITS_16_TO_1_9___d70 = DEF_v__h1626;
  DEF_tb_operands_fifo_first____d60 = INST_tb_operands_fifo.METH_first();
  DEF_a__h1595 = (tUInt8)(DEF_tb_operands_fifo_first____d60 >> 8u);
  DEF_signed_tb_operands_fifo_first__0_BITS_15_TO_8_1___d68 = DEF_a__h1595;
  DEF_b__h1596 = (tUInt8)((tUInt8)255u & DEF_tb_operands_fifo_first____d60);
  DEF_expected__h1661 = (tUInt32)(65535u & (primSignExt32(16u,
							  8u,
							  (tUInt8)(DEF_a__h1595)) * primSignExt32(16u,
												  8u,
												  (tUInt8)(DEF_b__h1596))));
  DEF_mod_p_BITS_16_TO_1_9_EQ_SEXT_tb_operands_fifo__ETC___d67 = DEF_v__h1626 == DEF_expected__h1661;
  DEF_signed_SEXT_tb_operands_fifo_first__0_BITS_15_ETC___d72 = DEF_expected__h1661;
  DEF_signed_tb_operands_fifo_first__0_BITS_7_TO_0_3___d69 = DEF_b__h1596;
  DEF__read__h136 = INST_mod_i.METH_read();
  DEF_NOT_mod_p_BITS_16_TO_1_9_EQ_SEXT_tb_operands_f_ETC___d71 = !DEF_mod_p_BITS_16_TO_1_9_EQ_SEXT_tb_operands_fifo__ETC___d67;
  DEF_x__h1958 = DEF_x__h2085 + 1u;
  DEF_x__h279 = (tUInt8)15u & (DEF__read__h136 + (tUInt8)1u);
  INST_tb_operands_fifo.METH_deq();
  INST_mod_i.METH_write(DEF_x__h279);
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    if (DEF_mod_p_BITS_16_TO_1_9_EQ_SEXT_tb_operands_fifo__ETC___d67)
      dollar_display(sim_hdl, this, "s,32", &__str_literal_1, DEF_x__h2085);
    if (DEF_mod_p_BITS_16_TO_1_9_EQ_SEXT_tb_operands_fifo__ETC___d67)
      dollar_display(sim_hdl,
		     this,
		     "s,-8,-8,-16",
		     &__str_literal_2,
		     DEF_signed_tb_operands_fifo_first__0_BITS_15_TO_8_1___d68,
		     DEF_signed_tb_operands_fifo_first__0_BITS_7_TO_0_3___d69,
		     DEF_signed_mod_p_BITS_16_TO_1_9___d70);
    if (DEF_mod_p_BITS_16_TO_1_9_EQ_SEXT_tb_operands_fifo__ETC___d67)
      dollar_display(sim_hdl,
		     this,
		     "s,8,8,16",
		     &__str_literal_3,
		     DEF_a__h1595,
		     DEF_b__h1596,
		     DEF_v__h1626);
    if (DEF_NOT_mod_p_BITS_16_TO_1_9_EQ_SEXT_tb_operands_f_ETC___d71)
      dollar_display(sim_hdl, this, "s,32", &__str_literal_4, DEF_x__h2085);
    if (DEF_NOT_mod_p_BITS_16_TO_1_9_EQ_SEXT_tb_operands_f_ETC___d71)
      dollar_display(sim_hdl,
		     this,
		     "s,-8,-8,-16,-16",
		     &__str_literal_5,
		     DEF_signed_tb_operands_fifo_first__0_BITS_15_TO_8_1___d68,
		     DEF_signed_tb_operands_fifo_first__0_BITS_7_TO_0_3___d69,
		     DEF_signed_mod_p_BITS_16_TO_1_9___d70,
		     DEF_signed_SEXT_tb_operands_fifo_first__0_BITS_15_ETC___d72);
    if (DEF_NOT_mod_p_BITS_16_TO_1_9_EQ_SEXT_tb_operands_f_ETC___d71)
      dollar_display(sim_hdl,
		     this,
		     "s,8,8,16,16",
		     &__str_literal_6,
		     DEF_a__h1595,
		     DEF_b__h1596,
		     DEF_v__h1626,
		     DEF_expected__h1661);
    if (DEF_NOT_mod_p_BITS_16_TO_1_9_EQ_SEXT_tb_operands_f_ETC___d71)
      dollar_finish(sim_hdl, "32", 1u);
  }
  INST_tb_read_count.METH_write(DEF_x__h1958);
}

void MOD_mkTbEx7a::RL_tb_monitor_test()
{
  tUInt32 DEF_x__h2332;
  tUInt8 DEF_tb_cycle_4_EQ_0___d75;
  tUInt8 DEF_tb_cycle_4_EQ_16384___d76;
  tUInt32 DEF_x__h2336;
  DEF_x__h2085 = INST_tb_read_count.METH_read();
  DEF_x__h2336 = INST_tb_cycle.METH_read();
  DEF_tb_cycle_4_EQ_16384___d76 = DEF_x__h2336 == 16384u;
  DEF_tb_cycle_4_EQ_0___d75 = DEF_x__h2336 == 0u;
  DEF_tb_read_count_5_EQ_128___d56 = DEF_x__h2085 == 128u;
  DEF_x__h2332 = DEF_x__h2336 + 1u;
  if (DEF_tb_cycle_4_EQ_0___d75)
    INST_tb_randomA_initialized.METH_write((tUInt8)1u);
  if (DEF_tb_cycle_4_EQ_0___d75)
    INST_tb_randomB_initialized.METH_write((tUInt8)1u);
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    if (DEF_tb_read_count_5_EQ_128___d56)
      dollar_display(sim_hdl, this, "s,32,32", &__str_literal_7, DEF_x__h2085, DEF_x__h2336);
    if (DEF_tb_read_count_5_EQ_128___d56)
      dollar_finish(sim_hdl, "32", 1u);
    if (DEF_tb_cycle_4_EQ_16384___d76)
      dollar_display(sim_hdl, this, "s", &__str_literal_8);
    if (DEF_tb_cycle_4_EQ_16384___d76)
      dollar_finish(sim_hdl, "32", 1u);
  }
  INST_tb_cycle.METH_write(DEF_x__h2332);
}


/* Methods */


/* Reset routines */

void MOD_mkTbEx7a::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_tb_read_count.reset_RST(ARG_rst_in);
  INST_tb_randomB_initialized.reset_RST(ARG_rst_in);
  INST_tb_randomA_initialized.reset_RST(ARG_rst_in);
  INST_tb_operands_fifo.reset_RST(ARG_rst_in);
  INST_tb_feed_count.reset_RST(ARG_rst_in);
  INST_tb_cycle.reset_RST(ARG_rst_in);
  INST_mod_i.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTbEx7a::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTbEx7a::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_mod_i.dump_state(indent + 2u);
  INST_mod_m_neg.dump_state(indent + 2u);
  INST_mod_m_pos.dump_state(indent + 2u);
  INST_mod_p.dump_state(indent + 2u);
  INST_tb_cycle.dump_state(indent + 2u);
  INST_tb_feed_count.dump_state(indent + 2u);
  INST_tb_operands_fifo.dump_state(indent + 2u);
  INST_tb_randomA_ignore.dump_state(indent + 2u);
  INST_tb_randomA_initialized.dump_state(indent + 2u);
  INST_tb_randomA_zaz.dump_state(indent + 2u);
  INST_tb_randomB_ignore.dump_state(indent + 2u);
  INST_tb_randomB_initialized.dump_state(indent + 2u);
  INST_tb_randomB_zaz.dump_state(indent + 2u);
  INST_tb_read_count.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTbEx7a::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 46u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_mod_mul_step", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_tb_feed", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_tb_monitor_test", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_tb_randomA_every", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_tb_randomA_every_1", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_tb_randomB_every", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_tb_randomB_every_1", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "CAN_FIRE_RL_tb_read", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d29", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "IF_tb_randomB_zaz_whas__6_THEN_tb_randomB_zaz__ETC___d30", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_mod_mul_step", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_tb_feed", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_tb_monitor_test", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_tb_randomA_every", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_tb_randomA_every_1", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_tb_randomB_every", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_tb_randomB_every_1", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_tb_read", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "_read__h136", 4u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "tb_randomA_zaz_whas____d19", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "tb_read_count_5_EQ_128___d56", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h1147", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h1227", 8u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h757", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h838", 8u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x__h1575", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x__h1655", 17u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x__h2085", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x__h279", 4u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x_wget__h1090", 8u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x_wget__h700", 8u);
  num = INST_mod_i.dump_VCD_defs(num);
  num = INST_mod_m_neg.dump_VCD_defs(num);
  num = INST_mod_m_pos.dump_VCD_defs(num);
  num = INST_mod_p.dump_VCD_defs(num);
  num = INST_tb_cycle.dump_VCD_defs(num);
  num = INST_tb_feed_count.dump_VCD_defs(num);
  num = INST_tb_operands_fifo.dump_VCD_defs(num);
  num = INST_tb_randomA_ignore.dump_VCD_defs(num);
  num = INST_tb_randomA_initialized.dump_VCD_defs(num);
  num = INST_tb_randomA_zaz.dump_VCD_defs(num);
  num = INST_tb_randomB_ignore.dump_VCD_defs(num);
  num = INST_tb_randomB_initialized.dump_VCD_defs(num);
  num = INST_tb_randomB_zaz.dump_VCD_defs(num);
  num = INST_tb_read_count.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTbEx7a::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbEx7a &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTbEx7a::vcd_defs(tVCDDumpType dt, MOD_mkTbEx7a &backing)
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
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 4u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 8u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 8u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 17u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 4u);
    vcd_write_x(sim_hdl, num++, 8u);
    vcd_write_x(sim_hdl, num++, 8u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.DEF_CAN_FIRE_RL_mod_mul_step) != DEF_CAN_FIRE_RL_mod_mul_step)
      {
	vcd_write_val(sim_hdl, num, DEF_CAN_FIRE_RL_mod_mul_step, 1u);
	backing.DEF_CAN_FIRE_RL_mod_mul_step = DEF_CAN_FIRE_RL_mod_mul_step;
      }
      ++num;
      if ((backing.DEF_CAN_FIRE_RL_tb_feed) != DEF_CAN_FIRE_RL_tb_feed)
      {
	vcd_write_val(sim_hdl, num, DEF_CAN_FIRE_RL_tb_feed, 1u);
	backing.DEF_CAN_FIRE_RL_tb_feed = DEF_CAN_FIRE_RL_tb_feed;
      }
      ++num;
      if ((backing.DEF_CAN_FIRE_RL_tb_monitor_test) != DEF_CAN_FIRE_RL_tb_monitor_test)
      {
	vcd_write_val(sim_hdl, num, DEF_CAN_FIRE_RL_tb_monitor_test, 1u);
	backing.DEF_CAN_FIRE_RL_tb_monitor_test = DEF_CAN_FIRE_RL_tb_monitor_test;
      }
      ++num;
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
      if ((backing.DEF_CAN_FIRE_RL_tb_read) != DEF_CAN_FIRE_RL_tb_read)
      {
	vcd_write_val(sim_hdl, num, DEF_CAN_FIRE_RL_tb_read, 1u);
	backing.DEF_CAN_FIRE_RL_tb_read = DEF_CAN_FIRE_RL_tb_read;
      }
      ++num;
      if ((backing.DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d29) != DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d29)
      {
	vcd_write_val(sim_hdl, num, DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d29, 1u);
	backing.DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d29 = DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d29;
      }
      ++num;
      if ((backing.DEF_IF_tb_randomB_zaz_whas__6_THEN_tb_randomB_zaz__ETC___d30) != DEF_IF_tb_randomB_zaz_whas__6_THEN_tb_randomB_zaz__ETC___d30)
      {
	vcd_write_val(sim_hdl, num, DEF_IF_tb_randomB_zaz_whas__6_THEN_tb_randomB_zaz__ETC___d30, 1u);
	backing.DEF_IF_tb_randomB_zaz_whas__6_THEN_tb_randomB_zaz__ETC___d30 = DEF_IF_tb_randomB_zaz_whas__6_THEN_tb_randomB_zaz__ETC___d30;
      }
      ++num;
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_mod_mul_step) != DEF_WILL_FIRE_RL_mod_mul_step)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_mod_mul_step, 1u);
	backing.DEF_WILL_FIRE_RL_mod_mul_step = DEF_WILL_FIRE_RL_mod_mul_step;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_tb_feed) != DEF_WILL_FIRE_RL_tb_feed)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_tb_feed, 1u);
	backing.DEF_WILL_FIRE_RL_tb_feed = DEF_WILL_FIRE_RL_tb_feed;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_tb_monitor_test) != DEF_WILL_FIRE_RL_tb_monitor_test)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_tb_monitor_test, 1u);
	backing.DEF_WILL_FIRE_RL_tb_monitor_test = DEF_WILL_FIRE_RL_tb_monitor_test;
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
      if ((backing.DEF_WILL_FIRE_RL_tb_read) != DEF_WILL_FIRE_RL_tb_read)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_tb_read, 1u);
	backing.DEF_WILL_FIRE_RL_tb_read = DEF_WILL_FIRE_RL_tb_read;
      }
      ++num;
      if ((backing.DEF__read__h136) != DEF__read__h136)
      {
	vcd_write_val(sim_hdl, num, DEF__read__h136, 4u);
	backing.DEF__read__h136 = DEF__read__h136;
      }
      ++num;
      if ((backing.DEF_tb_randomA_zaz_whas____d19) != DEF_tb_randomA_zaz_whas____d19)
      {
	vcd_write_val(sim_hdl, num, DEF_tb_randomA_zaz_whas____d19, 1u);
	backing.DEF_tb_randomA_zaz_whas____d19 = DEF_tb_randomA_zaz_whas____d19;
      }
      ++num;
      if ((backing.DEF_tb_read_count_5_EQ_128___d56) != DEF_tb_read_count_5_EQ_128___d56)
      {
	vcd_write_val(sim_hdl, num, DEF_tb_read_count_5_EQ_128___d56, 1u);
	backing.DEF_tb_read_count_5_EQ_128___d56 = DEF_tb_read_count_5_EQ_128___d56;
      }
      ++num;
      if ((backing.DEF_v__h1147) != DEF_v__h1147)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h1147, 32u);
	backing.DEF_v__h1147 = DEF_v__h1147;
      }
      ++num;
      if ((backing.DEF_v__h1227) != DEF_v__h1227)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h1227, 8u);
	backing.DEF_v__h1227 = DEF_v__h1227;
      }
      ++num;
      if ((backing.DEF_v__h757) != DEF_v__h757)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h757, 32u);
	backing.DEF_v__h757 = DEF_v__h757;
      }
      ++num;
      if ((backing.DEF_v__h838) != DEF_v__h838)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h838, 8u);
	backing.DEF_v__h838 = DEF_v__h838;
      }
      ++num;
      if ((backing.DEF_x__h1575) != DEF_x__h1575)
      {
	vcd_write_val(sim_hdl, num, DEF_x__h1575, 32u);
	backing.DEF_x__h1575 = DEF_x__h1575;
      }
      ++num;
      if ((backing.DEF_x__h1655) != DEF_x__h1655)
      {
	vcd_write_val(sim_hdl, num, DEF_x__h1655, 17u);
	backing.DEF_x__h1655 = DEF_x__h1655;
      }
      ++num;
      if ((backing.DEF_x__h2085) != DEF_x__h2085)
      {
	vcd_write_val(sim_hdl, num, DEF_x__h2085, 32u);
	backing.DEF_x__h2085 = DEF_x__h2085;
      }
      ++num;
      if ((backing.DEF_x__h279) != DEF_x__h279)
      {
	vcd_write_val(sim_hdl, num, DEF_x__h279, 4u);
	backing.DEF_x__h279 = DEF_x__h279;
      }
      ++num;
      if ((backing.DEF_x_wget__h1090) != DEF_x_wget__h1090)
      {
	vcd_write_val(sim_hdl, num, DEF_x_wget__h1090, 8u);
	backing.DEF_x_wget__h1090 = DEF_x_wget__h1090;
      }
      ++num;
      if ((backing.DEF_x_wget__h700) != DEF_x_wget__h700)
      {
	vcd_write_val(sim_hdl, num, DEF_x_wget__h700, 8u);
	backing.DEF_x_wget__h700 = DEF_x_wget__h700;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_mod_mul_step, 1u);
      backing.DEF_CAN_FIRE_RL_mod_mul_step = DEF_CAN_FIRE_RL_mod_mul_step;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_tb_feed, 1u);
      backing.DEF_CAN_FIRE_RL_tb_feed = DEF_CAN_FIRE_RL_tb_feed;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_tb_monitor_test, 1u);
      backing.DEF_CAN_FIRE_RL_tb_monitor_test = DEF_CAN_FIRE_RL_tb_monitor_test;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_tb_randomA_every, 1u);
      backing.DEF_CAN_FIRE_RL_tb_randomA_every = DEF_CAN_FIRE_RL_tb_randomA_every;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_tb_randomA_every_1, 1u);
      backing.DEF_CAN_FIRE_RL_tb_randomA_every_1 = DEF_CAN_FIRE_RL_tb_randomA_every_1;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_tb_randomB_every, 1u);
      backing.DEF_CAN_FIRE_RL_tb_randomB_every = DEF_CAN_FIRE_RL_tb_randomB_every;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_tb_randomB_every_1, 1u);
      backing.DEF_CAN_FIRE_RL_tb_randomB_every_1 = DEF_CAN_FIRE_RL_tb_randomB_every_1;
      vcd_write_val(sim_hdl, num++, DEF_CAN_FIRE_RL_tb_read, 1u);
      backing.DEF_CAN_FIRE_RL_tb_read = DEF_CAN_FIRE_RL_tb_read;
      vcd_write_val(sim_hdl, num++, DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d29, 1u);
      backing.DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d29 = DEF_IF_tb_randomA_zaz_whas__9_THEN_tb_randomA_zaz__ETC___d29;
      vcd_write_val(sim_hdl, num++, DEF_IF_tb_randomB_zaz_whas__6_THEN_tb_randomB_zaz__ETC___d30, 1u);
      backing.DEF_IF_tb_randomB_zaz_whas__6_THEN_tb_randomB_zaz__ETC___d30 = DEF_IF_tb_randomB_zaz_whas__6_THEN_tb_randomB_zaz__ETC___d30;
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_mod_mul_step, 1u);
      backing.DEF_WILL_FIRE_RL_mod_mul_step = DEF_WILL_FIRE_RL_mod_mul_step;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_tb_feed, 1u);
      backing.DEF_WILL_FIRE_RL_tb_feed = DEF_WILL_FIRE_RL_tb_feed;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_tb_monitor_test, 1u);
      backing.DEF_WILL_FIRE_RL_tb_monitor_test = DEF_WILL_FIRE_RL_tb_monitor_test;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_tb_randomA_every, 1u);
      backing.DEF_WILL_FIRE_RL_tb_randomA_every = DEF_WILL_FIRE_RL_tb_randomA_every;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_tb_randomA_every_1, 1u);
      backing.DEF_WILL_FIRE_RL_tb_randomA_every_1 = DEF_WILL_FIRE_RL_tb_randomA_every_1;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_tb_randomB_every, 1u);
      backing.DEF_WILL_FIRE_RL_tb_randomB_every = DEF_WILL_FIRE_RL_tb_randomB_every;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_tb_randomB_every_1, 1u);
      backing.DEF_WILL_FIRE_RL_tb_randomB_every_1 = DEF_WILL_FIRE_RL_tb_randomB_every_1;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_tb_read, 1u);
      backing.DEF_WILL_FIRE_RL_tb_read = DEF_WILL_FIRE_RL_tb_read;
      vcd_write_val(sim_hdl, num++, DEF__read__h136, 4u);
      backing.DEF__read__h136 = DEF__read__h136;
      vcd_write_val(sim_hdl, num++, DEF_tb_randomA_zaz_whas____d19, 1u);
      backing.DEF_tb_randomA_zaz_whas____d19 = DEF_tb_randomA_zaz_whas____d19;
      vcd_write_val(sim_hdl, num++, DEF_tb_read_count_5_EQ_128___d56, 1u);
      backing.DEF_tb_read_count_5_EQ_128___d56 = DEF_tb_read_count_5_EQ_128___d56;
      vcd_write_val(sim_hdl, num++, DEF_v__h1147, 32u);
      backing.DEF_v__h1147 = DEF_v__h1147;
      vcd_write_val(sim_hdl, num++, DEF_v__h1227, 8u);
      backing.DEF_v__h1227 = DEF_v__h1227;
      vcd_write_val(sim_hdl, num++, DEF_v__h757, 32u);
      backing.DEF_v__h757 = DEF_v__h757;
      vcd_write_val(sim_hdl, num++, DEF_v__h838, 8u);
      backing.DEF_v__h838 = DEF_v__h838;
      vcd_write_val(sim_hdl, num++, DEF_x__h1575, 32u);
      backing.DEF_x__h1575 = DEF_x__h1575;
      vcd_write_val(sim_hdl, num++, DEF_x__h1655, 17u);
      backing.DEF_x__h1655 = DEF_x__h1655;
      vcd_write_val(sim_hdl, num++, DEF_x__h2085, 32u);
      backing.DEF_x__h2085 = DEF_x__h2085;
      vcd_write_val(sim_hdl, num++, DEF_x__h279, 4u);
      backing.DEF_x__h279 = DEF_x__h279;
      vcd_write_val(sim_hdl, num++, DEF_x_wget__h1090, 8u);
      backing.DEF_x_wget__h1090 = DEF_x_wget__h1090;
      vcd_write_val(sim_hdl, num++, DEF_x_wget__h700, 8u);
      backing.DEF_x_wget__h700 = DEF_x_wget__h700;
    }
}

void MOD_mkTbEx7a::vcd_prims(tVCDDumpType dt, MOD_mkTbEx7a &backing)
{
  INST_mod_i.dump_VCD(dt, backing.INST_mod_i);
  INST_mod_m_neg.dump_VCD(dt, backing.INST_mod_m_neg);
  INST_mod_m_pos.dump_VCD(dt, backing.INST_mod_m_pos);
  INST_mod_p.dump_VCD(dt, backing.INST_mod_p);
  INST_tb_cycle.dump_VCD(dt, backing.INST_tb_cycle);
  INST_tb_feed_count.dump_VCD(dt, backing.INST_tb_feed_count);
  INST_tb_operands_fifo.dump_VCD(dt, backing.INST_tb_operands_fifo);
  INST_tb_randomA_ignore.dump_VCD(dt, backing.INST_tb_randomA_ignore);
  INST_tb_randomA_initialized.dump_VCD(dt, backing.INST_tb_randomA_initialized);
  INST_tb_randomA_zaz.dump_VCD(dt, backing.INST_tb_randomA_zaz);
  INST_tb_randomB_ignore.dump_VCD(dt, backing.INST_tb_randomB_ignore);
  INST_tb_randomB_initialized.dump_VCD(dt, backing.INST_tb_randomB_initialized);
  INST_tb_randomB_zaz.dump_VCD(dt, backing.INST_tb_randomB_zaz);
  INST_tb_read_count.dump_VCD(dt, backing.INST_tb_read_count);
}
