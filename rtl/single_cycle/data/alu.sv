module alu #(
    parameter WIDTH = 32,
    parameter SH_WIDTH = 5
)(
    input   logic [WIDTH-1:0]     SrcA,
    input   logic [WIDTH-1:0]     SrcB,
    input   logic [2:0]           ALUctrl,
    output  logic [WIDTH-1:0]     ALUResult,
    output  logic                 Zero
);

    // changed from 32'd255 to take that operand as t1, so that bnez also works

always_comb begin
    case (ALUctrl)
      3'b000: begin
        // ALU control is 3'b000, so perform addition (add)
        ALUResult <= SrcA + SrcB;
        Zero <= Zero; // Set Zero to 0 (not used in this case)
      end
      3'b001: begin
        // ALU control is 3'b001, so check for equality  (sub)
        ALUResult <= SrcA - SrcB;
        Zero <= Zero; // Set Zero to 0 (not used in this case)
      end
      3'b010: begin
        // ALU control is 3'b010, so check for (xor))
        ALUResult <= SrcA ^ SrcB;
        Zero <= Zero; // Set Zero to 0 (not used in this case)
      end
      3'b011: begin
        // ALU control is 3'b011, so check for (and)
        ALUResult <= SrcA & SrcB;
        Zero <= Zero; // Set Zero to 0 (not used in this case)
      end
      3'b100: begin
        // ALU control is 3'b100, so check for (jal)
        ALUResult <= SrcB;
        Zero <= Zero; // Set Zero to 0 (not used in this case)
      end
      3'b101: begin
        // ALU control is 3'b101, so check for equality (bne)
        Zero <= (ALUop1 == ALUop2) ? 1 : 0;
        ALUResult <= 0; // Set SUM to 0 (not used in this case)
      end
      3'b0111: begin
        // ALU control is 3'b111, so check for equality (beq)
        Zero <= (ALUop1 != ALUop2) ? 1 : 0;
        ALUResult <= 0; // Set SUM to 0 (not used in this case)
      end
      default: begin
        // Handle other cases if needed
        ALUResult <= 0;
        Zero <= 0;
      end
    endcase
  end
     
endmodule


//operations to consider:  bne, beq, add, and, xor,  sub, jal