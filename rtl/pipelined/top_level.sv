//##################################################################//
//                        Include directives                        //
//##################################################################//
`include "control/control_unit_pipelined.sv"
`include "control/extend.sv"
`include "control/instruction_memory.sv"
`include "control/PCSrclogic.sv"
`include "data/alu_src_mux.sv"
`include "data/alu.sv"
`include "data/data_memory.sv"
`include "data/rd1emux.sv"
`include "data/rd2emux.sv"
`include "data/register_file.sv"
`include "data/result_mux.sv"
`include "pipelines/decode.sv"
`include "pipelines/execute.sv"
`include "pipelines/fetch.sv"
`include "pipelines/memory.sv"
`include "pipelines/pc_reg.sv"
`include "pipelines/write_back.sv"
`include "hazard.sv"

module top_level #(
    parameter DATA_WIDTH = 32,
    parameter REGISTER_ADDRESS_WIDTH = 5
)(
    input logic                     clk,
    input logic                     rst,            
    output logic [DATA_WIDTH-1:0]   a0,              // measured output of program
    input logic                     trigger_val,     // inputs for F1 program
    input logic [DATA_WIDTH-1:0]    seed             // inputs for F1 program
);

//##################################################################//
//                      Interconnecting logic                       //
//##################################################################//

logic                               stall_f;        // from hazard to EN of program counter
logic [DATA_WIDTH-1:0]              imm_ext_e;      // from execute register to program counter, alu_mux, and memory register
logic [1:0]                         pc_src_e;       // from pcsrclogic to program counter and hazard
logic [DATA_WIDTH-1:0]              src_a_e;        // from rd1e mux to ALU and program counter
logic [DATA_WIDTH-1:0]              pc_e;           // from execute register to program counter
logic [DATA_WIDTH-1:0]              pc_f;           // from program counter to decode register and instruction memory
logic [DATA_WIDTH-1:0]              pc_plus_4_f;    // from program counter to decode register
logic [DATA_WIDTH-1:0]              instr_f;        // from instruction memory to decode register
logic                               stall_d;        // from hazard to decode register
logic                               flush_d;        // from hazard to decode register
logic [DATA_WIDTH-1:0]              pc_d;           // from decode register to execute register
logic [DATA_WIDTH-1:0]              pc_plus_4_d;    // from decode register to execute register
logic [DATA_WIDTH-1:0]              instr_d;        // from decode register to control unit, register file, extend and execute register
logic [2:0]                         imm_src_d;      // from control unit to sign extend
logic [DATA_WIDTH-1:0]              imm_ext_d;      // from sign extend to execute register
logic [1:0]                         result_src_d;   // from control unit to execute register
logic                               mem_write_d;    // ''
logic [2:0]                         alu_ctrl_d;     // ''
logic                               alu_src_d;      // ''
logic                               reg_write_d;    // ''
logic                               byte_addr_d;    // ''
logic [1:0]                         jump_type_d;    // ''
logic [1:0]                         branch_type_d;  // ''
logic [REGISTER_ADDRESS_WIDTH-1:0]  rd_w;           // from write_back register to register file and hazard
logic                               reg_write_w;    // ''
logic [DATA_WIDTH-1:0]              result_w;       // from result mux to register file, rd1emux and rd2emux
logic [DATA_WIDTH-1:0]              rd1_d;          // from register file to execute register
logic [DATA_WIDTH-1:0]              rd2_d;          // ''    
logic                               flush_e;        // from hazard to execute register
logic                               reg_write_e;    // from execute register to memory register
logic                               mem_write_e;    // ''
logic                               byte_addr_e;    // ''
logic [1:0]                         result_src_e;   // from execute register to memory register and hazard
logic [1:0]                         jump_type_e;    // from execute register to pc src logic
logic [1:0]                         branch_type_e;  // ''
logic [2:0]                         alu_ctrl_e;     // from execute register to alu
logic                               alu_src_e;      // from execure register to alu mux
logic [DATA_WIDTH-1:0]              rd1_e;          // from execute register to rd1emux and program counter
logic [DATA_WIDTH-1:0]              rd2_e;          // from execute register to rd2emux
logic [REGISTER_ADDRESS_WIDTH-1:0]  rs1_e;          // from execute register to hazard
logic [REGISTER_ADDRESS_WIDTH-1:0]  rs2_e;          // ''
logic [REGISTER_ADDRESS_WIDTH-1:0]  rd_e;           // from execute register to hazard and memory register
logic [DATA_WIDTH-1:0]              pc_plus_4_e;    // from execute register to memory register
logic [DATA_WIDTH-1:0]              alu_result_m;   // from memory register to rd1emux and rd2emux and write back register and data memory
logic [1:0]                         forward_ae;     // from hazard to rd1emux
logic [1:0]                         forward_be;     // from hazard to rd2emux 
logic [DATA_WIDTH-1:0]              rd2e_out;       // from rd2emux to alu mux and memory register
logic [DATA_WIDTH-1:0]              src_b_e;        // from alu mux to alu
logic [DATA_WIDTH-1:0]              alu_result_e;   // from alu to memory register
logic                               eq_flag;        // from alu to pc src logic
logic                               reg_write_m;    // from memory register to hazard and write back register
logic [1:0]                         result_src_m;   // from memory register to write back register
logic                               mem_write_m;    // from memory register to data memory
logic                               byte_addr_m;    // ''
logic [DATA_WIDTH-1:0]              write_data_m;   // ''
logic [DATA_WIDTH-1:0]              imm_ext_m;      // from memory register to write back register
logic [REGISTER_ADDRESS_WIDTH-1:0]  rd_m;           // from memory register to write back register and hazard
logic [DATA_WIDTH-1:0]              pc_plus_4_m;    // from memory register to write back register
logic [DATA_WIDTH-1:0]              read_data_m;    // from data memory to write back register
logic [1:0]                         result_src_w;   // from write back register to result mux
logic [DATA_WIDTH-1:0]              alu_result_w;   // ''
logic [DATA_WIDTH-1:0]              imm_ext_w;      // ''
logic [DATA_WIDTH-1:0]              read_data_w;    // ''
logic [DATA_WIDTH-1:0]              pc_plus_4_w;    // ''





