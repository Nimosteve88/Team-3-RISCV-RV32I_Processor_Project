module decode #(
    parameter DATA_WIDTH = 32
)(
    input logic                         clk,
    input logic                         EN,
    input logic                         CLR,
    input logic [DATA_WIDTH-1:0]        InstrDi,
    input logic [DATA_WIDTH-1:0]        PCF,
    input logic [DATA_WIDTH-1:0]        PC_plus_4F,

    output logic [DATA_WIDTH-1:0]       PCD,
    output logic [DATA_WIDTH-1:0]       PC_plus_4D,  
    output logic [DATA_WIDTH-1:0]       InstrDo
);

    logic [DATA_WIDTH-1:0]              Instr_internal;
    logic [DATA_WIDTH-1:0]              PCF_internal;
    logic [DATA_WIDTH-1:0]              PC_plus_4F_internal;
    
    always_ff @(posedge clk or posedge EN or posedge CLR) begin
    if (CLR) begin
      InstrDo <= 32'b0;  // Clear the register when clr is 1
    end else if (EN) begin
      InstrDo <= InstrDi;  // Update the register with input when enable is 1
    end
  end

/*
    always_ff @(posedge CLR or posedge clk)
    if (EN) begin
        InstrDo    <= InstrDi;
        PCD        <= PCF;
        PC_plus_4D <= PC_plus_4F;
    end
    */
    

    


endmodule
