import Vector::*;
import Complex::*;

import FftCommon::*;
import Fifo::*;
import FIFOF::*;

interface Fft;
    method Action enq(Vector#(FftPoints, ComplexData) in);
    method ActionValue#(Vector#(FftPoints, ComplexData)) deq;
endinterface

// 193 vs 324 vs 452

(* synthesize *)
module mkFftCombinational(Fft);
    FIFOF#(Vector#(FftPoints, ComplexData)) inFifo <- mkFIFOF;
    FIFOF#(Vector#(FftPoints, ComplexData)) outFifo <- mkFIFOF;

    Vector#(NumStages, Vector#(BflysPerStage, Bfly4)) bfly <- replicateM(replicateM(mkBfly4));

    Reg#(int) cycle <- mkReg(0);
    Reg#(int) combinationCount <- mkReg(0);
    rule counter;
        cycle <= cycle + 1;
    endrule


    function Vector#(FftPoints, ComplexData) stage_f(StageIdx stage, Vector#(FftPoints, ComplexData) stage_in);
        Vector#(FftPoints, ComplexData) stage_temp, stage_out;
        for (FftIdx i = 0; i < fromInteger(valueOf(BflysPerStage)); i = i + 1)  begin
            FftIdx idx = i * 4;
            Vector#(4, ComplexData) x;
            Vector#(4, ComplexData) twid;
            for (FftIdx j = 0; j < 4; j = j + 1 ) begin
                x[j] = stage_in[idx+j];
                twid[j] = getTwiddle(stage, idx+j);
            end
            let y = bfly[stage][i].bfly4(twid, x);

            for (FftIdx j = 0; j < 4; j = j + 1 ) begin
                stage_temp[idx+j] = y[j];
            end
        end

        stage_out = permute(stage_temp);

        return stage_out;
    endfunction

    rule doFftIn;
        inFifo.deq;
        $display("Combination logic \"%0d\" processes at: %0d", combinationCount, cycle);
        Vector#(4, Vector#(FftPoints, ComplexData)) stage_data;
        stage_data[0] = inFifo.first;

        for (StageIdx stage = 0; stage < 3; stage = stage + 1) begin
            stage_data[stage + 1] = stage_f(stage, stage_data[stage]);
        end
        outFifo.enq(stage_data[3]);
        combinationCount <= combinationCount + 1;
    endrule

    method Action enq(Vector#(FftPoints, ComplexData) in);
        inFifo.enq(in);
    endmethod

    method ActionValue#(Vector#(FftPoints, ComplexData)) deq;
        outFifo.deq;
        return outFifo.first;
    endmethod
endmodule

(* synthesize *)
module mkFftInelasticPipeline(Fft);
    FIFOF#(Vector#(FftPoints, ComplexData)) inFifo <- mkFIFOF;
    FIFOF#(Vector#(FftPoints, ComplexData)) outFifo <- mkFIFOF;
    Vector#(3, Vector#(16, Bfly4)) bfly <- replicateM(replicateM(mkBfly4));

    Reg#(int) cycle <- mkReg(0);
    Reg#(int) fftCount <- mkReg(0);

    rule counter;
        cycle <= cycle + 1;
    endrule

    function Vector#(FftPoints, ComplexData) stage_f(StageIdx stage, Vector#(FftPoints, ComplexData) stage_in);
        Vector#(FftPoints, ComplexData) stage_temp, stage_out;
        for (FftIdx i = 0; i < fromInteger(valueOf(BflysPerStage)); i = i + 1)  begin
            FftIdx idx = i * 4;
            Vector#(4, ComplexData) x;
            Vector#(4, ComplexData) twid;
            for (FftIdx j = 0; j < 4; j = j + 1 ) begin
                x[j] = stage_in[idx+j];
                twid[j] = getTwiddle(stage, idx+j);
            end
            let y = bfly[stage][i].bfly4(twid, x);

            for (FftIdx j = 0; j < 4; j = j + 1 ) begin
                stage_temp[idx+j] = y[j];
            end
        end

        stage_out = permute(stage_temp);

        return stage_out;
    endfunction

    Vector#(3, Reg#(Vector#(FftPoints, ComplexData))) inElasticPipes <- replicateM(mkReg(?));
    Vector#(3, Reg#(Bool)) valids <- replicateM(mkReg(False));

    rule doFft;
        valids[0] <= inFifo.notEmpty;
        $display("### valids[0] is %0d at %0d", inFifo.notEmpty, cycle);
        if(inFifo.notEmpty) begin
            inElasticPipes[0] <= stage_f(0, inFifo.first);
            inFifo.deq;
            $display("#Stage 0 starts at %0d", cycle);
        end
        for (StageIdx stage = 1; stage < 2; stage = stage + 1) begin
            if(valids[0]==True) $display("#Stage %0d starts at %0d", stage, cycle);
            valids[stage] <= valids[stage - 1];
            inElasticPipes[stage] <= stage_f(stage, inElasticPipes[stage - 1]);
        end
    endrule

    rule doFft2;
        if(valids[1]) begin
            $display("#Stage 2 starts at %0d", cycle);
            outFifo.enq(stage_f(2, inElasticPipes[1]));
        end
    endrule

    method Action enq(Vector#(FftPoints, ComplexData) in);
        inFifo.enq(in);
    endmethod

    method ActionValue#(Vector#(FftPoints, ComplexData)) deq;
        outFifo.deq;
        return outFifo.first;
    endmethod
endmodule

(* synthesize *)
module mkFftElasticPipeline(Fft);
    Fifo#(3, Vector#(FftPoints, ComplexData)) inFifo <- mkFifo;
    Fifo#(3, Vector#(FftPoints, ComplexData)) outFifo <- mkFifo;
    Reg#(int) cycle <- mkReg(0);

    rule counter;
        cycle <= cycle + 1;
    endrule

    Vector#(3, Vector#(16, Bfly4)) bfly <- replicateM(replicateM(mkBfly4));

    // Multiple rules
    function Vector#(FftPoints, ComplexData) stage_f(StageIdx stage, Vector#(FftPoints, ComplexData) stage_in);
        Vector#(FftPoints, ComplexData) stage_temp, stage_out;
        for (FftIdx i = 0; i < fromInteger(valueOf(BflysPerStage)); i = i + 1)  begin
            FftIdx idx = i * 4;
            Vector#(4, ComplexData) x;
            Vector#(4, ComplexData) twid;
            for (FftIdx j = 0; j < 4; j = j + 1 ) begin
                x[j] = stage_in[idx+j];
                twid[j] = getTwiddle(stage, idx+j);
            end
            let y = bfly[stage][i].bfly4(twid, x);

            for(FftIdx j = 0; j < 4; j = j + 1 ) begin
                stage_temp[idx+j] = y[j];
            end
        end

        stage_out = permute(stage_temp);

        return stage_out;
    endfunction

    Vector#(3, Fifo#(3, Vector#(FftPoints, ComplexData))) elasticFifos <- replicateM(mkFifo());

//     rule doFft;
//         if (inFifo.notEmpty) begin
//             elasticFifos[0].enq(stage_f(0, inFifo.first));
//             inFifo.deq;
//         end
// // Simultaneously enqueue and dequeue caused a problem?s
//         for (StageIdx stage = 1; stage < 3; stage = stage + 1) begin
//             elasticFifos[stage].enq(stage_f(stage, elasticFifos[stage - 1].first));
//             elasticFifos[stage - 1].deq;
//         end

//     endrule

//     rule getOut;
//         outFifo.enq(elasticFifos[2].first);
//         elasticFifos[2].deq;
//     endrule

    rule doFft1 if(inFifo.notEmpty);
        // $display("---Stage 0 starts at %0d---", cycle);
        elasticFifos[0].enq(stage_f(0, inFifo.first));
        inFifo.deq;
    endrule

    rule doFft2;
        // $display("---Stage 1 starts at %0d---", cycle);
        elasticFifos[1].enq(stage_f(1, elasticFifos[0].first));
        elasticFifos[0].deq;
    endrule

    rule doFft3;
        // $display("---Stage 2 starts at %0d---", cycle);
        outFifo.enq(stage_f(2, elasticFifos[1].first));
        elasticFifos[1].deq;
    endrule

    // rule doFft4;
    //     outFifo.enq(elasticFifos[2].first);
    //     elasticFifos[2].deq;
    // endrule


    method Action enq(Vector#(FftPoints, ComplexData) in);
        inFifo.enq(in);
    endmethod

    method ActionValue#(Vector#(FftPoints, ComplexData)) deq;
        outFifo.deq;
        return outFifo.first;
    endmethod
endmodule
