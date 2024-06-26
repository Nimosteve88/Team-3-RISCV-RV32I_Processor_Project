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
    tracep->declBit(c+57,"clk", false,-1);
    tracep->declBit(c+58,"rst", false,-1);
    tracep->declBus(c+59,"a0", false,-1, 31,0);
    tracep->declBit(c+60,"trigger_val", false,-1);
    tracep->declBus(c+61,"seed", false,-1, 31,0);
    tracep->pushNamePrefix("toplevel ");
    tracep->declBus(c+64,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+57,"clk", false,-1);
    tracep->declBit(c+58,"rst", false,-1);
    tracep->declBus(c+59,"a0", false,-1, 31,0);
    tracep->declBit(c+60,"trigger_val", false,-1);
    tracep->declBus(c+61,"seed", false,-1, 31,0);
    tracep->declBus(c+44,"sign_extend_immediate", false,-1, 31,0);
    tracep->declBus(c+45,"PCSrc", false,-1, 1,0);
    tracep->declBus(c+1,"register_data_1", false,-1, 31,0);
    tracep->declBus(c+2,"PC", false,-1, 31,0);
    tracep->declBus(c+3,"PC_plus_4", false,-1, 31,0);
    tracep->declBus(c+4,"instruction", false,-1, 31,0);
    tracep->declBit(c+46,"reg_write", false,-1);
    tracep->declBit(c+47,"ALUsrc", false,-1);
    tracep->declBus(c+48,"ALUctrl", false,-1, 2,0);
    tracep->declBus(c+62,"result_data", false,-1, 31,0);
    tracep->declBit(c+49,"EQ", false,-1);
    tracep->declBus(c+50,"ALU_result", false,-1, 31,0);
    tracep->declBus(c+5,"write_data", false,-1, 31,0);
    tracep->declBus(c+51,"result_src", false,-1, 1,0);
    tracep->declBit(c+52,"mem_write", false,-1);
    tracep->declBus(c+53,"imm_src", false,-1, 2,0);
    tracep->declBit(c+54,"byte_addr", false,-1);
    tracep->declBus(c+55,"read_data", false,-1, 31,0);
    tracep->pushNamePrefix("control ");
    tracep->declBit(c+49,"EQ", false,-1);
    tracep->declBus(c+4,"instr", false,-1, 31,0);
    tracep->declBus(c+45,"PCSrc", false,-1, 1,0);
    tracep->declBus(c+51,"ResultSrc", false,-1, 1,0);
    tracep->declBit(c+52,"MemWrite", false,-1);
    tracep->declBus(c+48,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+47,"ALUsrc", false,-1);
    tracep->declBus(c+53,"ImmSrc", false,-1, 2,0);
    tracep->declBit(c+46,"RegWrite", false,-1);
    tracep->declBit(c+54,"ByteAddr", false,-1);
    tracep->declBus(c+6,"opcode", false,-1, 6,0);
    tracep->declBit(c+7,"funct7", false,-1);
    tracep->declBus(c+8,"funct3", false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("data ");
    tracep->declBus(c+65,"REGWIDTH", false,-1, 31,0);
    tracep->declBus(c+64,"DATAWIDTH", false,-1, 31,0);
    tracep->declBit(c+57,"clk", false,-1);
    tracep->declBus(c+9,"rs1", false,-1, 4,0);
    tracep->declBus(c+10,"rs2", false,-1, 4,0);
    tracep->declBus(c+11,"rd", false,-1, 4,0);
    tracep->declBit(c+46,"RegWrite", false,-1);
    tracep->declBit(c+47,"ALUsrc", false,-1);
    tracep->declBus(c+48,"ALUctrl", false,-1, 2,0);
    tracep->declBus(c+44,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+62,"writeData", false,-1, 31,0);
    tracep->declBit(c+49,"EQ", false,-1);
    tracep->declBus(c+59,"a0", false,-1, 31,0);
    tracep->declBus(c+1,"ALUop1", false,-1, 31,0);
    tracep->declBus(c+50,"ALUout", false,-1, 31,0);
    tracep->declBus(c+5,"regOp2", false,-1, 31,0);
    tracep->declBus(c+61,"t4", false,-1, 31,0);
    tracep->declBit(c+60,"t0", false,-1);
    tracep->declBus(c+56,"ALUop2", false,-1, 31,0);
    tracep->pushNamePrefix("ALU ");
    tracep->declBus(c+64,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"SrcA", false,-1, 31,0);
    tracep->declBus(c+56,"SrcB", false,-1, 31,0);
    tracep->declBus(c+48,"ALUctrl", false,-1, 2,0);
    tracep->declBus(c+50,"ALUResult", false,-1, 31,0);
    tracep->declBit(c+49,"EQ", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("multi ");
    tracep->declBus(c+64,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+5,"d0", false,-1, 31,0);
    tracep->declBus(c+44,"d1", false,-1, 31,0);
    tracep->declBit(c+47,"ALUsrc", false,-1);
    tracep->declBus(c+56,"y", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("register ");
    tracep->declBus(c+65,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+64,"DATAWIDTH", false,-1, 31,0);
    tracep->declBus(c+9,"AD1", false,-1, 4,0);
    tracep->declBus(c+10,"AD2", false,-1, 4,0);
    tracep->declBus(c+11,"AD3", false,-1, 4,0);
    tracep->declBit(c+46,"WE3", false,-1);
    tracep->declBus(c+62,"WD3", false,-1, 31,0);
    tracep->declBit(c+57,"clk", false,-1);
    tracep->declBus(c+1,"RD1", false,-1, 31,0);
    tracep->declBus(c+5,"RD2", false,-1, 31,0);
    tracep->declBus(c+59,"a0", false,-1, 31,0);
    tracep->declBus(c+61,"t4", false,-1, 31,0);
    tracep->declBit(c+60,"t0", false,-1);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+12+i*1,"registers", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("data_memory ");
    tracep->declBus(c+64,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+66,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+57,"clk", false,-1);
    tracep->declBit(c+52,"WE", false,-1);
    tracep->declBus(c+50,"A", false,-1, 31,0);
    tracep->declBus(c+5,"WD", false,-1, 31,0);
    tracep->declBit(c+54,"ByteAddr", false,-1);
    tracep->declBus(c+55,"RD", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("instruction_memory ");
    tracep->declBus(c+64,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+2,"A", false,-1, 31,0);
    tracep->declBus(c+4,"RD", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("program_counter ");
    tracep->declBus(c+64,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+57,"clk", false,-1);
    tracep->declBit(c+58,"rst", false,-1);
    tracep->declBus(c+44,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+45,"PCSrc", false,-1, 1,0);
    tracep->declBus(c+1,"RegIn", false,-1, 31,0);
    tracep->declBus(c+2,"PC", false,-1, 31,0);
    tracep->declBus(c+3,"PC_plus_4", false,-1, 31,0);
    tracep->declBus(c+63,"next_PC", false,-1, 31,0);
    tracep->pushNamePrefix("mypc_reg ");
    tracep->declBus(c+64,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+57,"clk", false,-1);
    tracep->declBit(c+58,"rst", false,-1);
    tracep->declBus(c+63,"pcin", false,-1, 31,0);
    tracep->declBus(c+2,"pcout", false,-1, 31,0);
    tracep->declBus(c+2,"PCreg", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("result_select ");
    tracep->declBus(c+64,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+51,"result_src", false,-1, 1,0);
    tracep->declBus(c+50,"ALU_result", false,-1, 31,0);
    tracep->declBus(c+55,"read_data", false,-1, 31,0);
    tracep->declBus(c+3,"pc_plus_4", false,-1, 31,0);
    tracep->declBus(c+44,"immediate", false,-1, 31,0);
    tracep->declBus(c+62,"result", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sign_extend ");
    tracep->declBus(c+64,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+53,"Immsrc", false,-1, 2,0);
    tracep->declBus(c+4,"instr", false,-1, 31,0);
    tracep->declBus(c+44,"Immop", false,-1, 31,0);
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
    bufp->fullIData(oldp+1,(vlSelf->toplevel__DOT__register_data_1),32);
    bufp->fullIData(oldp+2,(vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg),32);
    bufp->fullIData(oldp+3,(((IData)(4U) + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg)),32);
    bufp->fullIData(oldp+4,(vlSelf->toplevel__DOT__instruction),32);
    bufp->fullIData(oldp+5,(vlSelf->toplevel__DOT__write_data),32);
    bufp->fullCData(oldp+6,((0x7fU & vlSelf->toplevel__DOT__instruction)),7);
    bufp->fullBit(oldp+7,((1U & (vlSelf->toplevel__DOT__instruction 
                                 >> 0x1eU))));
    bufp->fullCData(oldp+8,((7U & (vlSelf->toplevel__DOT__instruction 
                                   >> 0xcU))),3);
    bufp->fullCData(oldp+9,((0x1fU & (vlSelf->toplevel__DOT__instruction 
                                      >> 0xfU))),5);
    bufp->fullCData(oldp+10,((0x1fU & (vlSelf->toplevel__DOT__instruction 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+11,((0x1fU & (vlSelf->toplevel__DOT__instruction 
                                       >> 7U))),5);
    bufp->fullIData(oldp+12,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[0]),32);
    bufp->fullIData(oldp+13,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[1]),32);
    bufp->fullIData(oldp+14,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[2]),32);
    bufp->fullIData(oldp+15,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[3]),32);
    bufp->fullIData(oldp+16,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[4]),32);
    bufp->fullIData(oldp+17,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[5]),32);
    bufp->fullIData(oldp+18,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[6]),32);
    bufp->fullIData(oldp+19,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[7]),32);
    bufp->fullIData(oldp+20,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[8]),32);
    bufp->fullIData(oldp+21,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[9]),32);
    bufp->fullIData(oldp+22,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[10]),32);
    bufp->fullIData(oldp+23,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[11]),32);
    bufp->fullIData(oldp+24,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[12]),32);
    bufp->fullIData(oldp+25,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[13]),32);
    bufp->fullIData(oldp+26,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[14]),32);
    bufp->fullIData(oldp+27,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[15]),32);
    bufp->fullIData(oldp+28,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[16]),32);
    bufp->fullIData(oldp+29,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[17]),32);
    bufp->fullIData(oldp+30,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[18]),32);
    bufp->fullIData(oldp+31,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[19]),32);
    bufp->fullIData(oldp+32,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[20]),32);
    bufp->fullIData(oldp+33,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[21]),32);
    bufp->fullIData(oldp+34,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[22]),32);
    bufp->fullIData(oldp+35,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[23]),32);
    bufp->fullIData(oldp+36,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[24]),32);
    bufp->fullIData(oldp+37,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[25]),32);
    bufp->fullIData(oldp+38,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[26]),32);
    bufp->fullIData(oldp+39,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[27]),32);
    bufp->fullIData(oldp+40,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[28]),32);
    bufp->fullIData(oldp+41,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[29]),32);
    bufp->fullIData(oldp+42,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[30]),32);
    bufp->fullIData(oldp+43,(vlSelf->toplevel__DOT__data__DOT__register__DOT__registers[31]),32);
    bufp->fullIData(oldp+44,(vlSelf->toplevel__DOT__sign_extend_immediate),32);
    bufp->fullCData(oldp+45,(vlSelf->toplevel__DOT__PCSrc),2);
    bufp->fullBit(oldp+46,(vlSelf->toplevel__DOT__reg_write));
    bufp->fullBit(oldp+47,(vlSelf->toplevel__DOT__ALUsrc));
    bufp->fullCData(oldp+48,(vlSelf->toplevel__DOT__ALUctrl),3);
    bufp->fullBit(oldp+49,(vlSelf->toplevel__DOT__EQ));
    bufp->fullIData(oldp+50,(vlSelf->toplevel__DOT__ALU_result),32);
    bufp->fullCData(oldp+51,(vlSelf->toplevel__DOT__result_src),2);
    bufp->fullBit(oldp+52,(vlSelf->toplevel__DOT__mem_write));
    bufp->fullCData(oldp+53,(vlSelf->toplevel__DOT__imm_src),3);
    bufp->fullBit(oldp+54,(vlSelf->toplevel__DOT__byte_addr));
    bufp->fullIData(oldp+55,(vlSelf->toplevel__DOT__read_data),32);
    bufp->fullIData(oldp+56,(vlSelf->toplevel__DOT__data__DOT__ALUop2),32);
    bufp->fullBit(oldp+57,(vlSelf->clk));
    bufp->fullBit(oldp+58,(vlSelf->rst));
    bufp->fullIData(oldp+59,(vlSelf->a0),32);
    bufp->fullBit(oldp+60,(vlSelf->trigger_val));
    bufp->fullIData(oldp+61,(vlSelf->seed),32);
    bufp->fullIData(oldp+62,(((2U & (IData)(vlSelf->toplevel__DOT__result_src))
                               ? ((1U & (IData)(vlSelf->toplevel__DOT__result_src))
                                   ? vlSelf->toplevel__DOT__sign_extend_immediate
                                   : ((IData)(4U) + vlSelf->toplevel__DOT__program_counter__DOT__mypc_reg__DOT__PCreg))
                               : ((1U & (IData)(vlSelf->toplevel__DOT__result_src))
                                   ? vlSelf->toplevel__DOT__read_data
                                   : vlSelf->toplevel__DOT__ALU_result))),32);
    bufp->fullIData(oldp+63,(((IData)(vlSelf->rst) ? 0U
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
    bufp->fullIData(oldp+64,(0x20U),32);
    bufp->fullIData(oldp+65,(5U),32);
    bufp->fullIData(oldp+66,(8U),32);
}
