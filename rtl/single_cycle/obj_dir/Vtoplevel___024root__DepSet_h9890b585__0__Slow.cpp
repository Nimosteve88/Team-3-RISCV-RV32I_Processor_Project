// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoplevel.h for the primary calling header

#include "verilated.h"

#include "Vtoplevel___024root.h"

VL_ATTR_COLD void Vtoplevel___024root___initial__TOP__0(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___initial__TOP__0\n"); );
    // Body
    VL_WRITEF("Loading data memory\nFinished loading memory\nLoading instr.\n");
    VL_READMEM_N(true, 8, 256, 0, std::string{"f1.mem"}
                 ,  &(vlSelf->toplevel__DOT__instruction_memory__DOT__instr_array)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtoplevel___024root___settle__TOP__0(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->a0 = vlSelf->toplevel__DOT__data__DOT__register__DOT__registers
        [0xaU];
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

VL_ATTR_COLD void Vtoplevel___024root___eval_initial(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_initial\n"); );
    // Body
    Vtoplevel___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtoplevel___024root___eval_settle(Vtoplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root___eval_settle\n"); );
    // Body
    Vtoplevel___024root___settle__TOP__0(vlSelf);
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
    vlSelf->trigger_val = VL_RAND_RESET_I(1);
    vlSelf->seed = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__sign_extend_immediate = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__PCSrc = VL_RAND_RESET_I(2);
    vlSelf->toplevel__DOT__register_data_1 = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__instruction = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__reg_write = VL_RAND_RESET_I(1);
    vlSelf->toplevel__DOT__ALUsrc = VL_RAND_RESET_I(1);
    vlSelf->toplevel__DOT__ALUctrl = VL_RAND_RESET_I(3);
    vlSelf->toplevel__DOT__EQ = VL_RAND_RESET_I(1);
    vlSelf->toplevel__DOT__ALU_result = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__write_data = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__result_src = VL_RAND_RESET_I(2);
    vlSelf->toplevel__DOT__mem_write = VL_RAND_RESET_I(1);
    vlSelf->toplevel__DOT__imm_src = VL_RAND_RESET_I(3);
    vlSelf->toplevel__DOT__byte_addr = VL_RAND_RESET_I(1);
    vlSelf->toplevel__DOT__read_data = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__program_counter__DOT__next_PC = VL_RAND_RESET_I(32);
    vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->toplevel__DOT__instruction_memory__DOT__instr_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->toplevel__DOT__data__DOT__ALUop2 = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->toplevel__DOT__data_memory__DOT__data_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__Vchglast__TOP__toplevel__DOT__ALUsrc = VL_RAND_RESET_I(1);
    vlSelf->__Vchglast__TOP__toplevel__DOT__ALUctrl = VL_RAND_RESET_I(3);
    vlSelf->__Vchglast__TOP__toplevel__DOT__imm_src = VL_RAND_RESET_I(3);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
