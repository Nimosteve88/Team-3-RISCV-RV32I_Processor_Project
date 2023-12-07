module rd2emux #(
    parameter WIDTH = 32
)
(
    input logic[WIDTH-1:0] RD2E, WD3, ALUResult
    input logic [1:0]            ForwardBE,
    output logic [WIDTH-1:0] SrcBE
    );
    always_comb begin
    case (ForwardBE)
      2'b00: begin
        SrcBE <= RD2E;
      end
      2'b01: begin
        SrcBE <= WD3;
      end
      2'b10: begin
        SrcBE <= ALUResult;
      end
    endcase
  end
endmodule
