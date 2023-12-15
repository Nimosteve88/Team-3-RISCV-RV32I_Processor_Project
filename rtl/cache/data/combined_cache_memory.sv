module combined_cache_memory #(
    DATA_WIDTH = 32
) (
    input logic [DATA_WIDTH-1:0]            address,
    input logic [DATA_WIDTH-1:0]            write_data,
    input logic                             byte_addr,
    input logic                             WEN,
    input logic                             clk,
    output logic [DATA_WIDTH-1:0]           read_data
);

logic                                       hit;
logic [DATA_WIDTH-1:0]                      d0_internal;
logic [DATA_WIDTH-1:0]                      d1_internal;
logic [DATA_WIDTH-1:0]                      d2_internal;
logic [DATA_WIDTH-1:0]                      d3_internal;
logic [DATA_WIDTH-1:0]                      cache_output;
logic [DATA_WIDTH-1:0]                      memory_output;

cache data_cache (
    .clk(clk),
    .A(address),
    .Hit(hit),
    .ByteAddr(byte_addr),
    .d0(d0_internal),
    .d1(d1_internal),
    .d2(d2_internal),
    .d3(d3_internal),
    .dout_cache(cache_output)
);

data_memory main_memory (
    .clk(clk),
    .WE(WEN),
    .A(address),
    .REN(~(hit)),
    .WD(write_data),
    .ByteAddr(byte_addr),
    .d0(d0_internal),
    .d1(d1_internal),
    .d2(d2_internal),
    .d3(d3_internal),
    .read_data_mem(memory_output)
);

rd_mux read_data_output_val (
    .read_data_memory(memory_output),
    .read_data_cache(cache_output),
    .hit(hit),
    .read_data_output(read_data)
);

endmodule
