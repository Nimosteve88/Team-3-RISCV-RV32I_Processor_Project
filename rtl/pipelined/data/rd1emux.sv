module rd1emux #(
    parameter WIDTH = 32
)
(
    input logic [WIDTH-1:0]         RD1E, 
    input logic [WIDTH-1:0]         WD3, 
    input logic [WIDTH-1:0]         ALUResult,
    input logic [1:0]               ForwardAE,
    output logic [WIDTH-1:0]        SrcAE
    );
    always_comb begin
    case (ForwardAE)
      2'b00: begin
        SrcAE <= RD1E;
      end
      2'b01: begin
        SrcAE <= WD3;
      end
      2'b10: begin
        SrcAE <= ALUResult;
      end
      default: $stop;
    endcase
  end
endmodule
