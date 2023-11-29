module pc_reg #(
    parameter WIDTH = 32
)(
    input   logic               clk,    // clock
    input   logic               rst,    // reset
    input   logic   [WIDTH-1:0] pcin,   // 32-bit input pc
    output   logic  [WIDTH-1:0] pcout   // 32-bit output pc
);

    logic   [WIDTH-1:0]           PCreg;    // 32-bit register

    always_ff @(posedge clk or posedge rst)
    begin
        if (rst)
            PCreg <= 32'b0;
        else
            PCreg <= pcin;
    end

    assign pcout = PCreg; // fixed pc delay

endmodule

