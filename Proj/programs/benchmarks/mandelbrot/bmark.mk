#=======================================================================
# UCB CS250 Makefile fragment for benchmarks
#-----------------------------------------------------------------------
#
# Each benchmark directory should have its own fragment which
# essentially lists what the source files are and how to link them
# into an riscv and/or host executable. All variables should include
# the benchmark name as a prefix so that they are unique.
#

mandelbrot_c_src = \
	mandelbrot.c \
	syscalls.c \

mandelbrot_riscv_src = \
	crt.S \

mandelbrot_c_objs     = $(patsubst %.c, %.o, $(mandelbrot_c_src))
mandelbrot_riscv_objs = $(patsubst %.S, %.o, $(mandelbrot_riscv_src))

mandelbrot_host_bin = mandelbrot.host
$(mandelbrot_host_bin): $(mandelbrot_c_src)
	$(HOST_COMP) $^ -o $(bmarks_build_bin_dir)/$(mandelbrot_host_bin)

mandelbrot_riscv_bin = mandelbrot.riscv
$(mandelbrot_riscv_bin): $(mandelbrot_c_objs) $(mandelbrot_riscv_objs)
	cd $(bmarks_build_obj_dir); $(RISCV_LINK) $(mandelbrot_c_objs) $(mandelbrot_riscv_objs) -o $(bmarks_build_bin_dir)/$(mandelbrot_riscv_bin) $(RISCV_LINK_OPTS)

