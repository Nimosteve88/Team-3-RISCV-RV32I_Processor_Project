# Single Cycle
## Contents
[File Listing](#file-listing)  
[Testing Instructions](#testing-instructions)  
[Test Results](#test-results)   
[Documentation](#documentation)  

## File Listing
Key: `x`: full responsibility; `p`: partial responsibility; `t`: testing

| File Name             | Steve | Sne | Divine | Yannis |
|-----------------------|-------|-----|--------|--------|
| alu.sv                |       | t   |        |        |
| alu_src_mux.sv        |       |     |        |        |
| control_unit.sv       |       | t   |        |        |
| data_memory.sv        |       | x   |        |        |
| data_top_level.sv     |       | t   |        |        |
| extend.sv             |       | p   |        |        |
| instruction_memory.sv |       |     |        |        |
| pc_module.sv          |       | t   |        |        |
| pc_reg.sv             |       |     |        |        |
| register_file.sv      |       | t   |        |        |
| result_mux.sv         |       | x   |        |        |
| toplevel.sv           |       | x/t   |        |        |

## Testing Instructions
#### Testing the Formula 1 Program
1. Set up a connection to Vbuddy.
2. `cd` into the `single_cycle` directory
3. Open the directory in VSCode - this is to edit the code so that correct instructions are run.
4. In `instruction_memory.sv` (located in the control folder) edit line 13 to the following:
```verilog
    $readmemh("f1.mem", instr_array);
```

5. In `data_memory.sv` (located in the data folder) comment out line 24 (we do not need to read anything into data memory for the F1 program):
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

7. In the Ubuntu 22.04.3 LTS terminal run the following command, having ensure that you have `cd`'d into the `single_cycle` directory
```bash
source ./single.sh
```
8. When the program has loaded onto the Vbuddy, you can start the program by pressing the trigger (rotary encoder). The F1 lights turn off after a "random" delay, the delay is determined by the value of the rotary encoder and an LFSR. To ensure this works, make sure that the rotary encoder is not at 0 when pressing the trigger.

9. We also included a small way of measuring reaction time, whilst this is definitely not accurate, in terms of measuring reaction time in seconds, it does provide a representation of reaction time. When lights go out, press the trigger again to record your reaction time. You will see your reaction time "score" outputted on both the display and the led bar.

> [!NOTE]
> Right now, we are aware that the trigger is a bit "glitchy" when recording reaction times, this is something that we would definitely get to the bottom to given more time

#### Testing the reference program
1. Set up a connection to Vbuddy.
2. `cd` into the `single_cycle` directory
3. Open the directory in VSCode - this is to edit the code so that correct instructions are run.
4. In `instruction_memory.sv` (located in the control folder) edit line 13 to the following:
```verilog
    $readmemh("pdf.mem", instr_array);
```

5. In `data_memory.sv` (located in the data folder), make sure line 24 is uncommented and add the memory file for the desired probability distribution function e.g:
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

7. In the Ubuntu 22.04.3 LTS terminal run the following command, having ensure that you have `cd`'d into the `single_cycle` directory
```bash
source ./single.sh
```

8. The program will run automatically. Wait for a couple of seconds while the distribution is being built, then the display will plot the pdf. You should see pdfs that resemble that of those in the test results.

> [!NOTE]
> The testbench has lines to write output data to a csv file. If you want to do this, ensure that all lines related to csv file generation are uncommented.

## Test Results
#### F1 Program

#### Reference Program
Videos for the reference program can be seen below


https://github.com/Nimosteve88/Team-3-RISCV-RV32I_Processor_Project/assets/66144849/e2467acb-1db6-473e-b374-a0244b811c4e


Additionally, CSV files with output data were generated for each distribution in the test bench. These were plotted and are as follows:

| ![Single_Gaussian](../graph/output/single_gaussian_graph.png) | ![Single_Noisy](../graph/output/single_noisy_graph.png)       |
|---------------------------------------------------------------|---------------------------------------------------------------|
| ![Single_Sine](../graph/output/single_sine_graph.png)         | ![Single_Triangle](../graph/output/single_triangle_graph.png) |

## Documentation
There are number of changes required from Lab 4: From looking at both the reference program and out F1 RISC-V code, there a number of changes that must be implemented to successfully execute the new instructions found in these programs. The processor needs to be updated to include the following instructions:
- ADDI (already done from lab4)
- BNE (already done from lab4)
- ADD
- JAL
- LUI
- SB
- JALR 
- LBU
- XOR

The following changes to the processor are highlighted in the diagram and further explained below:
![Alt text](images/image.png)

1. **Data Memory**: Previously, we didn't have to read or store values into data memory. Now, with the introduction of `SB` and `LBU` we are both reading and writing to data memory. The data memory component must be built in accordance with the specified memory map. The WD (write data) input is always the RD2 value (value of register "rs2") since the `SB` instruction (where we are writing to the data memory) has the following format:
```
SB rs2, imm(rs1) --> the first byte of data at the address specified at (imm + rs1) = the first byte of the value at register rs2
```
The data memory has another control input apart from write enable, ByteAddr, I have added this in to specify when we want to preform a data write/store on the least significant byte (LSB) of a value at a given address (`SB`) or when we want to perform a 0 sign extension on the LSB of a value at a given address (`LBU`). Whilst this covers all cases we need from the data memory unit, it is best practice to still inlcude standard functionality of reading and writing to data memory and using a separate control bit to determine when we want to do reading and/or writing on just the least significant byte.

2. **Result MUX**: In lab4, when writing to the register file, there was only one source of input data - from the ALU. However, now there are 4 different sources of write data:
- Directly from the ALU (e.g `ADD`, `ADDI`, `XOR` instructions)
- Data output from reading from data memory (`LBU`)
- PC + 4 (Needed in the `JAL` and `JALR` instructions)
- When we want to store an immediate value (`LUI`)
To correctly choose the value we want to write to the register, we implement a mux. The select comes directly from the control unit, in accordance with the instruction type.

3. **MUX for PCTarget**: Before, for `BNE` instructions, the PCTarget would be PC + ImmExt. Now we have `JAL` and `JALR` instructions to consider. For `JAL`, we have PCTarget = PC + ImmExt (same as before), but for `JALR` we have PCTarget = rs1 + ImmExt. This is used especially in thr `RET` instruction since before jumping, we store the next PC instruction (PC+4) in a register, so when returning from a subroutine, it makes sense to set PCTarget to that value we saved before jumping. Since both cases from PCTarget have ImmExt as common, it makes sense to implement a mux to choose what to add ImmExt with to get PCTarget (PC or rs1). The select from this comes from the control unit, and its value depends on the current instruction.
> [!IMPORTANT]
> This has been changed now PCSrc is set to be 2 bytes long instead of 1 as before. The value of rs1 will be directly added with Imm and will be an option for the MUX related to PC, this also removes the need for the PCTargetSrc Signal - see updated diagram below

4. **Extend**: In lab4, we only had to consider immediate sign extension for 2 type of instruction, now we need to consider 5 types. As such the input, ImmSrc has an increased width to correctly determine the sign extended immediate format based of the current instruction.

5. **ALU**: We need to do more ALU operations than lab4.

6. **Control Unit**: There are now more ouput signals based of the changes implemented above. Notably:
- ResultSrc: Dtermines what data is being written to the register file.
- MemWrite: An enable for writing or reading to data memory
- ImmSrc: Increase width than lab4 to allow for more instruction type immediate sign extension.
- PCTargetSrc: A mux select line to determine PCTarget, depending on `BNE`, `JAL` and `JALR` instruction types.
- ByteAddr: A control input to determine how we modify outputs and inputs of data memory when we only want to focus on the least significant byte.

### Control Decode Table:
![Alt text](images/image-1.png)

### Upadted top level diagram:
![Alt text](images/image-2.png)
