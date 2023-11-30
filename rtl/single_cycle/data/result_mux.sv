// Description:
// - This mux is need to choose what will be written to the register file.
// - The input data for the register can be 3 things:
// -   1. Result of an arithmetic operation directly from the ALU
// -   2. Read from the data memory.
// -   3. PC + 4. When implementing a JAL instruction, a destination register needs to store the next instruction after JAL, so that the PC knows what to go to after running a subroutine - I think this is correct.
module reuslt_mux #(
    paremeter WIDTH = 32;,
)(
    input logic     [1:0]           result_src, // from control unit
    input logic     [WIDTH-1:0]     ALU_result, 
    input logic     [WIDTH-1:0]     read_data,
    input logic     [WIDTH-1:0]     pc_plus_4,
    output logic    [WIDTH-1:0]     result
)

always_comb (
    case (result_src)
    2'b00:      result = ALU_result;
    2'b01:      result = read_data;
    2'b10:      result = pc_plus_4;
    2'b11:      result = 32'h0F0F0F0F; // this is not an option anyway - added for safety, in the case result_src = 11 then this value will come up in the waveform so we know there is definitely an error.
    endcase
)

endmodule
