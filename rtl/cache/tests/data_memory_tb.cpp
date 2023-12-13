// Testing for the updated data memory 
// From looking at just the data memory, we look at the following:
// 1. When reading (REN is high) then we want the correct output for data and also correct data ouptut for surrounding words that would form the block in the cache.
// 2. When reading LBU is executed correctly with the additional read code. 
// 3. Writing has already been verified in both the single cycle and pipelined processors and the code is unchanged, so there is no need to test this for unless necessary in the future - given the the time constraints for the processor.

// Test cases to consider:
// 1. outputs when Block offset = 00, Byte Addr enabled
// 2. outputs when Block offset = 01, Byte Addr enabled
// 3. outputs when Block offset = 10, Byte Addr disabled
// 4. outputs when Block offset = 11, Byte Addr disabled
// 5. outputs when REN is disabled, ByteAddr, enabled, random block offset
// 6. outputs when REN and Byte Addr is enabled, random block offset
// 7. outputs when REN is enabled and Byte Addr is disabled, random block offset
// 8. outputs when REN is disabled and ByteAddr is disabled, random block offset
// All test cases have random write data inputs (shouldn't affect anything)
// WE is 0 for all cases - writing has already been tested.



#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vdata_memory.h"
#include <vector>

int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    Vdata_memory *top = new Vdata_memory;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC; 
    top->trace (tfp, 99);
    tfp->open ("data_memory.vcd");

    // Setup input signals - all zero for now, then will be value of vectors
    top->clk = 1;
    top->WE = 0;
    top->A = 0; 
    top->REN = 0;
    top->WD = 0;
    top->ByteAddr = 0;

    // 8 tets cases in total
    // intialise input vectors with test cases for each cycle
    std::vector<int> WE_i = {0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<int> A_i = {0x00010000, 0x00010004, 0x000100F8, 0x000102FC, 0x00010EF8, 0x00010EE4, 0x00010DAC, 0x00010210};
    std::vector<int> REN_i = {1, 1, 1, 1, 0, 1, 1, 0};
    std::vector<int> WD_i = {16, 32, 64, 128, 256, 512, 1024, 2048};
    std::vector<int> ByteAddr_i = {1, 1, 0, 0, 1, 1, 0, 0};


    for (int i = 0; i < A_i.size()+2; i++)
    {
        for (int clk = 0; clk<2; clk++)
        {
            tfp->dump (2*i+clk);
            top->clk = !top->clk; 
            top->eval();
        }
        top->WE = WE_i[i];
        top->A = A_i[i]; 
        top->REN = REN_i[i];
        top->WD = WD_i[i];
        top->ByteAddr = ByteAddr_i[i];


        if (Verilated::gotFinish()) exit(0);
    }

    tfp->close();
    exit(0);
}