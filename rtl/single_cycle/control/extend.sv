module signextend #(
    parameter WIDTH = 32
)(
    input logic        Immsrc,
    input logic [WIDTH-1:0]  instr,
    output logic [WIDTH-1:0] Immop
);

    //assign Immop = Immsrc ? {{20{instr[31]}}, instr[31:20]} : {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
always_comb
    case (Immsrc)
        2'b00:  Immop = {{20{instr[31]}}, instr[31:20]};                                    // I instruction
        2'b01:  Immop = {{20{instr[31]}}, instr[31:25], instr[11:7]};                       // S Instruction
        2'b10:  Immop = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};       // B Instruction
        2'b11:  Immop = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};     // J Instruction
    endcase

endmodule
