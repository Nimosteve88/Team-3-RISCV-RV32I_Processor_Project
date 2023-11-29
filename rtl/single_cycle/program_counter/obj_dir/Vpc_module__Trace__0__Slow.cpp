// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpc_module__Syms.h"


VL_ATTR_COLD void Vpc_module___024root__trace_init_sub__TOP__0(Vpc_module___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+4,"clk", false,-1);
    tracep->declBit(c+5,"rst", false,-1);
    tracep->declBus(c+6,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+7,"PCsrc", false,-1);
    tracep->declBus(c+8,"PC", false,-1, 31,0);
    tracep->pushNamePrefix("pc_module ");
    tracep->declBus(c+10,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+4,"clk", false,-1);
    tracep->declBit(c+5,"rst", false,-1);
    tracep->declBus(c+6,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+7,"PCsrc", false,-1);
    tracep->declBus(c+8,"PC", false,-1, 31,0);
    tracep->declBus(c+1,"branch_PC", false,-1, 31,0);
    tracep->declBus(c+2,"inc_PC", false,-1, 31,0);
    tracep->declBus(c+3,"next_PC", false,-1, 31,0);
    tracep->pushNamePrefix("mypc_reg ");
    tracep->declBus(c+10,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+4,"clk", false,-1);
    tracep->declBit(c+5,"rst", false,-1);
    tracep->declBus(c+3,"pcin", false,-1, 31,0);
    tracep->declBus(c+8,"pcout", false,-1, 31,0);
    tracep->declBus(c+9,"PCreg", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vpc_module___024root__trace_init_top(Vpc_module___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root__trace_init_top\n"); );
    // Body
    Vpc_module___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vpc_module___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpc_module___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpc_module___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vpc_module___024root__trace_register(Vpc_module___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vpc_module___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vpc_module___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vpc_module___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vpc_module___024root__trace_full_sub_0(Vpc_module___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpc_module___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root__trace_full_top_0\n"); );
    // Init
    Vpc_module___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpc_module___024root*>(voidSelf);
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vpc_module___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpc_module___024root__trace_full_sub_0(Vpc_module___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_module___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->pc_module__DOT__branch_PC),32);
    bufp->fullIData(oldp+2,(vlSelf->pc_module__DOT__inc_PC),32);
    bufp->fullIData(oldp+3,(vlSelf->pc_module__DOT__next_PC),32);
    bufp->fullBit(oldp+4,(vlSelf->clk));
    bufp->fullBit(oldp+5,(vlSelf->rst));
    bufp->fullIData(oldp+6,(vlSelf->ImmOp),32);
    bufp->fullBit(oldp+7,(vlSelf->PCsrc));
    bufp->fullIData(oldp+8,(vlSelf->PC),32);
    bufp->fullIData(oldp+9,(vlSelf->pc_module__DOT__mypc_reg__DOT__PCreg),32);
    bufp->fullIData(oldp+10,(0x20U),32);
}
