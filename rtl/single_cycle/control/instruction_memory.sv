module instrmem #(
    parameter ADDRESS_WIDTH = 32,
              DATA_WIDTH = 8
)(
    input logic [ADDRESS_WIDTH-1:0] A, //would be the memory address
    output logic [ADDRESS_WIDTH-1:0]   RD //instruction word 
);

    logic [DATA_WIDTH-1:0] instr_array [2**DATA_WIDTH-1:0];

initial begin
    $display("Loading instr.");
    $readmemh("instrrom.mem", instr_array);
end

always_comb begin
    RD = {instr_array[A], instr_array[A+1], instr_array[A+2], instr_array[A+3]}; //implements asynchronous reset
end

endmodule
