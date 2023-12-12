// Testing for the updated data memory 
// From looking at just the data memory, we look at the following:
// 1. When reading (REN is high) then we want the correct output for data and also correct data ouptut for surrounding words that would form the block in the cache.
// 2. When reading LBU is executed correctly with the additional read code. 
// 3. Writing has already been verified in both the single cycle and pipelined processors and the code is unchanged, so there is no need to test this for unless necessary in the future - given the the time constraints for the processor.

// Test cases to consider:
// 1. outputs when Block offset = 00
// 2. outputs when Block offset = 01
// 3. outputs when Block offset = 10
// 4. outputs when Block offset = 11
// 5. outputs when REN is disabled, random block offset
// 6. outputs when REN and Byte Addr is enabled, random block offset
// 7. outputs when REN is enabled and Byte Addr is disabled, random block offset
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

    // intialise input vectors with test cases for each cycle
    std::vector<int> WE_i = {};
    std::vector<int> A_i = {};
    std::vector<int> REN_i = {};
    std::vector<int> WD_i = {};
    std::vector<int> ByteAddr_i = {};


    // initialise output vectors
    std::vector<int> d0_o;
    std::vector<int> d1_o;
    std::vector<int> d2_o;  
    std::vector<int> d3_o;
    std::vector<int> read_data_mem_o;


    // initialise expected output vectors:
    std::vector<int> d0_oe = {};
    std::vector<int> d1_oe = {};
    std::vector<int> d2_oe = {};  
    std::vector<int> d3_oe = {};
    std::vector<int> read_data_mem_oe = {};





    tfp->close();
    exit(0);
}