import Vector::*;

//非函数调用用空格隔开

function Bit#(32) shiftRightPow2(Bit#(1) en, Bit#(32) unshifted, Integer power);
    Integer distance = 2**power;
    Bit#(32) shifted = 0;
    if (en == 0) begin
        return unshifted;
    end else begin
        for(Integer i = 0; i < 32; i = i + 1) begin
            if(i + distance < 32) begin
                shifted[i] = unshifted[i + distance];
            end
        end
        return shifted;
    end
endfunction

//

// for循环内用空格隔开
// 学习代码风格：OpenTitan DOC, Linux

function Bit#(32) barrelShifterRight(Bit#(32) in, Bit#(5) shiftBy);
    Vector#(6, Bit#(32)) shiftVec;
    shiftVec[0] = in;
    for (Bit#(32) i = 0; i < 5; i = i + 1) begin
        Integer ii = unpack(i);
        shiftVec[ii + 1] = shiftRightPow2(shiftBy[ii], shiftVec[ii], ii);
    end
    return shiftVec[5];
endfunction