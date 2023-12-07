#!/bin/sh

# cleanup
rm -rf obj_dir
rm -f control_unit_pipelined_test.vcd

# run Verilator to translate Verilog into C++, including c++ testbench
verilator -Wall --cc --trace control_unit_pipelined_test.sv --exe control_unit_pipelined_tb.cpp

# build a c++ project via make automatically generated by Verilator
make -j -C obj_dir/ -f Vcontrol_unit_pipelined_test.mk Vcontrol_unit_pipelined_test

# run executable simulation file 
obj_dir/Vcontrol_unit_pipelined_test