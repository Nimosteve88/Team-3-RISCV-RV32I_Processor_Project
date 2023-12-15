// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoplevel.h for the primary calling header

#include "verilated.h"

#include "Vtoplevel___024root.h"

VL_INLINE_OPT void Vtoplevel___024root___sequent__TOP__0(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdlyvval__toplevel__DOT__data__DOT__register__DOT__registers__v0;
    IData/*31:0*/ __Vdlyvval__toplevel__DOT__data__DOT__register__DOT__registers__v1;
    CData/*4:0*/ __Vdlyvdim0__toplevel__DOT__data__DOT__register__DOT__registers__v2;
    IData/*31:0*/ __Vdlyvval__toplevel__DOT__data__DOT__register__DOT__registers__v2;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__data__DOT__register__DOT__registers__v2;
    IData/*16:0*/ __Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v0;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__data_memory__DOT__data_array__v0;
    IData/*16:0*/ __Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v1;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__data_memory__DOT__data_array__v1;
    IData/*16:0*/ __Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v2;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v2;
    IData/*16:0*/ __Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v3;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v3;
    IData/*16:0*/ __Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v4;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v4;
    // Body
    __Vdlyvset__toplevel__DOT__data_memory__DOT__data_array__v0 = 0U;
    __Vdlyvset__toplevel__DOT__data_memory__DOT__data_array__v1 = 0U;
    __Vdlyvset__toplevel__DOT__data__DOT__register__DOT__registers__v2 = 0U;
    if (((IData)(vlSelf->toplevel__DOT__mem_write) 
         & (IData)(vlSelf->toplevel__DOT__byte_addr))) {
        __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v0 
            = (0xffU & vlSelf->toplevel__DOT__write_data);
        __Vdlyvset__toplevel__DOT__data_memory__DOT__data_array__v0 = 1U;
        __Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v0 
            = (0x1ffffU & vlSelf->toplevel__DOT__ALU_result);
    } else if (((IData)(vlSelf->toplevel__DOT__mem_write) 
                & (~ (IData)(vlSelf->toplevel__DOT__byte_addr)))) {
        __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v1 
            = (0xffU & vlSelf->toplevel__DOT__write_data);
        __Vdlyvset__toplevel__DOT__data_memory__DOT__data_array__v1 = 1U;
        __Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v1 
            = (0x1ffffU & vlSelf->toplevel__DOT__ALU_result);
        __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v2 
            = (0xffU & (vlSelf->toplevel__DOT__write_data 
                        >> 8U));
        __Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v2 
            = (0x1ffffU & ((IData)(1U) + vlSelf->toplevel__DOT__ALU_result));
        __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v3 
            = (0xffU & (vlSelf->toplevel__DOT__write_data 
                        >> 0x10U));
        __Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v3 
            = (0x1ffffU & ((IData)(2U) + vlSelf->toplevel__DOT__ALU_result));
        __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v4 
            = (vlSelf->toplevel__DOT__write_data >> 0x18U);
        __Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v4 
            = (0x1ffffU & ((IData)(3U) + vlSelf->toplevel__DOT__ALU_result));
    }
    __Vdlyvval__toplevel__DOT__data__DOT__register__DOT__registers__v0 
        = vlSelf->trigger_val;
    __Vdlyvval__toplevel__DOT__data__DOT__register__DOT__registers__v1 
        = vlSelf->seed;
    if (vlSelf->toplevel__DOT__reg_write) {
        __Vdlyvval__toplevel__DOT__data__DOT__register__DOT__registers__v2 
            = ((0U != (0x1fU & (vlSelf->toplevel__DOT__instruction 
                                >> 7U))) ? ((2U & (IData)(vlSelf->toplevel__DOT__result_src))
                                             ? ((1U 
                                                 & (IData)(vlSelf->toplevel__DOT__result_src))
                                                 ? vlSelf->toplevel__DOT__sign_extend_immediate
                                                 : 
                                                ((IData)(4U) 
                                                 + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg))
                                             : ((1U 
                                                 & (IData)(vlSelf->toplevel__DOT__result_src))
                                                 ? vlSelf->toplevel__DOT__read_data
                                                 : vlSelf->toplevel__DOT__ALU_result))
                : 0U);
        __Vdlyvset__toplevel__DOT__data__DOT__register__DOT__registers__v2 = 1U;
        __Vdlyvdim0__toplevel__DOT__data__DOT__register__DOT__registers__v2 
            = (0x1fU & (vlSelf->toplevel__DOT__instruction 
                        >> 7U));
    }
    if (__Vdlyvset__toplevel__DOT__data_memory__DOT__data_array__v0) {
        vlSelf->toplevel__DOT__data_memory__DOT__data_array[__Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v0] 
            = __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v0;
    }
    if (__Vdlyvset__toplevel__DOT__data_memory__DOT__data_array__v1) {
        vlSelf->toplevel__DOT__data_memory__DOT__data_array[__Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v1] 
            = __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v1;
        vlSelf->toplevel__DOT__data_memory__DOT__data_array[__Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v2] 
            = __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v2;
        vlSelf->toplevel__DOT__data_memory__DOT__data_array[__Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v3] 
            = __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v3;
        vlSelf->toplevel__DOT__data_memory__DOT__data_array[__Vdlyvdim0__toplevel__DOT__data_memory__DOT__data_array__v4] 
            = __Vdlyvval__toplevel__DOT__data_memory__DOT__data_array__v4;
    }
    vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[5U] 
        = __Vdlyvval__toplevel__DOT__data__DOT__register__DOT__registers__v0;
    vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[0x1dU] 
        = __Vdlyvval__toplevel__DOT__data__DOT__register__DOT__registers__v1;
    if (__Vdlyvset__toplevel__DOT__data__DOT__register__DOT__registers__v2) {
        vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[__Vdlyvdim0__toplevel__DOT__data__DOT__register__DOT__registers__v2] 
            = __Vdlyvval__toplevel__DOT__data__DOT__register__DOT__registers__v2;
    }
    vlSelf->a0 = vlSelf->toplevel__DOT__data__DOT__register__DOT__registers
        [0xaU];
    vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg 
        = vlSelf->toplevel__DOT__program_counter__DOT__next_PC;
    vlSelf->toplevel__DOT__instruction = ((vlSelf->toplevel__DOT__instruction_memory__DOT__instr_array
                                           [(0xffU 
                                             & vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg)] 
                                           << 0x18U) 
                                          | ((vlSelf->toplevel__DOT__instruction_memory__DOT__instr_array
                                              [(0xffU 
                                                & ((IData)(1U) 
                                                   + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg))] 
                                              << 0x10U) 
                                             | ((vlSelf->toplevel__DOT__instruction_memory__DOT__instr_array
                                                 [(0xffU 
                                                   & ((IData)(2U) 
                                                      + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg))] 
                                                 << 8U) 
                                                | vlSelf->toplevel__DOT__instruction_memory__DOT__instr_array
                                                [(0xffU 
                                                  & ((IData)(3U) 
                                                     + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg))])));
    vlSelf->toplevel__DOT__register_data_1 = vlSelf->toplevel__DOT__data__DOT__register__DOT__registers
        [(0x1fU & (vlSelf->toplevel__DOT__instruction 
                   >> 0xfU))];
    vlSelf->toplevel__DOT__write_data = vlSelf->toplevel__DOT__data__DOT__register__DOT__registers
        [(0x1fU & (vlSelf->toplevel__DOT__instruction 
                   >> 0x14U))];
}

