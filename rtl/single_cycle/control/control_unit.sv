module control_unit (
    input logic                 EQ,
    /* verilator lint_off UNUSED */
    input logic [31:0]          instr,
    /* verilator lint_on UNUSED */
    output logic [1:0]          PCSrc,
    output logic [1:0]          ResultSrc,
    output logic                MemWrite,
    output logic [2:0]          ALUctrl, // changed from [3:0]
    output logic                ALUsrc,
    output logic [2:0]          ImmSrc,
    output logic                RegWrite,
    output logic                ByteAddr // added
);
    logic [6:0] opcode = instr[6:0];
    logic        funct7 = instr[30]; //only 5th bit of funct7 is used which is bit 30 of instr word
    logic [2:0] funct3 = instr[14:12];

always_comb begin
    if (opcode == 7'b1100011) // B-type instruction - bne and beq
    begin
        case (funct3)
            3'b000: begin  // beq instruction
                PCSrc = EQ ? 2'b01 : 2'b00;
            end
            3'b001: begin // bne instruction
                PCSrc = EQ ? 2'b00 : 2'b01;
            end
            default: $stop;
        endcase
        begin
            ALUsrc   = 0;
            RegWrite = 0;
            ImmSrc = 3'b010;
            ALUctrl = 3'b001;
            MemWrite = 0;
            ResultSrc = 2'b00; //value doesn't matter here as not using ALU result
            ByteAddr = 0;
        end
    end
    
    else if (opcode == 7'b0010011)// I-type instruction - addi instruction
        begin
            ALUctrl  = 3'b000; //I-type signal
            ALUsrc   = 1;
            RegWrite = 1;
            PCSrc    = 2'b00;
            ImmSrc = 3'b000; // changed to correct value
            MemWrite = 0;
            ResultSrc = 0;
            ByteAddr = 0;
        end

    else if (opcode == 7'b0110011) // R-type instruction - add, and, xor, sub
    begin
        case (funct3)
            3'b000: // add or sub
              if (funct7) begin //sub function
                ALUctrl = 3'b001;
              end
              else begin // add function
                ALUctrl = 3'b000;
              end
            3'b100: begin // xor function for ALU
                ALUctrl = 3'b100; // changed
            end
            3'b111: begin // and function for ALU
                ALUctrl = 3'b010; 
            end
            default: begin
                ALUctrl = 3'b000;
            end
        endcase
        begin
            RegWrite = 1;
            ALUsrc = 0;
            ImmSrc = 3'b000;
            PCSrc = 2'b00;
            ResultSrc = 0;
            MemWrite = 0;
            ByteAddr = 0;
        end
    end
    
    else if (opcode == 7'b1101111) // J-type instruction - jal (fixed opcode for j-type)
        begin
            RegWrite = 1;
            ALUsrc = 1'b0;
            ALUctrl = 3'b000;
            ImmSrc = 3'b011;
            MemWrite = 0;
            ResultSrc = 2'b10;
            PCSrc = 2'b01;
            ByteAddr = 0;
        end
    
    else if (opcode == 7'b1100111) // JALR instruction
        begin
            RegWrite = 1;
            ALUsrc = 1'b1;
            ALUctrl = 3'b000; 
            ImmSrc = 3'b000; // JALR is I-type
            MemWrite = 0;
            ResultSrc = 2'b10;
            PCSrc = 2'b10; // Made PCsrc 2 bit to allow for jalr
            ByteAddr = 0; 
        end
    
    else if (opcode == 7'b0110111) // U-type instruction - LUI
        begin
            RegWrite = 1;
            ALUsrc = 0; //dont care
            ALUctrl = 0; //dont care
            ImmSrc = 3'b100;
            MemWrite = 0;
            ResultSrc = 2'b11;
            PCSrc = 0;
            ByteAddr = 0;
        end

    else if (opcode == 7'b0100011) // S-type instruction - SB
        begin
            RegWrite = 0;
            ALUsrc = 1;
            ALUctrl = 0;
            ImmSrc = 3'b001;
            MemWrite = 1;
            ResultSrc = 2'b00; //dont care
            PCSrc = 0;
            ByteAddr = 1;
        end
    
    else if  (opcode == 7'b0000011) // LBU instruction - added
    begin
        RegWrite = 1;
        ALUsrc = 1;
        ALUctrl = 0;
        ImmSrc = 3'b000;
        MemWrite = 0;
        ResultSrc = 2'b01; //dont care
        PCSrc = 0;
        ByteAddr = 1;
    end
    
    // EQ = 0;
end

endmodule
