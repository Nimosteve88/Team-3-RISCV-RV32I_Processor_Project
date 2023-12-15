module alu #(
    parameter WIDTH = 32
)(
    input   logic [WIDTH-1:0]     SrcAE,
    input   logic [WIDTH-1:0]     SrcBE,
    input   logic [2:0]           ALUcontrolE,
    output  logic [WIDTH-1:0]     ALUResult,
    output  logic                 EQ
);

    // changed from 32'd255 to take that operand as t1, so that bnez also works

always_comb begin
    case (ALUcontrolE)
      3'b000: begin
        // ALU control is 3'b000, so perform addition (add)
        ALUResult = SrcAE + SrcBE;
        EQ = (SrcAE == SrcBE) ? 1 : 0; 
      end
      3'b001: begin
        // ALU control is 3'b001, so check for equality  (sub)
        ALUResult = SrcAE - SrcBE;
        EQ = (SrcAE == SrcBE) ? 1 : 0; 
      end
      3'b010: begin
        // AND
        ALUResult = SrcAE & SrcBE;
        EQ = (SrcAE == SrcBE) ? 1 : 0;
      end 
      3'b100: begin
        // ALU control is 3'b100, so check for (xor))
        ALUResult = SrcAE ^ SrcBE;
        EQ = (SrcAE == SrcBE) ? 1 : 0; 
      end
      default: begin
        // Handle other cases if needed
        ALUResult = 0;
        EQ = 0;
      end
    endcase
  end
     
endmodule
