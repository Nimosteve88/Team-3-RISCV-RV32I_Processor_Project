#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vmemory.h"


int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    Vmemory *top = new Vmemory;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC; 
    top->trace (tfp, 99);
    tfp->open ("memory.vcd");

    top->clk = 1;
    
    for (int i=0; i <50; i++)
    {
        for (int clk = 0; clk<2; clk++)
        {
            

            tfp->dump (2*i+clk);
            top->clk = !top->clk; 
            top->eval();
        }

        top->RegWriteE = i%2;
        top->ResultsrcE = i%4;
        top->MemWriteE = i%2;
        top->ByteAddrE = i%2;
        top->ALUResultE = 4 * i;
        top->WriteDataE = 8 * i;
        top->ImmExtE = 16 * i;
        top->RdE = i%32; 
        top->PCPlus4E = 32 * i;


        if (Verilated::gotFinish()) exit(0);
    }

    tfp->close();
    exit(0);
}