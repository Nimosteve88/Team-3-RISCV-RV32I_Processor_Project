// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpc_module.h for the primary calling header

#include "verilated.h"

#include "Vpc_module__Syms.h"
#include "Vpc_module___024root.h"

void Vpc_module___024root___ctor_var_reset(Vpc_module___024root* vlSelf);

Vpc_module___024root::Vpc_module___024root(Vpc_module__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpc_module___024root___ctor_var_reset(this);
}

void Vpc_module___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vpc_module___024root::~Vpc_module___024root() {
}
