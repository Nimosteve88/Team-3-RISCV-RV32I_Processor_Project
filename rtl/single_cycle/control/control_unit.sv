module controlunit (
    input logic                 Zero,
    input logic [31:0]          instr,
    output logic                PCSrc,
    output logic                ResultSrc,
    output logic                MemWrite,
    output logic [2:0]          ALUctrl, // changed from [3:0]
    output logic                ALUsrc,
    output logic [2:0]          ImmSrc,
    output logic                RegWrite
);
    logic [6:0] opcode = instr[6:0];
    logic        funct7 = instr[30]; //only 5th bit of funct7 is used which is bit 30 of instr word
    logic [2:0] funct3 = instr[14:12];

always_comb begin
    if (opcode == 7'b1100011) // B-type instruction - bne and beq
        case (funct3)
            3'b000: begin  // beq instruction
                ALUctrl <= 3'b111;
            end
            3'b001: begin // bne instruction
                ALUctrl <= 3'b101;
            end
        endcase
        begin
            ALUsrc   <= 0;
            RegWrite <= 0;
            PCSrc <= Zero; // ALU determines whether branch is necessary so using Zero signal from ALU
            ImmSrc <= 3'b010;
            MemWrite <= 0;
            ResultSrc <= 0; //value doesn't matter here as not using ALU result
        end
    
    else if (opcode == 7'b0010011)// I-type instruction - addi instruction
        begin
            ALUctrl  <= 3'b000; //I-type signal
            ALUsrc   <= 1;
            RegWrite <= 1;
            PCSrc    <= 2'b00;
            ImmSrc <= 1;
            MemWrite <= 0;
            ResultSrc <= 0;
        end

    else if (opcode == 7'b0110011) // R-type instruction - add, and, xor, sub
        case (funct3)
            3'b000: // add or sub
              if (funct7) begin //sub function
                ALUctrl <= 3'b001;
              end
              else begin // add function
                ALUctrl <= 3'b000;
              end
            3'b100: begin // xor function for ALU
                ALUctrl <= 3'b010; 
            end
            3'b111: begin // and function for ALU
                ALUctrl <= 3'b011; 
            end
            default: begin
                ALUctrl <= 3'b000;
            end
        endcase
        begin
            RegWrite <= 1;
            ALUsrc <= 0;
            ImmSrc <= 3'b??;
            PCSrc <= 2'b00;
            ResultSrc <= 0;
            MemWrite <= 0;
        end
    
    else if (opcode == 7'b1101111) // J-type instruction - jal (fixed opcode for j-type)
        begin
            RegWrite <= 1;
            ALUsrc <= 1'b?;
            ALUctrl <= 3'b???;
            ImmSrc <= 3'b011;
            MemWrite <= 0;
            ResultSrc <= 2'b10;
            PCSrc <= 2'b01;
        end
    
    else if (opcode == 7'b1100111) // JALR instruction
        begin
            RegWrite <= 0;
            ALUsrc <= 1'b1;
            ALUctrl <= 3'b000; // alu adds rs1 value and immediate to then feed it back to the pc immediate input
            ImmSrc <= 3'b000; // JALR is I-type
            MemWrite <= 0;
            ResultSrc <= 2'b10;
            PCSrc <= 2'b10; // Made PCsrc 2 bit to allow for jalr
        end
    
    // EQ = 0;
end

endmodule
