// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpc_module__Syms.h"


void Vpc_module___024root__trace_chg_sub_0(Vpc_module___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vpc_module___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root__trace_chg_top_0\n"); );
    // Init
    Vpc_module___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpc_module___024root*>(voidSelf);
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vpc_module___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vpc_module___024root__trace_chg_sub_0(Vpc_module___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->pc_module__DOT__branch_PC),32);
        bufp->chgIData(oldp+1,(vlSelf->pc_module__DOT__inc_PC),32);
        bufp->chgIData(oldp+2,(vlSelf->pc_module__DOT__next_PC),32);
    }
    bufp->chgBit(oldp+3,(vlSelf->clk));
    bufp->chgBit(oldp+4,(vlSelf->rst));
    bufp->chgIData(oldp+5,(vlSelf->ImmOp),32);
    bufp->chgBit(oldp+6,(vlSelf->PCsrc));
    bufp->chgIData(oldp+7,(vlSelf->PC),32);
    bufp->chgIData(oldp+8,(vlSelf->pc_module__DOT__mypc_reg__DOT__PCreg),32);
}

void Vpc_module___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root__trace_cleanup\n"); );
    // Init
    Vpc_module___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpc_module___024root*>(voidSelf);
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
