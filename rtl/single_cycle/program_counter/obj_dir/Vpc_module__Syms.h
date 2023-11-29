// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPC_MODULE__SYMS_H_
#define VERILATED_VPC_MODULE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vpc_module.h"

// INCLUDE MODULE CLASSES
#include "Vpc_module___024root.h"

// SYMS CLASS (contains all model state)
class Vpc_module__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vpc_module* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vpc_module___024root           TOP;

    // CONSTRUCTORS
    Vpc_module__Syms(VerilatedContext* contextp, const char* namep, Vpc_module* modelp);
    ~Vpc_module__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
