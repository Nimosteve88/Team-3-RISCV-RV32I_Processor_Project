// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpc_module.h for the primary calling header

#include "verilated.h"

#include "Vpc_module___024root.h"

VL_ATTR_COLD void Vpc_module___024root___eval_initial(Vpc_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vpc_module___024root___combo__TOP__0(Vpc_module___024root* vlSelf);

VL_ATTR_COLD void Vpc_module___024root___eval_settle(Vpc_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root___eval_settle\n"); );
    // Body
    Vpc_module___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vpc_module___024root___final(Vpc_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root___final\n"); );
}

VL_ATTR_COLD void Vpc_module___024root___ctor_var_reset(Vpc_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->ImmOp = VL_RAND_RESET_I(32);
    vlSelf->PCsrc = VL_RAND_RESET_I(1);
    vlSelf->PC = VL_RAND_RESET_I(32);
    vlSelf->pc_module__DOT__branch_PC = VL_RAND_RESET_I(32);
    vlSelf->pc_module__DOT__inc_PC = VL_RAND_RESET_I(32);
    vlSelf->pc_module__DOT__next_PC = VL_RAND_RESET_I(32);
    vlSelf->pc_module__DOT__mypc_reg__DOT__PCreg = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
