#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtoplevel.h"

int main(int argc, char **argv, char **env)
{

    int i;
    int clk;
    Verilated::commandArgs(argc, argv);

    // top instance
    Vtoplevel* top = new Vtoplevel;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("toplevel.vcd");

    // initialuise simulation inputs
    top->clk = 1;
    top->rst = 0;
    //top->a0 = 12;


    // run simulation for many clock cycles
    for (i = 0; i<3000; ++i)
    {
        // dump variables into VCD file and toggle clock
        for (clk = 0; clk<2; ++clk)
        {
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->eval ();
        }
        if (Verilated::gotFinish()) exit(0);
    }
    tfp->close();
    exit(0);
}
