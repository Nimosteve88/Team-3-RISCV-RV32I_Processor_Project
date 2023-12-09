#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vfetch.h"



int main(int argc, char **argv, char **env)
{
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);

    Vfetch* top = new Vfetch;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("fetch.vcd");

    top->clk = 1;
    top->rst = 0; 
    top->en = 1;
    top->ImmExtE = 0; 
    top->PCSrcE = 0;
    top->SrcAE = 0;
    top->PCE = 0;

    // define inputs for simulation

    for (i = 0; i < 30; i++)
    {
        // for 15 clock cycles
        //
        for (clk = 0; clk<2; clk++)
        {
            
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->eval();
        }
        top->ImmExtE = i;
        

        if (i == 4)
        {
            top->PCSrcE = 2;
        }
        

        


        if (i == 3)
        {
            top->en = 0;
        }
        else
        {
            top->en = 1; 
        }

        

        if (Verilated::gotFinish()) exit(0);
    }



    tfp->close();

    delete top;

    return 0;
}