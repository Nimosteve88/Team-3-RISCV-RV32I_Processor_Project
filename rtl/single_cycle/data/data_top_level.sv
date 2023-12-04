module data_top_level #(
    parameter REGWIDTH = 5,
    parameter DATAWIDTH = 32
)(
    input logic                     clk,
    input logic  [REGWIDTH-1:0]     rs1,
    input logic  [REGWIDTH-1:0]     rs2,
    input logic  [REGWIDTH-1:0]     rd,
    input logic                     RegWrite,
    input logic                     ALUsrc,
    input logic  [2:0]              ALUctrl,
    input logic  [DATAWIDTH-1:0]    ImmOp,
    input logic  [DATAWIDTH-1:0]    writeData,
    output logic                    EQ,
    output logic [DATAWIDTH-1:0]    a0,
    output logic [DATAWIDTH-1:0]    ALUop1, // used exclusively for jalr
    output logic [DATAWIDTH-1:0]    ALUout,
    output logic [DATAWIDTH-1:0]    regOp2
);

logic [DATAWIDTH-1:0]               ALUop2;

regfile register(
    .AD1(rs1),
    .AD2(rs2),
    .AD3(rd),
    .WE3(RegWrite),
    .WD3(writeData),
    .clk(clk),
    .RD1(ALUop1),
    .RD2(regOp2),
    .a0(a0)
);

alu_src_mux multi(
    .d0 (regOp2),
    .d1 (ImmOp),
    .ALUsrc (ALUsrc),
    .y (ALUop2)
);

alu ALU(
    .ALUop1 (ALUop1),
    .ALUop2 (ALUop2),
    .ALUctrl (ALUctrl),
    .SUM (ALUout),
    .EQ (EQ)
);

endmodule
