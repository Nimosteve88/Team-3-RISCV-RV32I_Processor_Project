module cache #(
    DATA_WIDTH = 32,
    WIDTH = 8
) (
    input logic                             clk,
    /* verilator lint_off UNUSED */
    input logic     [DATA_WIDTH-1:0]        A,
    /* verilator lint_on UNUSED */
    output logic                            Hit,
    input logic                             ByteAddr,
    input logic    [DATA_WIDTH-1:0]         d0,                 // added as data inputs to be written to cache for spatial locality
    input logic    [DATA_WIDTH-1:0]         d1,                 // ''
    input logic    [DATA_WIDTH-1:0]         d2,                 // ''
    input logic    [DATA_WIDTH-1:0]         d3,                 // ''      
    output logic   [DATA_WIDTH-1:0]         dout_cache,

    // TESTING:
    input logic                             cache_block_0_valid,
    input logic [25:0]                      cache_block_0_tag,
    input logic [DATA_WIDTH-1:0]            cache_block_0_0_data,
    input logic [DATA_WIDTH-1:0]            cache_block_0_1_data,
    input logic [DATA_WIDTH-1:0]            cache_block_0_2_data,
    input logic [DATA_WIDTH-1:0]            cache_block_0_3_data,

    input logic                             cache_block_1_valid,
    input logic [25:0]                      cache_block_1_tag,
    input logic [DATA_WIDTH-1:0]            cache_block_1_0_data,
    input logic [DATA_WIDTH-1:0]            cache_block_1_1_data,
    input logic [DATA_WIDTH-1:0]            cache_block_1_2_data,
    input logic [DATA_WIDTH-1:0]            cache_block_1_3_data,

    input logic                             cache_block_2_valid,
    input logic [25:0]                      cache_block_2_tag,
    input logic [DATA_WIDTH-1:0]            cache_block_2_0_data,
    input logic [DATA_WIDTH-1:0]            cache_block_2_1_data,
    input logic [DATA_WIDTH-1:0]            cache_block_2_2_data,
    input logic [DATA_WIDTH-1:0]            cache_block_2_3_data,

    input logic                             cache_block_3_valid,
    input logic [25:0]                      cache_block_3_tag,
    input logic [DATA_WIDTH-1:0]            cache_block_3_0_data,
    input logic [DATA_WIDTH-1:0]            cache_block_3_1_data,
    input logic [DATA_WIDTH-1:0]            cache_block_3_2_data,
    input logic [DATA_WIDTH-1:0]            cache_block_3_3_data
);


logic [155:0] cache_array [2'h3:2'b0]; // V, tag (26 bits), 4*32 bit words

logic [DATA_WIDTH-1:0]                      pre_dout; 

logic [1:0] block_offset = A[3:2];
logic [1:0] set_number = A[5:4];
logic [25:0] tag = A[31:6];

logic WEN_cache = ~(Hit);

// TESTING:
    assign cache_array[0] = {cache_block_0_valid, cache_block_0_tag, cache_block_0_0_data, cache_block_0_1_data, cache_block_0_2_data, cache_block_0_3_data};
    assign cache_array[1] = {cache_block_1_valid, cache_block_1_tag, cache_block_1_0_data, cache_block_1_1_data, cache_block_1_2_data, cache_block_1_3_data};
    assign cache_array[2] = {cache_block_2_valid, cache_block_2_tag, cache_block_2_0_data, cache_block_2_1_data, cache_block_2_2_data, cache_block_2_3_data};
    assign cache_array[3] = {cache_block_3_valid, cache_block_3_tag, cache_block_3_0_data, cache_block_3_1_data, cache_block_3_2_data, cache_block_3_3_data};
 

// initial begin
//     cache_array[0] = 155'b0;
//     cache_array[1] = 155'b0;
//     cache_array[2] = 155'b0;
//     cache_array[3] = 155'b0;
// end


// reading is asynchronous (loading)
always_comb
begin
    //if (WEN_cache == 0) begin
        case (set_number)
                2'b00: begin
                    if ((tag == cache_array[0][153:128]) && (cache_array[0][154] == 1)) begin
                        Hit <= 1;
                        case (block_offset)
                            2'b00:          pre_dout = cache_array[0][31:0];
                            2'b01:          pre_dout = cache_array[0][63:32];
                            2'b10:          pre_dout = cache_array[0][95:64];
                            2'b11:          pre_dout = cache_array[0][127:96];
                        endcase
                    end
                    else begin
                        Hit <= 0;
                    end
                end
                2'b01: begin
                    if ((tag == cache_array[1][153:128]) && (cache_array[1][154] == 1)) begin
                        Hit <= 1;
                        case (block_offset)
                            2'b00:          pre_dout = cache_array[1][31:0];
                            2'b01:          pre_dout = cache_array[1][63:32];
                            2'b10:          pre_dout = cache_array[1][95:64];
                            2'b11:          pre_dout = cache_array[1][127:96];
                        endcase
                    end
                    else begin
                        Hit <= 0;
                    end
                end
                2'b10: begin
                    if ((tag == cache_array[2][153:128]) && (cache_array[2][154] == 1)) begin
                        Hit <= 1;
                        case (block_offset)
                            2'b00:          pre_dout = cache_array[2][31:0];
                            2'b01:          pre_dout = cache_array[2][63:32];
                            2'b10:          pre_dout = cache_array[2][95:64];
                            2'b11:          pre_dout = cache_array[2][127:96];
                        endcase
                    end
                    else begin
                        Hit <= 0;
                    end
                end
                2'b11: begin
                    if ((tag == cache_array[3][153:128]) && (cache_array[3][154] == 1)) begin
                        Hit <= 1;
                        case (block_offset)
                            2'b00:          pre_dout = cache_array[3][31:0];
                            2'b01:          pre_dout = cache_array[3][63:32];
                            2'b10:          pre_dout = cache_array[3][95:64];
                            2'b11:          pre_dout = cache_array[3][127:96];
                        endcase
                    end
                    else begin
                        Hit <= 0;
                    end
                end  
        endcase
        dout_cache <= ByteAddr ? {24'b0, pre_dout[7:0]} : pre_dout;
    //end
end


// writing is synchronous (storing)
always_ff @(posedge clk) begin
    if (WEN_cache) begin
        case (set_number)
            2'b00:          cache_array[0] = {1'b1, tag, d3, d2, d1, d0};
            2'b01:          cache_array[1] = {1'b1, tag, d3, d2, d1, d0};
            2'b10:          cache_array[2] = {1'b1, tag, d3, d2, d1, d0};
            2'b11:          cache_array[3] = {1'b1, tag, d3, d2, d1, d0};  
        endcase
    end
end

endmodule
