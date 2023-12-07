module hazard_unit (
    // fetch
    output  logic               StallF,

    // decode
    output  logic               StallD,
    output  logic               FlushD,
    input   logic   [4:0]       Rs1D,
    input   logic   [4:0]       Rs2D,

    // execute
    output  logic               FlushE,
    input   logic   [4:0]       Rs1E,
    input   logic   [4:0]       Rs2E,
    output  logic   [1:0]       ForwardAE,
    output  logic   [1:0]       ForwardBE,
    input   logic   [1:0]       ResultSrcE,

    // memory
    input   logic   [4:0]       RdM,
    input   logic               RegWriteM,

    // write back
    input   logic   [4:0]       RdW,
    input   logic               RegWriteW,
);


endmodule
