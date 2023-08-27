typedef 24 DDR3AddrSize;
typedef Bit#(DDR3AddrSize) DDR3Addr;
typedef 512 DDR3DataSize;
typedef Bit#(DDR3DataSize) DDR3Data;
typedef TDiv#(DDR3DataSize, 8) DDR3DataBytes;
typedef Bit#(DDR3DataBytes) DDR3ByteEn;
typedef TDiv#(DDR3DataSize, DataSize) DDR3DataWords;

// The below typedef is equivalent to this:
// typedef struct {
//     Bool        write;
//     Bit#(64)    byteen;
//     Bit#(24)    address;
//     Bit#(512)   data;
// } DDR3_Req deriving (Bits, Eq);
typedef MemoryRequest#(DDR3AddrSize, DDR3DataSize) DDR3_Req;

// The below typedef is equivalent to this:
// typedef struct {
//     Bit#(512)   data;
// } DDR3_Resp deriving (Bits, Eq);
typedef MemoryResponse#(DDR3DataSize) DDR3_Resp;

// The below typedef is equivalent to this:
// interface DDR3_Client;
//     interface Get#( DDR3_Req )  request;
//     interface Put#( DDR3_Resp ) response;
// endinterface;
typedef MemoryClient#(DDR3AddrSize, DDR3DataSize) DDR3_Client;