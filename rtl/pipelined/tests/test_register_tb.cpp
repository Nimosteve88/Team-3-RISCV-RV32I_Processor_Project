#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtest_register.h"


int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    Vtest_register *top = new Vtest_register;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC; 
    top->trace (tfp, 99);
    tfp->open ("test_register.vcd");

    top->clk = 1;
    //top->en = 1; 
    top->rst = 0;
    //top-> InstrDi = 32;

    for (int i=0; i <30; i++)
    {
        top->din = i % 16;

        
        if(i == 5)
        {
            top->rst = 1;
        }
        else
        {
            top->rst = 0;
        }


        // for execute register:

        // if (i == 12 || i == 13)
        // {
        //     top->en = 0;
        // }
        // else
        // {
        //     top->en = 1;
        // }
        for (int clk = 0; clk<2; clk++)
        {
            tfp->dump (2*i+clk);
            top->clk = !top->clk; 
            top->eval();
        }
        
        
        // printf("\n");
        // printf("Clock cycle: \t%i\n", i);
        // printf("Inputs: \n");
        // printf("EN: \t%i\t ", top->en);
        // printf("CLR: \t%i\t ", top->clr);
        // printf("InstrDi: \t%i\t", top->InstrDi);
        // printf("\n");
        // printf("Output: \n");
        // printf("InstrDo: \t%i\t ", top->InstrDo);
        // printf("\n");

        if (Verilated::gotFinish()) exit(0);
    }

    tfp->close();
    exit(0);
}