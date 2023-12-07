// Test cases for PCsrc:
// 1. no branch or jump
// 2. JAL
// 3. JALR
// 4. Valid BEQ
// 5. Invalid BEQ
// 6. Valid BNE
// 7. Invalid BNE

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VPCSrclogic_test.h"
#include <vector>

bool check_output(VPCSrclogic_test *top, int jump_type, int branch_type, int eq, int expected)
{
    top->JumpTypeE = jump_type;
    top->BranchTypeE = branch_type;
    top->EQ = eq;
    top->eval();

    return (top->PCSrcE == expected);
}

int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    VPCSrclogic_test* top = new VPCSrclogic_test;

    printf("No Jump or Branch Test 1: \t\t%s!\n", check_output(top, 0b00, 0b00, 0b0, 0b00) ? "Passed" : "Failed");
    printf("No Jump or Branch Test 2: \t\t%s!\n", check_output(top, 0b00, 0b00, 0b1, 0b00) ? "Passed" : "Failed");

    printf("JAL Test 1: \t\t\t\t%s!\n", check_output(top, 0b01, 0b00, 0b0, 0b01) ? "Passed" : "Failed");
    printf("JAL Test 2: \t\t\t\t%s!\n", check_output(top, 0b01, 0b00, 0b1, 0b01) ? "Passed" : "Failed");

    printf("JALR Test 1: \t\t\t\t%s!\n", check_output(top, 0b10, 0b00, 0b0, 0b10) ? "Passed" : "Failed");
    printf("JALR Test 2: \t\t\t\t%s!\n", check_output(top, 0b10, 0b00, 0b1, 0b10) ? "Passed" : "Failed");

    printf("BEQ Test 1: \t\t\t\t%s!\n", check_output(top, 0b00, 0b01, 0b0, 0b00) ? "Passed" : "Failed");
    printf("BEQ Test 2: \t\t\t\t%s!\n", check_output(top, 0b00, 0b01, 0b1, 0b01) ? "Passed" : "Failed");

    printf("BNE Test 1: \t\t\t\t%s!\n", check_output(top, 0b00, 0b10, 0b0, 0b01) ? "Passed" : "Failed");
    printf("BNE Test 2: \t\t\t\t%s!\n", check_output(top, 0b00, 0b10, 0b1, 0b00) ? "Passed" : "Failed");

    delete top;

    return 0;
}



