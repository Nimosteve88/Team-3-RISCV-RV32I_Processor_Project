module controlunit (
    input logic                 EQ,
    input logic [6:0]           opcode,
    output logic                RegWrite,
    output logic [2:0]          ALUctrl, // changed from [3:0]
    output logic                ALUsrc,
    output logic                ImmSrc,
    output logic                PCSrc
);
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