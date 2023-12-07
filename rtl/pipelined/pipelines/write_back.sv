module write_back #(
    parameter DATA_WIDTH = 32,
    parameter REGISTER_ADDRESS_WIDTH = 5
)(
    input logic                                 clk,

    input logic                                 RegWriteM,
    input logic  [1:0]                          ResultSrcM,
    input logic  [DATA_WIDTH-1:0]               ALUResultM,
    input logic  [DATA_WIDTH-1:0]               ReadDataM,
    input logic  [REGISTER_ADDRESS_WIDTH-1:0]   RdM,
    input logic  [DATA_WIDTH-1:0]               PCPlus4M,

    output logic                                RegWriteW,
    output logic  [1:0]                         ResultsrcW,
    output logic  [DATA_WIDTH-1:0]              ALUResultW,
    output logic  [DATA_WIDTH-1:0]              ReadDataW,
    output logic  [REGISTER_ADDRESS_WIDTH-1:0]  RdW,
    output logic  [DATA_WIDTH-1:0]              PCPlus4W
);

    logic                                   RegWrite_reg;
    logic  [1:0]                            Resultsrc_reg;
    logic  [DATA_WIDTH-1:0]                 ALUResult_reg;
    logic  [DATA_WIDTH-1:0]                 ReadData_reg;
    logic  [REGISTER_ADDRESS_WIDTH-1:0]     Rd_reg;
    logic  [DATA_WIDTH-1:0]                 PCPlus4_reg;

always_ff @(posedge clk) begin
    RegWrite_reg <= RegWriteM;
    Resultsrc_reg <= ResultsrcM;
    ALUResult_reg <= ALUResultM;
    ReadData_reg <= ReadDataM;
    Rd_reg <= RdM;
    PCPlus4_reg <= PCPlus4M;

    RegWriteW <= RegWrite_reg;
    ResultsrcW <= Resultsrc_reg;
    ALUResultW <= ALUResult_reg;
    ReadDataW <= ReadData_reg;
    RdW <= Rd_reg;
    PCPlus4W <= PCPlus4_reg;
end

endmodule