VL_INLINE_OPT void Vtoplevel___024root___combo__TOP__0(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->toplevel__DOT__sign_extend_immediate = 
        ((4U & (IData)(vlSelf->toplevel__DOT__imm_src))
          ? ((2U & (IData)(vlSelf->toplevel__DOT__imm_src))
              ? 0xf0f0f0fU : ((1U & (IData)(vlSelf->toplevel__DOT__imm_src))
                               ? 0xf0f0f0fU : (0xfffff000U 
                                               & vlSelf->toplevel__DOT__instruction)))
          : ((2U & (IData)(vlSelf->toplevel__DOT__imm_src))
              ? ((1U & (IData)(vlSelf->toplevel__DOT__imm_src))
                  ? (((- (IData)((vlSelf->toplevel__DOT__instruction 
                                  >> 0x1fU))) << 0x14U) 
                     | ((0xff000U & vlSelf->toplevel__DOT__instruction) 
                        | ((0x800U & (vlSelf->toplevel__DOT__instruction 
                                      >> 9U)) | (0x7feU 
                                                 & (vlSelf->toplevel__DOT__instruction 
                                                    >> 0x14U)))))
                  : (((- (IData)((vlSelf->toplevel__DOT__instruction 
                                  >> 0x1fU))) << 0xcU) 
                     | ((0x800U & (vlSelf->toplevel__DOT__instruction 
                                   << 4U)) | ((0x7e0U 
                                               & (vlSelf->toplevel__DOT__instruction 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlSelf->toplevel__DOT__instruction 
                                                    >> 7U))))))
              : ((1U & (IData)(vlSelf->toplevel__DOT__imm_src))
                  ? (((- (IData)((vlSelf->toplevel__DOT__instruction 
                                  >> 0x1fU))) << 0xcU) 
                     | ((0xfe0U & (vlSelf->toplevel__DOT__instruction 
                                   >> 0x14U)) | (0x1fU 
                                                 & (vlSelf->toplevel__DOT__instruction 
                                                    >> 7U))))
                  : (((- (IData)((vlSelf->toplevel__DOT__instruction 
                                  >> 0x1fU))) << 0xcU) 
                     | (vlSelf->toplevel__DOT__instruction 
                        >> 0x14U)))));
    vlSelf->toplevel__DOT__data__DOT__ALUop2 = ((IData)(vlSelf->toplevel__DOT__ALUsrc)
                                                 ? vlSelf->toplevel__DOT__sign_extend_immediate
                                                 : vlSelf->toplevel__DOT__write_data);
    if ((4U & (IData)(vlSelf->toplevel__DOT__ALUctrl))) {
        vlSelf->toplevel__DOT__ALU_result = ((2U & (IData)(vlSelf->toplevel__DOT__ALUctrl))
                                              ? 0U : 
                                             ((1U & (IData)(vlSelf->toplevel__DOT__ALUctrl))
                                               ? 0U
                                               : (vlSelf->toplevel__DOT__register_data_1 
                                                  ^ vlSelf->toplevel__DOT__data__DOT__ALUop2)));
        vlSelf->toplevel__DOT__EQ = (1U & (IData)((
                                                   (0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlSelf->toplevel__DOT__ALUctrl))) 
                                                   & ((vlSelf->toplevel__DOT__register_data_1 
                                                       == vlSelf->toplevel__DOT__data__DOT__ALUop2)
                                                       ? 1U
                                                       : 0U))));
    } else if ((2U & (IData)(vlSelf->toplevel__DOT__ALUctrl))) {
        vlSelf->toplevel__DOT__ALU_result = ((1U & (IData)(vlSelf->toplevel__DOT__ALUctrl))
                                              ? 0U : 
                                             (vlSelf->toplevel__DOT__register_data_1 
                                              & vlSelf->toplevel__DOT__data__DOT__ALUop2));
        vlSelf->toplevel__DOT__EQ = (1U & ((~ (IData)(vlSelf->toplevel__DOT__ALUctrl)) 
                                           & ((vlSelf->toplevel__DOT__register_data_1 
                                               == vlSelf->toplevel__DOT__data__DOT__ALUop2)
                                               ? 1U
                                               : 0U)));
    } else if ((1U & (IData)(vlSelf->toplevel__DOT__ALUctrl))) {
        vlSelf->toplevel__DOT__ALU_result = (vlSelf->toplevel__DOT__register_data_1 
                                             - vlSelf->toplevel__DOT__data__DOT__ALUop2);
        vlSelf->toplevel__DOT__EQ = (1U & ((vlSelf->toplevel__DOT__register_data_1 
                                            == vlSelf->toplevel__DOT__data__DOT__ALUop2)
                                            ? 1U : 0U));
    } else {
        vlSelf->toplevel__DOT__ALU_result = (vlSelf->toplevel__DOT__register_data_1 
                                             + vlSelf->toplevel__DOT__data__DOT__ALUop2);
        vlSelf->toplevel__DOT__EQ = (1U & ((vlSelf->toplevel__DOT__register_data_1 
                                            == vlSelf->toplevel__DOT__data__DOT__ALUop2)
                                            ? 1U : 0U));
    }
    if ((0x63U == (0x7fU & vlSelf->toplevel__DOT__instruction))) {
        if ((0U == (7U & (vlSelf->toplevel__DOT__instruction 
                          >> 0xcU)))) {
            vlSelf->toplevel__DOT__PCSrc = ((IData)(vlSelf->toplevel__DOT__EQ)
                                             ? 1U : 0U);
        } else if (VL_LIKELY((1U == (7U & (vlSelf->toplevel__DOT__instruction 
                                           >> 0xcU))))) {
            vlSelf->toplevel__DOT__PCSrc = ((IData)(vlSelf->toplevel__DOT__EQ)
                                             ? 0U : 1U);
        } else {
            VL_STOP_MT("control/control_unit.sv", 29, "");
        }
        vlSelf->toplevel__DOT__ALUsrc = 0U;
        vlSelf->toplevel__DOT__reg_write = 0U;
        vlSelf->toplevel__DOT__imm_src = 2U;
        vlSelf->toplevel__DOT__ALUctrl = 1U;
        vlSelf->toplevel__DOT__mem_write = 0U;
        vlSelf->toplevel__DOT__result_src = 0U;
        vlSelf->toplevel__DOT__byte_addr = 0U;
    } else if ((0x13U == (0x7fU & vlSelf->toplevel__DOT__instruction))) {
        vlSelf->toplevel__DOT__ALUctrl = 0U;
        vlSelf->toplevel__DOT__ALUsrc = 1U;
        vlSelf->toplevel__DOT__reg_write = 1U;
        vlSelf->toplevel__DOT__PCSrc = 0U;
        vlSelf->toplevel__DOT__imm_src = 0U;
        vlSelf->toplevel__DOT__mem_write = 0U;
        vlSelf->toplevel__DOT__result_src = 0U;
        vlSelf->toplevel__DOT__byte_addr = 0U;
    } else if ((0x33U == (0x7fU & vlSelf->toplevel__DOT__instruction))) {
        vlSelf->toplevel__DOT__ALUctrl = ((0U == (7U 
                                                  & (vlSelf->toplevel__DOT__instruction 
                                                     >> 0xcU)))
                                           ? ((0x40000000U 
                                               & vlSelf->toplevel__DOT__instruction)
                                               ? 1U
                                               : 0U)
                                           : ((4U == 
                                               (7U 
                                                & (vlSelf->toplevel__DOT__instruction 
                                                   >> 0xcU)))
                                               ? 4U
                                               : ((7U 
                                                   == 
                                                   (7U 
                                                    & (vlSelf->toplevel__DOT__instruction 
                                                       >> 0xcU)))
                                                   ? 2U
                                                   : 0U)));
        vlSelf->toplevel__DOT__reg_write = 1U;
        vlSelf->toplevel__DOT__ALUsrc = 0U;
        vlSelf->toplevel__DOT__imm_src = 0U;
        vlSelf->toplevel__DOT__PCSrc = 0U;
        vlSelf->toplevel__DOT__result_src = 0U;
        vlSelf->toplevel__DOT__mem_write = 0U;
        vlSelf->toplevel__DOT__byte_addr = 0U;
    } else if ((0x6fU == (0x7fU & vlSelf->toplevel__DOT__instruction))) {
        vlSelf->toplevel__DOT__reg_write = 1U;
        vlSelf->toplevel__DOT__ALUsrc = 0U;
        vlSelf->toplevel__DOT__ALUctrl = 0U;
        vlSelf->toplevel__DOT__imm_src = 3U;
        vlSelf->toplevel__DOT__mem_write = 0U;
        vlSelf->toplevel__DOT__result_src = 2U;
        vlSelf->toplevel__DOT__PCSrc = 1U;
        vlSelf->toplevel__DOT__byte_addr = 0U;
    } else if ((0x67U == (0x7fU & vlSelf->toplevel__DOT__instruction))) {
        vlSelf->toplevel__DOT__reg_write = 1U;
        vlSelf->toplevel__DOT__ALUsrc = 1U;
        vlSelf->toplevel__DOT__ALUctrl = 0U;
        vlSelf->toplevel__DOT__imm_src = 0U;
        vlSelf->toplevel__DOT__mem_write = 0U;
        vlSelf->toplevel__DOT__result_src = 2U;
        vlSelf->toplevel__DOT__PCSrc = 2U;
        vlSelf->toplevel__DOT__byte_addr = 0U;
    } else if ((0x37U == (0x7fU & vlSelf->toplevel__DOT__instruction))) {
        vlSelf->toplevel__DOT__reg_write = 1U;
        vlSelf->toplevel__DOT__ALUsrc = 0U;
        vlSelf->toplevel__DOT__ALUctrl = 0U;
        vlSelf->toplevel__DOT__imm_src = 4U;
        vlSelf->toplevel__DOT__mem_write = 0U;
        vlSelf->toplevel__DOT__result_src = 3U;
        vlSelf->toplevel__DOT__PCSrc = 0U;
        vlSelf->toplevel__DOT__byte_addr = 0U;
    } else if ((0x23U == (0x7fU & vlSelf->toplevel__DOT__instruction))) {
        vlSelf->toplevel__DOT__reg_write = 0U;
        vlSelf->toplevel__DOT__ALUsrc = 1U;
        vlSelf->toplevel__DOT__ALUctrl = 0U;
        vlSelf->toplevel__DOT__imm_src = 1U;
        vlSelf->toplevel__DOT__mem_write = 1U;
        vlSelf->toplevel__DOT__result_src = 0U;
        vlSelf->toplevel__DOT__PCSrc = 0U;
        vlSelf->toplevel__DOT__byte_addr = 1U;
    } else if ((3U == (0x7fU & vlSelf->toplevel__DOT__instruction))) {
        vlSelf->toplevel__DOT__reg_write = 1U;
        vlSelf->toplevel__DOT__ALUsrc = 1U;
        vlSelf->toplevel__DOT__ALUctrl = 0U;
        vlSelf->toplevel__DOT__imm_src = 0U;
        vlSelf->toplevel__DOT__mem_write = 0U;
        vlSelf->toplevel__DOT__result_src = 1U;
        vlSelf->toplevel__DOT__PCSrc = 0U;
        vlSelf->toplevel__DOT__byte_addr = 1U;
    }
    vlSelf->toplevel__DOT__program_counter__DOT__next_PC 
        = ((IData)(vlSelf->rst) ? 0U : ((0U == (IData)(vlSelf->toplevel__DOT__PCSrc))
                                         ? ((IData)(4U) 
                                            + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg)
                                         : ((1U == (IData)(vlSelf->toplevel__DOT__PCSrc))
                                             ? (vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg 
                                                + vlSelf->toplevel__DOT__sign_extend_immediate)
                                             : ((2U 
                                                 == (IData)(vlSelf->toplevel__DOT__PCSrc))
                                                 ? 
                                                (vlSelf->toplevel__DOT__register_data_1 
                                                 + vlSelf->toplevel__DOT__sign_extend_immediate)
                                                 : 
                                                ((IData)(4U) 
                                                 + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg)))));
    if (vlSelf->toplevel__DOT__byte_addr) {
        if ((1U & (~ (IData)(vlSelf->toplevel__DOT__mem_write)))) {
            vlSelf->toplevel__DOT__read_data = vlSelf->toplevel__DOT__data_memory__DOT__data_array
                [(0x1ffffU & vlSelf->toplevel__DOT__ALU_result)];
        }
    } else if ((1U & (~ (IData)(vlSelf->toplevel__DOT__mem_write)))) {
        vlSelf->toplevel__DOT__read_data = ((vlSelf->toplevel__DOT__data_memory__DOT__data_array
                                             [(0x1ffffU 
                                               & ((IData)(3U) 
                                                  + vlSelf->toplevel__DOT__ALU_result))] 
                                             << 0x18U) 
                                            | ((vlSelf->toplevel__DOT__data_memory__DOT__data_array
                                                [(0x1ffffU 
                                                  & ((IData)(2U) 
                                                     + vlSelf->toplevel__DOT__ALU_result))] 
                                                << 0x10U) 
                                               | ((vlSelf->toplevel__DOT__data_memory__DOT__data_array
                                                   [
                                                   (0x1ffffU 
                                                    & ((IData)(1U) 
                                                       + vlSelf->toplevel__DOT__ALU_result))] 
                                                   << 8U) 
                                                  | vlSelf->toplevel__DOT__data_memory__DOT__data_array
                                                  [
                                                  (0x1ffffU 
                                                   & vlSelf->toplevel__DOT__ALU_result)])));
    }
}

