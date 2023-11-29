#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vpc_module.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    // Instantiate the Verilated module
    Vpc_module* top = new Vpc_module;

    // Enable VCD tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;

    // Link the trace object to the Verilated hierarchy
    top->trace(tfp, 99); // 99 is the trace depth

    // Open the VCD file
    tfp->open("trace.vcd");

    // Initialize signals
    top->clk = 0;
    top->rst = 1;
    top->ImmOp = 0b0;
    top->PCsrc = 0;

    /***
    // Apply reset and wait
    top->rst = 0;
    for (int i = 0; i < 10; ++i) {
        top->eval();
        tfp->dump(i * 10);  // Dump VCD every 10 time units
        top->clk = !top->clk;
    }

    // Test Case 1: Increment PC
    top->PCsrc = 0;
    for (int i = 0; i < 50; ++i) {
        top->eval();
        tfp->dump(i * 10);
        top->clk = !top->clk;
    }***/

    for (int i = 0; i < 10; ++i) {
        top->eval();
        tfp->dump(i * 10);  // Dump VCD every 10 time units
        top->clk = !top->clk;}
    
    top->rst = 0;

    // Test Case 2: Branch PC
    top->ImmOp = 0b1011;
    top->PCsrc = 1;
    for (int i = 0; i < 50; ++i) {
        top->eval();
        tfp->dump(i * 10);
        top->clk = !top->clk;
    }

    // Add more test cases as needed...

    // Close the VCD file
    tfp->close();

    // Clean up
    delete top;
    delete tfp;
    return 0;
}
