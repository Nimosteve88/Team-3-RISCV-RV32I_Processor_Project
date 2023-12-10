`include "decode.sv"
`include "fetch.sv"
`include "execute.sv"

module fetch_decode_top #(

  // Parameters
  parameter WIDTH = 32,
  parameter DATA_WIDTH = 32,
  parameter REGISTER_ADDRESS_WIDTH = 5
)(
  // Clock and reset signals
  input logic clk,
  input logic rst,

  // Inputs and outputs for fetch module
  input logic en_fetch,
  output logic [WIDTH-1:0] ImmExtE,
  input logic [1:0] PCSrcE,
  input logic [WIDTH-1:0] SrcAE,
  output logic [WIDTH-1:0] PCF,
  output logic [WIDTH-1:0] PCPlus4F,

  // Inputs and outputs for decode module
  input logic en_decode,
  input logic CLR_decode,
  input logic [DATA_WIDTH-1:0] InstrDi,
  output logic [DATA_WIDTH-1:0] PCD,
  output logic [DATA_WIDTH-1:0] PC_plus_4D,
  output logic [DATA_WIDTH-1:0] InstrDo,

  // Inputs and outputs for execute module
  input logic                                 CLR_execute,
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
  input logic  [REGISTER_ADDRESS_WIDTH-1:0]   Rs1D,
  input logic  [REGISTER_ADDRESS_WIDTH-1:0]   Rs2D,
  input logic  [REGISTER_ADDRESS_WIDTH-1:0]   RdD,
  input logic  [DATA_WIDTH-1:0]               ImmExtD,
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
  output logic  [DATA_WIDTH-1:0]              PCPlus4E
);

  // Instantiate fetch module
  fetch fetch_inst (
    .clk(clk),
    .rst(rst),
    .en(en_fetch),
    .ImmExtE(ImmExtE),
    .PCSrcE(PCSrcE),
    .SrcAE(SrcAE),
    .PCE(PCE),
    .PCF(PCF),
    .PCPlus4F(PCPlus4F)
  );

  // Instantiate decode module
  decode decode_inst (
    .clk(clk),
    .EN(en_decode),
    .CLR(CLR_decode),
    .InstrDi(InstrDi),
    .PCF(PCF),
    .PC_plus_4F(PCPlus4F),
    .PCD(PCD),
    .PC_plus_4D(PC_plus_4D),
    .InstrDo(InstrDo)
  );

execute execute_inst (
        .clk(clk),                // Connect these to your top-level signals
        .CLR(CLR_execute),
        .RegWriteD(RegWriteD),
        .ResultSrcD(ResultSrcD),
        .MemWriteD(MemWriteD),
        .ByteAddrD(ByteAddrD),
        .JumpTypeD(JumpTypeD),
        .BranchTypeD(BranchTypeD),
        .ALUControlD(ALUControlD),
        .ALUsrcD(ALUsrcD),
        .RD1D(RD1D),
        .RD2D(RD2D),
        .PCD(PCD),
        .Rs1D(Rs1D),
        .Rs2D(Rs2D),
        .RdD(RdD),
        .ImmExtD(ImmExtD),
        .PCPlus4D(PC_plus_4D),
        .RegWriteE(RegWriteE),    // Connect these to your top-level signals
        .ResultSrcE(ResultSrcE),
        .MemWriteE(MemWriteE),
        .ByteAddrE(ByteAddrE),
        .JumpTypeE(JumpTypeE),
        .BranchTypeE(BranchTypeE),
        .ALUControlE(ALUControlE),
        .ALUsrcE(ALUsrcE),
        .RD1E(RD1E),
        .RD2E(RD2E),
        .PCE(PCE),
        .Rs1E(Rs1E),
        .Rs2E(Rs2E),
        .RdE(RdE),
        .ImmExtE(ImmExtE),
        .PCPlus4E(PCPlus4E)
    );

endmodule
