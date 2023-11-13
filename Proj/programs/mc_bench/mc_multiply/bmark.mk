#=======================================================================
# UCB CS250 Makefile fragment for benchmarks
#-----------------------------------------------------------------------
#
# Each benchmark directory should have its own fragment which
# essentially lists what the source files are and how to link them
# into an riscv and/or host executable. All variables should include
# the benchmark name as a prefix so that they are unique.
#

mc_multiply_c_src = \
	mc_multiply_main.c \
	multiply.c \
	syscalls.c \

mc_multiply_riscv_src = \
	crt.S \

mc_multiply_c_objs     = $(patsubst %.c, %.o, $(mc_multiply_c_src))
mc_multiply_riscv_objs = $(patsubst %.S, %.o, $(mc_multiply_riscv_src))

mc_multiply_host_bin = mc_multiply.host
$(mc_multiply_host_bin): $(mc_multiply_c_src)
	$(HOST_COMP) $^ -o $(bmarks_build_bin_dir)/$(mc_multiply_host_bin)

mc_multiply_riscv_bin = mc_multiply.riscv
$(mc_multiply_riscv_bin): $(mc_multiply_c_objs) $(mc_multiply_riscv_objs)
	cd $(bmarks_build_obj_dir); $(RISCV_LINK) $(mc_multiply_c_objs) $(mc_multiply_riscv_objs) -o $(bmarks_build_bin_dir)/$(mc_multiply_riscv_bin) $(RISCV_LINK_OPTS)

