module write_back #(
    parameter DATA_WIDTH = 32,
    parameter REGISTER_ADDRESS_WIDTH = 5
)(
    input logic                                 clk,

    input logic                                 RegWriteM,
    input logic  [1:0]                          ResultSrcM,
    input logic  [DATA_WIDTH-1:0]               ALUResultM,
    input logic  [DATA_WIDTH-1:0]               ReadDataM,
    input logic  [DATA_WIDTH-1:0]               ImmExtM,
    input logic  [REGISTER_ADDRESS_WIDTH-1:0]   RdM,
    input logic  [DATA_WIDTH-1:0]               PCPlus4M,

    output logic                                RegWriteW,
    output logic  [1:0]                         ResultsrcW,
    output logic  [DATA_WIDTH-1:0]              ALUResultW,
    output logic  [DATA_WIDTH-1:0]              ReadDataW,
    output logic  [DATA_WIDTH-1:0]              ImmExtW,
    output logic  [REGISTER_ADDRESS_WIDTH-1:0]  RdW,
    output logic  [DATA_WIDTH-1:0]              PCPlus4W
);

    logic                                       RegWrite_reg;
    logic  [1:0]                                Resultsrc_reg;
    logic  [DATA_WIDTH-1:0]                     ALUResult_reg;
    logic  [DATA_WIDTH-1:0]                     ReadData_reg;
    logic  [DATA_WIDTH-1:0]                     ImmExt_reg;
    logic  [REGISTER_ADDRESS_WIDTH-1:0]         Rd_reg;
    logic  [DATA_WIDTH-1:0]                     PCPlus4_reg;

    always_ff @(posedge clk) begin
        RegWrite_reg                            <= RegWriteM;
        Resultsrc_reg                           <= ResultSrcM;
        ALUResult_reg                           <= ALUResultM;
        ReadData_reg                            <= ReadDataM;
        ImmExt_reg                              <= ImmExtM;
        Rd_reg                                  <= RdM;
        PCPlus4_reg                             <= PCPlus4M;
    end

    assign RegWriteW                            = RegWrite_reg;
    assign ResultsrcW                           = Resultsrc_reg;
    assign ALUResultW                           = ALUResult_reg;
    assign ReadDataW                            = ReadData_reg;
    assign ImmExtW                              = ImmExt_reg;
    assign RdW                                  = Rd_reg;
    assign PCPlus4W                             = PCPlus4_reg;

endmodule
