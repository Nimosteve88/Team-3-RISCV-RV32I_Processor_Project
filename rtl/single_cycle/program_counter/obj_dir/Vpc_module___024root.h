// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpc_module.h for the primary calling header

#ifndef VERILATED_VPC_MODULE___024ROOT_H_
#define VERILATED_VPC_MODULE___024ROOT_H_  // guard

#include "verilated.h"

class Vpc_module__Syms;

class Vpc_module___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(PCsrc,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN(ImmOp,31,0);
    VL_OUT(PC,31,0);
    IData/*31:0*/ pc_module__DOT__branch_PC;
    IData/*31:0*/ pc_module__DOT__inc_PC;
    IData/*31:0*/ pc_module__DOT__next_PC;
    IData/*31:0*/ pc_module__DOT__mypc_reg__DOT__PCreg;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vpc_module__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpc_module___024root(Vpc_module__Syms* symsp, const char* name);
    ~Vpc_module___024root();
    VL_UNCOPYABLE(Vpc_module___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
