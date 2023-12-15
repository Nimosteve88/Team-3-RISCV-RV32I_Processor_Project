module extend #(
    parameter WIDTH = 32
)(
    input logic     [2:0]           Immsrc,
    /* verilator lint_off UNUSED */
    input logic     [WIDTH-1:0]     instr,
    /* verilator lint_on UNUSED */
    output logic    [WIDTH-1:0]     Immop
);

    //assign Immop = Immsrc ? {{20{instr[31]}}, instr[31:20]} : {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
always_comb
    case (Immsrc)
        3'b000:     Immop = {{20{instr[31]}}, instr[31:20]};                                    // I instruction
        3'b001:     Immop = {{20{instr[31]}}, instr[31:25], instr[11:7]};                       // S Instruction
        3'b010:     Immop = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};       // B Instruction
        3'b011:     Immop = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};     // J Instruction
        3'b100:     Immop = {{instr[31:12], 12'b0}};                                            // U Instruction
        default:    Immop = 32'h0F0F0F0F;                                                       // default case - easy to spot errors here
    endcase

endmodule
