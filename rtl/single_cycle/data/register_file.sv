module regfile #(
    parameter WIDTH = 5,
    parameter DATAWIDTH = 32
)(
    input   logic  [WIDTH-1:0]     AD1, 
    input   logic  [WIDTH-1:0]     AD2,
    input   logic  [WIDTH-1:0]     AD3,
    input   logic                  WE3,
    input   logic  [DATAWIDTH-1:0] WD3,
    input   logic                  clk,
    output  logic  [DATAWIDTH-1:0] RD1,
    output  logic  [DATAWIDTH-1:0] RD2,
    output  logic  [DATAWIDTH-1:0] a0,
    output logic   [DATAWIDTH-1:0] a1, // added for debugging
    output logic   [DATAWIDTH-1:0] t1  // added for debugging   
);

logic [DATAWIDTH-1:0] registers [31:0];



    always_ff @(posedge clk) begin
        if (WE3 == 1'b1) begin
            if (AD3 != WIDTH{1'b0}) registers[AD3] <= WD3; //RESULT FROM ALU IS STORED IN ADDRESS 3
            else registers[AD3] <= DATAWIDTH{1'b0};
        end
    end

    always_comb
    begin
        RD1 <= registers[AD1]; // DATA IS READ FROM AD1 AND AD2
        RD2 <= registers[AD2];
        a0 <=  registers[AD3]; // a0 is output which is set to result
        a1 <=  registers[5'b01011];
        t1 <=  registers[5'b00110];
    end


endmodule
