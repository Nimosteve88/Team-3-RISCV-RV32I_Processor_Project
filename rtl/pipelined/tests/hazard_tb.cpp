// Hazard unit test cases:
// 1. Forwarding from memory stage
// 2. Forwarding from Writeback stage
// 3. No Forwarding required
// 4. Check stall fetch
// 5. Check stall decode
// 6. Check decode flush
// 7. Check execute flush 

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vhazard_test.h"
#include <vector>


bool check_output(Vhazard_test *top, std::vector<int>& inputs, std::vector<int>& expected_outputs)
{
    top->Rs1D = inputs[0];
    top->Rs2D = inputs[1];
    top->RdE = inputs[2];
    top->Rs1E = inputs[3];
    top->Rs2E = inputs[4];
    top->ResultSrcE = inputs[5];
    top->PCSrcE = inputs[6];
    top->RdM = inputs[7];
    top->RegWriteM = inputs[8];
    top->RdW = inputs[9];
    top->RegWriteW = inputs[10]; 

    std::vector<int> outputs(6);

    top->eval(); 

    outputs[0] = top->StallF;
    outputs[1] = top->StallD;
    outputs[2] = top->FlushD;
    outputs[3] = top->FlushE;
    outputs[4] = top->ForwardAE;
    outputs[5] = top->ForwardBE;

    for (int i = 0; i < 6; i++)
    {
        if (outputs[i] != expected_outputs[i])
        {
            return false;
        }
    }

    return true;
}


int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    Vhazard_test* top = new Vhazard_test;

    // different test cases:
    std::vector<std::vector<int>> testcase_inputs = {{1,0,1,2,0,1,1,12,0,2,1}, 
                                                    {3,2,2,4,4,1,2,12,0,4,1}, 
                                                    {3,4,3,4,3,1,1,3,1,4,1}, 
                                                    {5,4,4,5,0,1,2,5,1,12,0}, 
                                                    {5,6,5,6,6,1,1,6,1,6,1}, 
                                                    {7,6,6,7,7,1,2,7,1,12,0}, 
                                                    {7,7,7,0,3,1,1,0,1,9,1}, 
                                                    {9,8,8,0,4,1,2,4,0,4,1}, 
                                                    {9,10,9,0,6,1,1,6,1,0,0}, 
                                                    {10,10,10,8,0,0,0,0,0,8,1}, 
                                                    {1,2,11,8,8,0,0,2,1,8,1}, 
                                                    {12,13,11,8,6,1,1,6,1,8,1}, 
                                                    {12,13,13,9,0,0,2,9,1,1,1}, 
                                                    {14,12,14,10,3,3,0,10,1,3,1}, 
                                                    {12,10,15,11,11,1,0,11,1,3,0}, 
                                                    {16,17,16,12,12,1,2,12,0,12,0}, 
                                                    {16,17,17,16,0,1,1,12,1,16,1}, 
                                                    {18,19,18,16,16,1,0,13,0,16,1}, 
                                                    {18,19,19,16,12,1,0,12,1,16,1}, 
                                                    {20,21,20,17,0,1,1,17,1,12,0}, 
                                                    {20,21,21,18,12,1,2,18,1,12,1}, 
                                                    {22,23,22,19,19,1,0,19,1,12,0}, 
                                                    {22,23,23,0,10,1,0,13,1,12,1}, 
                                                    {24,25,24,0,14,1,1,12,1,14,1}, 
                                                    {24,25,25,0,10,1,2,10,1,2,1}};

    std::vector<std::vector<int>> testcase_expected = {{1,1,1,1,1,0},
                                                        {1,1,1,1,1,1},
                                                        {1,1,1,1,1,2},
                                                        {1,1,1,1,2,0},
                                                        {1,1,1,1,2,2},
                                                        {1,1,1,1,2,2},
                                                        {1,1,1,1,0,0},
                                                        {1,1,1,1,0,1},
                                                        {1,1,1,1,0,2},
                                                        {0,0,0,0,1,0},
                                                        {0,0,0,0,1,1},
                                                        {0,0,1,1,1,2},
                                                        {0,0,1,1,2,0},
                                                        {0,0,0,0,2,1},
                                                        {0,0,0,0,2,2},
                                                        {1,1,1,1,0,0},
                                                        {1,1,1,1,1,0},
                                                        {1,1,0,1,1,1},
                                                        {1,1,0,1,1,2},
                                                        {1,1,1,1,2,0},
                                                        {1,1,1,1,2,1},
                                                        {1,1,0,1,2,2},
                                                        {1,1,0,1,0,0},
                                                        {1,1,1,1,0,1},
                                                        {1,1,1,1,0,2}};

    for (int i = 0; i < testcase_inputs.size(); i++)
    {
            printf("Test %i\t%s!\n", i, check_output(top, testcase_inputs[i], testcase_expected[i]) ? "Passed" : "Failed");
    }

    delete top;

    return 0; 
}