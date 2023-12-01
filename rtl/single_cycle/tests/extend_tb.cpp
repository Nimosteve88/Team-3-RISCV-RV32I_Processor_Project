// Sign extend test cases:
// 1. I Instruction
// 2. S 
// 3. B 
// 4. J 
// 5. U

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vextend.h"

bool check_I_type(Vextend *top, int instruction, int expected)
{
    top->Immsrc = 0b000;
    top->instr = instruction; 
    return(top->Immop == expected);
}


bool check_S_type(Vextend *top, int instruction, int expected)
{
    top->Immsrc = 0b001;
    top->instr = instruction; 
    return(top->Immop == expected);
}


bool check_B_type(Vextend *top, int instruction, int expected)
{
    top->Immsrc = 0b010;
    top->instr = instruction; 
    return(top->Immop == expected);
}


bool check_J_type(Vextend *top, int instruction, int expected)
{
    top->Immsrc = 0b011;
    top->instr = instruction; 
    return(top->Immop == expected);
}


bool check_U_type(Vextend *top, int instruction, int expected)
{
    top->Immsrc = 0b100;
    top->instr = instruction; 
    return(top->Immop == expected);
}


bool check_invalid(Vextend *top, int instruction, int expected)
{
    top->Immsrc = 0b110;
    top->instr = instruction; 
    return(top->Immop == expected);
}


int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    // top instance
    Vextend* top = new Vextend;

    // TODO: Add correct input parameters.

    printf("I_type Test 1: %s!\n", check_I_type(top, 5, 3, 8) ? "Passed" : "Failed");
    printf("I_type Test 2: %s!\n", check_I_type(top, 12, 45, 57) ? "Passed" : "Failed");

    printf("S_type Test 1: %s!\n", check_S_type(top, 13, 3, 10) ? "Passed" : "Failed");
    printf("S_type Test 2: %s!\n", check_S_type(top, 149, 59, 90) ? "Passed" : "Failed");

    printf("B_type Test 1: %s!\n", check_B_type(top, 13, 10, 7) ? "Passed" : "Failed");
    printf("B_type Test 2: %s!\n", check_B_type(top, 149, 59, 174) ? "Passed" : "Failed");
    
    printf("J_type Test 1: %s!\n", check_J_type(top, 13, 3, 0) ? "Passed" : "Failed");
    printf("J_type Test 2: %s!\n", check_J_type(top, 149, 149, 1) ? "Passed" : "Failed");

    printf("U_type Test 1: %s!\n", check_U_type(top, 13, 3, 0) ? "Passed" : "Failed");
    printf("U_type Test 2: %s!\n", check_U_type(top, 149, 149, 1) ? "Passed" : "Failed");

    printf("Invalid ImmSrc Test 1: %s!\n", check_invalid(top, 13, 3, 0) ? "Passed" : "Failed");
    printf("Invalid ImmSrc Test 2: %s!\n", check_invalid(top, 149, 149, 1) ? "Passed" : "Failed");
    
    delete top;

    return 0;
}