//##################################################################//
//                           Stage: Fetch                           //
//##################################################################//

fetch program_counter (
    .clk(clk),
    .rst(rst),
    .en(~(stall_f)),
    .ImmExtE(imm_ext_e),
    .PCSrcE(pc_src_e),
    .SrcAE(rd1_e),
    .PCE(pc_e),
    .PCF(pc_f),
    .PCPlus4F(pc_plus_4_f)
);



instruction_memory instruction_mem (
    .A(pc_f),
    .RD(instr_f)
);





//##################################################################//
//                          Stage: Decode                           //
//##################################################################//

decode decode_pipeline_register (
    .clk(clk),
    .EN(~(stall_d)),
    .CLR(flush_d),
    .InstrDi(instr_f),
    .PCF(pc_f),
    .PC_plus_4F(pc_plus_4_f),
    .PCD(pc_d),
    .PC_plus_4D(pc_plus_4_d),
    .InstrDo(instr_d)
);



extend sign_extension_unit (
    .Immsrc(imm_src_d),
    .instr(instr_d),
    .Immop(imm_ext_d)
);



control_unit_pipelined control_unit (
    .instr(instr_d),
    .ResultSrc(result_src_d),
    .MemWrite(mem_write_d),
    .ALUctrl(alu_ctrl_d),
    .ALUsrc(alu_src_d),
    .ImmSrc(imm_src_d),
    .RegWrite(reg_write_d),
    .ByteAddr(byte_addr_d),
    .JumpType(jump_type_d),
    .BranchType(branch_type_d)
);



register_file reg_file (
    .AD1(instr_d[19:15]),
    .AD2(instr_d[24:20]),
    .AD3(rd_w),
    .WE3(reg_write_w),
    .WD3(result_w),
    .clk(clk),
    .RD1(rd1_d),
    .RD2(rd2_d),
    .a0(a0),
    .t4(seed),
    .t0(trigger_val)
);





//##################################################################//
//                          Stage: Execute                          //
//##################################################################//

execute execute_pipeline_register (
    .clk(clk),
    .CLR(flush_e),
    .RegWriteD(reg_write_d),
    .ResultSrcD(result_src_d),
    .MemWriteD(mem_write_d),
    .ByteAddrD(byte_addr_d),
    .JumpTypeD(jump_type_d),
    .BranchTypeD(branch_type_d),
    .ALUControlD(alu_ctrl_d),
    .ALUsrcD(alu_src_d),
    .RD1D(rd1_d),
    .RD2D(rd2_d),
    .PCD(pc_d),
    .Rs1D(instr_d[19:15]),
    .Rs2D(instr_d[24:20]),
    .RdD(instr_d[11:7]),
    .ImmExtD(imm_ext_d),
    .PCPlus4D(pc_plus_4_d),
    .RegWriteE(reg_write_e),
    .ResultSrcE(result_src_e),
    .MemWriteE(mem_write_e),
    .ByteAddrE(byte_addr_e),
    .JumpTypeE(jump_type_e),
    .BranchTypeE(branch_type_e),
    .ALUControlE(alu_ctrl_e),
    .ALUsrcE(alu_src_e),
    .RD1E(rd1_e),
    .RD2E(rd2_e),
    .PCE(pc_e),
    .Rs1E(rs1_e),
    .Rs2E(rs2_e),
    .RdE(rd_e),
    .ImmExtE(imm_ext_e),
    .PCPlus4E(pc_plus_4_e)
);



