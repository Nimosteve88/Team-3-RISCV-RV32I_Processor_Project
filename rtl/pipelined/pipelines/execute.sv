module execute #(
    parameter DATA_WIDTH = 32,
    parameter REGISTER_ADDRESS_WIDTH = 5
)(
    input logic                                 clk,
    input logic                                 CLR,

    input logic                                 RegWriteD,
    input logic  [1:0]                          ResultSrcD,
    input logic                                 MemWriteD,
    input logic                                 ByteAddrD,
    input logic  [1:0]                          JumpTypeD,
    input logic  [1:0]                          BranchTypeD,
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


    output logic                                RegWriteE,
    output logic  [1:0]                         ResultSrcE,
    output logic                                MemWriteE,
    output logic                                ByteAddrE,
    output logic  [1:0]                         JumpTypeE,
    output logic  [1:0]                         BranchTypeE,
    output logic  [2:0]                         ALUControlE,
    output logic                                ALUsrcE,
    output logic  [DATA_WIDTH-1:0]              RD1E, 
    output logic  [DATA_WIDTH-1:0]              RD2E,
    output logic  [DATA_WIDTH-1:0]              PCE,
    output logic  [REGISTER_ADDRESS_WIDTH-1:0]  Rs1E,
    output logic  [REGISTER_ADDRESS_WIDTH-1:0]  Rs2E,
    output logic  [REGISTER_ADDRESS_WIDTH-1:0]  RdE,
    output logic  [DATA_WIDTH-1:0]              ImmExtE,
    output logic  [DATA_WIDTH-1:0]              PCPlus4E
);

    logic                                       RegWrite_reg;
    logic  [1:0]                                ResultSrc_reg;
    logic                                       MemWrite_reg;
    logic                                       ByteAddr_reg;
    logic  [1:0]                                JumpType_reg;
    logic  [1:0]                                BranchType_reg;
    logic  [2:0]                                ALUControl_reg;
    logic                                       ALUsrc_reg;
    logic  [DATA_WIDTH-1:0]                     RD1_reg; 
    logic  [DATA_WIDTH-1:0]                     RD2_reg;
    logic  [DATA_WIDTH-1:0]                     PC_reg;
    logic  [REGISTER_ADDRESS_WIDTH-1:0]         Rs1_reg;
    logic  [REGISTER_ADDRESS_WIDTH-1:0]         Rs2_reg;
    logic  [REGISTER_ADDRESS_WIDTH-1:0]         Rd_reg;
    logic  [DATA_WIDTH-1:0]                     ImmExt_reg;
    logic  [DATA_WIDTH-1:0]                     PCPlus4_reg;

always_ff @(posedge clk) begin
    if (CLR) begin
        RegWrite_reg                            <= 1'b0;
        ResultSrc_reg                           <= 2'b0;
        MemWrite_reg                            <= 1'b0;
        ByteAddr_reg                            <= 1'b0;
        JumpType_reg                            <= 2'b0;
        BranchType_reg                          <= 2'b0;
        ALUControl_reg                          <= 3'b0;
        ALUsrc_reg                              <= 1'b0;
        RD1_reg                                 <= 32'b0; 
        RD2_reg                                 <= 32'b0;
        PC_reg                                  <= 32'b0;
        Rs1_reg                                 <= 5'b0;
        Rs2_reg                                 <= 5'b0;
        Rd_reg                                  <= 5'b0;
        ImmExt_reg                              <= 32'b0;
        PCPlus4_reg                             <= 32'b0;
    end
    else begin
        RegWrite_reg                            <= RegWriteD;
        ResultSrc_reg                           <= ResultSrcD;
        MemWrite_reg                            <= MemWriteD;
        ByteAddr_reg                            <= ByteAddrD;
        JumpType_reg                            <= JumpTypeD;
        BranchType_reg                          <= BranchTypeD;
        ALUControl_reg                          <= ALUControlD;
        ALUsrc_reg                              <= ALUsrcD;
        RD1_reg                                 <= RD1D; 
        RD2_reg                                 <= RD2D;
        PC_reg                                  <= PCD;
        Rs1_reg                                 <= Rs1D;
        Rs2_reg                                 <= Rs2D;
        Rd_reg                                  <= RdD;
        ImmExt_reg                              <= ImmExtD;
        PCPlus4_reg                             <= PCPlus4D;
    end   
end

    assign RegWriteE                            = RegWrite_reg;
    assign ResultSrcE                           = ResultSrc_reg;
    assign MemWriteE                            = MemWrite_reg;
    assign ByteAddrE                            = ByteAddr_reg;
    assign JumpTypeE                            = JumpType_reg;
    assign BranchTypeE                          = BranchType_reg;
    assign ALUControlE                          = ALUControl_reg;
    assign ALUsrcE                              = ALUsrc_reg;
    assign RD1E                                 = RD1_reg; 
    assign RD2E                                 = RD2_reg;
    assign PCE                                  = PC_reg;
    assign Rs1E                                 = Rs1_reg;
    assign Rs2E                                 = Rs2_reg;
    assign RdE                                  = Rd_reg;
    assign ImmExtE                              = ImmExt_reg;
    assign PCPlus4E                             = PCPlus4_reg;

endmodule
