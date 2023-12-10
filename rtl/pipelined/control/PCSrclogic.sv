module PCSrclogic(
    input   logic           EQ,
    input   logic   [1:0]   JumpTypeE,
    input   logic   [1:0]   BranchTypeE,
    output  logic   [1:0]   PCSrcE
);

always_comb begin
    case(BranchTypeE)
        2'b00: begin
            PCSrcE <= JumpTypeE;
        end
        2'b01: begin
            PCSrcE <= (EQ) ? BranchTypeE : JumpTypeE;
        end
        2'b10: begin
            PCSrcE <= (EQ) ? JumpTypeE : ~(BranchTypeE);
        end
        default: $stop;
    endcase
end

endmodule
