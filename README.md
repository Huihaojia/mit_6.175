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

### Discussion Question 6: BHT Planning

#### 1. Where will the BHT be positioned in the pipeline?

Because we got brTaken in Execute Stage, we should update Branch History Table (BHT) also at Execute Stage. Meanwhile, we got predicted PC in Fetch, so the ppcDP method should be positioned at Fetch Stage. In a word, the BHT should be positioned between Fetch and Execute, just like BTB.

#### 2. What pipeline stage performs lookups into the BHT?

As mentioned above, Execute lookups into BHT for updating and Fetch lookups into BHT for prediction.

#### 3. In which pipeline stage will the BHT prediction be used?

The BHT prediction will be used at Fetch Stage.

#### 4. Will the BHT prediction need to be passed between pipeline stages?

If misprediction happens in Execute Stage and caused a divergence between fetch epoch and execute epoch, this divergence message should be passed to the following pipeline stages to clear the Scoreboard updated by mis-fetched instructions.

#### 5. How to redirect PC using BHT prediction?

Under a global Epoch strategy, there are 3 steps to redirect PC:

+ Step 1: The mispredict message is produced by Execute Stage and push the redirect PC addr into FIFO. Then it caused a mismatch between fetch epoch and execute epoch in the next clock and update DP bits in BHT.
+ Step 2: The Fetch stage catches the redirect message and update PC with the correct PC. Meanwhile, the fetch epoch is updated with, for instance, counter and keep its pace with execute epoch.
+ Step 3: The fetch stage pushes the up-to-date pc to decode and predict the next PC with BHT.

#### 6. Do you need to add a new epoch?

I think either is OK. One global epoch is ready to take over this job.

#### 7. How to handle the redirect messages?

I have answer the redirect procedure in Question 5.

#### 8. Do you need to change anything to the current instruction and its data structures if redirecting?

Yes, I have introduced poision bit from Execute to Memory and from Memory to Writeback.

#### 9. How will you train the BHT?

![Bimodel predictor](https://pic3.zhimg.com/96c0731181d342c4c7e8c4fdaa1c7946_r.jpg)

I trained the BHT with Bimodel predictor, which has four stages called "Strongly not, Weakly not, Weakly, Strongly". The prediction is taken only when the predictor is in "Strongly" stage and not taken when "Weakly". According to the assessment, the accuracy of this predictor can reach 93.5%.

#### 10. Which stage produces training data for the BHT?

The Execute produces training data for BHT through the "Branch Taken" signal.

#### 11. Which stage will use the interface method to train the BHT?

Also the Execute stage i think.

#### 12. How to send training data?

We can use a register file to store the stage of each PC and sending it through register index.

#### 13. For which instructions will you train the BHT?

Every branch instruction should be trained ,such as J, Jr, Br, Auipc.

#### 14. How will you know if your BHT works?

If the misprediction occurs every two instructions, we will know whether the BHT works. Without the BHT, the flush will happens to each pipeline every cycle, which is caused by misprediction. Thus, we can use a case that introducing parity into loop kernel to verify the functionality of BHT.