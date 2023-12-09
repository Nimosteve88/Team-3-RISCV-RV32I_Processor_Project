//##################################################################//
//                        Include directives                        //
//##################################################################//
`include "control/countrol_unit_pipelined.sv"
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
    output logic [WIDTH-1:0]        a0,              // measured output of program
    input logic                     trigger_val,     // inputs for F1 program
    input logic [WIDTH-1:0]         seed             // inputs for F1 program
);

//##################################################################//
//                      Interconnecting logic                       //
//##################################################################//



//##################################################################//
//                           Stage: Fetch                           //
//##################################################################//

fetch program_counter (
    .clk(),
    .rst(),
    .en(),
    .ImmExtE(),
    .PCSrcE(),
    .SrcAE(),
    .PCE(),
    .PCF(),
    .PCPlus4F()
)



instruction_memory instruction_mem (
    .A(),
    .RD()
)





//##################################################################//
//                          Stage: Decode                           //
//##################################################################//

decode decode_pipeline_register (
    .clk(),
    .EN(),
    .CLR(),
    .InstrDi(),
    .PCF(),
    .PC_plus_4F(),
    .PCD(),
    .PC_plus_4D(),
    .InstrDo()
)



extend sign_extension_unit (
    .Immsrc(),
    .instr(),
    .Immop()
)



control_unit_pipelined control_unit (
    .instr(),
    .ResultSrc(),
    .MemWrite(),
    .ALUctrl(),
    .ALUsrc(),
    .ImmSrc(),
    .RegWrite(),
    .ByteAddr(),
    .JumpType(),
    .BranchType()
)



register_file registers (
    .AD1(),
    .AD2(),
    .AD3(),
    .WE3(),
    .WD3(),
    .clk(),
    .RD1(),
    .RD2(),
    .a0(),
    .t4(),
    .t0()
)





//##################################################################//
//                          Stage: Execute                          //
//##################################################################//

execute execute_pipeline_register (
    .clk(),
    .CLR(),
    .RegWriteD(),
    .ResultSrcD(),
    .MemWriteD(),
    .ByteAddrD(),
    .JumpTypeD(),
    .BranchTypeD(),
    .ALUControlD(),
    .ALUsrcD(),
    .RD1D(),
    .RD2D(),
    .PCD(),
    .Rs1D(),
    .Rs2D(),
    .RdD(),
    .ImmExtD(),
    .PCPlus4D(),
    .RegWriteE(),
    .ResultSrcE(),
    .MemWriteE(),
    .ByteAddrE(),
    .JumpTypeE(),
    .BranchTypeE(),
    .ALUControlE(),
    .ALUsrcE(),
    .RD1E(),
    .RD2E(),
    .PCE(),
    .Rs1E(),
    .Rs2E(),
    .RdE(),
    .ImmExtE(),
    .PCPlus4E()
)



rd1emux RD1E_mux (
    .RD1E(),
    .WD3(),
    .ALUResult(),
    .ForwardAE(),
    .SrcAE()
)



rd2emux RD2E_mux (
    .RD2E(),
    .WD3(),
    .ALUResult(),
    .ForwardBE(),
    .SrcBE()
)



alu_src_mux ALU_mux (
    .d0(),
    .d1(),
    .ALUsrc(),
    .y()
)



alu ALU (
    .SrcAE(),
    .SrcBE(),
    .ALUcontrolE(),
    .ALUResult(),
    .EQ()
)



PCSrclogic pc_src_logic (
    .EQ(),
    .JumpTypeE(),
    .BranchTypeE(),
    .PCSrcE()
) 





//##################################################################//
//                          Stage: Memory                           //
//##################################################################//

memory memory_pipeline_register (
    .clk(),
    .RegWriteE(),
    .ResultsrcE(),
    .MemWriteE(),
    .ByteAddrE(),
    .ALUResultE(),
    .WriteDataE(),
    .ImmExtE(),
    .RdE(),
    .PCPlus4E(),
    .RegWriteM(),
    .ResultsrcM(),
    .MemWriteM(),
    .ByteAddrM(),
    .ALUResultM(),
    .WriteDataM(),
    .ImmExtM(),
    .RdM(),
    .PCPlus4M()
)



data_memory data_mem (
    .clk(),
    .WE(),
    .A(),
    .WD(),
    .ByteAddr(),
    .RD()
)





//##################################################################//
//                        Stage: Write Back                         //
//##################################################################//

write_back write_back_pipeline_register (
    .clk(),
    .RegWriteM(),
    .ResultSrcM(),
    .ALUResultM(),
    .ReadDataM(),
    .ImmExtM(),
    .RdM(),
    .PCPlus4M(),
    .RegWriteW(),
    .ResultsrcW(),
    .ALUResultW(),
    .ReadDataW(),
    .ImmExtW(),
    .RdW(),
    .PCPlus4W()
)



result_mux result_data (
    .result_src(),
    .ALU_result(),
    .read_data(),
    .pc_plus_4(),
    .immediate(),
    .result()
)




//##################################################################//
//                           Hazard Unit                            //
//##################################################################//

hazard hazard_unit (
    .StallF(),
    .StallD(),
    .FlushD(),
    .Rs1D(),
    .Rs2D(),
    .FlushE(),
    .RdE(),
    .Rs1E(),
    .Rs2E(),
    .ForwardAE(),
    .ForwardBE(),
    .ResultSrcE(),
    .PCSrcE(),
    .RdM(),
    .RegWriteM(),
    .RdW(),
    .RegWriteW()
)



endmodule
