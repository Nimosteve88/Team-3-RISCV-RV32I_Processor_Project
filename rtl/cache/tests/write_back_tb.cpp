#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vwrite_back.h"


int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    Vwrite_back *top = new Vwrite_back;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC; 
    top->trace (tfp, 99);
    tfp->open ("write_back.vcd");

    top->clk = 1;
    
    for (int i=0; i <50; i++)
    {
        for (int clk = 0; clk<2; clk++)
        {
            

            tfp->dump (2*i+clk);
            top->clk = !top->clk; 
            top->eval();
        }

        top->RegWriteM = i % 2;
        top->ResultSrcM = i % 4;
        top->ALUResultM = i;
        top->ReadDataM = i * 2;
        top->ImmExtM = i * 4;
        top->RdM = i % 32;
        top->PCPlus4M = i * 8;


        if (Verilated::gotFinish()) exit(0);
    }

    tfp->close();
    exit(0);
}