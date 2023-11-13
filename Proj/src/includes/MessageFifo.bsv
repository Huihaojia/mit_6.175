import CacheTypes::*;
import Fifo::*;

module mkMessageFifo(MessageFifo#(n));

    Fifo#(n, CacheMemResp) respFifo <- mkCFFifo;
    Fifo#(n, CacheMemReq)  reqFifo  <- mkCFFifo;

    method Action enq_resp(CacheMemResp d) if (respFifo.notFull);
        respFifo.enq(d);
    endmethod

    method Action enq_req(CacheMemReq d) if(reqFifo.notFull);
        reqFifo.enq(d);
    endmethod

    method Bool hasResp;
        return respFifo.notEmpty;
    endmethod

    method Bool hasReq;
        return reqFifo.notEmpty;
    endmethod

    method Bool notEmpty;
        return respFifo.notEmpty || reqFifo.notEmpty;
    endmethod

    method CacheMemMessage first;
        CacheMemMessage message;
        if (respFifo.notEmpty) begin
            message = tagged Resp respFifo.first;
        end
        else begin
            message = tagged Req reqFifo.first;
        end
        return message;
    endmethod

    method Action deq;
        if (respFifo.notEmpty) begin
            respFifo.deq;
        end
        else if (reqFifo.notEmpty) begin
            reqFifo.deq;
        end
    endmethod

endmodule
