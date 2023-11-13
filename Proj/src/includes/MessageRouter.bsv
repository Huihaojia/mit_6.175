import Vector::*;
import CacheTypes::*;
import MessageFifo::*;
import Types::*;


module mkMessageRouter(
    Vector#(CoreNum, MessageGet) c2r,
    Vector#(CoreNum, MessagePut) r2c,
    MessageGet m2r,
    MessagePut r2m,
    Empty ifc
);

    rule router2master;
        CoreID coreID = 0;
        Bool hasResp = False;
        Bool hasReq = False;
        Bool occupied = hasResp || hasReq;

        for (Integer i = 0; i < valueOf(CoreNum); i = i + 1) begin
            if (c2r[fromInteger(i)].notEmpty) begin
                let x = c2r[fromInteger(i)].first;
                if (x matches tagged Resp .resp) begin
                    if (!hasResp) begin
                        coreID = fromInteger(i);
                        hasResp = True;
                        hasReq = True;
                    end
                end
                else if (x matches tagged Req .req) begin
                    if (!hasReq && !hasResp) begin
                        coreID = fromInteger(i);
                        hasReq = True;
                    end
                end
            end
        end

        if (hasReq || hasResp) begin
            let message = c2r[coreID].first;
            c2r[coreID].deq;
            case(message) matches
                tagged Resp .resp: begin
                    r2m.enq_resp(resp);
                end
                tagged Req  .req: begin
                    r2m.enq_req(req);
                end
            endcase
        end
    endrule

    rule master2router;
        let t = m2r.first;
        m2r.deq;
        case(t) matches
            tagged Resp .resp: begin
                let coreID = resp.child;
                r2c[coreID].enq_resp(resp);
            end
            tagged Req  .req: begin
                let coreID = req.child;
                r2c[coreID].enq_req(req);
            end
        endcase
    endrule

endmodule