# Stretch Goal 1: Pipelined Processor
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

