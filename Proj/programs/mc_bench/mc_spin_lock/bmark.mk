#=======================================================================
# UCB CS250 Makefile fragment for benchmarks
#-----------------------------------------------------------------------
#
# Each benchmark directory should have its own fragment which
# essentially lists what the source files are and how to link them
# into an riscv and/or host executable. All variables should include
# the benchmark name as a prefix so that they are unique.
#

mc_spin_lock_c_src = \
	mc_spin_lock_main.c \
	syscalls.c \


mc_spin_lock_riscv_src = \
	crt.S \

mc_spin_lock_c_objs     = $(patsubst %.c, %.o, $(mc_spin_lock_c_src))
mc_spin_lock_riscv_objs = $(patsubst %.S, %.o, $(mc_spin_lock_riscv_src))

mc_spin_lock_host_bin = mc_spin_lock.host
$(mc_spin_lock_host_bin): $(mc_spin_lock_c_src)
	$(HOST_COMP) $^ -o $(bmarks_build_bin_dir)/$(mc_spin_lock_host_bin)

mc_spin_lock_riscv_bin = mc_spin_lock.riscv
$(mc_spin_lock_riscv_bin): $(mc_spin_lock_c_objs) $(mc_spin_lock_riscv_objs)
	cd $(bmarks_build_obj_dir); $(RISCV_LINK) $(mc_spin_lock_c_objs) $(mc_spin_lock_riscv_objs) -o $(bmarks_build_bin_dir)/$(mc_spin_lock_riscv_bin) $(RISCV_LINK_OPTS)

