/* TEST FOR DECODE REGISTER*/

/*
module test_register (
    input logic     clk,
  input logic [3:0] din,        // Data input
  input logic en,               // Enable signal
  input logic rst,              // Reset signal
  output logic [3:0] dout        // Data output
);

  // Register declaration
  logic [3:0] register;

  // Asynchronous reset
  always_ff @(negedge clk or negedge rst)
    if (rst)
      register <= 4'b0;
    else if (en)
      register <= din;

  // Assign output
  assign dout = register;

endmodule
*/

// Execute register test

module test_register (
    input logic     clk,
    input logic [3:0] din,        // Data input
    input logic rst,              // Reset signal
    output logic [3:0] dout        // Data output
);

  // Register declaration
  logic [3:0] register;

  // Asynchronous reset
  always_ff @(posedge clk or posedge rst)
    if (rst)
      register <= 4'b0;
    else
      register <= din;

  // Assign output
  assign dout = register;

endmodule
