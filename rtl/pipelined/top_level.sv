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

)



instruction_memory instruction_mem (

)





//##################################################################//
//                          Stage: Decode                           //
//##################################################################//

decode decode_pipeline_register (

)



extend sign_extension_unit (

)



control_unit_pipelined control_unit (

)



register_file registers (

)





//##################################################################//
//                          Stage: Execute                          //
//##################################################################//

execute execute_pipeline_register (

)



rd1emux RD1E_mux (

)



rd2emux RD2E_mux (

)



alu_src_mux ALU_mux (

)



alu ALU (

)



PCSrclogic pc_src_logic (

) 





//##################################################################//
//                          Stage: Memory                           //
//##################################################################//

memory memory_pipeline_register (

)



data_memory data_mem (

)





//##################################################################//
//                        Stage: Write Back                         //
//##################################################################//

write_back write_back_pipeline_register (

)



result_mux result_data (

)




//##################################################################//
//                           Hazard Unit                            //
//##################################################################//

hazard hazard_unit (

)



endmodule
