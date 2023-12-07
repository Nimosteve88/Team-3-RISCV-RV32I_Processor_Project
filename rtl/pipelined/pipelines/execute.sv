module execute #(
    parameter DATA_WIDTH = 32,
    parameter REGISTER_ADDRESS_WIDTH = 5
)(
    input logic                                 clk,
    input logic                                 CLR,

    input logic                                 RegWriteD,
    input logic  [1:0]                          ResultSrcD,
    input logic                                 MemWriteD,
    input logic                                 JumpD,
    input logic                                 BranchD,
    input logic  [2:0]                          ALUControlD,
    input logic                                 ALUsrcD,
    input logic  [DATA_WIDTH-1:0]               RD1D, 
    input logic  [DATA_WIDTH-1:0]               RD2D,
    input logic  [DATA_WIDTH-1:0]               PCD,
    input logic  [REGISTER_ADDRESS_WIDTH-1:0]   Rs1D,
    input logic  [REGISTER_ADDRESS_WIDTH-1:0]   Rs2D,
    input logic  [REGISTER_ADDRESS_WIDTH-1:0]   RdD,
    input logic  [DATA_WIDTH-1:0]               ImmExtD,
    input logic  [DATA_WIDTH-1:0]               PCPlus4D,   


    output logic                                 RegWriteE,
    output logic  [1:0]                          ResultSrcE,
    output logic                                 MemWriteE,
    output logic                                 JumpE,
    output logic                                 BranchE,
    output logic  [2:0]                          ALUControlE,
    output logic                                 ALUsrcE,
    output logic  [DATA_WIDTH-1:0]               RD1E, 
    output logic  [DATA_WIDTH-1:0]               RD2E,
    output logic  [DATA_WIDTH-1:0]               PCE,
    output logic  [REGISTER_ADDRESS_WIDTH-1:0]   Rs1E,
    output logic  [REGISTER_ADDRESS_WIDTH-1:0]   Rs2E,
    output logic  [REGISTER_ADDRESS_WIDTH-1:0]   RdE,
    output logic  [DATA_WIDTH-1:0]               ImmExtE,
    output logic  [DATA_WIDTH-1:0]               PCPlus4E
);

    logic                                 RegWrite_reg;
    logic  [1:0]                          ResultSrc_reg;
    logic                                 MemWrite_reg;
    logic                                 Jump_reg;
    logic                                 Branch_reg;
    logic  [2:0]                          ALUControl_reg;
    logic                                 ALUsrc_reg;
    logic  [DATA_WIDTH-1:0]               RD1_reg; 
    logic  [DATA_WIDTH-1:0]               RD2_reg;
    logic  [DATA_WIDTH-1:0]               PC_reg;
    logic  [REGISTER_ADDRESS_WIDTH-1:0]   Rs1_reg;
    logic  [REGISTER_ADDRESS_WIDTH-1:0]   Rs2_reg;
    logic  [REGISTER_ADDRESS_WIDTH-1:0]   Rd_reg;
    logic  [DATA_WIDTH-1:0]               ImmExt_reg;
    logic  [DATA_WIDTH-1:0]               PCPlus4_reg;

always_ff @(posedge clk) begin
    if (CLR) begin
        RegWrite_reg <= 1'b0;
        ResultSrc_reg <= 1'b0;
        MemWrite_reg <= 1'b0;
        Jump_reg <= 1'b0;
        Branch_reg <= 1'b0;
        ALUControl_reg <= 3'b0;
        ALUsrc_reg <= 1'b0;
        RD1_reg <= DATA_WIDTH'b0; 
        RD2_reg <= DATA_WIDTH'b0;
        PC_reg <= DATA_WIDTH'b0;
        Rs1_reg <= REGISTER_ADDRESS_WIDTH'b0;
        Rs2_reg <= REGISTER_ADDRESS_WIDTH'b0;
        Rd_reg <= REGISTER_ADDRESS_WIDTH'b0;
        ImmExt_reg <= DATA_WIDTH'b0;
        PCPlus4_reg <= DATA_WIDTH'b0;
    end
    else if (EN == 1'd1) begin
        RegWrite_reg <= RegWriteD;
        ResultSrc_reg <= ResultSrcD;
        MemWrite_reg <= MemWriteD;
        Jump_reg <= JumpD;
        Branch_reg <= BranchD;
        ALUControl_reg <= ALUControlD;
        ALUsrc_reg <= ALUsrcD;
        RD1_reg <= RD1D; 
        RD2_reg <= RD2D;
        PC_reg <= PCD;
        Rs1_reg <= Rs1D;
        Rs2_reg <= Rs2D;
        Rd_reg <= RdD;
        ImmExt_reg <= ImmExtD;
        PCPlus4_reg <= PCPlus4D;

        RegWriteE <= RegWrite_reg;
        ResultSrcE <= ResultSrc_reg;
        MemWriteE <= MemWrite_reg;
        JumpE <= Jump_reg;
        BranchE <= Branch_reg;
        ALUControlE <= ALUControl_reg;
        ALUsrcE <= ALUsrc_reg;
        RD1E <= RD1_reg; 
        RD2E <= RD2_reg;
        PCE <= PC_reg;
        Rs1E <= Rs1_reg;
        Rs2E <= Rs2_reg;
        RdE <= Rd_reg;
        ImmExtE <= ImmExt_reg;
        PCPlus4E <= PCPlus4_reg;
    end
end

endmodule