/*
 * Generated by Bluespec Compiler (build 14ff62d)
 * 
 * On Wed Jun 21 19:33:47 CST 2023
 * 
 */

/* Generation options: */
#ifndef __model_mkTbMuxSimple_h__
#define __model_mkTbMuxSimple_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"

#include "bs_model.h"
#include "mkTbMuxSimple.h"

/* Class declaration for a model of mkTbMuxSimple */
class MODEL_mkTbMuxSimple : public Model {
 
 /* Top-level module instance */
 private:
  MOD_mkTbMuxSimple *mkTbMuxSimple_instance;
 
 /* Handle to the simulation kernel */
 private:
  tSimStateHdl sim_hdl;
 
 /* Constructor */
 public:
  MODEL_mkTbMuxSimple();
 
 /* Functions required by the kernel */
 public:
  void create_model(tSimStateHdl simHdl, bool master);
  void destroy_model();
  void reset_model(bool asserted);
  void get_version(unsigned int *year,
		   unsigned int *month,
		   char const **annotation,
		   char const **build);
  time_t get_creation_time();
  void * get_instance();
  void dump_state();
  void dump_VCD_defs();
  void dump_VCD(tVCDDumpType dt);
};

/* Function for creating a new model */
extern "C" {
  void * new_MODEL_mkTbMuxSimple();
}

#endif /* ifndef __model_mkTbMuxSimple_h__ */
