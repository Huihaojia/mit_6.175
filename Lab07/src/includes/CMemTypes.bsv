
import GetPut::*;

import Types::*;

import MemTypes::*;

typedef Data MemResp;

typedef enum{Ld, St} MemOp deriving(Eq, Bits, FShow);
typedef struct{
    MemOp op;
    Addr  addr;
    Data  data;
} MemReq deriving(Eq, Bits, FShow);

typedef 16 NumTokens;
typedef Bit#(TLog#(NumTokens)) Token;

typedef 16 LoadBufferSz;
typedef Bit#(TLog#(LoadBufferSz)) LoadBufferIndex;

typedef struct {
    Addr addr;
    Data data;
} MemInitLoad deriving(Eq, Bits, FShow);

typedef union tagged {
    MemInitLoad InitLoad;
    void InitDone;
} MemInit deriving(Eq, Bits, FShow);

interface MemInitIfc;
    interface Put#(MemInit) request;
    method Bool done();
endinterface

typedef struct {
    DDR3Addr addr;
    DDR3Data data;
} WideMemInitLoad deriving(Eq, Bits, FShow);

typedef union tagged {
    WideMemInitLoad InitLoad;
    void WideInitDone;
} WideMemInit deriving(Eq, Bits, FShow);

interface WideMemInitIfc;
    interface Put#(WideMemInit) request;
    method Bool done();
endinterface