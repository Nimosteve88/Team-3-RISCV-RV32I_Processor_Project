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
// 11. AND

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vcontrol_unit.h"
#include <vector>

bool check_instruction(Vcontrol_unit *top, int instruction, int zero, std::vector<int>& expected, std::vector<int>& dont_cares)
{
    std::vector<int> outputs(9);
    top->instr = instruction;
    top->EQ = zero;

    top->eval();

    outputs[0] = top->PCSrc;
    outputs[1] = top->ResultSrc;
    outputs[2] = top->MemWrite;
    outputs[3] = top->ALUctrl;
    outputs[4] = top->ALUsrc;
    outputs[5] = top->ImmSrc;
    outputs[6] = top->RegWrite;
    outputs[7] = top->ByteAddr;

    for (int i = 0; i < 9; i++)
    {
        if (outputs[i] != expected[i])
        {
            if (!dont_cares[i])
            {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    Vcontrol_unit* top = new Vcontrol_unit;

    std::vector<int> expected_answers(8);
    // in the form (PCSrc, ResultsSrc, MemWrite, ALUControl, ALUSrc, ImmSrc, RegWrite, ByteAddr)

    std::vector<int> dont_cares(8);
    // creates a vectors of whether we care about the control unit output for some values.

    // ADD
    expected_answers = {0b00, 0b00, 0b0, 0b000, 0b0, 0b000, 0b1, 0b0};
    dont_cares = {0, 0, 0, 0, 0, 1, 0, 1};
    printf("ADD test 1: \t%s!\n", check_instruction(top, 0x00C587B3, 0, expected_answers, dont_cares) ? "Passed" : "Failed");
    printf("ADD test 2: \t%s!\n", check_instruction(top, 0x00C587B3, 1, expected_answers, dont_cares) ? "Passed" : "Failed");


    // JAL
    expected_answers = {0b01, 0b10, 0b0, 0b000, 0b0, 0b011, 0b1, 0b0};
    dont_cares = {0, 0, 0, 1, 1, 0, 0, 1};
    printf("JAL test 1: \t%s!\n", check_instruction(top, 0x100000EF, 0, expected_answers, dont_cares) ? "Passed" : "Failed");
    printf("JAL test 2: \t%s!\n", check_instruction(top, 0x100000EF, 1, expected_answers, dont_cares) ? "Passed" : "Failed");


    // JALR
    expected_answers = {0b10, 0b10, 0b0, 0b000, 0b0, 0b000, 0b1, 0b0};
    dont_cares = {0, 0, 0, 1, 1, 0, 0, 1};
    printf("JALR test 1: \t%s!\n", check_instruction(top, 0x00008067, 0, expected_answers, dont_cares) ? "Passed" : "Failed");
    printf("JALR test 2: \t%s!\n", check_instruction(top, 0x00008067, 1, expected_answers, dont_cares) ? "Passed" : "Failed");


    // LBU
    expected_answers = {0b00, 0b01, 0b0, 0b000, 0b1, 0b000, 0b1, 0b1};
    dont_cares = {0, 0, 0, 0, 0, 0, 0, 0};
    printf("LBU test 1: \t%s!\n", check_instruction(top, 0x00084303, 0, expected_answers, dont_cares) ? "Passed" : "Failed");
    printf("LBU test 2: \t%s!\n", check_instruction(top, 0x00084303, 1, expected_answers, dont_cares) ? "Passed" : "Failed");
    

    // ADDI
    expected_answers = {0b00, 0b00, 0b0, 0b000, 0b1, 0b000, 0b1, 0b0};
    dont_cares = {0, 0, 0, 0, 0, 0, 0, 1};
    printf("ADDI test 1: \t%s!\n", check_instruction(top, 0xFFF58593, 0, expected_answers, dont_cares) ? "Passed" : "Failed");
    printf("ADDI test 2: \t%s!\n", check_instruction(top, 0xFFF58593, 1, expected_answers, dont_cares) ? "Passed" : "Failed");


    // BNE
    expected_answers = {0b01, 0b00, 0b0, 0b001, 0b0, 0b010, 0b0, 0b0};
    dont_cares = {0, 1, 0, 0, 0, 0, 0, 1};
    printf("BNE test 1: \t%s!\n", check_instruction(top, 0xFE659CE3, 0, expected_answers, dont_cares) ? "Passed" : "Failed");
    
    expected_answers = {0b00, 0b00, 0b0, 0b001, 0b0, 0b010, 0b0, 0b0};
    dont_cares = {0, 1, 0, 0, 0, 0, 0, 1};
    printf("BNE test 2: \t%s!\n", check_instruction(top, 0xFE659CE3, 1, expected_answers, dont_cares) ? "Passed" : "Failed");


    // LUI
    expected_answers = {0b00, 0b11, 0b0, 0b000, 0b0, 0b100, 0b1, 0b0};
    dont_cares = {0, 0, 0, 1, 1, 0, 0, 1};
    printf("LUI test 1: \t%s!\n", check_instruction(top, 0x000105B7, 0, expected_answers, dont_cares) ? "Passed" : "Failed");
    printf("LUI test 2: \t%s!\n", check_instruction(top, 0x000105B7, 1, expected_answers, dont_cares) ? "Passed" : "Failed");


    // SB
    expected_answers = {0b00, 0b00, 0b1, 0b000, 0b1, 0b001, 0b0, 0b1};
    dont_cares = {0, 1, 0, 0, 0, 0, 0, 0};
    printf("SB test 1: \t%s!\n", check_instruction(top, 0x00680023, 0, expected_answers, dont_cares) ? "Passed" : "Failed");
    printf("SB test 2: \t%s!\n", check_instruction(top, 0x00680023, 1, expected_answers, dont_cares) ? "Passed" : "Failed");


    // XOR
    expected_answers = {0b00, 0b00, 0b0, 0b100, 0b0, 0b000, 0b1, 0b0}; 
    dont_cares = {0, 0, 0, 0, 0, 1, 0, 1};
    printf("XOR test 1: \t%s!\n", check_instruction(top, 0x00C5C7B3, 0, expected_answers, dont_cares) ? "Passed" : "Failed");
    printf("XOR test 2: \t%s!\n", check_instruction(top, 0x00C5C7B3, 1, expected_answers, dont_cares) ? "Passed" : "Failed");


    // AND
    expected_answers = {0b00, 0b00, 0b0, 0b010, 0b0, 0b000, 0b1, 0b0};
    dont_cares = {0, 0, 0, 0, 0, 1, 0, 1};
    printf("AND test 1: \t%s!\n", check_instruction(top, 0x00C5F7B3, 0, expected_answers, dont_cares) ? "Passed" : "Failed");
    printf("AND test 2: \t%s!\n", check_instruction(top, 0x00C5F7B3, 1, expected_answers, dont_cares) ? "Passed" : "Failed");

    delete top;

    return 0;
}
