// Top Level Component for Single Cycle Processor


`include "program_counter/pc_module.sv"
`include "program_counter/pc_reg.sv"
`include "data/alu_src_mux.sv"
`include "data/alu.sv"
`include "data/data_memory.sv"
`include "data/data_top_level.sv"
`include "data/register_file.sv"
`include "data/result_mux.sv"
`include "control/control_unit.sv"
`include "control/extend.sv"
`include "control/instruction_memory.sv"



module toplevel #(
    parameter WIDTH = 32
)(
    input logic                     clk,
    input logic                     rst,            
    output logic [WIDTH-1:0]        a0,              // measured output of program
    input logic                     trigger_val,     // inputs for F1 program
    input logic [WIDTH-1:0]         seed             // inputs for F1 program
);

logic   [WIDTH-1:0]                 sign_extend_immediate;      // sign extension to program counter, result mux and ALU
logic   [1:0]                       PCSrc;                      // control unit to program counter
logic   [WIDTH-1:0]                 register_data_1;            // register file in data top level to program counter
logic   [WIDTH-1:0]                 PC;                         // program counter to instruction memory
logic   [WIDTH-1:0]                 PC_plus_4;                  // program counter module to result mux
logic   [WIDTH-1:0]                 instruction;                // instruction memory to control unit, sign extension and register file
logic                               reg_write;                  // control unit to data memory
logic                               ALUsrc;                     // control unit to ALU 2nd operand mux
logic   [2:0]                       ALUctrl;                    // contorl unit to ALU
logic   [WIDTH-1:0]                 result_data;                // result mux to write data for register file
logic                               EQ;                         // ALU equals flag to control unit
logic   [WIDTH-1:0]                 ALU_result;                 // ALU result to data memory address and result MUX
logic   [WIDTH-1:0]                 write_data;                 // register data 2 to write data of data memory
logic   [1:0]                       result_src;                 // control unit result source to reuslt mux
logic                               mem_write;                  // control unit to memory write enable on data memory
logic   [2:0]                       imm_src;                    // control unit to sign extend
logic                               byte_addr;                  // control unit to data memory
logic   [WIDTH-1:0]                 read_data;                  // data memory read output to result mux

pc_module program_counter (
    .clk(clk),
    .rst(rst),
    .ImmOp(sign_extend_immediate),
    .PCSrc(PCSrc),
    .RegIn(register_data_1),
    .PC(PC),
    .PC_plus_4(PC_plus_4)
);

instruction_memory instruction_memory (
    .A(PC),
    .RD(instruction) 
);

data_top_level data (
    .clk(clk),
    .rs1(instruction[19:15]),
    .rs2(instruction[24:20]),
    .rd(instruction[11:7]),
    .RegWrite(reg_write),
    .ALUsrc(ALUsrc),
    .ALUctrl(ALUctrl),
    .ImmOp(sign_extend_immediate),
    .writeData(result_data),
    .EQ(EQ),
    .a0(a0),
    .ALUop1(register_data_1),
    .ALUout(ALU_result),
    .regOp2(write_data),
    .t0(trigger_val),   // inputs for F1 program
    .t4(seed)           // inputs for F1 program
);

control_unit control (
    .EQ(EQ),
    .instr(instruction),
    .PCSrc(PCSrc),
    .ResultSrc(result_src),
    .MemWrite(mem_write),
    .ALUctrl(ALUctrl),
    .ALUsrc(ALUsrc),
    .ImmSrc(imm_src),
    .RegWrite(reg_write),
    .ByteAddr(byte_addr)
);

extend sign_extend (
    .Immsrc(imm_src),
    .instr(instruction),
    .Immop(sign_extend_immediate)
);

data_memory data_memory (
    .clk(clk),
    .WE(mem_write),
    .A(ALU_result),
    .WD(write_data),
    .ByteAddr(byte_addr),
    .RD(read_data)
);

result_mux result_select (
    .result_src(result_src),
    .ALU_result(ALU_result),
    .read_data(read_data),
    .pc_plus_4(PC_plus_4),
    .immediate(sign_extend_immediate),
    .result(result_data)
);

endmodule
