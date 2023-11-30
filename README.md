# Team-3-RISCV-RV32I_Processor_Project
# Group 3 Pipelined RV32I

## Todo:
- [ ] Update control unit for J, S, R and U type instructions
- [x] Update sign extend for new instructions
- [ ] Update ALU
- [ ] Add data memory and result MUX

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
| Yannis Zioulis |  | **yanniszioullis**  |   | 

---

## Work Split 

| File Name     |  Steve  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  | Sne &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;       | Yannis  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;       | Divine   &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;         |
|:-------------|:----------------:|:----------:|:------------:|:--------------:|
| ALU.sv |  |  | |
| control.sv | | |  |
| ram_i.sv | | | |
| ram_o.sv | | | |
| ram.sv | | | |
| rom.sv | | | |
| register_file.sv | | | |
| memory.sv | | | |
| extend.sv | | | |
| fetch_reg_file.sv | | | |
| decode_reg_file.sv | | | |
| execute_reg_file.sv | | | |
| mem_reg_file.sv | | | |
| top.sv (singlecycle) | | | |
| top.sv (pipeline) | | | |
| cpu_tb.cpp | | | |
| F1Assembly.s | | | |

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


