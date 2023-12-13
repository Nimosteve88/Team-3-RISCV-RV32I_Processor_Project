module rd_mux #(
    parameter DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1:0]        read_data_memory,
    input logic [DATA_WIDTH-1:0]        read_data_cache,
    input logic                         hit,
    output logic [DATA_WIDTH-1:0]       read_data_output;
);

    assign read_data_output = hit ? read_data_cache : read_data_memory;

endmodule
