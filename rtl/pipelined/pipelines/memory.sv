module memory #(
    parameter DATA_WIDTH = 32,
    parameter REGISTER_ADDRESS_WIDTH = 5
)(
    input logic                                 clk,

    input logic                                 RegWriteE,
    input logic  [1:0]                          ResultsrcE,
    input logic                                 MemWriteE,
    input logic  [DATA_WIDTH-1:0]               ALUResultE,
    input logic  [DATA_WIDTH-1:0]               WriteDataE,
    input logic  [REGISTER_ADDRESS_WIDTH-1:0]   RdE,
    input logic  [DATA_WIDTH-1:0]               PCPlus4E,

    output logic                                RegWriteM,
    output logic  [1:0]                         ResultsrcM,
    output logic                                MemWriteM,
    output logic  [DATA_WIDTH-1:0]              ALUResultM,
    output logic  [DATA_WIDTH-1:0]              WriteDataM,
    output logic  [REGISTER_ADDRESS_WIDTH-1:0]  RdM,
    output logic  [DATA_WIDTH-1:0]              PCPlus4M
);

    logic                                       RegWrite_reg;
    logic  [1:0]                                ResultsrcM_reg;
    logic                                       MemWriteM_reg;
    logic  [DATA_WIDTH-1:0]                     ALUResultM_reg;
    logic  [DATA_WIDTH-1:0]                     WriteDataM_reg;
    logic  [REGISTER_ADDRESS_WIDTH-1:0]         RdM_reg;
    logic  [DATA_WIDTH-1:0]                     PCPlus4_reg;

always_ff @(posedge clk) begin
    RegWrite_reg <= RegWriteE;
    Resultsrc_reg <= ResultsrcE;
    MemWrite_reg <= MemWriteE;
    ALUResult_reg <= ALUResultE;
    WriteData_reg <= WriteDataE;
    Rd_reg <= RdE;
    PCPlus4_reg <= PCPlus4E;

    RegWriteM <= RegWrite_reg;
    ResultsrcM <= Resultsrc_reg;
    MemWriteM <= MemWrite_reg;
    ALUResultM <= ALUResult_reg;
    WriteDataM <= WriteData_reg;
    RdM <= Rd_reg;
    PCPlus4M <= PCPlus4_reg;
end

endmodule