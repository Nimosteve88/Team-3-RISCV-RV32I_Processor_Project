// Description:
// - This mux is need to choose what will be written to the register file.
// - The input data for the register can be 4 things:
// -   1. Result of an arithmetic operation directly from the ALU
// -   2. Read from the data memory.
// -   3. PC + 4. When implementing a JAL instruction, a destination register needs to store the next instruction after JAL, so that the PC knows what to go to after running a subroutine - I think this is correct.
// -   4. Immediate - for the LUI instruction, (LU rd upimm is equivalent to rd = [upimm, 12'b0]), we don't need to go through the ALU or data memory for this.
module result_mux #(
    parameter WIDTH = 32
)(
    input logic     [1:0]           result_src, // from control unit
    input logic     [WIDTH-1:0]     ALU_result, 
    input logic     [WIDTH-1:0]     read_data,
    input logic     [WIDTH-1:0]     pc_plus_4,
    input logic     [WIDTH-1:0]     immediate,
    output logic    [WIDTH-1:0]     result
);

always_comb begin
    case (result_src)
        2'b00: result = ALU_result;
        2'b01: result = read_data;
        2'b10: result = pc_plus_4;
        2'b11: result = immediate; 
    endcase
end

endmodule
