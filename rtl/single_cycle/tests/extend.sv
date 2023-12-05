module extend #(
    parameter WIDTH = 32
)(
    input logic     [2:0]           Immsrc,
    input logic     [WIDTH-1:0]     instr,
    output logic    [WIDTH-1:0]     Immop
);

    //assign Immop = Immsrc ? {{20{instr[31]}}, instr[31:20]} : {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
always_comb
    case (Immsrc)
        3'b000:     assign Immop = {{20{instr[31]}}, instr[31:20]};                                    // I instruction
        3'b001:     assign Immop = {{20{instr[31]}}, instr[31:25], instr[11:7]};                       // S Instruction
        3'b010:     assign Immop = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};       // B Instruction
        3'b011:     assign Immop = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};     // J Instruction
        3'b100:     assign Immop = {{instr[31:12], 12'b0}};                                            // U Instruction
        default:    assign Immop = 32'h0F0F0F0F;                                                       // default case - easy to spot errors here
    endcase

endmodule
