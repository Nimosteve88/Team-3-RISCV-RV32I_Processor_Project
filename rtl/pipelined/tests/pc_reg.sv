module pc_reg #(
    parameter WIDTH = 32
)(
    input   logic               clk,    // clock
    input   logic               rst,    // reset
    input   logic               en,

    input   logic   [WIDTH-1:0] pcin,   // 32-bit input pc
    output  logic   [WIDTH-1:0] pcout   // 32-bit output pc
);

    logic   [WIDTH-1:0]           PCreg;    // 32-bit register

    always_ff @(posedge clk)
    begin
        if (en) PCreg <= pcin;
    end

    assign pcout = PCreg; // fixed pc delay

endmodule

