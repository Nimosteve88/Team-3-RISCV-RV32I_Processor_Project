module pc_module #(
    parameter WIDTH = 32
)(
    input   logic               clk,    // clock
    input   logic               rst,    // reset
    input   logic   [WIDTH-1:0] ImmOp,  // 32-bit immediate to make a pc jump
    input   logic               PCsrc,  // determined whether pc is +4 or +ImmOp
    output  logic   [WIDTH-1:0] PC      // program counter
);

    logic   [WIDTH-1:0]           branch_PC;    // branch pc ie. pc + immop
    logic   [WIDTH-1:0]           inc_PC;       // increased pc ie. pc + 4
    logic   [WIDTH-1:0]           next_PC;      // next program counter

always_comb begin
    if (rst)
        next_PC <= 32'b0; // resolved wrong value after reset problem
    else begin
        branch_PC <= PC + ImmOp;
        inc_PC <= PC + 32'd4;
        next_PC <= (PCsrc) ? branch_PC : inc_PC;
    end
end

pc_reg mypc_reg (
    .clk (clk),
    .rst (rst),
    .pcin (next_PC),
    .pcout (PC)
);

endmodule