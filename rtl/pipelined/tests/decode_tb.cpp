#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vdecode.h"


int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    Vdecode *top = new Vdecode;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC; 
    top->trace (tfp, 99);
    tfp->open ("decode.vcd");

    top->clk = 1;
    top->EN = 1; 
    top->CLR = 0;
    //top-> InstrDi = 32;

    for (int i=0; i <30; i++)
    {
        for (int clk = 0; clk<2; clk++)
        {
            

            tfp->dump (2*i+clk);
            top->clk = !top->clk; 
            top->eval();
        }
        top->InstrDi = i;
        if(i == 5)
        {
            top->CLR = 1;
        }
        else
        {
            top->CLR = 0;
        }

        if (i == 12 || i == 13)
        {
            top->EN = 0;
        }
        else
        {
            top->EN = 1;
        }
        printf("\n");
        printf("Clock cycle: \t%i\n", i);
        printf("Inputs: \n");
        printf("EN: \t%i\t ", top->EN);
        printf("CLR: \t%i\t ", top->CLR);
        printf("InstrDi: \t%i\t", top->InstrDi);
        printf("\n");
        printf("Output: \n");
        printf("InstrDo: \t%i\t ", top->InstrDo);
        printf("\n");

        if (Verilated::gotFinish()) exit(0);
    }

    tfp->close();
    exit(0);
}