module alu_src_mux #(
    parameter WIDTH = 32
)
(
    input logic[WIDTH-1:0] d0, d1,
    input logic             ALUsrc,
    output logic [WIDTH-1:0] y
    );
    assign y = ALUsrc ? d1 : d0;
endmodule
