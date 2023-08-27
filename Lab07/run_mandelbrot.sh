#!/bin/bash

asm_tests=(
    mandelbrot
	)

vmh_dir=programs/build/benchmarks/vmh512
log_dir=logs
wait_time=0

# create bsim log dir
mkdir -p ${log_dir}

pkill bsim
pkill ubuntu.exe
pkill bluetcl

echo "Benchmarks Test" > log

# run each test
for test_name in ${asm_tests[@]}; do
	echo "-- benchmark test: ${test_name} --" >> log
	# copy vmh file
	mem_file=${vmh_dir}/${test_name}.riscv.vmh
	if [ ! -f $mem_file ]; then
		echo "ERROR: $mem_file does not exit, you need to first compile"
		exit
	fi
	cp ${mem_file} mem.vmh 

	# run test
	bluesim/bin/ubuntu.exe 1> ${log_dir}/${test_name}.log
	sleep ${wait_time} # wait for bsim to setup
	echo ""
done
pkill bsim
pkill ubuntu.exe
pkill bluetcl

rm ./SWSOCK0
rm ./mem.vmh