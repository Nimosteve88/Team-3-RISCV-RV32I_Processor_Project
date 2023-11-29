#!/bin/sh

# cleanup
rm -rf obj_dir
rm -f pc_module.vcd

# run Verilator to translate Verilog into C++, including C++ testbench
verilator -Wall --cc --trace pc_module.sv --exe pc_module_tb.cpp

# build C++ project automatically generated by Verilator
make -j -C obj_dir/ -f Vpc_module.mk Vpc_module

# run executable simulation file
obj_dir/Vpc_module