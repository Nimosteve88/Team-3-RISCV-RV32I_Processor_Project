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
  
    always_ff @(posedge clk)
        if (CLR) begin
            Instr_internal      <= 32'b0;
            PCF_internal        <= 32'b0;
            PC_plus_4F_internal <= 32'b0;
        end
        else if (EN) begin 
            Instr_internal      <= InstrDi;
            PCF_internal        <= PCF;
            PC_plus_4F_internal <= PC_plus_4F;
        end

    assign InstrDo = Instr_internal;
    assign PCD = PCF_internal;
    assign PC_plus_4D = PC_plus_4F_internal;

endmodule
