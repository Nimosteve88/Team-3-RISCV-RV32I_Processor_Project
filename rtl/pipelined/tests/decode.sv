module decode #(
    parameter DATA_WIDTH = 32
)(
    input logic                         clk,
    input logic                         EN,
    input logic                         CLR,
    input logic [DATA_WIDTH-1:0]        InstrDi,

    output logic [DATA_WIDTH-1:0]       InstrDo
);

    logic   [DATA_WIDTH-1:0]            Instr_internal;
    
    always_ff @(posedge clk)
    if (EN) begin
        if (CLR) Instr_internal    <= 32'b0;
        else Instr_internal        <= InstrDi;
    end

    assign InstrDo = Instr_internal;    

endmodule
