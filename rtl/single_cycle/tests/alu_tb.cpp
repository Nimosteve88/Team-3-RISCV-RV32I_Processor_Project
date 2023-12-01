// Different Test Cases for the ALU:
// 1. Addition of 2 Values
// 2. Subtraction of 2 Values
// 3. XOR of 2 inputs
// 4. Checking of Equality of 2 Values

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Valu.h"


bool check_addition(Valu *top, int a, int b, int expected)
{
    top->SrcA = a;
    top->SrcB = b;
    top->ALUctrl = 0;
    top->eval();
    return(top->ALUResult == expected);
}


bool check_subtraction(Valu *top, int a, int b, int expected)
{
    top->SrcA = a;
    top->SrcB = b;
    top->ALUctrl = 1;
    top->eval();
    return(top->ALUResult == expected); 
}


bool check_xor(Valu *top, int a, int b, int expected)
{
    top->SrcA = a;
    top->SrcB = b;
    top->ALUctrl = 0; // change with relevant opcode
    top->eval();
    return(top->ALUResult == expected);
}


bool check_equality(Valu *top, int a, int b, int expected)
{
    top->SrcA = a;
    top->SrcB = b;
    top->ALUctrl = 1;
    top->eval();
    return(top->Zero == expected);
}


int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    // top instance
    Valu* top = new Valu;

    printf("Addition Test 1: %s!\n", check_addition(top, 5, 3, 8) ? "Passed" : "Failed");
    printf("Addition Test 2: %s!\n", check_addition(top, 12, 45, 57) ? "Passed" : "Failed");
    printf("Subtraction Test 1: %s!\n", check_subtraction(top, 13, 3, 10) ? "Passed" : "Failed");
    printf("Subtraction Test 2: %s!\n", check_subtraction(top, 149, 59, 90) ? "Passed" : "Failed");
    printf("XOR Test 1: %s!\n", check_xor(top, 13, 10, 7) ? "Passed" : "Failed");
    printf("XOR Test 2: %s!\n", check_xor(top, 149, 59, 174) ? "Passed" : "Failed");
    printf("Equality Test 1: %s!\n", check_equality(top, 13, 3, 0) ? "Passed" : "Failed");
    printf("Equality Test 2: %s!\n", check_equality(top, 149, 149, 1) ? "Passed" : "Failed");

    delete top;

    return 0;
}