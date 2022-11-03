# CSE-306-Computer-Architecture-Sessional
This is a repository containing all the simulations and reports of CSE-306 Computer Architecture Sessional.

## 4 bit ALU
**This ALU contains:**
- Two 4 bit inputs A and B
- Three select bits S<sub>2</sub>, S<sub>1</sub>, S<sub>0</sub> as ALU opcodes
- One 4 bit output
- Four flags: Z (Zero), C (Carry), O (Overflow), N (Negative)
### Implemented functions and opcodes:
<p align="center">
<table>
<thead>
  <tr>
    <th style="text-align:center"colspan="3" style="text-align:center">ALU opcodes</th>
    <th style="text-align:center"rowspan="2" text-align="center">Functions</th>
  </tr>
  <tr>
    <th>S<sub>2</sub></th>
    <th>S<sub>1</sub></th>
    <th>S<sub>0</sub> (C<sub>in</sub>)</th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>Transfer A</td>
  </tr>
  <tr>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>Increment A</td>
  </tr>
  <tr>
    <td>0</td>
    <td>1</td>
    <td>X</td>
    <td>AND</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>0</td>
    <td>Add</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>1</td>
    <td>Add with carry</td>
  </tr>
  <tr>
    <td>1</td>
    <td>1</td>
    <td>X</td>
    <td>OR</td>
  </tr>
</tbody>
</table>
</p>

### Truth table:
<p align="center">
<table>
<thead>
  <tr>
    <th style="text-align:center"colspan="3">ALU opcodes</th>
    <th style="text-align:center"rowspan="2">Required outputs</th>
    <th style="text-align:center"colspan="3">Adder inputs</th>
    <th style="text-align:center"rowspan="2">Functions</th>
  </tr>
  <tr>
    <th>S<sub>2</sub></th>
    <th>S<sub>1</sub></th>
    <th>S<sub>0</sub> (C<sub>in</sub>)</th>
    <th>X<sub>i</sub></th>
    <th>Y<sub>i</sub></th>
    <th>Z<sub>i</sub></th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>A</td>
    <td rowspan="2">A<sub>i</sub></td>
    <td rowspan="2">0</td>
    <td rowspan="2">C<sub>i</sub></td>
    <td>Transfer A</td>
  </tr>
  <tr>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>A + 1</td>
    <td>Increment A</td>
  </tr>
  <tr>
    <td>0</td>
    <td>1</td>
    <td>0</td>
    <td rowspan="2">A ^ B</td>
    <td rowspan="2">A<sub>i</sub>B<sub>i</sub></td>
    <td rowspan="2">0</td>
    <td rowspan="2">0</td>
    <td rowspan="2">AND</td>
  </tr>
  <tr>
    <td>0</td>
    <td>1</td>
    <td>1</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>0</td>
    <td>A + B</td>
    <td rowspan="2">A<sub>i</sub></td>
    <td rowspan="2">B<sub>i</sub></td>
    <td rowspan="2">C<sub>i</sub></td>
    <td>Add</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>1</td>
    <td>A + B + 1</td>
    <td>Add with carry</td>
  </tr>
  <tr>
    <td>1</td>
    <td>1</td>
    <td>0</td>
    <td rowspan="2">A OR B</td>
    <td rowspan="2">A<sub>i</sub>B<sub>i</sub>'</td>
    <td rowspan="2">B<sub>i</sub></td>
    <td rowspan="2">0</td>
    <td rowspan="2">OR</td>
  </tr>
  <tr>
    <td>1</td>
    <td>1</td>
    <td>1</td>
  </tr>
</tbody>
</table>
</p>

