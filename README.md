# mit_6.175
Codes and notes on Labs of mit 6.175

## Lab05: RISC-V Introduction -- Multi-Cycle and Two-Stage Pipeline

In this Lab, you need to establish RISC-V compiler environment. However, the version of the RISC-V tools is 2016 which is too old to work properly. My solution is as follows:

### Building RISC-V assemble environment

You can get the up-to-date RISC-V compiler from their riscv-gnu-toolchain repository

[riscv-gnu-toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain)

Here you should follow their detailed process in README. I have concluded some command you may use. I finished this lab on Ubuntu 20.04

```

$ sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev

./configure --prefix=/opt/riscv --with-multilib-generator="rv32i-ilp32--"
make linux

make check-gcc

```

Now, you will get executable "riscv32-unknown-elf" in the path "/opt/riscv/bin/". This is the compiler which translates C to assembly code.

### Getting elf2hex Tool

The elf2hex tool provides in up-to-date RISC-V toolchain is incompatible with this old fashion lab. Fortunately, we can get it from [riscv-fesvr](https://github.com/riscvarchive/riscv-fesvr) in spite of this repo has been aborted for a long time. The README is broken, but I have found the approach to build "elf2hex"

```

$ ./configure
$ make
$ [sudo] make install

```

Congratuations! We got elf2hex

### Modifying Makefile

There is still something you should pay attention to in Makefile.

```
RISCV_GCC_OPTS = -static -fno-builtin-printf -fno-common -Wa,-march=rv32imazicsr -march=rv32imazicsr -std=gnu99 -ffast-math
```

Firstly, the extension of zicsr is necessary, or the compiler cannot identify zicsr commands.

Secondly, if you type ```-Wa,``` before ```-march```, you should replicate the ```-march``` in GCC options. Otherwise, only the assembler can identify the zicsr extension, the compiler cannot.

### Changing Python Codes

The last trival left by the old lab is the difference between ```python``` and ```python3```.

### Compiling

```
cd ./programs/assembly/
make clean
make

cd ./programs/benchmarks
make clean
make
```

### Building BSV in Docker

```
sudo ./docker.sh
cd /hhj
cd Lab05
make build.bluesim VPROC=ONECYCLE
./run_asm.sh
./run_bmarks.sh
```

### Problems I have met

#### 1. Program exit incorrct

In BTB Lab, my program cannot exit correctly. PC have arrived at ```j	75c <exit+0x6c>``` but the predicted PC still updated with ```PC+4```. The key of this issue is that I donnot update PC from Btb all the time in the fetch stage, where I threw ```PC+4``` when the fEpoch does not conflict with eEpoch.

#### 2. Dead loop

Also, in BTB Lab, my for loop program confronts with an invalid bne jump operation, which makes it like an endless while loop. The key of this issue is that I distinguish ```misPredict``` with ```brTaken```. The former one caused by ```fEpoch != eEpoch``` and the latter one caused by ```brAddr != predAddr```. To slove this problem, I update BTB only when ```misPredict && brTaken``` and redirect my PC with ```correctPc``` whenever ```misPredict``` happens.

## Lab06: RISC-V Processor with Six-Stage Pipeline and Branch Prediction

### The relationship among exeEpoch, misPredic, and brTaken

Under the assumption of one global epoch in six stage RISC-V, if misPredic is asserted, exeEpoch is reversed, which caused the difference with exeEpoch fired from Ifetch stage.