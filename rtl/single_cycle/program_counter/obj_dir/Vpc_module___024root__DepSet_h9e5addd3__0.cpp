// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpc_module.h for the primary calling header

#include "verilated.h"

#include "Vpc_module___024root.h"

VL_INLINE_OPT void Vpc_module___024root___sequent__TOP__0(Vpc_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root___sequent__TOP__0\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->rst)))) {
        vlSelf->PC = vlSelf->pc_module__DOT__mypc_reg__DOT__PCreg;
    }
    vlSelf->pc_module__DOT__mypc_reg__DOT__PCreg = 
        ((IData)(vlSelf->rst) ? 0U : vlSelf->pc_module__DOT__next_PC);
}

VL_INLINE_OPT void Vpc_module___024root___combo__TOP__0(Vpc_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->pc_module__DOT__branch_PC = (vlSelf->PC 
                                         + vlSelf->ImmOp);
    vlSelf->pc_module__DOT__inc_PC = ((IData)(4U) + vlSelf->PC);
    vlSelf->pc_module__DOT__next_PC = ((IData)(vlSelf->PCsrc)
                                        ? vlSelf->pc_module__DOT__branch_PC
                                        : vlSelf->pc_module__DOT__inc_PC);
}

void Vpc_module___024root___eval(Vpc_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vpc_module___024root___sequent__TOP__0(vlSelf);
    }
    Vpc_module___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vpc_module___024root___eval_debug_assertions(Vpc_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->PCsrc & 0xfeU))) {
        Verilated::overWidthError("PCsrc");}
}
#endif  // VL_DEBUG
