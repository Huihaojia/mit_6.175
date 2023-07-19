//缩进和填充有点难用
//真正的多态mux怎么写
// 类型系统
// n 代表类型变量

function Bit#(1) multiplexer11(Bit#(1) sel, Bit#(1) a, Bit#(1) b);
    return (sel == 0)? a: b;
endfunction

function Bit#(1) or1(Bit#(1) a, Bit#(1) b);
    return a | b;
endfunction

function Bit#(1) and1(Bit#(1) a, Bit#(1) b);
    return a & b;
endfunction

function Bit#(1) not1(Bit#(1) a);
    return ~a;
endfunction

function Bit#(1) multiplexer1(Bit#(1) sel, Bit#(1) a, Bit#(1) b);
    return or1(and1(not1(sel),a), and1(sel,b));
endfunction

// 5在Haskell中也是类型，通过alueOf转换成整数
// n代表多态，所推断出来的
// FO类型件检查强大

// 常量用typedef的方式定义
// n代表位宽不确定
typedef 5 N;

function Bit#(N) multiplexerN(Bit#(1) sel, Bit#(N) a, Bit#(N) b);
    Bit#(N) out;
    for(Integer i=0; i<valueOf(N); i=i+1) begin
        out[i] = multiplexer1(sel, a[i], b[i]);
    end
    return out;
endfunction

function Bit#(5) multiplexer5(Bit#(1) sel, Bit#(5) a, Bit#(5) b);
    return multiplexerN(sel, a, b);
endfunction