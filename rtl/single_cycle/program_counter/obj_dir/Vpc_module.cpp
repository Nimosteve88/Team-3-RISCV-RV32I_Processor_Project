// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpc_module.h"
#include "Vpc_module__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vpc_module::Vpc_module(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpc_module__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , PCsrc{vlSymsp->TOP.PCsrc}
    , ImmOp{vlSymsp->TOP.ImmOp}
    , PC{vlSymsp->TOP.PC}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vpc_module::Vpc_module(const char* _vcname__)
    : Vpc_module(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpc_module::~Vpc_module() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vpc_module___024root___eval_initial(Vpc_module___024root* vlSelf);
void Vpc_module___024root___eval_settle(Vpc_module___024root* vlSelf);
void Vpc_module___024root___eval(Vpc_module___024root* vlSelf);
#ifdef VL_DEBUG
void Vpc_module___024root___eval_debug_assertions(Vpc_module___024root* vlSelf);
#endif  // VL_DEBUG
void Vpc_module___024root___final(Vpc_module___024root* vlSelf);

static void _eval_initial_loop(Vpc_module__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vpc_module___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vpc_module___024root___eval_settle(&(vlSymsp->TOP));
        Vpc_module___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vpc_module::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpc_module::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpc_module___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vpc_module___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vpc_module::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vpc_module::final() {
    Vpc_module___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpc_module::hierName() const { return vlSymsp->name(); }
const char* Vpc_module::modelName() const { return "Vpc_module"; }
unsigned Vpc_module::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vpc_module::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vpc_module___024root__trace_init_top(Vpc_module___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vpc_module___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpc_module___024root*>(voidSelf);
    Vpc_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vpc_module___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vpc_module___024root__trace_register(Vpc_module___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpc_module::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vpc_module___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
