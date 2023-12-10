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
    if (EN) begin
        if (CLR) begin
            InstrDo     <= 32'b0;
            PCD         <= 32'b0;
            PC_plus_4D  <= 32'b0;
        end
        else begin 
            InstrDo     <= InstrDi;
            PCD         <= PCF;
            PC_plus_4D  <= PC_plus_4F;
        end
    end

    assign Instr_internal = InstrDo;
    assign PCF_internal = PCD;
    assign PC_plus_4F_internal = PC_plus_4F;

endmodule
