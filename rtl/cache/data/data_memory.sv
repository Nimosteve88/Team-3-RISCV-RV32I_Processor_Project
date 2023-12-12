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
    input logic                             REN,                // added for new data cache - deasserted when cache returns a hit.
    input logic     [DATA_WIDTH-1:0]        WD,
    input logic                             ByteAddr,
    output logic    [DATA_WIDTH-1:0]        d0,                 // added as data outputs to be written to cache for spatial locality
    output logic    [DATA_WIDTH-1:0]        d1,                 // ''
    output logic    [DATA_WIDTH-1:0]        d2,                 // ''
    output logic    [DATA_WIDTH-1:0]        d3,                 // ''      
    output logic    [DATA_WIDTH-1:0]        read_data_mem       // changed name for cache implementation.
);


logic [WIDTH-1:0] data_array [17'h1FFFF: 17'h0];

logic [1:0]       block_offset = A[3:2];                        // used to determine what data is sent to the cache

initial begin
    $display("Loading data memory");
    //$readmemh("gaussian.mem", data_array, 17'h10000);      // change parameter to correct filename. NB: the third parameter is there to start writing/ storing memory into the correct location according to the memory map
    $display("Finished loading memory");
end


// reading is asynchronous (loading)
// need to check if bits are correctly alligned - i.e. need to determine whether big endian or little endian


// reading is now controlled by read enable signal - REN
always_comb
begin
    if (REN) begin
        // assign new data to be written into the cache:
        case (block_offset)
            2'b00: begin
                assign d0 = {data_array[A[16:0] + 3], data_array[A[16:0] + 2], data_array[A[16:0] + 1], data_array[A[16:0]]};           // same as read_data_mem
                assign d1 = {data_array[A[16:0] + 7], data_array[A[16:0] + 6], data_array[A[16:0] + 5], data_array[A[16:0] + 4]};       // 1 word after
                assign d2 = {data_array[A[16:0] + 11], data_array[A[16:0] + 10], data_array[A[16:0] + 9], data_array[A[16:0] + 8]};     // 2 words after
                assign d3 = {data_array[A[16:0] + 15], data_array[A[16:0] + 14], data_array[A[16:0] + 13], data_array[A[16:0] + 12]};   // 3 words after
            end
            2'b01: begin
                assign d0 = {data_array[A[16:0] - 1], data_array[A[16:0] - 2], data_array[A[16:0] - 3], data_array[A[16:0] - 4]};       // 1 word before
                assign d1 = {data_array[A[16:0] + 3], data_array[A[16:0] + 2], data_array[A[16:0] + 1], data_array[A[16:0]]};           // same as read_data_mem
                assign d2 = {data_array[A[16:0] + 7], data_array[A[16:0] + 6], data_array[A[16:0] + 5], data_array[A[16:0] + 4]};       // 1 word after
                assign d3 = {data_array[A[16:0] + 11], data_array[A[16:0] + 10], data_array[A[16:0] + 9], data_array[A[16:0] + 8]};     // 2 words after
            end
            2'b10: begin
                assign d0 = {data_array[A[16:0] - 5], data_array[A[16:0] - 6], data_array[A[16:0] - 7], data_array[A[16:0] - 8]};       // 2 words before
                assign d1 = {data_array[A[16:0] - 1], data_array[A[16:0] - 2], data_array[A[16:0] - 3], data_array[A[16:0] - 4]};       // 1 word before
                assign d2 = {data_array[A[16:0] + 3], data_array[A[16:0] + 2], data_array[A[16:0] + 1], data_array[A[16:0]]};           // same as read_data_mem
                assign d3 = {data_array[A[16:0] + 7], data_array[A[16:0] + 6], data_array[A[16:0] + 5], data_array[A[16:0] + 4]};       // 1 word after
            end
            2'b11: begin
                assign d0 = {data_array[A[16:0] - 9], data_array[A[16:0] - 10], data_array[A[16:0] - 11], data_array[A[16:0] - 12]};    // 3 words before
                assign d1 = {data_array[A[16:0] - 5], data_array[A[16:0] - 6], data_array[A[16:0] - 7], data_array[A[16:0] - 8]};       // 2 words before
                assign d2 = {data_array[A[16:0] - 1], data_array[A[16:0] - 2], data_array[A[16:0] - 3], data_array[A[16:0] - 4]};       // 1 word before
                assign d3 = {data_array[A[16:0] + 3], data_array[A[16:0] + 2], data_array[A[16:0] + 1], data_array[A[16:0]]};           // same as read_data_mem
            end
        endcase
        if (ByteAddr) begin
            if (!WE) begin
                read_data_mem = {24'b0, data_array[A[16:0]]};
            end
        end
        else begin 
            if (!WE) begin
                assign read_data_mem = {data_array[A[16:0] + 3], data_array[A[16:0] + 2], data_array[A[16:0] + 1], data_array[A[16:0]]};
            end
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
