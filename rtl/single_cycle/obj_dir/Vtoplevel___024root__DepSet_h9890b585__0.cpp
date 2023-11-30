// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoplevel.h for the primary calling header

#include "verilated.h"

#include "Vtoplevel___024root.h"

VL_INLINE_OPT void Vtoplevel___024root___sequent__TOP__0(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg 
        = ((IData)(vlSelf->rst) ? 0U : vlSelf->toplevel__DOT__program_counter__DOT__next_PC);
}

VL_INLINE_OPT void Vtoplevel___024root___sequent__TOP__1(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___sequent__TOP__1\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__toplevel__DOT__alu_and_registers__DOT__register__DOT__registers__v0;
    IData/*31:0*/ __Vdlyvval__toplevel__DOT__alu_and_registers__DOT__register__DOT__registers__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__alu_and_registers__DOT__register__DOT__registers__v0;
    // Body
    __Vdlyvset__toplevel__DOT__alu_and_registers__DOT__register__DOT__registers__v0 = 0U;
    if (vlSelf->toplevel__DOT__RegWrite) {
        __Vdlyvval__toplevel__DOT__alu_and_registers__DOT__register__DOT__registers__v0 
            = vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUout;
        __Vdlyvset__toplevel__DOT__alu_and_registers__DOT__register__DOT__registers__v0 = 1U;
        __Vdlyvdim0__toplevel__DOT__alu_and_registers__DOT__register__DOT__registers__v0 
            = (0x1fU & (vlSelf->toplevel__DOT__instr 
                        >> 7U));
    }
    if (__Vdlyvset__toplevel__DOT__alu_and_registers__DOT__register__DOT__registers__v0) {
        vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[__Vdlyvdim0__toplevel__DOT__alu_and_registers__DOT__register__DOT__registers__v0] 
            = __Vdlyvval__toplevel__DOT__alu_and_registers__DOT__register__DOT__registers__v0;
    }
    vlSelf->a0 = vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers
        [0xaU];
}

VL_INLINE_OPT void Vtoplevel___024root___sequent__TOP__2(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___sequent__TOP__2\n"); );
    // Body
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
}

VL_INLINE_OPT void Vtoplevel___024root___combo__TOP__0(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___combo__TOP__0\n"); );
    // Body
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

void Vtoplevel___024root___eval(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtoplevel___024root___sequent__TOP__0(vlSelf);
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtoplevel___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtoplevel___024root___sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    Vtoplevel___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[3U] = 1U;
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vtoplevel___024root___eval_debug_assertions(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
