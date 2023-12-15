# Yannis Zioulis' Personal Statement
### CID: 02223077  |  GitHub username: yanniszioulis

---
##  Summary of Contributions

*  Built and tested the Program Counter 
*  Wrote and tested the F1 Light Sequence assembly code program
*  Built the Hazard Detection Unit and helped in the design, debugging and testing of the Pipeline Registers
* Helped in building the Cache, and helped test our Cache Memory system

## Contributions
### Program Counter
My first contribution was building the Program Counter (a task which was randomly assigned to me for Lab 4. I continued modifying the PC to make sure it works for the single-cycle, pipelined and cache versions of our CPU). 

My final design of the PC for Lab 4 can by seen by Sne's commit [824c2c3](https://github.com/Nimosteve88/Team-3-RISCV-RV32I_Processor_Project/commit/824c2c392575be7485710e18ccce1e39f5f9e49a) where the files were copied over. The development of the Program Counter then continued with my design choice to include a 2-bit `PCSrc` input signal (although only 3 of the 4 inputs were needed to implement the instructions necessary to run the reference and f1 programs).  

| PCSrc [1:0] | Use Case | Instruction Types | Instructions Used
| --------------- | --------------- | --------------- | --------------- |
| 00 | PC <- PC + 4 | R-type, I-type (apart from jalr), S-type | addi (li, noop), add, xor, sub, sb, lbu |
| 01 | PC <- PC + Imm | B-type, J-type | beq, bne, jal|
| 10 | PC <- Rs1 + Imm | (only used jalr, technically I-type) | jalr (ret)
| 11 | ~~not used~~ | - | - |

See commit [05291c3](https://github.com/Nimosteve88/Team-3-RISCV-RV32I_Processor_Project/commit/05291c32b537287012723846c5f68ebc26844e28) for the adjustments made to the Program Counter, the Control Unit, the Datapath and the Top Level to accommodate for the JALR instruction. 

Finally, as a result of Sne's testing, we found that the Program Counter would would take **2 clock cycles to resume normal operation after a reset input.**

![Alt text](Resources/pc_reset_error.jpg)

This issue was caused by the fact that both `pc_module.sv` (the pc 'top')  would set `pc_next` to 0, and `pc_reg.sv` (the register itself) would set the stored value to 0. This would effectively create a two-cycle bubble which was resolved with commit [ac768a0](https://github.com/Nimosteve88/Team-3-RISCV-RV32I_Processor_Project/commit/ac768a058ef602ffd99314098295a2d83d68e19b). 

By overcoming this error, we arrived at the final version of the PC module which is used by the single cycle version of our CPU. The pipelined and pipelined+cache versions of the CPU saw `pc_module.sv` evolve to `fetch.sv` which I will cover below. [Final Version of Single Cycle Program Counter](main/rtl/single_cycle#program-counter).


> [Include any additional statements or reflections you have about your work, challenges faced, and how you overcame them.]

---

## What I learned 

### Git
[Discuss your experience with Git, including specific commands used, problem-solving, and collaboration with team members.]

### Markdown
[Describe your use of Markdown for documentation purposes.]

### System Verilog and Verilator
[Discuss your learning experience with System Verilog and Verilator, highlighting your comfort level and ability to handle common errors.]

### Debugging skills
[Explain how you improved your debugging skills, whether through GTKwave or other tools.]

### Group dynamics
[Share your insights into working within a team, including the importance of giving team members creative space and time to work at their own pace.]

---

## Mistakes

* [Reflect on any mistakes made during the project and what you learned from them.]

---

## Design Decisions
* [Outline any design decisions you made during the project, including why you chose specific approaches.]

> [Include visuals or diagrams if necessary.]

---

## Next time
[Discuss what you would do differently next time, any improvements you would make, and lessons learned.]

---

## Acknowledgments
[If there are specific individuals or resources you want to acknowledge, include them here.]

---

## References
[List any references or links to specific commits, branches, or documents mentioned in your statement.]

---

[Include any additional sections or details you find relevant to your personal statement. Customize the template to fit your specific experiences and contributions.]
