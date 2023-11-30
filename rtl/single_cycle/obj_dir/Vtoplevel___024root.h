// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtoplevel.h for the primary calling header

#ifndef VERILATED_VTOPLEVEL___024ROOT_H_
#define VERILATED_VTOPLEVEL___024ROOT_H_  // guard

#include "verilated.h"

class Vtoplevel__Syms;

class Vtoplevel___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ toplevel__DOT__ImmSrc;
    CData/*0:0*/ toplevel__DOT__RegWrite;
    CData/*2:0*/ toplevel__DOT__ALUctrl;
    CData/*0:0*/ toplevel__DOT__ALUsrc;
    CData/*0:0*/ toplevel__DOT__PCsrc;
    CData/*0:0*/ toplevel__DOT__EQ;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    VL_OUT(a0,31,0);
    IData/*31:0*/ toplevel__DOT__instr;
    IData/*31:0*/ toplevel__DOT__ImmOp;
    IData/*31:0*/ toplevel__DOT__program_counter__DOT__branch_PC;
    IData/*31:0*/ toplevel__DOT__program_counter__DOT__inc_PC;
    IData/*31:0*/ toplevel__DOT__program_counter__DOT__next_PC;
    IData/*31:0*/ toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg;
    IData/*31:0*/ toplevel__DOT__alu_and_registers__DOT__ALUop1;
    IData/*31:0*/ toplevel__DOT__alu_and_registers__DOT__ALUop2;
    IData/*31:0*/ toplevel__DOT__alu_and_registers__DOT__ALUout;
    VlUnpacked<CData/*7:0*/, 256> toplevel__DOT__instruction_memory__DOT__instr_array;
    VlUnpacked<IData/*31:0*/, 32> toplevel__DOT__alu_and_registers__DOT__register__DOT__registers;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtoplevel__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtoplevel___024root(Vtoplevel__Syms* symsp, const char* name);
    ~Vtoplevel___024root();
    VL_UNCOPYABLE(Vtoplevel___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
