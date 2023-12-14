# Pipelined Processor
## Contents
[File Listing](#file-listing)  
[Testing Instructions](#testing-instructions)  
[Test Results](#test-results)   
[Documentation](#documentation)  

## File Listing
> [!IMPORTANT] 
> This file listing contains only the components that required changing for this version, components that are in the top level, but aren't listed remained the same in terms of individual functonality to that of the single cycle processor. You can see the file listing for those parts on the [single cycle file listing](https://github.com/Nimosteve88/Team-3-RISCV-RV32I_Processor_Project/tree/main/rtl/single_cycle#file-listing). Alternatively, you can also view a [combined file listing](https://github.com/Nimosteve88/Team-3-RISCV-RV32I_Processor_Project/tree/main?tab=readme-ov-file#combined-file-listing), with files from all goals.

Key: `x`: full responsibility; `p`: partial responsibility; `t`: testing

| File Name                 | Steve | Sne | Divine | Yannis |
|---------------------------|-------|-----|--------|--------|
| control_unit_pipelined.sv |       | t   |        |        |
| decode.sv                 |       | t   |        |        |
| execute.sv                |       | t   |        |        |
| fetch.sv                  |       | t   |        |        |
| hazard.sv                 |       | t   |        |        |
| memory.sv                 |       | t   |        |        |
| pc_reg.sv                 |       |     |        |        |
| PCSrclogic.sv             |       | t   |        |        |
| rd1emux.sv                |       |     |        |        |
| rd2emux.sv                |       |     |        |        |
| top_level.sv              |       | x/t   |        |        |
| write_back.sv             |       | t   |        |        |

## Testing Instructions
#### Testing the Formula 1 Program
1. Set up a connection to Vbuddy.
2. `cd` into the `pipelined` directory
3. Open the directory in VSCode - this is to edit the code so that correct instructions are run.
4. In `instruction_memory.sv` (located in the control folder) edit line 13 to the following:
```verilog
    $readmemh("f1.mem", instr_array);
```

5. In `data_memory.sv` (located in the data folder) comment out line 26 (we do not need to read anything into data memory for the F1 program):
```verilog
    //$readmemh("gaussian.mem", data_array, 17'h10000);
```

> [!NOTE]
> The commented out code has `gaussian.mem` in it - ignore this, this could have been any .mem file, for the sake of the F1 program, we don't care.

6. In the top level test bench file (`toplevel_tb.cpp`) comment out the code for the reference program and make sure that the code for the F1 program is uncommented:
```cpp
        // reference program
        // if (simcyc > 1300000 && simcyc % 2 == 0)
        // {  
        //     vbdPlot(int(top->a0), 0, 255);
        //     vbdCycle(simcyc);
        // }
        // end of reference program
        

        // F1 program:
        vbdCycle(simcyc);
        top->trigger_val = vbdFlag(); 
        vbdBar(top->a0 & 0xFF);
        vbdHex(3,(int(top->a0)>>8)&0xF);
        vbdHex(2,(int(top->a0)>>4)&0xF);
        vbdHex(1,int(top->a0)&0xF);
        // End of F1 program
```

7. In the Ubuntu 22.04.3 LTS terminal run the following command, having ensure that you have `cd`'d into the `pipelined` directory
```bash
source ./pipelined.sh
```
8. When the program has loaded onto the Vbuddy, you can start the program by pressing the trigger (rotary encoder). The F1 lights turn off after a "random" delay, the delay is determined by the value of the rotary encoder and an LFSR. To ensure this works, make sure that the rotary encoder is not at 0 when pressing the trigger.

9. We also included a small way of measuring reaction time, whilst this is definitely not accurate, in terms of measuring reaction time in seconds, it does provide a representation of reaction time. When lights go out, press the trigger again to record your reaction time. You will see your reaction time "score" outputted on both the display and the led bar.

> [!NOTE]
> Right now, we are aware that the trigger is a bit "glitchy" when recording reaction times, this is something that we would definitely get to the bottom to given more time

#### Testing the reference program
1. Set up a connection to Vbuddy.
2. `cd` into the `pipelined` directory
3. Open the directory in VSCode - this is to edit the code so that correct instructions are run.
4. In `instruction_memory.sv` (located in the control folder) edit line 13 to the following:
```verilog
    $readmemh("pdf.mem", instr_array);
```

5. In `data_memory.sv` (located in the data folder), make sure line 26 is uncommented and add the memory file for the desired probability distribution function e.g:
```verilog
    $readmemh("gaussian.mem", data_array, 17'h10000);
```

6. In the top level test bench file (`toplevel_tb.cpp`) comment out the code for the F1 program and make sure that the code for the reference program is uncommented:
```cpp
        // reference program
        if (simcyc > 1300000 && simcyc % 2 == 0)
        {  
            vbdPlot(int(top->a0), 0, 255);
            vbdCycle(simcyc);
        }
        // end of reference program
        

        // F1 program:
        // vbdCycle(simcyc);
        // top->trigger_val = vbdFlag(); 
        // vbdBar(top->a0 & 0xFF);
        // vbdHex(3,(int(top->a0)>>8)&0xF);
        // vbdHex(2,(int(top->a0)>>4)&0xF);
        // vbdHex(1,int(top->a0)&0xF);
        // End of F1 program
```

7. In the Ubuntu 22.04.3 LTS terminal run the following command, having ensure that you have `cd`'d into the `pipelined` directory
```bash
source ./pipelined.sh
```

8. The program will run automatically. Wait for a couple of seconds while the distribution is being built, then the display will plot the pdf. You should see pdfs that resemble that of those in the test results.
## Test Results

## Documentation
    
## Pipelining proposal:
This is the single cycle processor from before:

In order to successfully implement pipelining, the processor must be split into 5 stages. Each stage is associated with a particular part of the processor
| **Stage**  | **Abbreviation** | **Role**                                                                                                               |
|------------|------------------|------------------------------------------------------------------------------------------------------------------------|
| Fetch      | F                | Processor reads the instruction from instruction memory                                                                |
| Decode     | D                | Processor reads the source operands from the register file and decodes the instruction to produce the control signals. |
| Execute    | E                | Processor performs a computation with the ALU                                                                          |
| Memory     | M                | Processor reads or writes data memory, if applicable                                                                   |
| Write Back | W                | Processor writes the result to the register file, if applicable.                                                       |

It is important to note that the register file is used twice in every cycle (written in the first part and read in the second - writing done on the falling edge and reading done on the rising edge)

### Updated datapath with pipelining
![Alt text](image.png)

The destination register address has been pipelined as well so that the result data is in sync with the correct destination register when it is written to the register file.
### Updated controlpath with pipelining
![Alt text](image-1.png)
Control signals must be pipelined along with the data so that they remain synchronized with the instruction.4

It is not possible to calculate the PCSrc value within the control unit, since the we would need to effectively "pipeline back" the EQ flag from the execute stage. It makes most sense to work out PCSrc in the execute stage too since conditons for BEQ and BNE will be determined by the ALU in that current clock cycle. As such, there are 3 modifications:
1. JumpType [1:0] signal added from control
2. BranchType [1:0] signal added from control
3. PCSrc Logic Block added

The PCSrc logic block takes as input the type of branch or jump and the EQ flag and determines the correct PCSrc value.
The specifications for the new control signals is as follows:
JumpType [1:0]:
| JumpType[1] | JumpType[0] | Instruction |
|-------------|-------------|-------------|
| 0           | 0           | No Jump     |
| 0           | 1           | JAL         |
| 1           | 0           | JALR        |

Similarly for BranchType [1:0]:
| BranchType[1] | BranchType[0] | Instruction |
|-------------|-------------|-------------|
| 0           | 0           | No Branch     |
| 0           | 1           | BEQ         |
| 1           | 0           | BNE        |

Output logic for the PCSrc logic block:
| BranchType[1] | BranchType[0] | JumpType[1] | JumpType[0] | EQ | PCSrc[1] | PCSrc[0] |
|---------------|--------------|-------------|-------------|----|----------|---------|
| 0             | 0            | 0           | 0           | X  | 0        | 0       |
| 0             | 0            | 0           | 1           | X  | 0        | 1       |
| 0             | 0            | 1           | 0           | X  | 1        | 0       |
| 0             | 1            | 0           | 0           | 0  | 0        | 0       |
| 0             | 1            | 0           | 0           | 1  | 0        | 1       |
| 1             | 0            | 0           | 0           | 0  | 0        | 1       |
| 1             | 0            | 0           | 0           | 1  | 0        | 0       |

### Hazards
Hazards occur when one instruction's result is needed by a subsequent instruction before the former instruction has completed. There are 3 methods of resolving hazards:
1. Forwarding
2. Stalls
3. Flushes

A software solution to hazards would invovle a programmer or compiler to insert `nop` instructions between hazard areas. This software solution is not ideal since it complicates programming and degrades performance.

2 types of hazards:
1. Data hazard: occurs when an instruction tries to read a register that has not yet been written back by a previous instruction.
2. Control hazard: occurs when the decision of what instruction to fetch next has not been made by the time the fetch takes place.

#### Forwarding:
- A method of solving data hazards.
- Requires adding MUXs infront of the ALU so that it selects its operands from the register file, memory or writeback stage.
- Forwarding is necessary when an instruction in the Execute stage has a source register matching the destination register of an instruction in the Memory or Writeback stage.

TODO: Fill out documentation for hazard unit development.

### Updated Processor with Hazard unit changes:
![Alt text](image-2.png)

### Complete pipelined processor:
![Alt text](image-3.png)

### Updated diagram with general fetch stage:
![Alt text](image-4.png)