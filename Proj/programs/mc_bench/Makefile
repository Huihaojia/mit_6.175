#=======================================================================
# UCB VLSI FLOW: Makefile for riscv-bmarks
#-----------------------------------------------------------------------
# Yunsup Lee (yunsup@cs.berkeley.edu)
#
SHELL := /bin/bash

default: all

bmarkdir := $(CURDIR)
bmarks_build_dir := $(bmarkdir)/../build/mc_bench
bmarks_build_bin_dir := $(bmarks_build_dir)/bin
bmarks_build_obj_dir := $(bmarks_build_dir)/obj
bmarks_build_dump_dir := $(bmarks_build_dir)/dump
bmarks_build_vmh_dir := $(bmarks_build_dir)/vmh

#--------------------------------------------------------------------
# Sources
#--------------------------------------------------------------------

bmarks = \
	mc_print \
	mc_hello \
	mc_produce_consume \
	mc_median \
	mc_vvadd \
	mc_multiply \
	mc_multiply2 \
	mc_incrementers \
	mc_dekker \
	mc_spin_lock \

bmarks_host = \
	mc_print \
	mc_hello \
	mc_produce_consume \
	mc_median \
	mc_vvadd \
	mc_multiply \
	mc_multiply2 \
	mc_incrementers \
	mc_dekker \
	mc_spin_lock \

#--------------------------------------------------------------------
# Build rules
#--------------------------------------------------------------------

HOST_OPTS = -std=gnu99 -DPREALLOCATE=0 -DHOST_DEBUG=1 -I$(bmarkdir)/common
HOST_COMP = gcc $(HOST_OPTS)

RISCV_TOOL_DIR = /opt/riscv/bin
ELF_2_HEX_DIR = /opt/riscv/riscv-fesvr-master
RISCV_PREFIX = $(RISCV_TOOL_DIR)/riscv32-unknown-elf
# gcc
RISCV_GCC = $(RISCV_PREFIX)-gcc
# GCC是入口，编译过程：汇编--编译--链接，汇编和链接是GCC调用其他工具做的
# Wa,把后面的参数传递给汇编器，如果所Wl,所传递给连接器
RISCV_GCC_OPTS = -static -fno-builtin-printf -fno-common -Wa,-march=rv32imazicsr -march=rv32imazicsr -std=gnu99 -ffast-math
# link
RISCV_LINK = $(RISCV_GCC) -T$(bmarkdir)/common/test.ld $(incs) -I$(bmarks_build_obj_dir)/
RISCV_LINK_OPTS = -nostdlib -nostartfiles -ffast-math -lc -lgcc
# objdump
RISCV_OBJDUMP = $(RISCV_PREFIX)-objdump --disassemble --disassemble-zeroes --section=.text --section=.text.startup --section=.data
# convert to VMH: 64KB memory
RISCV_ELF2HEX = $(ELF_2_HEX_DIR)/elf2hex
VMH_WIDTH = 8
VMH_DEPTH = 65536

VPATH += $(addprefix $(bmarkdir)/, $(bmarks))
VPATH += $(bmarkdir)/common
VPATH += $(bmarks_build_bin_dir)
VPATH += $(bmarks_build_obj_dir)
VPATH += $(bmarks_build_dump_dir)
VPATH += $(bmarks_build_vmh_dir)

incs  += -I$(bmarkdir)/../env -I$(bmarkdir)/common $(addprefix -I$(bmarkdir)/, $(bmarks))

include $(patsubst %, $(bmarkdir)/%/bmark.mk, $(bmarks))

#------------------------------------------------------------
# Build and run benchmarks on riscv simulator

bmarks_riscv_bin  = $(addsuffix .riscv, $(bmarks))
bmarks_riscv_dump = $(addsuffix .riscv.dump, $(bmarks))
bmarks_riscv_vmh = $(addsuffix .riscv.vmh, $(bmarks))

bmarks_defs   = -DPREALLOCATE=0 -DHOST_DEBUG=0
bmarks_cycles = 80000

$(bmarks_riscv_vmh): %.riscv.vmh: %.riscv
	@echo $(basename $<)
	@echo "@0" > $(bmarks_build_vmh_dir)/temp
	$(RISCV_ELF2HEX) $(VMH_WIDTH) $(VMH_DEPTH) $(bmarks_build_bin_dir)/$< >> $(bmarks_build_vmh_dir)/temp
	python3 $(bmarkdir)/../trans_vmh.py $(bmarks_build_vmh_dir)/temp $(bmarks_build_vmh_dir)/$@

$(bmarks_riscv_dump): %.riscv.dump: %.riscv
	$(RISCV_OBJDUMP) $(bmarks_build_bin_dir)/$< > $(bmarks_build_dump_dir)/$@

%.o: %.c
	$(RISCV_GCC) $(RISCV_GCC_OPTS) $(bmarks_defs) \
	             -c $(incs) $< -o $(bmarks_build_obj_dir)/$@

%.o: %.S
	$(RISCV_GCC) $(RISCV_GCC_OPTS) $(bmarks_defs) -D__ASSEMBLY__=1 \
	             -c $(incs) $< -o $(bmarks_build_obj_dir)/$@

riscv: $(bmarks_build_bin_dir) $(bmarks_build_obj_dir) $(bmarks_build_dump_dir) $(bmarks_build_vmh_dir) $(bmarks_riscv_dump) $(bmarks_riscv_vmh)


#------------------------------------------------------------
# Build and run benchmarks on host machine

bmarks_host_bin = $(addsuffix .host, $(bmarks_host))

host: $(bmarks_build_bin_dir) $(bmarks_host_bin)


#------------------------------------------------------------
# Default
$(bmarks_build_bin_dir):
	mkdir -p $@

$(bmarks_build_obj_dir):
	mkdir -p $@

$(bmarks_build_dump_dir):
	mkdir -p $@

$(bmarks_build_vmh_dir):
	mkdir -p $@

all: riscv

# Clean up

clean:
	rm -rf $(bmarks_build_dir)

.PHONY: all clean riscv host

