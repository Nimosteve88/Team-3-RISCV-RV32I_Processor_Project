module memory #(
    parameter DATA_WIDTH = 32,
    parameter REGISTER_ADDRESS_WIDTH = 5
)(
    input logic                                 clk,

    input logic                                 RegWriteE,
    input logic  [1:0]                          ResultsrcE,
    input logic                                 MemWriteE,
    input logic                                 ByteAddrE,
    input logic  [DATA_WIDTH-1:0]               ALUResultE,
    input logic  [DATA_WIDTH-1:0]               WriteDataE,
    input logic  [DATA_WIDTH-1:0]               ImmExtE,
    input logic  [REGISTER_ADDRESS_WIDTH-1:0]   RdE,
    input logic  [DATA_WIDTH-1:0]               PCPlus4E,

    output logic                                RegWriteM,
    output logic  [1:0]                         ResultsrcM,
    output logic                                MemWriteM,
    output logic                                ByteAddrM,
    output logic  [DATA_WIDTH-1:0]              ALUResultM,
    output logic  [DATA_WIDTH-1:0]              WriteDataM,
    output logic  [DATA_WIDTH-1:0]              ImmExtM,
    output logic  [REGISTER_ADDRESS_WIDTH-1:0]  RdM,
    output logic  [DATA_WIDTH-1:0]              PCPlus4M
);

    logic                                       RegWriteM_reg;
    logic  [1:0]                                ResultsrcM_reg;
    logic                                       MemWriteM_reg;
    logic                                       ByteAddrM_reg;
    logic  [DATA_WIDTH-1:0]                     ALUResultM_reg;
    logic  [DATA_WIDTH-1:0]                     WriteDataM_reg;
    logic  [DATA_WIDTH-1:0]                     ImmExtM_reg;
    logic  [REGISTER_ADDRESS_WIDTH-1:0]         RdM_reg;
    logic  [DATA_WIDTH-1:0]                     PCPlus4M_reg;

    always_ff @(posedge clk) begin
        RegWriteM_reg                           <= RegWriteE;
        ResultsrcM_reg                          <= ResultsrcE;
        MemWriteM_reg                           <= MemWriteE;
        ByteAddrM_reg                           <= ByteAddrE;
        ALUResultM_reg                          <= ALUResultE;
        WriteDataM_reg                          <= WriteDataE;
        ImmExtM_reg                             <= ImmExtE;
        RdM_reg                                 <= RdE;
        PCPlus4M_reg                            <= PCPlus4E;
    end

    assign RegWriteM                             = RegWriteM_reg;
    assign ResultsrcM                            = ResultsrcM_reg;
    assign MemWriteM                             = MemWriteM_reg;
    assign ByteAddrM                             = ByteAddrM_reg;
    assign ALUResultM                            = ALUResultM_reg;
    assign WriteDataM                            = WriteDataM_reg;
    assign ImmExtM                               = ImmExtM_reg;
    assign RdM                                   = RdM_reg;
    assign PCPlus4M                              = PCPlus4M_reg;

endmodule
