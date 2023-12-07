module fetch #(
    parameter DATA_WIDTH = 32
)(
    input logic                         clk,
    input logic                         EN,
    input logic [DATA_WIDTH-1:0]        PCFi,

    output logic [DATA_WIDTH-1:0]       PCFo
);


always_ff @(posedge clk) begin
    if (EN == 1'd1) PCFo <= PCFi;
end

endmodule