rd1emux RD1E_mux (
    .RD1E(rd1_e),
    .WD3(result_w),
    .ALUResult(alu_result_m),
    .ForwardAE(forward_ae),
    .SrcAE(src_a_e)
);



rd2emux RD2E_mux (
    .RD2E(rd2_e),
    .WD3(result_w),
    .ALUResult(alu_result_m),
    .ForwardBE(forward_be),
    .SrcBE(rd2e_out)
);



alu_src_mux ALU_mux (
    .d0(rd2e_out),
    .d1(imm_ext_e),
    .ALUsrc(alu_src_e),
    .y(src_b_e)
);



alu ALU (
    .SrcAE(src_a_e),
    .SrcBE(src_b_e),
    .ALUcontrolE(alu_ctrl_e),
    .ALUResult(alu_result_e),
    .EQ(eq_flag)
);



PCSrclogic pc_src_logic (
    .EQ(eq_flag),
    .JumpTypeE(jump_type_e),
    .BranchTypeE(branch_type_e),
    .PCSrcE(pc_src_e)
);





//##################################################################//
//                          Stage: Memory                           //
//##################################################################//

memory memory_pipeline_register (
    .clk(clk),
    .RegWriteE(reg_write_e),
    .ResultsrcE(result_src_e),
    .MemWriteE(mem_write_e),
    .ByteAddrE(byte_addr_e),
    .ALUResultE(alu_result_e),
    .WriteDataE(rd2e_out),
    .ImmExtE(imm_ext_e),
    .RdE(rd_e),
    .PCPlus4E(pc_plus_4_e),
    .RegWriteM(reg_write_m),
    .ResultsrcM(result_src_m),
    .MemWriteM(mem_write_m),
    .ByteAddrM(byte_addr_m),
    .ALUResultM(alu_result_m),
    .WriteDataM(write_data_m),
    .ImmExtM(imm_ext_m),
    .RdM(rd_m),
    .PCPlus4M(pc_plus_4_m)
);



data_memory data_mem (
    .clk(clk),
    .WE(mem_write_m),
    .A(alu_result_m),
    .WD(write_data_m),
    .ByteAddr(byte_addr_m),
    .RD(read_data_m)
);





//##################################################################//
//                        Stage: Write Back                         //
//##################################################################//

write_back write_back_pipeline_register (
    .clk(clk),
    .RegWriteM(reg_write_m),
    .ResultSrcM(result_src_m),
    .ALUResultM(alu_result_m),
    .ReadDataM(read_data_m),
    .ImmExtM(imm_ext_m),
    .RdM(rd_m),
    .PCPlus4M(pc_plus_4_m),
    .RegWriteW(reg_write_w),
    .ResultsrcW(result_src_w),
    .ALUResultW(alu_result_w),
    .ReadDataW(read_data_w),
    .ImmExtW(imm_ext_w),
    .RdW(rd_w),
    .PCPlus4W(pc_plus_4_w)
);



result_mux result_data (
    .result_src(result_src_w),
    .ALU_result(alu_result_w),
    .read_data(read_data_w),
    .pc_plus_4(pc_plus_4_w),
    .immediate(imm_ext_w),
    .result(result_w)
);




//##################################################################//
//                           Hazard Unit                            //
//##################################################################//

hazard hazard_unit (
    .StallF(stall_f),
    .StallD(stall_d),
    .FlushD(flush_d),
    .Rs1D(instr_d[19:15]),
    .Rs2D(instr_d[24:20]),
    .FlushE(flush_e),
    .RdE(rd_e),
    .Rs1E(rs1_e),
    .Rs2E(rs2_e),
    .ForwardAE(forward_ae),
    .ForwardBE(forward_be),
    .ResultSrcE(result_src_e),
    .PCSrcE(pc_src_e),
    .RdM(rd_m),
    .RegWriteM(reg_write_m),
    .RdW(rd_w),
    .RegWriteW(reg_write_w)
);



endmodule
