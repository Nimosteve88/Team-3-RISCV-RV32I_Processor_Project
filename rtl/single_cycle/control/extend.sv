module signextend #(
    parameter WIDTH = 32
)(
    input logic              Immsrc,
    input logic [WIDTH-1:0]  instr,
    output logic [WIDTH-1:0] Immop
);

    assign Immop = Immsrc ? {{20{instr[31]}}, instr[31:20]} : {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
    

endmodule
