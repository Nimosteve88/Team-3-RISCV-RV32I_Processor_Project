// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtoplevel__Syms.h"


VL_ATTR_COLD void Vtoplevel___024root__trace_init_sub__TOP__0(Vtoplevel___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBit(c+54,"rst", false,-1);
    tracep->declBus(c+55,"a0", false,-1, 31,0);
    tracep->pushNamePrefix("toplevel ");
    tracep->declBus(c+58,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBit(c+54,"rst", false,-1);
    tracep->declBus(c+55,"a0", false,-1, 31,0);
    tracep->declBus(c+56,"PC", false,-1, 31,0);
    tracep->declBus(c+35,"instr", false,-1, 31,0);
    tracep->declBus(c+36,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+37,"ImmSrc", false,-1);
    tracep->declBit(c+38,"RegWrite", false,-1);
    tracep->declBus(c+39,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+40,"ALUsrc", false,-1);
    tracep->declBit(c+41,"PCsrc", false,-1);
    tracep->declBit(c+42,"EQ", false,-1);
    tracep->pushNamePrefix("alu_and_registers ");
    tracep->declBus(c+59,"REGWIDTH", false,-1, 31,0);
    tracep->declBus(c+58,"DATAWIDTH", false,-1, 31,0);
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBus(c+43,"rs1", false,-1, 4,0);
    tracep->declBus(c+44,"rs2", false,-1, 4,0);
    tracep->declBus(c+45,"rd", false,-1, 4,0);
    tracep->declBit(c+38,"RegWrite", false,-1);
    tracep->declBit(c+40,"ALUsrc", false,-1);
    tracep->declBus(c+39,"ALUctrl", false,-1, 2,0);
    tracep->declBus(c+36,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+42,"EQ", false,-1);
    tracep->declBus(c+55,"a0", false,-1, 31,0);
    tracep->declBus(c+46,"ALUop1", false,-1, 31,0);
    tracep->declBus(c+57,"regOp2", false,-1, 31,0);
    tracep->declBus(c+47,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+48,"ALUout", false,-1, 31,0);
    tracep->pushNamePrefix("ALU ");
    tracep->declBus(c+58,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+46,"ALUop1", false,-1, 31,0);
    tracep->declBus(c+47,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+39,"ALUctrl", false,-1, 2,0);
    tracep->declBus(c+48,"SUM", false,-1, 31,0);
    tracep->declBit(c+42,"EQ", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("multi ");
    tracep->declBus(c+58,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+57,"d0", false,-1, 31,0);
    tracep->declBus(c+36,"d1", false,-1, 31,0);
    tracep->declBit(c+40,"ALUsrc", false,-1);
    tracep->declBus(c+47,"y", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("register ");
    tracep->declBus(c+59,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+58,"DATAWIDTH", false,-1, 31,0);
    tracep->declBus(c+43,"AD1", false,-1, 4,0);
    tracep->declBus(c+44,"AD2", false,-1, 4,0);
    tracep->declBus(c+45,"AD3", false,-1, 4,0);
    tracep->declBit(c+38,"WE3", false,-1);
    tracep->declBus(c+48,"WD3", false,-1, 31,0);
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBus(c+46,"RD1", false,-1, 31,0);
    tracep->declBus(c+57,"RD2", false,-1, 31,0);
    tracep->declBus(c+55,"a0", false,-1, 31,0);
    tracep->declBus(c+1,"a1", false,-1, 31,0);
    tracep->declBus(c+2,"t1", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+3+i*1,"registers", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("control_unit ");
    tracep->declBit(c+42,"EQ", false,-1);
    tracep->declBus(c+49,"opcode", false,-1, 6,0);
    tracep->declBit(c+38,"RegWrite", false,-1);
    tracep->declBus(c+39,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+40,"ALUsrc", false,-1);
    tracep->declBit(c+37,"ImmSrc", false,-1);
    tracep->declBit(c+41,"PCSrc", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("instruction_memory ");
    tracep->declBus(c+58,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+60,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+56,"A", false,-1, 31,0);
    tracep->declBus(c+35,"RD", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("program_counter ");
    tracep->declBus(c+58,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBit(c+54,"rst", false,-1);
    tracep->declBus(c+36,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+41,"PCsrc", false,-1);
    tracep->declBus(c+56,"PC", false,-1, 31,0);
    tracep->declBus(c+50,"branch_PC", false,-1, 31,0);
    tracep->declBus(c+51,"inc_PC", false,-1, 31,0);
    tracep->declBus(c+52,"next_PC", false,-1, 31,0);
    tracep->pushNamePrefix("mypc_reg ");
    tracep->declBus(c+58,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBit(c+54,"rst", false,-1);
    tracep->declBus(c+52,"pcin", false,-1, 31,0);
    tracep->declBus(c+56,"pcout", false,-1, 31,0);
    tracep->declBus(c+56,"PCreg", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("sign_extend ");
    tracep->declBus(c+58,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+37,"Immsrc", false,-1);
    tracep->declBus(c+35,"instr", false,-1, 31,0);
    tracep->declBus(c+36,"Immop", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtoplevel___024root__trace_init_top(Vtoplevel___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_init_top\n"); );
    // Body
    Vtoplevel___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtoplevel___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtoplevel___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtoplevel___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtoplevel___024root__trace_register(Vtoplevel___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtoplevel___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtoplevel___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtoplevel___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtoplevel___024root__trace_full_sub_0(Vtoplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtoplevel___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_full_top_0\n"); );
    // Init
    Vtoplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtoplevel___024root*>(voidSelf);
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtoplevel___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtoplevel___024root__trace_full_sub_0(Vtoplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers
                            [0xbU]),32);
    bufp->fullIData(oldp+2,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers
                            [6U]),32);
    bufp->fullIData(oldp+3,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[0]),32);
    bufp->fullIData(oldp+4,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[1]),32);
    bufp->fullIData(oldp+5,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[2]),32);
    bufp->fullIData(oldp+6,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[3]),32);
    bufp->fullIData(oldp+7,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[4]),32);
    bufp->fullIData(oldp+8,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[5]),32);
    bufp->fullIData(oldp+9,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[6]),32);
    bufp->fullIData(oldp+10,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[7]),32);
    bufp->fullIData(oldp+11,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[8]),32);
    bufp->fullIData(oldp+12,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[9]),32);
    bufp->fullIData(oldp+13,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[10]),32);
    bufp->fullIData(oldp+14,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[11]),32);
    bufp->fullIData(oldp+15,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[12]),32);
    bufp->fullIData(oldp+16,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[13]),32);
    bufp->fullIData(oldp+17,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[14]),32);
    bufp->fullIData(oldp+18,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[15]),32);
    bufp->fullIData(oldp+19,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[16]),32);
    bufp->fullIData(oldp+20,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[17]),32);
    bufp->fullIData(oldp+21,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[18]),32);
    bufp->fullIData(oldp+22,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[19]),32);
    bufp->fullIData(oldp+23,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[20]),32);
    bufp->fullIData(oldp+24,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[21]),32);
    bufp->fullIData(oldp+25,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[22]),32);
    bufp->fullIData(oldp+26,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[23]),32);
    bufp->fullIData(oldp+27,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[24]),32);
    bufp->fullIData(oldp+28,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[25]),32);
    bufp->fullIData(oldp+29,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[26]),32);
    bufp->fullIData(oldp+30,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[27]),32);
    bufp->fullIData(oldp+31,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[28]),32);
    bufp->fullIData(oldp+32,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[29]),32);
    bufp->fullIData(oldp+33,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[30]),32);
    bufp->fullIData(oldp+34,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers[31]),32);
    bufp->fullIData(oldp+35,(vlSelf->toplevel__DOT__instr),32);
    bufp->fullIData(oldp+36,(vlSelf->toplevel__DOT__ImmOp),32);
    bufp->fullBit(oldp+37,(vlSelf->toplevel__DOT__ImmSrc));
    bufp->fullBit(oldp+38,(vlSelf->toplevel__DOT__RegWrite));
    bufp->fullCData(oldp+39,(vlSelf->toplevel__DOT__ALUctrl),3);
    bufp->fullBit(oldp+40,(vlSelf->toplevel__DOT__ALUsrc));
    bufp->fullBit(oldp+41,(vlSelf->toplevel__DOT__PCsrc));
    bufp->fullBit(oldp+42,(vlSelf->toplevel__DOT__EQ));
    bufp->fullCData(oldp+43,((0x1fU & (vlSelf->toplevel__DOT__instr 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+44,((0x1fU & (vlSelf->toplevel__DOT__instr 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+45,((0x1fU & (vlSelf->toplevel__DOT__instr 
                                       >> 7U))),5);
    bufp->fullIData(oldp+46,(vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUop1),32);
    bufp->fullIData(oldp+47,(vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUop2),32);
    bufp->fullIData(oldp+48,(vlSelf->toplevel__DOT__alu_and_registers__DOT__ALUout),32);
    bufp->fullCData(oldp+49,((0x7fU & vlSelf->toplevel__DOT__instr)),7);
    bufp->fullIData(oldp+50,(vlSelf->toplevel__DOT__program_counter__DOT__branch_PC),32);
    bufp->fullIData(oldp+51,(vlSelf->toplevel__DOT__program_counter__DOT__inc_PC),32);
    bufp->fullIData(oldp+52,(vlSelf->toplevel__DOT__program_counter__DOT__next_PC),32);
    bufp->fullBit(oldp+53,(vlSelf->clk));
    bufp->fullBit(oldp+54,(vlSelf->rst));
    bufp->fullIData(oldp+55,(vlSelf->a0),32);
    bufp->fullIData(oldp+56,(vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg),32);
    bufp->fullIData(oldp+57,(vlSelf->toplevel__DOT__alu_and_registers__DOT__register__DOT__registers
                             [(0x1fU & (vlSelf->toplevel__DOT__instr 
                                        >> 0x14U))]),32);
    bufp->fullIData(oldp+58,(0x20U),32);
    bufp->fullIData(oldp+59,(5U),32);
    bufp->fullIData(oldp+60,(8U),32);
}
