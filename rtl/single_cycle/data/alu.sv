module alu #(
    parameter WIDTH = 32,
    parameter SH_WIDTH = 5
)(
    input   logic [WIDTH-1:0]     SrcA,
    input   logic [WIDTH-1:0]     SrcB,
    input   logic [2:0]           ALUctrl,
    output  logic [WIDTH-1:0]     ALUResult,
    output  logic                 EQ
);

    // changed from 32'd255 to take that operand as t1, so that bnez also works

always_comb begin
    case (ALUctrl)
      3'b000: begin
        // ALU control is 3'b000, so perform addition
        ALUResult <= SrcA + SrcB;
        EQ <= EQ; // Set EQ to 0 (not used in this case)
      end
      3'b001: begin
        // ALU control is 3'b001, so check for equality
        EQ <= (ALUop1 == ALUop2) ? 1 : 0;
        SUM <= 0; // Set SUM to 0 (not used in this case)
      end
      default: begin
        // Handle other cases if needed
        ALUResult <= 0;
        EQ <= 0;
      end
    endcase
  end
     
endmodule
