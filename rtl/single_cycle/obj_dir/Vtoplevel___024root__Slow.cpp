// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoplevel.h for the primary calling header

#include "verilated.h"

#include "Vtoplevel__Syms.h"
#include "Vtoplevel___024root.h"

void Vtoplevel___024root___ctor_var_reset(Vtoplevel___024root* vlSelf);

Vtoplevel___024root::Vtoplevel___024root(Vtoplevel__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtoplevel___024root___ctor_var_reset(this);
}

void Vtoplevel___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtoplevel___024root::~Vtoplevel___024root() {
}
