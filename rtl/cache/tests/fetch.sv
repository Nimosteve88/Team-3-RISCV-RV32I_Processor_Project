module fetch #(
    parameter WIDTH = 32
)(
    input   logic               clk,        // clock
    input   logic               rst,        // reset
    input   logic               en,         // enable

    input   logic   [WIDTH-1:0] ImmExtE,    // 32-bit immediate to make a pc jump
    input   logic   [1:0]       PCSrcE,     // determined whether pc is +4 or +ImmOp
    input   logic   [WIDTH-1:0] SrcAE,      // register value input for jalr
    input   logic   [WIDTH-1:0] PCE,        // program counter in
    output  logic   [WIDTH-1:0] PCF,        // program counter
    output  logic   [WIDTH-1:0] PCPlus4F    // pc plus 4
);

    logic   [WIDTH-1:0]         next_PC;    // next program counter

always_comb begin
    assign PCPlus4F = PCF + 32'd4;

    if (rst)
        next_PC <= 32'b0; 
    else begin
        case (PCSrcE)
        2'b00: next_PC = PCPlus4F;           // pc + 4
        2'b01: next_PC = PCE + ImmExtE;     // pc + offset
        2'b10: next_PC = SrcAE + ImmExtE;   // rs1 + offset (jalr)
        default: next_PC = PCPlus4F;        // default to pc + 4
        endcase
    end
end

pc_reg mypc_reg (
    .clk (clk),
    .en(en),
    .rst (rst),
    .pcin (next_PC),
    .pcout (PCF)
);

endmodule
