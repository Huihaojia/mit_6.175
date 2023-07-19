// Reference functions that use Bluespec's '*' operator
function Bit#(TAdd#(n,n)) multiply_unsigned( Bit#(n) a, Bit#(n) b );
    UInt#(n) a_uint = unpack(a);
    UInt#(n) b_uint = unpack(b);
    UInt#(TAdd#(n,n)) product_uint = zeroExtend(a_uint) * zeroExtend(b_uint);
    return pack( product_uint );
endfunction

function Bit#(TAdd#(n,n)) multiply_signed( Bit#(n) a, Bit#(n) b );
    Int#(n) a_int = unpack(a);
    Int#(n) b_int = unpack(b);
    Int#(TAdd#(n,n)) product_int = signExtend(a_int) * signExtend(b_int);
    return pack( product_int );
endfunction

// Multiplication by repeated addition
function Bit#(TAdd#(n,n)) multiply_by_adding(Bit#(n) a, Bit#(n) b);
    Bit#(n) carry = 0;
    Bit#(n) res = 0;

    for(Integer i = 0; i < valueOf(n); i = i + 1)
    begin
        Bit#(TAdd#(1,n)) sum = zeroExtend(carry) + ((b[i] == 1) ? zeroExtend(a) : 0);
        res[i] = sum[0];
        // carry = sum[TSub#(n, 1): 1];
        carry = truncateLSB(sum);
    end
    return {carry, res};
endfunction

// Multiplier Interface
interface Multiplier#( numeric type n );
    method Bool start_ready();
    method Action start( Bit#(n) a, Bit#(n) b );
    method Bool result_ready();
    method ActionValue#(Bit#(TAdd#(n,n))) result();
endinterface


// Folded multiplier by repeated addition
module mkFoldedMultiplier( Multiplier#(n) )
	provisos(Add#(1, a__, n)); // make sure n >= 1

    // You can use these registers or create your own if you want
    Reg#(Bit#(n)) a <- mkReg(0);
    Reg#(Bit#(n)) b <- mkReg(0);
    Reg#(Bit#(n)) res <- mkReg(0);
    Reg#(Bit#(n)) carry <- mkReg(0);
    Reg#(Bit#(TAdd#(TLog#(n),1))) index <- mkReg(fromInteger(valueOf(n)) + 1);

    rule mulStep if (i < fromInteger(valueOf(n)));
        i <= i + 1;
        Bit#(TAdd#(n, 1)) sum = zeroExtend(carry) + zeroExtend((b[0] == 1) ? a : 0);
        res <= { sum[0], res[fromInteger(valueOf(TSub#(n, 1))) : 1] };
        // $display("res: %0d, all: \t%0d\t%b", res, {carry, res}, {carry, res});
        carry <= truncateLSB(sum);
        b <= b >> 1;
    endrule

    method Bool start_ready();
        return i == fromInteger(valueOf(n) + 1);
    endmethod

    method Action start( Bit#(n) aIn, Bit#(n) bIn ) if (i == fromInteger(valueOf(n)) + 1);
        a <= aIn;
        b <= bIn;
        i <= 0;
        carry <= 0;
        res <= 0;
    endmethod

    method Bool result_ready();
        return i == fromInteger(valueOf(n));
    endmethod

    method ActionValue#(Bit#(TAdd#(n,n))) result if (i == fromInteger(valueOf(n)));
        i <= i + 1;
        return { carry, res };
    endmethod
endmodule



function Bit#(n) arthShift(Bit#(n) a, Integer n, Bool right);
    Int#(n) temp = unpack(a);
    if (right) begin
        return pack(temp >> n);
    end
    else begin
        return pack(temp << n);
    end
endfunction



// Booth Multiplier
module mkBoothMultiplier( Multiplier#(n) )
	provisos(Add#(2, a__, n)); // make sure n >= 2

    Reg#(Bit#(TAdd#(TAdd#(n,n),1))) m_pos <- mkRegU;
    Reg#(Bit#(TAdd#(TAdd#(n,n),1))) m_neg <- mkRegU;
    Reg#(Bit#(TAdd#(TAdd#(n,n),1))) p <- mkRegU;
    Reg#(Bit#(TAdd#(TLog#(n),1))) i <- mkReg( fromInteger(valueOf(n) + 1) );

    rule mul_step(i < fromInteger(valueOf(n)));
        Bit#(2) part_r = p[1:0];
        Bit#(TAdd#(TAdd#(n,n),1)) temp_p;
        temp_p =    case (part_r)
                        2'b01: return (p + m_pos);
                        2'b10: return (p + m_neg);
                        default: return p;
                    endcase;
        p <= arthShift(temp_p, 1, True);
        i <= i + 1;
    endrule

    method Bool start_ready();
        return i == fromInteger(valueOf(n) + 1);
    endmethod

    method Action start( Bit#(n) m, Bit#(n) r ) if (i == fromInteger(valueOf(n) + 1));
        m_pos <= {m, 0};
        m_neg <= {-m, 0};
        p <= {0, r, 1'b0};
        i <= 0;
    endmethod

    method Bool result_ready();
        return i == fromInteger(valueOf(n));
    endmethod

    method ActionValue#(Bit#(TAdd#(n,n))) result() if (i == fromInteger(valueOf(n)));
        i <= i + 1;
        return truncateLSB(p);
    endmethod
endmodule



// Radix-4 Booth Multiplier
module mkBoothMultiplierRadix4( Multiplier#(n) )
	provisos(Mul#(a__, 2, n), Add#(1, b__, a__)); // make sure n >= 2 and n is even

    Reg#(Bit#(TAdd#(TAdd#(n,n),2))) m_pos <- mkRegU;
    Reg#(Bit#(TAdd#(TAdd#(n,n),2))) m_neg <- mkRegU;
    Reg#(Bit#(TAdd#(TAdd#(n,n),2))) p <- mkRegU;
    Reg#(Bit#(TAdd#(TLog#(n),1))) i <- mkReg(fromInteger(valueOf(n) / 2 + 1));

    rule mul_step(i < fromInteger(valueOf(n)) / 2);
        Bit#(3) part_r = p[2:0];
        Bit#(TAdd#(TAdd#(n,n),2)) temp_p;
        temp_p =    case(part_r)
                        3'b001, 3'b010: return p + m_pos;
                        3'b011: return p + (m_pos << 1);
                        3'b101, 3'b110: return p + m_neg;
                        3'b100: return p + (m_neg << 1);
                        default: return p;
                    endcase;
        p <= arthShift(temp_p, 2, True);
        i <= i + 1;
    endrule

    method Bool start_ready();
        return i == fromInteger(valueOf(n)/2 + 1);
    endmethod

    method Action start( Bit#(n) m, Bit#(n) r ) if (i == fromInteger(valueOf(n)/2 + 1));
        m_pos <= {msb(m), m, 0};
        m_neg <= {msb(-m), -m, 0};
        p <= {0, r, 1'b0};
        i <= 0;
    endmethod

    method Bool result_ready();
        return i == fromInteger(valueOf(n)/2);
    endmethod

    method ActionValue#(Bit#(TAdd#(n,n))) result() if (i == fromInteger(valueOf(n)/2));
        i <= i + 1;
        return p [(2*valueOf(n)):1];
    endmethod
endmodule
