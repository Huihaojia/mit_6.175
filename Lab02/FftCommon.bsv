// How to introduce FIFO into FFT?

import Vector::*;
import Complex::*;

typedef 8 DataSz;
typedef Bit#(DataSz) Data;
typedef Complex#(Data) ComplexData;
// 64 point
typedef 64 FftPoints;
// 6 bit FFT idx
typedef Bit#(TLog#(FftPoints)) FftIdx;
// 3 bit Stage idx
typedef Bit#(TLog#(TLog#(FftPoints))) StageIdx;
// 3 Num Stages
typedef TDiv#(TLog#(FftPoints), 2) NumStages;
// 16 BFlys Per stage
typedef TDiv#(FftPoints, 4) BflysPerStage;


Integer fftPoints = valueOf(FftPoints);


interface Bfly4;
    method Vector#(4,ComplexData) bfly4(Vector#(4, ComplexData) t, Vector#(4, ComplexData) x);
endinterface

(* synthesize *)
module mkBfly4(Bfly4);
    method Vector#(4,ComplexData) bfly4(Vector#(4, ComplexData) t, Vector#(4, ComplexData) x);
        Vector#(4, ComplexData) m, y, z;

        for (Integer i = 0; i < 4; i = i + 1)
        begin
            m[i] = x[i] * t[i];
        end

        y[0] = m[0] + m[2];
        y[1] = m[0] - m[2];
        y[2] = m[1] + m[3];
        y[3] = m[1] - m[3];

        z[0] = y[0] + y[2];
        z[1] = y[1] + y[3];
        z[2] = y[0] - y[2];
        z[3] = y[1] - y[3];
        return z;
    endmethod
endmodule

// Calculat weight
function ComplexData getTwiddle(StageIdx stage, FftIdx index);
    // Complex constructor
    return cmplx(zeroExtend(index)/(2+zeroExtend(stage)/fromInteger(fftPoints)),
            zeroExtend(index)/(1+zeroExtend(stage)/fromInteger(fftPoints)));
endfunction

// Reorder to the next layer
function Vector#(FftPoints,ComplexData) permute(Vector#(FftPoints,ComplexData) inVector);
    Vector#(FftPoints,ComplexData) outVector = newVector;
    for(Integer i = 0; i < valueof(FftPoints) / 2; i = i + 1) begin
        outVector[i] =  inVector[i*2];
        outVector[i + fftPoints / 2] = inVector[i * 2 + 1];
    end
    return outVector;
endfunction
