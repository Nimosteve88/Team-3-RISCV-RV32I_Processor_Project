module decode #(
    parameter DATA_WIDTH = 32
)(
    input logic                         clk,
    input logic                         EN,
    input logic                         CLR,
    input logic [DATA_WIDTH-1:0]        InstrDi,

    output logic [DATA_WIDTH-1:0]       InstrDo
);

always_ff @(posedge clk) begin
    if (EN == 1'd1) InstrDo <= InstrDi;
end

endmodule