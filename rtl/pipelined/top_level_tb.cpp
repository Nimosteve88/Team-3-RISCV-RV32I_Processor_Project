#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop_level.h"

#include "vbuddy.cpp"

#define MAX_SIM_CYCLES 150000000

int main(int argc, char **argv, char **env)
{

    int simcyc;
    int tick;
    Verilated::commandArgs(argc, argv);

    // top instance
    Vtop_level* top = new Vtop_level;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("top_level.vcd");


    // init vbuddy
    if (vbdOpen()!=1) return(-1);
    vbdHeader("Pipelined"); // change to correct title
    vbdSetMode(1);
    vbdBar(0); 
    

    // initialuise simulation inputs
    top->clk = 1;
    top->rst = 0;

    
    // for f1 program:
    top->seed = vbdValue();
    top->trigger_val = 0; 

    for (simcyc=0; simcyc<MAX_SIM_CYCLES; simcyc++)
    {
        for(tick=0; tick<2; tick++)
        {
            tfp->dump (2*simcyc+tick);
            top->clk = !top->clk;
            top->eval();
        }


        // reference program
        // if (simcyc > 1300000 && simcyc % 2 == 0)
        // {  
        //     vbdPlot(int(top->a0), 0, 255);
        //     vbdCycle(simcyc);
        // }
        // end of reference program
        

        // F1 program:
        vbdCycle(simcyc);
        top->trigger_val = vbdFlag(); 
        vbdBar(top->a0 & 0xFF);
        vbdHex(3,(int(top->a0)>>8)&0xF);
        vbdHex(2,(int(top->a0)>>4)&0xF);
        vbdHex(1,int(top->a0)&0xF);
        // End of F1 program

        if((Verilated::gotFinish()) || (vbdGetkey()=='q'))
            exit(0);

        
    }


    vbdClose();
    tfp->close();
    exit(0);
}
