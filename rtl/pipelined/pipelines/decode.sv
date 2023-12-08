module decode #(
    parameter DATA_WIDTH = 32
)(
    input logic                         clk,
    input logic                         EN,
    input logic                         CLR,
    input logic [DATA_WIDTH-1:0]        InstrDi,

    output logic [DATA_WIDTH-1:0]       InstrDo
);

    logic   [DATA_WIDTH-1:0]            decode_reg;

always_ff @(posedge clk) begin
    if (CLR && EN) begin
        decode_reg <= DATA_WIDTH'b0;
        InstrDo <= decode_reg;
    end
    else if (EN && !(CLR)) begin
        decode_reg <= InstrDi;
        InstrDo <= decode_reg;
    end
    else if (!(EN) && CLR) begin
        decode_reg <= DATA_WIDTH'b0;
    end
end

endmodule