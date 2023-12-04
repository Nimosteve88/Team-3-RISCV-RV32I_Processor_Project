// Whole top level for PC counter:
// Test Cases:
// 1. PC = PC+4
// 2. PC = PC+Imm 
// 3. PC = rs1+Imm
// 4. Reset functionality

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vpc_module.h"
#include <vector>


int main(int argc, char **argv, char **env)
{
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);

    Vpc_module* top = new Vpc_module;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;

    // define inputs for simulation
    std::vector<int> resets = {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0};
    std::vector<int> pc_src = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 0, 1, 2};
    std::vector<int> imm_op = {0, 4, 8, 12, 16, 20, 24, -4, 12, 36, -12, 64, 40, 44, 16, -4};
    std::vector<int> reg_in = {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, -8, 32, 36, 32, 32};

    // define expected outputs:
    // std::vector<int> expected_next_pc = {4, 8, 12, 0, 4, 24, 48, 44, 0, 36, 68, 56, 0, 4, 20, 28};
    std::vector<int> expected_pc = {0, 4, 8, 12, 0, 4, 24, 48, 44, 0, 36, 68, 56, 0, 4, 20};

    // initialise output vectors
    // std::vector<int> output_next_pc;
    std::vector<int> output_pc;


    for (i = 0; i < 16; i++)
    {
        // for 15 clock cycles
        for (clk = 0; clk<2; clk++)
        {
            
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->rst = resets[i];
            top->ImmOp = imm_op[i];
            top->PCSrc = pc_src[i];
            top->RegIn = reg_in[i];
            top->eval();
            
        }

        // print outputs for debugging
        
        // printf("clock cycle: %i\n", i);
        // printf("Inputs: \n");
        // printf("reset: %i\t", top->rst);
        // printf("PCSrc: %i\t", top->PCSrc);
        // printf("ImmOp: %i\t", top->ImmOp);
        // printf("RegIn: %i\t", top->RegIn);
        // printf("\n");
        // printf("Outputs: \n");
        // printf("pc: %i\t", top->PC);
        // printf("\n");
        // printf("\n");


        output_pc.push_back(top->PC);


        if (Verilated::gotFinish()) exit(0);
    }


    // compare actual and expected values. 
    bool correct = true;
    int fail_cycle = 0;
    for (int i = 0; i < output_pc.size(); i++)
    {
        if (output_pc[i] != expected_pc[i])
        {
            fail_cycle = i;
            correct = false; 
            break;
        }
    }

    if (correct)
    {
        printf("All Tests Passed! \n");
    }
    else
    {
        printf("Test failed at cycle: %i\n", fail_cycle);
    }

    tfp->close();

    delete top;

    return 0;
}