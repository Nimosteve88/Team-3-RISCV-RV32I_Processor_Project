// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoplevel.h for the primary calling header

#include "verilated.h"

#include "Vtoplevel___024root.h"

VL_ATTR_COLD void Vtoplevel___024root___initial__TOP__0(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___initial__TOP__0\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_hfa9ff1da__0;
    // Body
    VL_WRITEF("Loading instr.\n");
    __Vtemp_hfa9ff1da__0[0U] = 0x2e6d656dU;
    __Vtemp_hfa9ff1da__0[1U] = 0x72726f6dU;
    __Vtemp_hfa9ff1da__0[2U] = 0x696e7374U;
    VL_READMEM_N(true, 8, 256, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_hfa9ff1da__0)
                 ,  &(vlSelf->toplevel__DOT__instruction_memory__DOT__instr_array)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtoplevel___024root___settle__TOP__0(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->a0 = vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers
        [0xaU];
    vlSelf->toplevel__DOT__instr = ((vlSelf->toplevel__DOT__instruction_memory__DOT__instr_array
                                     [(0xffU & vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg)] 
                                     << 0x18U) | ((
                                                   vlSelf->toplevel__DOT__instruction_memory__DOT__instr_array
                                                   [
                                                   (0xffU 
                                                    & ((IData)(1U) 
                                                       + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg))] 
                                                   << 0x10U) 
                                                  | ((vlSelf->toplevel__DOT__instruction_memory__DOT__instr_array
                                                      [
                                                      (0xffU 
                                                       & ((IData)(2U) 
                                                          + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg))] 
                                                      << 8U) 
                                                     | vlSelf->toplevel__DOT__instruction_memory__DOT__instr_array
                                                     [
                                                     (0xffU 
                                                      & ((IData)(3U) 
                                                         + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg))])));
    vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUop1 
        = vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers
        [(0x1fU & (vlSelf->toplevel__DOT__instr >> 0xfU))];
    if ((0x63U == (0x7fU & vlSelf->toplevel__DOT__instr))) {
        vlSelf->toplevel__DOT__RegWrite = 0U;
        vlSelf->toplevel__DOT__ALUctrl = 1U;
        vlSelf->toplevel__DOT__ALUsrc = 0U;
        vlSelf->toplevel__DOT__ImmSrc = 0U;
    } else if ((0x13U == (0x7fU & vlSelf->toplevel__DOT__instr))) {
        vlSelf->toplevel__DOT__RegWrite = 1U;
        vlSelf->toplevel__DOT__ALUctrl = 0U;
        vlSelf->toplevel__DOT__ALUsrc = 1U;
        vlSelf->toplevel__DOT__ImmSrc = 1U;
    }
    vlSelf->toplevel__DOT__ImmOp = ((IData)(vlSelf->toplevel__DOT__ImmSrc)
                                     ? (((- (IData)(
                                                    (vlSelf->toplevel__DOT__instr 
                                                     >> 0x1fU))) 
                                         << 0xcU) | 
                                        (vlSelf->toplevel__DOT__instr 
                                         >> 0x14U))
                                     : (((- (IData)(
                                                    (vlSelf->toplevel__DOT__instr 
                                                     >> 0x1fU))) 
                                         << 0xcU) | 
                                        ((0x800U & 
                                          (vlSelf->toplevel__DOT__instr 
                                           << 4U)) 
                                         | ((0x7e0U 
                                             & (vlSelf->toplevel__DOT__instr 
                                                >> 0x14U)) 
                                            | (0x1eU 
                                               & (vlSelf->toplevel__DOT__instr 
                                                  >> 7U))))));
    vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUop2 
        = ((IData)(vlSelf->toplevel__DOT__ALUsrc) ? vlSelf->toplevel__DOT__ImmOp
            : vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers
           [(0x1fU & (vlSelf->toplevel__DOT__instr 
                      >> 0x14U))]);
    vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUout 
        = ((0U == (IData)(vlSelf->toplevel__DOT__ALUctrl))
            ? (vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUop1 
               + vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUop2)
            : 0U);
    if ((0U != (IData)(vlSelf->toplevel__DOT__ALUctrl))) {
        vlSelf->toplevel__DOT__EQ = ((1U == (IData)(vlSelf->toplevel__DOT__ALUctrl)) 
                                     & ((vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUop1 
                                         == vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUop2)
                                         ? 1U : 0U));
    }
    if ((0x63U == (0x7fU & vlSelf->toplevel__DOT__instr))) {
        vlSelf->toplevel__DOT__PCsrc = (1U & (~ (IData)(vlSelf->toplevel__DOT__EQ)));
    } else if ((0x13U == (0x7fU & vlSelf->toplevel__DOT__instr))) {
        vlSelf->toplevel__DOT__PCsrc = 0U;
    }
    if (vlSelf->rst) {
        vlSelf->toplevel__DOT__program_counter__DOT__next_PC = 0U;
    } else {
        vlSelf->toplevel__DOT__program_counter__DOT__branch_PC 
            = (vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg 
               + vlSelf->toplevel__DOT__ImmOp);
        vlSelf->toplevel__DOT__program_counter__DOT__inc_PC 
            = ((IData)(4U) + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg);
        vlSelf->toplevel__DOT__program_counter__DOT__next_PC 
            = ((IData)(vlSelf->toplevel__DOT__PCsrc)
                ? vlSelf->toplevel__DOT__program_counter__DOT__branch_PC
                : vlSelf->toplevel__DOT__program_counter__DOT__inc_PC);
    }
}

VL_ATTR_COLD void Vtoplevel___024root___eval_initial(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_initial\n"); );
    // Body
    Vtoplevel___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vtoplevel___024root___eval_settle(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_settle\n"); );
    // Body
    Vtoplevel___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtoplevel___024root___final(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___final\n"); );
}

VL_ATTR_COLD void Vtoplevel___024root___ctor_var_reset(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->a0 = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__ImmOp = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__ImmSrc = VL_RAND_RESET_I(1);
    vlSelf->toplevel__DOT__RegWrite = VL_RAND_RESET_I(1);
    vlSelf->toplevel__DOT__ALUctrl = VL_RAND_RESET_I(3);
    vlSelf->toplevel__DOT__ALUsrc = VL_RAND_RESET_I(1);
    vlSelf->toplevel__DOT__PCsrc = VL_RAND_RESET_I(1);
    vlSelf->toplevel__DOT__EQ = VL_RAND_RESET_I(1);
    vlSelf->toplevel__DOT__program_counter__DOT__branch_PC = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__program_counter__DOT__inc_PC = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__program_counter__DOT__next_PC = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->toplevel__DOT__instruction_memory__DOT__instr_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUop1 = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUop2 = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUout = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
