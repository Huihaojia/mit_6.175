#!/bin/bash


asm_tests=(
	simple
	add addi
	and andi
	auipc
	beq bge bgeu blt bltu bne
	j jal jalr
	lw
	lui
	or ori
	sw
	sll slli
	slt slti
	sra srai
	srl srli
	sub
	xor xori
	bpred_bht bpred_j bpred_ras
	cache
	)
simple_tests=(
	bpred_bht bpred_j bpred_ras
	cache
)

vmh_dir=programs/build/assembly/vmh
log_dir=logs
wait_time=3

# create bsim log dir
mkdir -p ${log_dir}

# kill previous bsim if any
pkill bluetcl
pkill ubuntu.exe

# run each test
for test_name in ${asm_tests[@]}; do
	echo "-- Assemble Results--" > ./bluesim/log
	echo "-- assembly test: ${test_name} --" >> ./bluesim/log
	# copy vmh file
	mem_file=${vmh_dir}/${test_name}.riscv.vmh
	if [ ! -f $mem_file ]; then
		echo "ERROR: $mem_file does not exit, you need to first compile"
		exit
	fi
	cp ${mem_file} bluesim/mem.vmh 

	# run test
	make run.bluesim > ${log_dir}/${test_name}.log # run bsim, redirect outputs to log
	sleep ${wait_time}
	echo ""
done

# kill previous bsim if any
pkill bluetcl
pkill ubuntu.exe
