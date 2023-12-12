// Description:
// - specified as a ram
// - this is the data memory of the CPU - data memory starts from location 0x00000000 to 0x0001FFFF
// - if write_enable is asserted then it writes data, WD, into address A on the rising edge of the clock.
// - If write enable is 0, then it reads data from address A into the outputm RD
module data_memory #(
    DATA_WIDTH = 32,
    WIDTH = 8
) (
    input logic                             clk,
    input logic                             WE,
    /* verilator lint_off UNUSED */
    input logic     [DATA_WIDTH-1:0]        A,
    /* verilator lint_on UNUSED */
    input logic     [DATA_WIDTH-1:0]        WD,
    input logic                             ByteAddr,
    output logic    [DATA_WIDTH-1:0]        RD
);


logic [WIDTH-1:0] data_array [17'h1FFFF: 17'h0];


initial begin
    $display("Loading data memory");
    //$readmemh("gaussian.mem", data_array, 17'h10000);      // change parameter to correct filename. NB: the third parameter is there to start writing/ storing memory into the correct location according to the memory map
    $display("Finished loading memory");
end


// reading is asynchronous (loading)
// need to check if bits are correctly alligned - i.e. need to determine whether big endian or little endian
always_comb
begin
    if (ByteAddr) begin
        if (!WE) begin
            RD = {24'b0, data_array[A[16:0]]};
        end
    end
    else begin 
        if (!WE) begin
            assign RD = {data_array[A[16:0] + 3], data_array[A[16:0] + 2], data_array[A[16:0] + 1], data_array[A[16:0]]};
        end
    end
end


// writing is synchronous (storing)
always_ff @(posedge clk) begin
    if (WE && ByteAddr) begin
        data_array[A[16:0]] <= WD[7:0];                 // SB instruction
    end
    else if (WE && !ByteAddr) begin
        data_array[A[16:0]]         <= WD[7:0];
        data_array[A[16:0] + 1]     <= WD[15:8];
        data_array[A[16:0] + 2]     <= WD[23:16];
        data_array[A[16:0] + 3]     <= WD[31:24];
    end
end


endmodule
