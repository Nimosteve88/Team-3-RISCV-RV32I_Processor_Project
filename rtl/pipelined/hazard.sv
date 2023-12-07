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
    input   logic               RegWriteW
);

always_comb begin
    // ** Data Hazard Forwarding Logic:

    // Check if the source register (Rs1R) matches the destination register (RdM) in the memory stage (M) 
    // AND if register write is enabled in the memory stage (RegWriteM)
    // AND if the source register is not zero (Rs1E != 0)
    if ((Rs1R == RdM) & RegWriteM) & (Rs1E != 0) begin
        // If all conditions are met, set ForwardAE to 10
        ForwardAE = 10
    end

    // Check if the source register (Rs1E) matches the destination register (RdW) in the write-back stage (W)
    // AND if register write is enabled in the write-back stage (RegWriteW)
    // AND if the source register is not zero (Rs1E != 0)
    else if ((Rs1E == RdW) & RegWriteW) & (Rs1E != 0) begin
        // If all conditions are met, set ForwardAE to 01
        ForwardAE = 01
    end

    // If none of the above conditions are met, set ForwardAE to 00
    else begin
        ForwardAE = 00
    end

    // ** Data Hazard Stalls Logic (Occurs when a load hazard takes place):

    // Check if there is a result from the source in the execution stage (ResultSrcE0)
    // AND if either the source register 1 (Rs1D) matches the destination register in the execute stage (RdE)
    // OR if the source register 2 (Rs2D) matches the destination register in the execute stage (RdE)
    lwStall = ResultSrcE0 & ((Rs1D == RdE) | (Rs2D == RdE))

    // Set various pipeline stage stall signals based on the load hazard condition
    // If lwStall is true, set StallF, StallD, FlushE to true, indicating stalls in Fetch, Decode, and Execute stages
    StallF = StallD = FlushE = lwStall
end

endmodule
