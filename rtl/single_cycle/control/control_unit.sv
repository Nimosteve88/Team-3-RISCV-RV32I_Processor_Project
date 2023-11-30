module controlunit (
    input logic                 EQ,
    input logic [31:0]          instr,
    output logic                PCSrc,
    output logic                ResultSrc,
    output logic                MemWrite,
    output logic [2:0]          ALUctrl, // changed from [3:0]
    output logic                ALUsrc,
    output logic [1:0]          ImmSrc,
    output logic                RegWrite
);
    logic [6:0] opcode = instr[6:0];
    logic [6:0] funct7 = instr[31:25];
    logic [2:0] funct3 = instr[14:12];
always_comb begin
    if (opcode == 7'b1100011) // B-type instruction - branch not equals
        begin
            ALUctrl  <= 3'b001; //B-type signal
            ALUsrc   <= 0;
            RegWrite <= 0;
            PCSrc <= ~(EQ);
            ImmSrc <= 0;
        end
    
    else if (opcode == 7'b0010011)// I-type instruction - addi instruction
        begin
            ALUctrl  <= 3'b000; //I-type signal
            ALUsrc   <= 1;
            RegWrite <= 1;
            PCSrc    <= 0;
            ImmSrc <= 1;
        end
    
    // EQ = 0;
end

endmodule
