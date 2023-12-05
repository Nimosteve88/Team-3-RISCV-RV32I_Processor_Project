// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtoplevel__Syms.h"


void Vtoplevel___024root__trace_chg_sub_0(Vtoplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtoplevel___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_chg_top_0\n"); );
    // Init
    Vtoplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtoplevel___024root*>(voidSelf);
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtoplevel___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtoplevel___024root__trace_chg_sub_0(Vtoplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->toplevel__DOT__sign_extend_immediate),32);
        bufp->chgCData(oldp+1,(vlSelf->toplevel__DOT__PCSrc),2);
        bufp->chgIData(oldp+2,(vlSelf->toplevel__DOT__register_data_1),32);
        bufp->chgIData(oldp+3,(vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg),32);
        bufp->chgIData(oldp+4,(((IData)(4U) + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg)),32);
        bufp->chgIData(oldp+5,(vlSelf->toplevel__DOT__instruction),32);
        bufp->chgBit(oldp+6,(vlSelf->toplevel__DOT__reg_write));
        bufp->chgBit(oldp+7,(vlSelf->toplevel__DOT__ALUsrc));
        bufp->chgCData(oldp+8,(vlSelf->toplevel__DOT__ALUctrl),3);
        bufp->chgIData(oldp+9,(((2U & (IData)(vlSelf->toplevel__DOT__result_src))
                                 ? ((1U & (IData)(vlSelf->toplevel__DOT__result_src))
                                     ? vlSelf->toplevel__DOT__sign_extend_immediate
                                     : ((IData)(4U) 
                                        + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg))
                                 : ((1U & (IData)(vlSelf->toplevel__DOT__result_src))
                                     ? vlSelf->toplevel__DOT__read_data
                                     : vlSelf->toplevel__DOT__ALU_result))),32);
        bufp->chgBit(oldp+10,(vlSelf->toplevel__DOT__EQ));
        bufp->chgIData(oldp+11,(vlSelf->toplevel__DOT__ALU_result),32);
        bufp->chgIData(oldp+12,(vlSelf->toplevel__DOT__write_data),32);
        bufp->chgCData(oldp+13,(vlSelf->toplevel__DOT__result_src),2);
        bufp->chgBit(oldp+14,(vlSelf->toplevel__DOT__mem_write));
        bufp->chgCData(oldp+15,(vlSelf->toplevel__DOT__imm_src),3);
        bufp->chgBit(oldp+16,(vlSelf->toplevel__DOT__byte_addr));
        bufp->chgIData(oldp+17,(vlSelf->toplevel__DOT__read_data),32);
        bufp->chgCData(oldp+18,((0x7fU & vlSelf->toplevel__DOT__instruction)),7);
        bufp->chgBit(oldp+19,((1U & (vlSelf->toplevel__DOT__instruction 
                                     >> 0x1eU))));
        bufp->chgCData(oldp+20,((7U & (vlSelf->toplevel__DOT__instruction 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+21,((0x1fU & (vlSelf->toplevel__DOT__instruction 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+22,((0x1fU & (vlSelf->toplevel__DOT__instruction 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+23,((0x1fU & (vlSelf->toplevel__DOT__instruction 
                                          >> 7U))),5);
        bufp->chgIData(oldp+24,(vlSelf->toplevel__DOT__data__DOT__ALUop2),32);
        bufp->chgIData(oldp+25,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[0]),32);
        bufp->chgIData(oldp+26,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[1]),32);
        bufp->chgIData(oldp+27,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[2]),32);
        bufp->chgIData(oldp+28,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[3]),32);
        bufp->chgIData(oldp+29,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[4]),32);
        bufp->chgIData(oldp+30,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[5]),32);
        bufp->chgIData(oldp+31,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[6]),32);
        bufp->chgIData(oldp+32,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[7]),32);
        bufp->chgIData(oldp+33,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[8]),32);
        bufp->chgIData(oldp+34,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[9]),32);
        bufp->chgIData(oldp+35,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[10]),32);
        bufp->chgIData(oldp+36,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[11]),32);
        bufp->chgIData(oldp+37,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[12]),32);
        bufp->chgIData(oldp+38,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[13]),32);
        bufp->chgIData(oldp+39,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[14]),32);
        bufp->chgIData(oldp+40,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[15]),32);
        bufp->chgIData(oldp+41,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[16]),32);
        bufp->chgIData(oldp+42,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[17]),32);
        bufp->chgIData(oldp+43,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[18]),32);
        bufp->chgIData(oldp+44,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[19]),32);
        bufp->chgIData(oldp+45,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[20]),32);
        bufp->chgIData(oldp+46,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[21]),32);
        bufp->chgIData(oldp+47,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[22]),32);
        bufp->chgIData(oldp+48,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[23]),32);
        bufp->chgIData(oldp+49,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[24]),32);
        bufp->chgIData(oldp+50,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[25]),32);
        bufp->chgIData(oldp+51,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[26]),32);
        bufp->chgIData(oldp+52,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[27]),32);
        bufp->chgIData(oldp+53,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[28]),32);
        bufp->chgIData(oldp+54,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[29]),32);
        bufp->chgIData(oldp+55,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[30]),32);
        bufp->chgIData(oldp+56,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[31]),32);
    }
    bufp->chgBit(oldp+57,(vlSelf->clk));
    bufp->chgBit(oldp+58,(vlSelf->rst));
    bufp->chgIData(oldp+59,(vlSelf->a0),32);
    bufp->chgBit(oldp+60,(vlSelf->trigger_val));
    bufp->chgIData(oldp+61,(vlSelf->seed),32);
    bufp->chgIData(oldp+62,(((IData)(vlSelf->rst) ? 0U
                              : ((0U == (IData)(vlSelf->toplevel__DOT__PCSrc))
                                  ? ((IData)(4U) + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg)
                                  : ((1U == (IData)(vlSelf->toplevel__DOT__PCSrc))
                                      ? (vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg 
                                         + vlSelf->toplevel__DOT__sign_extend_immediate)
                                      : ((2U == (IData)(vlSelf->toplevel__DOT__PCSrc))
                                          ? (vlSelf->toplevel__DOT__register_data_1 
                                             + vlSelf->toplevel__DOT__sign_extend_immediate)
                                          : ((IData)(4U) 
                                             + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg)))))),32);
}

void Vtoplevel___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_cleanup\n"); );
    // Init
    Vtoplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtoplevel___024root*>(voidSelf);
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
