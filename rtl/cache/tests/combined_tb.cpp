// Testing for the new data cache and related components.
// Aim of testing is to ensure that the RD is correctly chosen and chosen from cache when possible.

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vcombined.h"
#include <vector>

int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    Vcombined *top = new Vcombined;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC; 
    top->trace (tfp, 99);
    tfp->open ("combined.vcd");

    // Setup input signals - all zero for now, then will be value of vectors
    top->clk = 1;
    top->WEN = 0;
    top->address = 0x00010000; 
    top->write_data = 0;
    top->byte_addr = 0;

    long base_address = 0x00010000;


    for (int i = 0; i < 500; i++)
    {
        
        for (int clk = 0; clk<2; clk++)
        {
            tfp->dump (2*i+clk);
            top->clk = !top->clk; 
            top->eval();
        }

        top->address = (base_address + ( 4 * i));


        if (Verilated::gotFinish()) exit(0);
    }

    tfp->close();
    exit(0);
}