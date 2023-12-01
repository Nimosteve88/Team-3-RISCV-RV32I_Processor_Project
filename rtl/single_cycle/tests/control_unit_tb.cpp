// Control Unit Test Cases:
// 1. ADD Instruction
// 2. JAL 
// 3. JALR
// 4. LBU 
// 5. ADDI
// 6. BNE with EQ 
// 7. BNE without EQ 
// 8. LUI 
// 9. SB 
// 10. XOR

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vcontrol_unit.h"
#include <vector>

bool check_instruction(Vcontrol_unit *top, int instruction, int zero, std::vector<int>& expected)
{
    std::vector<int> outputs(9);
    top->instr = instruction;
    top->EQ = zero;

    top->eval();

    outputs[0] = top->PCSrc;
    outputs[1] = top->ResultSrc;
    outputs[2] = top->MemWrite;
    outputs[3] = top->ALUControl;
    outputs[4] = top->ALUSrc;
    outputs[5] = top->ImmSrc;
    outputs[6] = top->RegWrite;
    outputs[7] = top->PCTargetSrc;
    outputs[8] = top->LBUSrc;

    bool correct = false;
    for (int i = 0; i < 9; i++)
    {
        if (outputs[i] != expected[i])
        {
            return false;
        }
    }

    correct = true;

    return (correct);
}

int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    Vcontrol_unit* top = new Vcontrol_unit;

    std::vector<int> expected_answers(9);
    // in the form (PCSrc, ResultsSrc, MemWrite, ALUControl, ALUSrc, ImmSrc, RegWrite, PCTargetSrc, LBUSrc)

    // ADD
    expected_answers = {0b0, 0b00, 0b0, 0b000, 0b0, 0b000, 0b1, 0b0, 0b0};
    printf("ADD test 1: %s!\n", check_instruction(top, 0x00A58533, 0, expected_answers) ? "Passed" : "Failed");
    printf("ADD test 2: %s!\n", check_instruction(top, 0x00D30933, 1, expected_answers) ? "Passed" : "Failed");

    // JAL
    expected_answers = {0b1, 0b10, 0b0, 0b000, 0b0, 0b011, 0b1, 0b0, 0b0};
    printf("JAL test 1: %s!\n", check_instruction(top, 0x00A58533, 0, expected_answers) ? "Passed" : "Failed");
    printf("JAL test 2: %s!\n", check_instruction(top, 0x00D30933, 1, expected_answers) ? "Passed" : "Failed");

    // JALR
    expected_answers = {0b1, 0b10, 0b0, 0b000, 0b1, 0b000, 0b1, 0b1, 0b0};
    printf("JALR test 1: %s!\n", check_instruction(top, 0x00A58533, 0, expected_answers) ? "Passed" : "Failed");
    printf("JALR test 2: %s!\n", check_instruction(top, 0x00D30933, 1, expected_answers) ? "Passed" : "Failed");

    // LBU
    expected_answers = {0b0, 0b01, 0b0, 0b000, 0b1, 0b000, 0b1, 0b0, 0b1};
    printf("LBU test 1: %s!\n", check_instruction(top, 0x00A58533, 0, expected_answers) ? "Passed" : "Failed");
    printf("LBU test 2: %s!\n", check_instruction(top, 0x00D30933, 1, expected_answers) ? "Passed" : "Failed");
    
    // ADDI
    expected_answers = {0b0, 0b00, 0b0, 0b000, 0b1, 0b000, 0b1, 0b0, 0b0};
    printf("ADDI test 1: %s!\n", check_instruction(top, 0x00A58533, 0, expected_answers) ? "Passed" : "Failed");
    printf("ADDI test 2: %s!\n", check_instruction(top, 0x00D30933, 1, expected_answers) ? "Passed" : "Failed");

    // BNE
    expected_answers = {0b1, 0b00, 0b0, 0b001, 0b0, 0b010, 0b0, 0b0, 0b0};
    printf("BNE test 1: %s!\n", check_instruction(top, 0x00A58533, 0, expected_answers) ? "Passed" : "Failed");
    expected_answers = {0b0, 0b00, 0b0, 0b001, 0b0, 0b010, 0b0, 0b0, 0b0};
    printf("BNE test 2: %s!\n", check_instruction(top, 0x00D30933, 1, expected_answers) ? "Passed" : "Failed");

    // LUI
    expected_answers = {0b0, 0b11, 0b0, 0b000, 0b0, 0b100, 0b1, 0b0, 0b0};
    printf("LUI test 1: %s!\n", check_instruction(top, 0x00A58533, 0, expected_answers) ? "Passed" : "Failed");
    printf("LUI test 2: %s!\n", check_instruction(top, 0x00D30933, 1, expected_answers) ? "Passed" : "Failed");

    // SB
    expected_answers = {0b0, 0b00, 0b1, 0b000, 0b1, 0b001, 0b0, 0b0, 0b0};
    printf("SB test 1: %s!\n", check_instruction(top, 0x00A58533, 0, expected_answers) ? "Passed" : "Failed");
    printf("SB test 2: %s!\n", check_instruction(top, 0x00D30933, 1, expected_answers) ? "Passed" : "Failed");

    // XOR
    expected_answers = {0b0, 0b00, 0b0, 0b010, 0b0, 0b000, 0b1, 0b0, 0b0}; // TODO: double check expected output for XOR instruction
    printf("XOR test 1: %s!\n", check_instruction(top, 0x00A58533, 0, expected_answers) ? "Passed" : "Failed");
    printf("XOR test 2: %s!\n", check_instruction(top, 0x00D30933, 1, expected_answers) ? "Passed" : "Failed");

    delete top;

    return 0
}