void Vtoplevel___024root___eval(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtoplevel___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vtoplevel___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData Vtoplevel___024root___change_request_1(Vtoplevel___024root* vlSelf);

VL_INLINE_OPT QData Vtoplevel___024root___change_request(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___change_request\n"); );
    // Body
    return (Vtoplevel___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vtoplevel___024root___change_request_1(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSelf->toplevel__DOT__ALUsrc ^ vlSelf->__Vchglast__TOP__toplevel__DOT__ALUsrc)
         | (vlSelf->toplevel__DOT__ALUctrl ^ vlSelf->__Vchglast__TOP__toplevel__DOT__ALUctrl)
         | (vlSelf->toplevel__DOT__imm_src ^ vlSelf->__Vchglast__TOP__toplevel__DOT__imm_src));
    VL_DEBUG_IF( if(__req && ((vlSelf->toplevel__DOT__ALUsrc ^ vlSelf->__Vchglast__TOP__toplevel__DOT__ALUsrc))) VL_DBG_MSGF("        CHANGE: toplevel.sv:36: toplevel.ALUsrc\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->toplevel__DOT__ALUctrl ^ vlSelf->__Vchglast__TOP__toplevel__DOT__ALUctrl))) VL_DBG_MSGF("        CHANGE: toplevel.sv:37: toplevel.ALUctrl\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->toplevel__DOT__imm_src ^ vlSelf->__Vchglast__TOP__toplevel__DOT__imm_src))) VL_DBG_MSGF("        CHANGE: toplevel.sv:46: toplevel.imm_src\n"); );
    // Final
    vlSelf->__Vchglast__TOP__toplevel__DOT__ALUsrc 
        = vlSelf->toplevel__DOT__ALUsrc;
    vlSelf->__Vchglast__TOP__toplevel__DOT__ALUctrl 
        = vlSelf->toplevel__DOT__ALUctrl;
    vlSelf->__Vchglast__TOP__toplevel__DOT__imm_src 
        = vlSelf->toplevel__DOT__imm_src;
    return __req;
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
    if (VL_UNLIKELY((vlSelf->trigger_val & 0xfeU))) {
        Verilated::overWidthError("trigger_val");}
}
#endif  // VL_DEBUG