### Simplified inputs to individual full adders:
X<sub>i</sub> = A(S<sub>1</sub>' + S<sub>2</sub> XOR B)

Y<sub>i</sub> = S<sub>2</sub>B

Z<sub>i</sub> = S<sub>1</sub>'C<sub>i</sub>

### Circuit diagram:
![4 bit ALU circuit diagram](1%20-%204%20bit%20ALU/4%20bit%20ALU%20circuit%20diagram.png)

## Floating Point Adder
The adder takes two 32 bit floating point numbers and adds them together. The numbers are represented in the following format:

|  Sign | Exponent |        Fraction        |
|:-----:|:--------:|:---------------------:|
| 1 bit |  10 bits | 21 bits (Lowest bits) |

The numbers are in normalized form. There are two flags U (underflow) and O (overflow) which are set if the result is too small or too large to be represented in the format.

### Flow chart:
<p align="center">
  <img src="2 - Floating Point Adder/floating_point_adder_flowchart.svg" height="1200em" placeholder="Floating point adder flow chart"></img>
</p>

### Circuit diagram:
![Floating point adder circuit diagram](2%20-%20Floating%20Point%20Adder/floating_point_adder_circuit_diagram.png)

### What individual components do:
- **Sign check**: Checks if a 32 floating point number is positive, negative or the exponent is zero. If the number is positive then the output is the same as input. If the number is negative then it outputs the two's complement of the input. And if the exponent is zero then the output is zero.
- **Normalizer**: Normalizes a floating point number. But if the number is overflowed or underflowed while trying to normalize then the appropriate flags are set.
- **Rounder**: Rounds the 32 bit significand to 21 bits.

## 4 bit MIPS processor

### How to use:
Write a valid MIPS assembly code and compile the code with [MIPS-assembler](3%20-%204%20bit%20MIPS%20processor/assembly_to_machine.cpp). Now open the [MIPS-simulator](3%20-%204%20bit%20MIPS%20processor/4-bit-MIPS.circ) with `logisim 2.7.1` Then open the `machine.txt` file (generated after runnig the C++ code) from the instruction memory.
### MIPS instruction formats:
- **R-type**:
<p align="center">
<table>
<thead>
  <tr>
    <th>Opcode</th>
    <th>Src Reg 1</th>
    <th>Src Reg 2</th>
    <th>Dst Reg</th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>4-bits</td>
    <td>4-bits</td>
    <td>4-bits</td>
    <td>4-bits</td>
  </tr>
</tbody>
</table>
</p>

- **S-type**:

<p align="center">
<table>
<thead>
  <tr>
    <th>Opcode</th>
    <th>Src Reg 1</th>
    <th>Dst Reg</th>
    <th>Shamt</th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>4-bits</td>
    <td>4-bits</td>
    <td>4-bits</td>
    <td>4-bits</td>
  </tr>
</tbody>
</table>
</p>

- **I-type**:

<p align="center">
<table>
<thead>
  <tr>
    <th>Opcode</th>
    <th>Src Reg 1</th>
    <th>Src Reg 2/Dst Reg</th>
    <th>Addr./Immdt</th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>4-bits</td>
    <td>4-bits</td>
    <td>4-bits</td>
    <td>4-bits</td>
  </tr>
</tbody>
</table>
</p>

- J-type:

<p align="center">
<table>
<thead>
  <tr>
    <th>Opcode</th>
    <th style="text-align:center"colspan="2">Target Jump Address</th>
    <th>0</th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>4-bits</td>
    <td colspan="2">8-bits</td>
    <td>4-bits</td>
  </tr>
</tbody>
</table>
</p>

### Instruction set:
<p align="center">
<table>
<thead>
  <tr>
    <th>Instruction Opcode</th>
    <th>Instruction</th>
    <th>MIPS Instruction Format</th>
    <th>Instruction Type</th>
  </tr>
</thead>
<tbody align="center">
  <tr>
    <td>0000</td>
    <td>sub</td>
    <td>R</td>
    <td>Arithmetic</td>
  </tr>
  <tr>
    <td>0001</td>
    <td>ori</td>
    <td>I</td>
    <td>Logic</td>
  </tr>
  <tr>
    <td>0010</td>
    <td>bneq</td>
    <td>I</td>
    <td>Control</td>
  </tr>
  <tr>
    <td>0011</td>
    <td>addi</td>
    <td>I</td>
    <td>Arithmetic</td>
  </tr>
  <tr>
    <td>0100</td>
    <td>beq</td>
    <td>I</td>
    <td>Control</td>
  </tr>
  <tr>
    <td>0101</td>
    <td>or</td>
    <td>R</td>
    <td>Logic</td>
  </tr>
  <tr>
    <td>0110</td>
    <td>sw</td>
    <td>I</td>
    <td>Memory</td>
  </tr>
  <tr>
    <td>0111</td>
    <td>srl</td>
    <td>S</td>
    <td>Logic</td>
  </tr>
  <tr>
    <td>1000</td>
    <td>and</td>
    <td>R</td>
    <td>Logic</td>
  </tr>
  <tr>
    <td>1001</td>
    <td>andi</td>
    <td>I</td>
    <td>Logic</td>
  </tr>
  <tr>
    <td>1010</td>
    <td>lw</td>
    <td>I</td>
    <td>Memory</td>
  </tr>
  <tr>
    <td>1011</td>
    <td>add</td>
    <td>R</td>
    <td>Arithmetic</td>
  </tr>
  <tr>
    <td>1100</td>
    <td>sll</td>
    <td>S</td>
    <td>Logic</td>
  </tr>
  <tr>
    <td>1101</td>
    <td>subi</td>
    <td>I</td>
    <td>Arithmetic</td>
  </tr>
  <tr>
    <td>1110</td>
    <td>j</td>
    <td>J</td>
    <td>Control</td>
  </tr>
  <tr>
    <td>1111</td>
    <td>nor</td>
    <td>R</td>
    <td>Logic</td>
  </tr>
</tbody>
</table>
</p>

### Circuit diagram:

![4-bit MIPS Circuit Diagram](3%20-%204%20bit%20MIPS%20processor/4-bit_mips_processor_circuit_diagram.png)

## Group members:
- [Showvik Biswas](https://github.com/showvikbiswas)
- [Fardin Anam Aungon](https://github.com/fardinanam)
- [Kazi Ababil Azam](https://github.com/ababiltalha)
- [Muhammad Ehsanul Kader](https://github.com/ehsankader16)
- [Anup Bhowmik](https://github.com/Anupznk)