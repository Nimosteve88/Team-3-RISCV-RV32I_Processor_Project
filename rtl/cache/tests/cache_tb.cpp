// Testing for the new data cache
// Individual testing for data cache would be to load the cache with dummy memory and test the following:
// - Valid bit - test when tag matches and valid bit = 0
// - Test writing to the cache on the clock edge.

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vcache.h"
#include <vector>

int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    Vcache *top = new Vcache;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC; 
    top->trace (tfp, 99);
    tfp->open ("cache.vcd");

    // set up input signals
    top->clk = 1;
    top->A = 0;
    top->ByteAddr = 0;
    top->d0 = 0;
    top->d1 = 0;
    top->d2 = 0;
    top->d3 = 0;

    top->cache_block_0_valid = 0;
    top->cache_block_0_tag = 0;
    top->cache_block_0_0_data = 0;
    top->cache_block_0_1_data = 0;
    top->cache_block_0_2_data = 0;
    top->cache_block_0_3_data = 0;
    top->cache_block_1_valid = 0;
    top->cache_block_1_tag = 0;
    top->cache_block_1_0_data = 0;
    top->cache_block_1_1_data = 0;
    top->cache_block_1_2_data = 0;
    top->cache_block_1_3_data = 0;
    top->cache_block_2_valid = 0;
    top->cache_block_2_tag = 0;
    top->cache_block_2_0_data = 0;
    top->cache_block_2_1_data = 0;
    top->cache_block_2_2_data = 0;
    top->cache_block_2_3_data = 0;
    top->cache_block_3_valid = 0;
    top->cache_block_3_tag = 0;
    top->cache_block_3_0_data = 0;
    top->cache_block_3_1_data = 0;
    top->cache_block_3_2_data = 0;
    top->cache_block_3_3_data = 0;


    // input vectors with test cases:
    std::vector<long> A_i = {0x00010190, 0x000101C4, 0x000101E8, 0x0001013C, 0x00010190, 0x000101C4, 0x000101E8, 0x0001013C, 0x00010190, 0x000101C4, 0x000101E8, 0x0001013C};
    std::vector<int> ByteAddr_i = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
    std::vector<long> d0_i = {0x0000000C, 0x0000000C, 0x0000000C, 0x0000000C, 0x0000000C, 0x0000000C, 0x0000000C, 0x0000000C, 0x0000000C, 0x0000000C, 0x0000000C, 0x0000000C};
    std::vector<long> d1_i = {0x0000000D, 0x0000000D, 0x0000000D, 0x0000000D, 0x0000000D, 0x0000000D, 0x0000000D, 0x0000000D, 0x0000000D, 0x0000000D, 0x0000000D, 0x0000000D};
    std::vector<long> d2_i = {0x0000000E, 0x0000000E, 0x0000000E, 0x0000000E, 0x0000000E, 0x0000000E, 0x0000000E, 0x0000000E, 0x0000000E, 0x0000000E, 0x0000000E, 0x0000000E};
    std::vector<long> d3_i = {0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F};

    std::vector<int> block_0_valid_i = {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1};
    std::vector<int> block_1_valid_i = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1};
    std::vector<int> block_2_valid_i = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1};
    std::vector<int> block_3_valid_i = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

    std::vector<long> block_0_0_data_i = {0xFFFFFFFC, 0xFFFFFFFC, 0xFFFFFFFC, 0xFFFFFFFC, 0xFFFFFFFC, 0xFFFFFFFC, 0xFFFFFFFC, 0xFFFFFFFC, 0xFFFFFFFC, 0xFFFFFFFC, 0xFFFFFFFC, 0xFFFFFFFC};
    std::vector<long> block_0_1_data_i = {0xFFFFFFFD, 0xFFFFFFFD, 0xFFFFFFFD, 0xFFFFFFFD, 0xFFFFFFFD, 0xFFFFFFFD, 0xFFFFFFFD, 0xFFFFFFFD, 0xFFFFFFFD, 0xFFFFFFFD, 0xFFFFFFFD, 0xFFFFFFFD};
    std::vector<long> block_0_2_data_i = {0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE};
    std::vector<long> block_0_3_data_i = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};

    std::vector<long> block_1_0_data_i = {0xFFFFFFF8, 0xFFFFFFF8, 0xFFFFFFF8, 0xFFFFFFF8, 0xFFFFFFF8, 0xFFFFFFF8, 0xFFFFFFF8, 0xFFFFFFF8, 0xFFFFFFF8, 0xFFFFFFF8, 0xFFFFFFF8, 0xFFFFFFF8};
    std::vector<long> block_1_1_data_i = {0xFFFFFFF9, 0xFFFFFFF9, 0xFFFFFFF9, 0xFFFFFFF9, 0xFFFFFFF9, 0xFFFFFFF9, 0xFFFFFFF9, 0xFFFFFFF9, 0xFFFFFFF9, 0xFFFFFFF9, 0xFFFFFFF9, 0xFFFFFFF9};
    std::vector<long> block_1_2_data_i = {0xFFFFFFFA, 0xFFFFFFFA, 0xFFFFFFFA, 0xFFFFFFFA, 0xFFFFFFFA, 0xFFFFFFFA, 0xFFFFFFFA, 0xFFFFFFFA, 0xFFFFFFFA, 0xFFFFFFFA, 0xFFFFFFFA, 0xFFFFFFFA};
    std::vector<long> block_1_3_data_i = {0xFFFFFFFB, 0xFFFFFFFB, 0xFFFFFFFB, 0xFFFFFFFB, 0xFFFFFFFB, 0xFFFFFFFB, 0xFFFFFFFB, 0xFFFFFFFB, 0xFFFFFFFB, 0xFFFFFFFB, 0xFFFFFFFB, 0xFFFFFFFB};

    std::vector<long> block_2_0_data_i = {0xFFFFFFF4, 0xFFFFFFF4, 0xFFFFFFF4, 0xFFFFFFF4, 0xFFFFFFF4, 0xFFFFFFF4, 0xFFFFFFF4, 0xFFFFFFF4, 0xFFFFFFF4, 0xFFFFFFF4, 0xFFFFFFF4, 0xFFFFFFF4};
    std::vector<long> block_2_1_data_i = {0xFFFFFFF5, 0xFFFFFFF5, 0xFFFFFFF5, 0xFFFFFFF5, 0xFFFFFFF5, 0xFFFFFFF5, 0xFFFFFFF5, 0xFFFFFFF5, 0xFFFFFFF5, 0xFFFFFFF5, 0xFFFFFFF5, 0xFFFFFFF5};
    std::vector<long> block_2_2_data_i = {0xFFFFFFF6, 0xFFFFFFF6, 0xFFFFFFF6, 0xFFFFFFF6, 0xFFFFFFF6, 0xFFFFFFF6, 0xFFFFFFF6, 0xFFFFFFF6, 0xFFFFFFF6, 0xFFFFFFF6, 0xFFFFFFF6, 0xFFFFFFF6};
    std::vector<long> block_2_3_data_i = {0xFFFFFFF7, 0xFFFFFFF7, 0xFFFFFFF7, 0xFFFFFFF7, 0xFFFFFFF7, 0xFFFFFFF7, 0xFFFFFFF7, 0xFFFFFFF7, 0xFFFFFFF7, 0xFFFFFFF7, 0xFFFFFFF7, 0xFFFFFFF7};

    std::vector<long> block_3_0_data_i = {0xFFFFFFF0, 0xFFFFFFF0, 0xFFFFFFF0, 0xFFFFFFF0, 0xFFFFFFF0, 0xFFFFFFF0, 0xFFFFFFF0, 0xFFFFFFF0, 0xFFFFFFF0, 0xFFFFFFF0, 0xFFFFFFF0, 0xFFFFFFF0};
    std::vector<long> block_3_1_data_i = {0xFFFFFFF1, 0xFFFFFFF1, 0xFFFFFFF1, 0xFFFFFFF1, 0xFFFFFFF1, 0xFFFFFFF1, 0xFFFFFFF1, 0xFFFFFFF1, 0xFFFFFFF1, 0xFFFFFFF1, 0xFFFFFFF1, 0xFFFFFFF1};
    std::vector<long> block_3_2_data_i = {0xFFFFFFF2, 0xFFFFFFF2, 0xFFFFFFF2, 0xFFFFFFF2, 0xFFFFFFF2, 0xFFFFFFF2, 0xFFFFFFF2, 0xFFFFFFF2, 0xFFFFFFF2, 0xFFFFFFF2, 0xFFFFFFF2, 0xFFFFFFF2};
    std::vector<long> block_3_3_data_i = {0xFFFFFFF3, 0xFFFFFFF3, 0xFFFFFFF3, 0xFFFFFFF3, 0xFFFFFFF3, 0xFFFFFFF3, 0xFFFFFFF3, 0xFFFFFFF3, 0xFFFFFFF3, 0xFFFFFFF3, 0xFFFFFFF3, 0xFFFFFFF3};

    std::vector<int> block_0_tag_i = {1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030, 1030};
    std::vector<int> block_1_tag_i = {1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031};
    std::vector<int> block_2_tag_i = {1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031, 1031};
    std::vector<int> block_3_tag_i = {1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029, 1029};

    for (int i = 0; i < A_i.size()+2; i++)
    {
        for (int clk = 0; clk<2; clk++)
        {
            tfp->dump (2*i+clk);
            top->clk = !top->clk; 
            top->eval();
        }
        top->A = A_i[i];
        top->ByteAddr = ByteAddr_i[i];
        top->d0 = d0_i[i];
        top->d1 = d1_i[i];
        top->d2 = d2_i[i];
        top->d3 = d3_i[i];

        top->cache_block_0_valid = block_0_valid_i[i];
        top->cache_block_0_tag = block_0_tag_i[i];
        top->cache_block_0_0_data = block_0_0_data_i[i];
        top->cache_block_0_1_data = block_0_1_data_i[i];
        top->cache_block_0_2_data = block_0_2_data_i[i];
        top->cache_block_0_3_data = block_0_3_data_i[i];
        top->cache_block_1_valid = block_1_valid_i[i];
        top->cache_block_1_tag = block_1_tag_i[i];
        top->cache_block_1_0_data = block_1_0_data_i[i];
        top->cache_block_1_1_data = block_1_1_data_i[i];
        top->cache_block_1_2_data = block_1_2_data_i[i];
        top->cache_block_1_3_data = block_1_3_data_i[i];
        top->cache_block_2_valid = block_2_valid_i[i];
        top->cache_block_2_tag = block_2_tag_i[i];
        top->cache_block_2_0_data = block_2_0_data_i[i];
        top->cache_block_2_1_data = block_2_1_data_i[i];
        top->cache_block_2_2_data = block_2_2_data_i[i];
        top->cache_block_2_3_data = block_2_3_data_i[i];
        top->cache_block_3_valid = block_3_valid_i[i];
        top->cache_block_3_tag = block_3_tag_i[i];
        top->cache_block_3_0_data = block_3_0_data_i[i];
        top->cache_block_3_1_data = block_3_1_data_i[i];;
        top->cache_block_3_2_data = block_3_2_data_i[i];;
        top->cache_block_3_3_data = block_3_3_data_i[i];;

        if (Verilated::gotFinish()) exit(0);
    }

    tfp->close();
    exit(0);

}
