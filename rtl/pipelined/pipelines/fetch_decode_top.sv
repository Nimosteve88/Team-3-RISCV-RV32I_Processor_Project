`include "decode.sv"
`include "fetch.sv"

module fetch_decode_top #(

  // Parameters
  parameter WIDTH = 32,
  parameter DATA_WIDTH = 32
)(
  // Clock and reset signals
  input logic clk,
  input logic rst,

  // Inputs and outputs for fetch module
  input logic en_fetch,
  input logic [WIDTH-1:0] ImmExtE,
  input logic [1:0] PCSrcE,
  input logic [WIDTH-1:0] SrcAE,
  input logic [WIDTH-1:0] PCE,
  output logic [WIDTH-1:0] PCF,
  output logic [WIDTH-1:0] PCPlus4F,

  // Inputs and outputs for decode module
  input logic en_decode,
  input logic CLR_decode,
  input logic [DATA_WIDTH-1:0] InstrDi,
  output logic [DATA_WIDTH-1:0] PCD,
  output logic [DATA_WIDTH-1:0] PC_plus_4D,
  output logic [DATA_WIDTH-1:0] InstrDo
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

endmodule
