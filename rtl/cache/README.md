# Stretch Goal 2: Pipelined Processor with Data Cache.
For this stretch goal, we will be implementing a data cache designed for both temporal and spatial locality.

### Cache Organisation:
![Alt text](image.png)

### Cache in the Top Level:
- Since the data cache interacts directly with the data memory, there needed to be some modifications to the data memory:

![Alt text](image-1.png)

### Data Cache Functionality Overview:
- The address comes from the memory pipeline register.
- It is fed into the data cache that determines whether there is a hit or not.
- If there is a hit, then output data from the data cache is sent to the MUX that has hit as a select and hence the read data (RD) is the value from cache.
- When there is a hit, the read enable (REN) for data memory is disabled, effectively bypassing data memory.
- If there is a miss, data needs to be read from data memory and needs to be written to data cache in accordance with spatial locality.
- When there is a miss, REN is high and we read from data memory as before in the pipelined and single cycle processors. Since hit is low, the MUX chooses the data from data memory to be RD.
- We also need to write new data to the cache. The correct words are determined by the block offset part of the memory address. For example, if the block offset is `01` then we need to send back data of the current memory address, the memory address + 1 word (for block offset `10`), the memory address + 2 words (for block offset `11`) and the memory address - 1 word (for block address `00`). Similar cases can be applied to the other 3 cases for the block offset.
- The new data is written into the cache and the valid bit is set to 1 regardless of previous result.