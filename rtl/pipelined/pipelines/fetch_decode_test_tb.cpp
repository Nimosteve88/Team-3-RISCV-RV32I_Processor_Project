#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vfetch_decode_top.h"


int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    Vfetch_decode_top *top = new Vfetch_decode_top;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC; 
    top->trace (tfp, 99);
    tfp->open ("fetch_decode_top.vcd");

    top->clk = 1;
    top->CLR_decode = 0;
    top->CLR_execute = 0;
    top->PCSrcE = 0;
    // top->PCF = 0;
    top->en_fetch = 1;
    top->en_decode = 1;
    //top-> InstrDi = 32;

    for (int i=0; i <50; i++)
    {
        for (int clk = 0; clk<2; clk++)
        {
            

            tfp->dump (2*i+clk);
            top->clk = !top->clk; 
            top->eval();
        }


        if(i == 5 || i == 6 || i==7)
        {
            top->en_fetch = 0;
            top->en_decode = 0;
            top->CLR_execute = 1;
        }
        else if (i == 8)
        {
            top->en_fetch = 0;
            top->en_decode = 1;
            top->CLR_decode = 1;
            top->CLR_execute = 0;
        }
        else
        {
            top->en_fetch = 1;
            top->en_decode = 1;
            top->CLR_decode = 0;
            top->CLR_execute = 0;
        }



        if (Verilated::gotFinish()) exit(0);
    }

    tfp->close();
    exit(0);
}