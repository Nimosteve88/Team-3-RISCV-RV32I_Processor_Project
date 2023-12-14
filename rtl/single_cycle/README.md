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

## Test Results

## Documentation