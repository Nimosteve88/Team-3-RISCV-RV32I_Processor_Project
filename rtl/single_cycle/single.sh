#!/bin/sh

# cleanup
rm -rf obj_dir
rm -f toplevel.vcd

# run Verilator to translate Verilog into C++, including c++ testbench
verilator -Wall --cc --trace toplevel.sv --exe toplevel_tb.cpp

# build a c++ project via make automatically generated by Verilator
make -j -C obj_dir/ -f Vtoplevel.mk Vtoplevel

# run executable simulation file 
obj_dir/Vtoplevel