import Fifo::*;
import Vector::*;
import MemTypes::*;
import CacheTypes::*;

import CMemTypes::*;
import MemUtil::*;
import Types::*;
import FShow::*;

import Memory::*;
import RegFile::*;

interface CacheMy;
    method Action req(MemReq r);
    method ActionValue #(Data) resp;

    method ActionValue#(WideMemReq) memReq;
    method Action memResp(CacheLine r);
endinterface

typedef enum {
    Ready,
    StartMiss,
    SendFillReq,
    WaitFillResp
} CacheStatus deriving (Eq, Bits, FShow);

function WideMemReq getWideMemReq(MemOp op, Addr addr, CacheLine data);
    // You should update the entire cacheline, not the specific word
    Bit#(CacheLineWords) write_en = '1;
    CacheWordSelect wordsel = truncate( addr >> 2 );
    // Cache line words * 4, meaning Cache line length
    // Cache Tag + Cache Index
    for( Integer i = 0 ; i < valueOf(TLog#(CacheLineBytes)) ; i = i+1 ) begin
        addr[i] = 0;
    end

    return WideMemReq {
                write_en: write_en,
                addr: addr,
                data: data
            };
endfunction

module mkCacheMy(CacheMy);
    Reg#(CacheStatus) status <- mkReg(Ready);

    RegFile#(CacheIndex, CacheLine)         dataArray   <- mkRegFileFull;
    RegFile#(CacheIndex, Maybe#(CacheTag))  tagArray    <- mkRegFileFull;
    RegFile#(CacheIndex, Bool)              dirtyArray  <- mkRegFileFull;

    Fifo#(8, Data)              hitQ    <- mkCFFifo;
    Reg#(MemReq)                missReq <- mkRegU;

    Fifo#(4, WideMemReq)       memReqQ     <- mkCFFifo;
    Fifo#(4, CacheLine)        memRespQ    <- mkCFFifo;

    rule startMiss if (status == StartMiss);
        let idx = getIndex(missReq.addr);
        let wordSel = getWordSelect(missReq.addr);
        let tag = tagArray.sub(idx);
        let dirty = dirtyArray.sub(idx);

        if (isValid(tag) && dirty) begin
            let addr = {fromMaybe(?, tag), idx, wordSel, 2'b0};
            let data = dataArray.sub(idx);
            memReqQ.enq(getWideMemReq(St, addr, data));
        end
        status <= SendFillReq;
    endrule

    rule sendFillReq if (status == SendFillReq);
        memReqQ.enq(toWideMemReq(missReq));
        status <= WaitFillResp;
    endrule

    rule waitFillResp if (status == WaitFillResp);
        let idx = getIndex(missReq.addr);
        let tag = getTag(missReq.addr);
        let data = memRespQ.first;
        dataArray.upd(idx, data);
        tagArray.upd(idx, tagged Valid tag);

        dirtyArray.upd(idx, False);
        hitQ.enq(data[getWordSelect(missReq.addr)]);
        memRespQ.deq;
        status <= Ready;
    endrule

    method Action req(MemReq r) if (status == Ready);
        let idx = getIndex(r.addr);
        let line = dataArray.sub(idx);
        let hit = False;
        if(tagArray.sub(idx) matches tagged Valid .currTag &&& currTag == getTag(r.addr)) begin
            hit = True;
        end
        if(r.op == Ld) begin
            if(hit) begin
                hitQ.enq(line[getWordSelect(r.addr)]);
            end
            else begin
                missReq <= r;
                status <= StartMiss;
            end
        end
        else begin
            if(hit) begin
                line[getWordSelect(r.addr)] = r.data;
                dataArray.upd(idx, line);
                dirtyArray.upd(idx, True);
            end
            else begin
                memReqQ.enq(toWideMemReq(r));
            end
        end
    endmethod

    method ActionValue#(Data) resp;
        hitQ.deq;
        return hitQ.first;
    endmethod

    method ActionValue#(WideMemReq) memReq;
        memReqQ.deq;
        return memReqQ.first;
    endmethod

    method Action memResp(CacheLine r);
        memRespQ.enq(r);
    endmethod
endmodule

// module mkNBCache(CacheMy);
//     RegFile#(CacheIndex, CacheLine)         dataArray   <- mkRegFileFull;
//     RegFile#(CacheIndex, Maybe#(CacheTag))  tagArray    <- mkRegFileFull;

//     CompletionBuffer#()
// endmodule