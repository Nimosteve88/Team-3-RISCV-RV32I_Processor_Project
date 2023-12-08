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
    if (CLR) begin
        decode_reg <= DATA_WIDTH'b0;
    end
    else if (EN == 1'd1) begin
        decode_reg <= InstrDi;
    end
    assign InstrDo = decode_reg;
end

endmodule