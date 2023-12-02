/*
Five main sub components: 
1. "program_counter" : Program Counter and related adders.
2, 3, 4. control_module : The Control Unit, the Sign-extension Unit and the instruction memory.
    2. "control_unit"
    3. "instruction_memory"
    4. "sign_extend"
5. "alu_and_registers" : The Register File, ALU and the related MUX.
*/ 


module toplevel #(
    parameter WIDTH = 32
)(
    input logic                     clk,
    input logic                     rst,            
    output logic [WIDTH-1:0]        a0              // measured output of program
);

// inerconnecting signals
logic [WIDTH-1:0]                   PC;             // from pc_module to control_module)
logic [WIDTH-1:0]                   instr;          // output of the instruction memory - the instruction
logic [WIDTH-1:0]                   ImmOp;          // from control_module to alu_module and from control_module to pc_module
logic                               ImmSrc;         // From control unit to Sign Extend
//unused logic [4:0]                         rs1;            // from control_module to alu_module
//unused logic [4:0]                         rs2;            // from control_module to alu_module
//unused logic [4:0]                         rd;             // from control_module to alu_module
logic                               RegWrite;       // from control_module to alu_module
logic [2:0]                         ALUctrl;        // from control_module to alu_module
logic                               ALUsrc;         // from control_module to alu_module
logic                               PCsrc;          // from control_module to pc_module
logic                               EQ;             // from alu_module to control_module
logic [WIDTH-1:0]                   ALUop1;         // from data_module to pc_module

pc_module program_counter(
    .clk(clk),
    .rst(rst),
    .ImmOp (ImmOp),
    .PCsrc (PCsrc),
    .RegIn (ALUop1),
    .PC (PC)
);


instrmem instruction_memory(
    .A(PC),
    .RD(instr)
);


controlunit control_unit(
    .EQ(EQ),
    .opcode(instr[6:0]),
    .RegWrite(RegWrite),
    .ALUctrl(ALUctrl),
    .ALUsrc(ALUsrc),
    .ImmSrc(ImmSrc),
    .PCSrc(PCsrc)
);


signextend sign_extend(
    .Immsrc(ImmSrc),
    .instr(instr),
    .Immop(ImmOp)
);


data_top_level alu_and_registers(
    .clk(clk),
    .rs1 (instr[19:15]),
    .rs2 (instr[24:20]),
    .rd (instr[11:7]),
    .RegWrite (RegWrite),
    .ALUctrl(ALUctrl),
    .ALUsrc (ALUsrc),
    .ImmOp (ImmOp),
    .EQ (EQ),
    .ALUop1 (ALUop1);
    .a0(a0)
);

endmodule
