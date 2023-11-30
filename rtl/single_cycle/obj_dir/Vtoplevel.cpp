// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtoplevel.h"
#include "Vtoplevel__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtoplevel::Vtoplevel(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtoplevel__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , a0{vlSymsp->TOP.a0}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtoplevel::Vtoplevel(const char* _vcname__)
    : Vtoplevel(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtoplevel::~Vtoplevel() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vtoplevel___024root___eval_initial(Vtoplevel___024root* vlSelf);
void Vtoplevel___024root___eval_settle(Vtoplevel___024root* vlSelf);
void Vtoplevel___024root___eval(Vtoplevel___024root* vlSelf);
#ifdef VL_DEBUG
void Vtoplevel___024root___eval_debug_assertions(Vtoplevel___024root* vlSelf);
#endif  // VL_DEBUG
void Vtoplevel___024root___final(Vtoplevel___024root* vlSelf);

static void _eval_initial_loop(Vtoplevel__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vtoplevel___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vtoplevel___024root___eval_settle(&(vlSymsp->TOP));
        Vtoplevel___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vtoplevel::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtoplevel::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtoplevel___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vtoplevel___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vtoplevel::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vtoplevel::final() {
    Vtoplevel___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtoplevel::hierName() const { return vlSymsp->name(); }
const char* Vtoplevel::modelName() const { return "Vtoplevel"; }
unsigned Vtoplevel::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vtoplevel::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtoplevel___024root__trace_init_top(Vtoplevel___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtoplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtoplevel___024root*>(voidSelf);
    Vtoplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vtoplevel___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vtoplevel___024root__trace_register(Vtoplevel___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtoplevel::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtoplevel___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
