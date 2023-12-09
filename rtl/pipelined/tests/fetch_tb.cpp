#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vfetch.h"
#include <vector>



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

    std::vector<int> en = {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1};
    std::vector<int> PCSrcE = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
    std::vector<int> PCE = {10, 10, 10, 10, 10, 12, 16, 20, 4, 40, 10, 10, 10, 10, 10};
    std::vector<int> ImmExtE = {5, 5, 5, 5, 5, 24, 40, 4, 8, 40, 4, 12, 20, 12, 40};
    std::vector<int> SrcAE = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 16, 20, 4, 40};
    
    std::vector<int> PCF;
    std::vector<int> PCPlus4F;
    // define inputs for simulation

    for (i = 0; i < en.size(); i++)
    {
        top->en = en[i];
        top->PCSrcE = PCSrcE[i];
        top->PCE = PCE[i];
        top->ImmExtE = ImmExtE[i];
        top->SrcAE = SrcAE[i];
        for (clk = 0; clk<2; clk++)
        {
            
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->eval();
        }

        PCF.push_back(top->PCF);
        PCPlus4F.push_back(top->PCPlus4F);

        if (Verilated::gotFinish()) exit(0);
    }

    printf("PCF Values: \n");
    for (int i = 0; i < PCF.size(); i++)
    {
        printf("clock cycle: %i\t PCF: %i\n", i, PCF[i]);
    }
    printf("\n");


    printf("PCPlus4F Values: \n");
    for (int i = 0; i < PCPlus4F.size(); i++)
    {
        printf("clock cycle: %i\t PCPlus4F: %i\n", i, PCPlus4F[i]);
    }
    printf("\n");




    tfp->close();

    delete top;

    return 0;
}