// Sign extend test cases:
// 1. I Instruction
// 2. S 
// 3. B 
// 4. J 
// 5. U

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vextend.h"
#include <iostream>

bool check_I_type(Vextend *top, int instruction, int expected)
{
    top->Immsrc = 0;
    top->instr = instruction; 
    top->eval();
    return(top->Immop == expected);
}


bool check_S_type(Vextend *top, int instruction, int expected)
{
    top->Immsrc = 1;
    top->instr = instruction; 
    top->eval();
    return(top->Immop == expected);
}


bool check_B_type(Vextend *top, int instruction, int expected)
{
    top->Immsrc = 2;
    top->instr = instruction; 
    top->eval();
    return(top->Immop == expected);
}


bool check_J_type(Vextend *top, int instruction, int expected)
{
    top->Immsrc = 3;
    top->instr = instruction; 
    top->eval();
    return(top->Immop == expected);
}


bool check_U_type(Vextend *top, int instruction, int expected)
{
    top->Immsrc = 4;
    top->instr = instruction; 
    top->eval();
    return(top->Immop == expected);
}


int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    // top instance
    Vextend* top = new Vextend;

    // TODO: Add correct input parameters.

    printf("I_type Test 1: %s!\n", check_I_type(top, 0xFFF58593, 0xFFFFFFFF) ? "Passed" : "Failed");

    printf("S_type Test 1: %s!\n", check_S_type(top, 0x00680023, 0x00000000) ? "Passed" : "Failed");

    printf("B_type Test 1: %s!\n", check_B_type(top, 0xFE659CE3, 0xFFFFFFF8) ? "Passed" : "Failed");
    
    printf("J_type Test 1: %s!\n", check_J_type(top, 0x100000EF, 0x00000100) ? "Passed" : "Failed");

    printf("U_type Test 1: %s!\n", check_U_type(top, 0x000105B7, 0x00010000) ? "Passed" : "Failed");

    delete top;

    return 0;
}