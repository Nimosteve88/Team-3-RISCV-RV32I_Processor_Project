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
        bufp->chgIData(oldp+0,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers
                               [0xbU]),32);
        bufp->chgIData(oldp+1,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers
                               [6U]),32);
        bufp->chgIData(oldp+2,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[0]),32);
        bufp->chgIData(oldp+3,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[1]),32);
        bufp->chgIData(oldp+4,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[2]),32);
        bufp->chgIData(oldp+5,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[3]),32);
        bufp->chgIData(oldp+6,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[4]),32);
        bufp->chgIData(oldp+7,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[5]),32);
        bufp->chgIData(oldp+8,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[6]),32);
        bufp->chgIData(oldp+9,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[7]),32);
        bufp->chgIData(oldp+10,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[8]),32);
        bufp->chgIData(oldp+11,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[9]),32);
        bufp->chgIData(oldp+12,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[10]),32);
        bufp->chgIData(oldp+13,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[11]),32);
        bufp->chgIData(oldp+14,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[12]),32);
        bufp->chgIData(oldp+15,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[13]),32);
        bufp->chgIData(oldp+16,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[14]),32);
        bufp->chgIData(oldp+17,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[15]),32);
        bufp->chgIData(oldp+18,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[16]),32);
        bufp->chgIData(oldp+19,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[17]),32);
        bufp->chgIData(oldp+20,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[18]),32);
        bufp->chgIData(oldp+21,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[19]),32);
        bufp->chgIData(oldp+22,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[20]),32);
        bufp->chgIData(oldp+23,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[21]),32);
        bufp->chgIData(oldp+24,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[22]),32);
        bufp->chgIData(oldp+25,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[23]),32);
        bufp->chgIData(oldp+26,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[24]),32);
        bufp->chgIData(oldp+27,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[25]),32);
        bufp->chgIData(oldp+28,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[26]),32);
        bufp->chgIData(oldp+29,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[27]),32);
        bufp->chgIData(oldp+30,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[28]),32);
        bufp->chgIData(oldp+31,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[29]),32);
        bufp->chgIData(oldp+32,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[30]),32);
        bufp->chgIData(oldp+33,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[31]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+34,(vlSelf->toplevel__DOT__instr),32);
        bufp->chgIData(oldp+35,(vlSelf->toplevel__DOT__ImmOp),32);
        bufp->chgBit(oldp+36,(vlSelf->toplevel__DOT__ImmSrc));
        bufp->chgBit(oldp+37,(vlSelf->toplevel__DOT__RegWrite));
        bufp->chgCData(oldp+38,(vlSelf->toplevel__DOT__ALUctrl),3);
        bufp->chgBit(oldp+39,(vlSelf->toplevel__DOT__ALUsrc));
        bufp->chgBit(oldp+40,(vlSelf->toplevel__DOT__PCsrc));
        bufp->chgBit(oldp+41,(vlSelf->toplevel__DOT__EQ));
        bufp->chgCData(oldp+42,((0x1fU & (vlSelf->toplevel__DOT__instr 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+43,((0x1fU & (vlSelf->toplevel__DOT__instr 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+44,((0x1fU & (vlSelf->toplevel__DOT__instr 
                                          >> 7U))),5);
        bufp->chgIData(oldp+45,(vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUop1),32);
        bufp->chgIData(oldp+46,(vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUop2),32);
        bufp->chgIData(oldp+47,(vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUout),32);
        bufp->chgCData(oldp+48,((0x7fU & vlSelf->toplevel__DOT__instr)),7);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+49,(vlSelf->toplevel__DOT__program_counter__DOT__branch_PC),32);
        bufp->chgIData(oldp+50,(vlSelf->toplevel__DOT__program_counter__DOT__inc_PC),32);
        bufp->chgIData(oldp+51,(vlSelf->toplevel__DOT__program_counter__DOT__next_PC),32);
    }
    bufp->chgBit(oldp+52,(vlSelf->clk));
    bufp->chgBit(oldp+53,(vlSelf->rst));
    bufp->chgIData(oldp+54,(vlSelf->a0),32);
    bufp->chgIData(oldp+55,(vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg),32);
    bufp->chgIData(oldp+56,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers
                            [(0x1fU & (vlSelf->toplevel__DOT__instr 
                                       >> 0x14U))]),32);
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
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
