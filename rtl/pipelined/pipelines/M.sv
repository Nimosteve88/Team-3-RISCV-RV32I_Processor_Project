module M #(
    parameter DATA_WIDTH = 32
)(
    input logic                         clk,
    input logic                         RegWriteE,
    input logic  [1:0]                  ResultsrcE,
    input logic                         MemWriteE,
    input logic  [DATA_WIDTH-1:0]       ALUResultE,
    input logic  [DATA_WIDTH-1:0]       WriteDataE,
    input logic                         RdE,
    input logic                         PCPlus4E,

    output logic                         RegWriteM,
    output logic  [1:0]                  ResultsrcM,
    output logic                         MemWriteM,
    output logic  [DATA_WIDTH-1:0]       ALUResultM,
    output logic  [DATA_WIDTH-1:0]       WriteDataM,
    output logic                         RdM,
    output logic                         PCPlus4M
);

always_ff @(posedge clk) begin
    RegWriteM <= RegWriteE;
    ResultsrcM <= ResultsrcE;
    MemWriteM <= MemWriteE;
    ALUResultM <= ALUResultE;
    WriteDataM <= WriteDataE;
    RdM <= RdE;
    PCPlus4M <= PCPlus4E;
end

endmodule