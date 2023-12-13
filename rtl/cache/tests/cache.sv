module cache #(
    DATA_WIDTH = 32,
    WIDTH = 8
) (
    input logic                             clk,
    input logic                             WEN_cache,
    /* verilator lint_off UNUSED */
    input logic     [DATA_WIDTH-1:0]        A,
    /* verilator lint_on UNUSED */
    input logic     [DATA_WIDTH-1:0]        WData,
    output logic                            Hit,
    input logic                             ByteAddr,
    input logic    [DATA_WIDTH-1:0]         d0,                 // added as data outputs to be written to cache for spatial locality
    input logic    [DATA_WIDTH-1:0]         d1,                 // ''
    input logic    [DATA_WIDTH-1:0]         d2,                 // ''
    input logic    [DATA_WIDTH-1:0]         d3,                 // ''      
    input logic    [DATA_WIDTH-1:0]         read_data_mem,      // changed name for cache implementation.
    output logic   [DATA_WIDTH-1:0]         dout_cache
);


logic [155:0] cache_array [2'h3:2'b0]; // V, tag (27 bits), 4*32 bit words
logic [DATA_WIDTH-1:0]                      pre_dout; 

initial begin
    cache_array[0] = 156'b0;
    cache_array[1] = 156'b0;
    cache_array[2] = 156'b0;
    cache_array[3] = 156'b0;
end


// reading is asynchronous (loading)
always_comb
begin
    if (WEN_cache == 0) begin
        case (A[5:4])
                2'b00: begin
                    if ((A[30:6] == cache_array[0][30:6]) && (cache_array[0][155] == 1)) begin
                        Hit <= 1;
                        case (A[3:2])
                            2'b00: begin
                                pre_dout <= cache_array[0][31:0];
                            end
                            2'b01: begin
                                pre_dout <= cache_array[0][63:32];
                            end
                            2'b10: begin
                                pre_dout <= cache_array[0][95:64];
                            end
                            2'b11: begin
                                pre_dout <= cache_array[0][127:96];
                            end
                        endcase
                    end
                    else begin
                        Hit <= 0;
                    end
                end
                2'b01: begin
                    if ((A[30:6] == cache_array[1][30:6]) && (cache_array[1][155] == 1)) begin
                        Hit <= 1;
                        case (A[3:2])
                            2'b00: begin
                                pre_dout <= cache_array[1][31:0];
                            end
                            2'b01: begin
                                pre_dout <= cache_array[1][63:32];
                            end
                            2'b10: begin
                                pre_dout <= cache_array[1][95:64];
                            end
                            2'b11: begin
                                pre_dout <= cache_array[1][127:96];
                            end
                        endcase
                    end
                    else begin
                        Hit <= 0;
                    end
                end
                2'b10: begin
                    if ((A[30:6] == cache_array[2][30:6]) && (cache_array[2][155] == 1)) begin
                        Hit <= 1;
                        case (A[3:2])
                            2'b00: begin
                                pre_dout <= cache_array[2][31:0];
                            end
                            2'b01: begin
                                pre_dout <= cache_array[2][63:32];
                            end
                            2'b10: begin
                                pre_dout <= cache_array[2][95:64];
                            end
                            2'b11: begin
                                pre_dout <= cache_array[2][127:96];
                            end
                        endcase
                    end
                    else begin
                        Hit <= 0;
                    end
                end
                2'b11: begin
                    if ((A[30:6] == cache_array[3][30:6]) && (cache_array[3][155] == 1)) begin
                        Hit <= 1;
                        case (A[3:2])
                            2'b00: begin
                                pre_dout <= cache_array[3][31:0];
                            end
                            2'b01: begin
                                pre_dout <= cache_array[3][63:32];
                            end
                            2'b10: begin
                                pre_dout <= cache_array[3][95:64];
                            end
                            2'b11: begin
                                pre_dout <= cache_array[3][127:96];
                            end
                        endcase
                    end
                    else begin
                        Hit <= 0;
                    end
                end  
        endcase
        if (ByteAddr) begin
            case (A[1:0])
                2'b00: begin
                    dout_cache <= {(DATA_WIDTH-1:WIDTH)'b0, pre_dout[7:0]};
                end
                2'b01: begin
                    dout_cache <= {(DATA_WIDTH-1:WIDTH)'b0, pre_dout[15:8]};
                end
                2'b10: begin
                    dout_cache <= {(DATA_WIDTH-1:WIDTH)'b0, pre_dout[23:16]};
                end
                2'b00: begin
                    dout_cache <= {(DATA_WIDTH-1:WIDTH)'b0, pre_dout[31:24]};
                end
            endcase
        end
        else dout_cache <= pre_dout;
    end
end


// writing is synchronous (storing)
always_ff @(posedge clk) begin
    if (WEN_cache) begin
        case (A[5:4])
            2'b00: begin
                assign cache_array[0] = {1'b1, A[DATA_WIDTH:6], d3, d2, d1, d0};
            end
            2'b01: begin
                assign cache_array[1] = {1'b1, A[DATA_WIDTH:6], d3, d2, d1, d0};
            end
            2'b10: begin
                assign cache_array[2] = {1'b1, A[DATA_WIDTH:6], d3, d2, d1, d0};
            end
            2'b11: begin
                assign cache_array[3] = {1'b1, A[DATA_WIDTH:6], d3, d2, d1, d0};
            end  
        endcase
    end
end


endmodule