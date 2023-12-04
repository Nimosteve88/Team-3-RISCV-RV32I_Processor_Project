module pc_module #(
    parameter WIDTH = 32
)(
    input   logic               clk,    // clock
    input   logic               rst,    // reset
    input   logic   [WIDTH-1:0] ImmOp,  // 32-bit immediate to make a pc jump
    input   logic   [1:0]       PCSrc,  // determined whether pc is +4 or +ImmOp
    input   logic   [WIDTH-1:0] RegIn,  // register value input for jalr
    output  logic   [WIDTH-1:0] PC      // program counter
);

    logic   [WIDTH-1:0]           next_PC;      // next program counter

always_comb begin
    if (rst)
        next_PC <= 32'b0; // resolved wrong value after reset problem
    else begin
        case (PCSrc)
        2'b00: next_PC = PC + 32'd4;    // pc + 4
        2'b01: next_PC = PC + ImmOp;    // pc + offset
        2'b10: next_PC = RegIn + ImmOp; // rs1 + offset (jalr)
        default: next_PC = PC + 32'd4;  // default to pc + 4
        endcase
    end
end

pc_reg mypc_reg (
    .clk (clk),
    .rst (rst),
    .pcin (next_PC),
    .pcout (PC)
);

endmodule
