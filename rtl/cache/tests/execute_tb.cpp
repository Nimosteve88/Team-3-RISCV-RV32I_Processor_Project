#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vexecute.h"


int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    Vexecute *top = new Vexecute;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC; 
    top->trace (tfp, 99);
    tfp->open ("execute.vcd");

    top->clk = 1;
    top->CLR = 0;
    //top-> InstrDi = 32;

    for (int i=0; i <50; i++)
    {
        for (int clk = 0; clk<2; clk++)
        {
            

            tfp->dump (2*i+clk);
            top->clk = !top->clk; 
            top->eval();
        }

        top->RegWriteD = i%2;
        top->ResultSrcD = i%4;
        top->MemWriteD = i%2;
        top->ByteAddrD = i%2;
        top->JumpTypeD = i%4;
        top->BranchTypeD = i%4;
        top->ALUControlD = i%8;
        top->ALUsrcD = i%2;
        top->RD1D = 16*i;
        top->RD2D = 16*i;
        top->PCD = 16*i;
        top->Rs1D = i%32;
        top->Rs2D = i%32;
        top->RdD = i%32;
        top->ImmExtD = 16*i;
        top->PCPlus4D = 16*i;

        if(i == 5 || i == 20)
        {
            top->CLR = 1;
        }
        else
        {
            top->CLR = 0;
        }


        if (Verilated::gotFinish()) exit(0);
    }

    tfp->close();
    exit(0);
}