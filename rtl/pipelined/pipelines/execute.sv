module execute_reg_file #(
    parameter DATA_WIDTH = 32,
    REGISTER_ADDRESS_WIDTH = 5
)(
    input logic                         clk,
    input logic                         RegWriteD,
    input logic  [1:0]                  ResultsrcD,
    input logic                         MemWriteD,
    input logic                         JumpD,
    input logic                         BranchD,
    input logic  [2:0]                  ALUControlD,
    input logic                         ALUsrcD,
    input logic                         RD1D, 
    input logic                         RD2D,
    input logic                         PCD,
    input logic                         Rs1D,
    input logic                         Rs2D,
    input logic                         RdD,
    input logic                         ImmExtD,
    input logic                         PCPlus4D,   


    output logic                         RegWriteE,
    output logic  [1:0]                  ResultsrcE,
    output logic                         MemWriteE,
    output logic                         JumpE,
    output logic                         BranchE,
    output logic  [2:0]                  ALUControlE,
    output logic                         ALUsrcE,
    output logic                         RD1E, 
    output logic                         RD2E,
    output logic                         PCE,
    output logic                         Rs1E,
    output logic                         Rs2E,
    output logic                         RdE,
    output logic                         ImmExtE,
    output logic                         PCPlus4E, 
    

);

always_ff @(posedge clk) begin
    RegWriteE <= RegWriteD;
    ResultsrcE <= ResultsrcD;
    MemWriteE <= MemWriteD;
    JumpE <= JumpD;
    BranchE <= BranchD;
    ALUControlE <= ALUControlD;
    ALUsrcE <= ALUsrcD;
    RD1E <= RD1D;
    RD2E <= RD2D;
    PCE <= PCD;
    Rs1E <= Rs1D;
    Rs2E <= Rs2D;
    RdE <= RdD;
    ImmExtE <= ImmExtD;
    PCPlus4E <= PCPlus4D;
end

endmodule