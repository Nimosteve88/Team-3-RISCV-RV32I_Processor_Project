module alu #(
    parameter WIDTH = 32,
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
        // ALU control is 3'b000, so perform addition (add)
        ALUResult <= SrcA + SrcB;
        EQ <= (SrcA == SrcB) ? 1 : 0; 
      end
      3'b001: begin
        // ALU control is 3'b001, so check for equality  (sub)
        ALUResult <= SrcA - SrcB;
        EQ <= (SrcA == SrcB) ? 1 : 0; 
      end
      3'b010: begin
        // AND
        ALUResult <= SrcA & SrcB;
        EQ <= (SrcA == SrcB) ? 1 : 0;
      end 
      3'b100: begin
        // ALU control is 3'b100, so check for (xor))
        ALUResult <= SrcA ^ SrcB;
        EQ <= (SrcA == SrcB) ? 1 : 0; 
      end
      default: begin
        // Handle other cases if needed
        ALUResult <= 0;
        EQ <= 0;
      end
    endcase
  end
     
endmodule
