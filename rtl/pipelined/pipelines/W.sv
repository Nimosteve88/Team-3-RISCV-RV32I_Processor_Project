module F #(
    parameter DATA_WIDTH = 32
)(
    input logic                         clk,
    input logic                         RegWriteM,
    input logic  [1:0]                  ResultsrcM,
    input logic  [DATA_WIDTH-1:0]       ALUResultM,
    input logic  [DATA_WIDTH-1:0]       WriteDataE,
    input logic  [DATA_WIDTH-1:0]       ReadDataM,
    input logic                         RdM,
    input logic                         PCPlus4M,

    output logic                         RegWriteW,
    output logic  [1:0]                  ResultsrcW,
    output logic  [DATA_WIDTH-1:0]       ALUResultW,
    output logic  [DATA_WIDTH-1:0]       WriteDataW,
    output logic  [DATA_WIDTH-1:0]       ReadDataW,
    output logic                         RdW,
    output logic                         PCPlus4W
);

always_ff @(posedge clk) begin
    RegWriteW <= RegWriteM;
    ResultsrcW <= ResultsrcM;
    ReadDataW <= ReadDataM;
    ALUResultW <= ALUResultM;
    WriteDataW <= WriteDataM;
    RdW <= RdM;
    PCPlus4W <= PCPlus4M;
end

endmodule