# Team-3-RISCV-RV32I_Processor_Project

## Contents:
[Joint Statement](#joint-statement)  
[Contributors and Personal Statements](#contributors-and-personal-statements)  
[High Level Description](#high-level-description)  
[Repository Structure](#repository-structure)  
[Source Code](#source-code)  
[Combined File Listing](#combined-file-listing)  
[References](#references)  

## Joint Statement
>TODO: Insert Joint Statement Here

## Contributors and Personal Statements

| Name           | CID      | GitHub Username    | Email           | Personal Statement |
|----------------|----------|--------------------|-----------------|----------------------------|
| Steve Nimo     | 02254814 | **Nimosteve88**    | sn722@ic.ac.uk  |                            |
| Sne Samal      | 02201807 | **sne-samal**      | ss5322@ic.ac.uk |                            |
| Divine Wodi    | 02208866 | **CB-WO3**         | dw722@ic.ac.uk  |                            |
| Yannis Zioulis | 02223077 | **yanniszioullis** | yz9722@ic.ac.uk |                            |

## High Level Description
> TODO: Insert high level description of what were tasked to do in each stretch goal

## Repository Structure
> TODO: Insert a tree diagram of the structure of this repository so that the marker has a broad overview of files and where they are located. Also include a list of important files and folders and explain their purpose - don't want the marker to figure it out on their own.

## Source Code
In the table below, you can directly access the source code for the different processor versions. You can click on a link to the test results for each version. This link contains video evidence of the processor working and instructions to access relevant waveforms. If you want to test the code for yourself, click on the test instructions link, where you will be directed to instructions on how to test the processor with both the reference and f1 programs.

| Processor Version         | Test Results | Testing Instructions |
|---------------------------|--------------|----------------------|
| [Single Cycle](https://github.com/Nimosteve88/Team-3-RISCV-RV32I_Processor_Project/tree/main/rtl/single_cycle#readme)              | Single Cycle Test Instructions             |  Single Cycle Test Results                    |
| [Pipelined](https://github.com/Nimosteve88/Team-3-RISCV-RV32I_Processor_Project/blob/main/rtl/pipelined/README.md)                 | Pipelined Test Instructions             |  Pipelined Test Results                    |
| [Pipelined with Data Cache](https://github.com/Nimosteve88/Team-3-RISCV-RV32I_Processor_Project/blob/main/rtl/cache/README.md) |  Pipelined with Data Cache Test Instructions            | Pipelined with Data Cache Test Results                     |

## Combined File Listing
This is the file listing for all the files that were used in each processor version. The listing has the file name and the version in which they were first used alongside the relevant contributors.

Key: `x`: full responsibility; `p`: partial responsibility; `t`: testing

| File Name                          | First Seen          | Steve | Sne | Divine | Yannis |
|------------------------------------|---------------------|-------|-----|--------|--------|
| alu.sv                             | Single Cycle        |       | t   |        |        |
| alu_src_mux.sv                     | Single Cycle        |       |     |        |        |
| control_unit.sv                    | Single Cycle        |       | t   |        |        |
| data_memory.sv                     | Single Cycle        |       | x   |        |        |
| data_top_level.sv                  | Single Cycle        |       | t   |        |        |
| extend.sv                          | Single Cycle        |       | p   |        |        |
| instruction_memory.sv              | Single Cycle        |       |     |        |        |
| pc_module.sv                       | Single Cycle        |       | t   |        |        |
| pc_reg.sv                          | Single Cycle        |       |     |        |        |
| register_file.sv                   | Single Cycle        |       | t   |        |        |
| result_mux.sv                      | Single Cycle        |       | x   |        |        |
| toplevel.sv (single cycle)         | Single Cycle        |       | x/t |        |        |
| control_unit_pipelined.sv          | Pipelined           |       | t   |        |        |
| decode.sv                          | Pipelined           |       | t   |        |        |
| execute.sv                         | Pipelined           |       | t   |        |        |
| fetch.sv                           | Pipelined           |       | t   |        |        |
| hazard.sv                          | Pipelined           |       | t   |        |        |
| memory.sv                          | Pipelined           |       | t   |        |        |
| pc_reg.sv                          | Pipelined           |       |     |        |        |
| PCSrclogic.sv                      | Pipelined           |       | t   |        |        |
| rd1emux.sv                         | Pipelined           |       |     |        |        |
| rd2emux.sv                         | Pipelined           |       |     |        |        |
| top_level.sv (pipelined)           | Pipelined           |       | x/t |        |        |
| write_back.sv                      | Pipelined           |       | t   |        |        |
| cache.sv                           | Pipelined and Cache |       |     |        |        |
| combined_cache_memory.sv           | Pipelined and Cache |       | p/t |        |        |
| data_memory.sv                     | Pipelined and Cache |       | x/t |        |        |
| rd_mux.sv                          | Pipelined and Cache |       | x   |        |        |
| top_level.sv (pipelined and cache) | Pipelined and Cache |       | x/t |        |        |

## References
Our CPU was an extension of the processor outlined in Prof. Peter Cheung's lecture notes and in the textbook: _"Digital Design and Computer Architecture (RISC-V Edition)"_ by Sarah Harris and David Harris. 

#### If desired, please skip ahead to:
1. [Repo Structure Explanation](#structure)
2. [Evidence](#evidence)
3.  [Test instructions](#test)

---
## Quick summary

The result of this coursework is two CPUs: a pipelined, and a single-cycle CPU ....

## Group Details

| Name           | CID      | GitHub   | Email                     | Link to Personal Statement|
|----------------|----------|----------|---------------------------|--------------|
| Steve Nimo      | 02254814 | **Nimosteve88**  | sn722@imperial.ac.uk   &nbsp; &nbsp; &nbsp; &nbsp;   | 
| Sne Samal   | 02201807 | **sne-samal** | ss5322@ic.ac.uk | 
| Divine Wodi | 02208866 | **CB-W03** | dw722@ic.ac.uk | 
| Yannis Zioulis | 02223077 | **yanniszioullis**  | yz9722@ic.ac.uk | 

---

## Work Split 

| Goal     |  Task  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  | Status &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;       | Primary Contributor  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;       | Secondary Contributor   &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;         | Tertiary Contributor   &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;         |
|:-------------|:----------------:|:----------:|:------------:|:--------------:|:--------------:| 
| Lab 4 | PC Counter |Completed  | | |
| Lab 4 | ALU |Completed  | | |
| Lab 4 | Regfile |Completed  | | |
| Lab 4 | Control Unit |Completed  | | |
| Lab 4 | Instruction Memory |Completed  | | |
| Lab 4 | Immediate Extend |Completed  | | |
| Lab 4 | Lab 4 Top Level |Completed  | | |
| Base | F1 Assembly Code |  | | |
| Base | Update Immediate Extend |  | | |
| Base | Update Program Counter |  | | |
| Base | Update Control Unit |  | | |
| Base | Update ALU |  | | |
| Base | Create Data Memory |  | | |
| Base | Update Top Level |  | | |
| Base | Top Level Testing |  | | |
| Stretch Goal 1 | Add Pipeline Registers |  | | |
| Stretch Goal 1 | Hazard Unit |  | | |
| Stretch Goal 1 | Top Level Testing |  | | |
| Stretch Goal 1 | Update Top Level |  | | |
| Stretch Goal 2 | Add Data Cache |  | | |
| Stretch Goal 2 | Update Top Level |  | | |
| Stretch Goal 2 | Top Level Testing |  | | |

LEGEND :       `x` = full responsibility;  `p` = partial contribution; 

---
<div id="structure"/>

## Repo Structure Explained

* A new folder for each new feature

- (More descritption to be add)

 

| Version name | Explanation | 
| -----------------|-------------|
| `FOLDER 1` | Partiallyimplemented single cycle, Upper immediate and SH, LHU, LH not implemented (do not test)
| `FOLDER 2` | Full implementation of single cycle processor, no AUIPC
| `FOLDER 3` | Full Pipelined implementation, all instructions (up to date in main)

> (Potential Image of Branch breakdown / File directory (Heirarchy) )


---
<div id="evidence"/>

## Evidence

>Video evidence placed below

Single Cycle: 

> Video mp3 file for Single Cycle Outcome


F1:

> Video mp3 file for F1

In the `test` folder, you can find copies of the following:
* The above videos (in case they have not loaded properly)
*  VCD trace files for both the Single Cycle and F1 programs

---

<div id="test"/>

# Testing instructions

## 1. Clone repo and configure _vbuddy.cfg_ file

This is explained in the guide to set up VBuddy provided at the start of the course.
If possible, please also make sure that the flag is set to low before running the f1 program. This prevents bugs in some cases. 

## 2. Execute shell script 

This branch has been configured for testing both the **F1** and **PDF** programs in the pipelined processor. To test the **F1** program, please run the following shell script:
```bash
$ ./f1.sh
```
And push the trigger to start it. This will run for a maximum of 2000 cycles. Please note that trigger is mapped to the register `t0`, within the register file. 

Or likewise for the pdf distribution calculation,
```bash
$ ./pdf.sh
```
Please note that there is one test-bench, but the shell scripts will configure it accordingly. 


