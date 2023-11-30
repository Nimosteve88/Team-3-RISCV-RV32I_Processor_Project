module alu #(
    parameter WIDTH = 32
)(
    input   logic [WIDTH-1:0]     ALUop1,
    input   logic [WIDTH-1:0]     ALUop2,
    input   logic [2:0]           ALUctrl,
    output  logic [WIDTH-1:0]     SUM,
    output  logic                 EQ
);

    // changed from 32'd255 to take that operand as t1, so that bnez also works

always_comb begin
    case (ALUctrl)
      3'b000: begin
        // ALU control is 3'b000, so perform addition
        SUM <= ALUop1 + ALUop2;
        EQ <= EQ; // Set EQ to 0 (not used in this case)
      end
      3'b001: begin
        // ALU control is 3'b001, so subtraction and check for equality
        SUM <= ALUop1 - ALUop2;
        EQ <= (SUM == 0) ? 1 : 0;
      end
      default: begin
        // Handle other cases if needed
        SUM <= 0;
        EQ <= 0;
      end
    endcase
  end
     
endmodule
