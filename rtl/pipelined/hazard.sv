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
    input   logic   [4:0]       RdE,
    input   logic   [4:0]       Rs1E,
    input   logic   [4:0]       Rs2E,
    output  logic   [1:0]       ForwardAE,
    output  logic   [1:0]       ForwardBE,
    input   logic   [1:0]       ResultSrcE,
    input   logic   [1:0]       PCSrcE,

    // memory
    input   logic   [4:0]       RdM,
    input   logic               RegWriteM,

    // write back
    input   logic   [4:0]       RdW,
    input   logic               RegWriteW
);

    logic                       lwStall;            // flag for load word instructions
    logic                       branch_or_jump;     // flag for branch or jump instructions

always_comb begin
    // ** Data Hazard Forwarding Logic:

    // Check if the source register (Rs1R) matches the destination register (RdM) in the memory stage (M) 
    // AND if register write is enabled in the memory stage (RegWriteM)
    // AND if the source register is not zero (Rs1E != 0)
    if (((Rs1E == RdM) && RegWriteM) && (Rs1E != 0)) begin
        // If all conditions are met, set ForwardAE to 10
        ForwardAE = 2'b10;
    end

    // Check if the source register (Rs1E) matches the destination register (RdW) in the write-back stage (W)
    // AND if register write is enabled in the write-back stage (RegWriteW)
    // AND if the source register is not zero (Rs1E != 0)
    else if (((Rs1E == RdW) && RegWriteW) && (Rs1E != 0)) begin
        // If all conditions are met, set ForwardAE to 01
        ForwardAE = 2'b01;
    end

    // If none of the above conditions are met, set ForwardAE to 00
    else begin
        ForwardAE = 2'b00;
    end

    // The same goes for Rs2 and ForwardBE
     if (((Rs2E == RdM) && RegWriteM) && (Rs2E != 0)) begin
        ForwardBE = 2'b10;
    end

    else if (((Rs2E == RdW) && RegWriteW) && (Rs2E != 0)) begin
        ForwardBE = 2'b01;
    end

    else begin
        ForwardBE = 2'b00;
    end



    // ** Data Hazard Stalls Logic (Occurs when a load hazard takes place):

    // Check if there is a result from the source in the execution stage (ResultSrcE0)
    // AND if either the source register 1 (Rs1D) matches the destination register in the execute stage (RdE)
    // OR if the source register 2 (Rs2D) matches the destination register in the execute stage (RdE)
    lwStall = ((ResultSrcE == 2'b01) && ((Rs1D == RdE) || (Rs2D == RdE)));

    // Set various pipeline stage stall signals based on the load hazard condition
    // If lwStall is true, set StallF, StallD, to true, indicating stalls in Fetch, Decode, and Execute stages
    StallF = lwStall;
    StallD = lwStall;




    // ** Flush decode and execute staged when a branch is taken or a load introduces a bubble:
    // 2 cycle stall for lw instructions, avoiding execute for instructions following taken jumps or branches
    branch_or_jump = ((PCSrcE == 2'b01) || (PCSrcE == 2'b10));
    FlushD = branch_or_jump;
    FlushE = lwStall || branch_or_jump;

end

endmodule
