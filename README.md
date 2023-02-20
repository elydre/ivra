# ivra
IVRA is a register-based runtime. Around the runtime, layers
of abstraction are created to use IVRA more simply.

Runtime auto-build is [available](https://github.com/elydre/ivra/releases/tag/latest)
for linux (x86_64) and for profanOS (i386).

## Update Note

v1 is in progress, if you are looking for v0 (in c++)
watch [the releases](https://github.com/elydre/ivra/releases)

## Instructions

```
00.   DIS => display R(1) as a text if R(2) else as a number
01.   SET => R(1) = (2)
02.   CPY => R(1) = R(2)
03.   TRC => R(R(1)) = R(R(2))

04.   ADD => R(1) = R(1) + R(2)
05.   SUB => R(1) = R(1) - R(2)
06.   MUL => R(1) = R(1) * R(2)
07.   DIV => R(1) = R(1) / R(2)

08.   AND => R(1) = R(1) & R(2)
09.   HOR => R(1) = R(1) | R(2)
10.   NOT => R(1) = !R(1)

11.   SUP => R(1) = R(1) > R(2)
12.   EQU => R(1) = R(1) == R(2)

13.   JMP => CT = R(1)
14.   GIF => if R(1) != 0 then CT = R(2)
15.   SCT => R(1) = CT

16.   HLT => exit
```

## Examples

### abstraction layer 0

#### print 1 to 10

```sh
1 6 10  # constant \n #
1 7 0   # constant 0 #

1 0 0   # counter #
1 1 9   # max -1 #
1 3 1   # increment value #
1 9 32  # increment section index #

15 8    # save the current position #
2 2 0   # copy counter for comparison #
11 2 1  # compare counter to max #
10 2    # we need to jump if false #
14 2 9  # jump to increment section #

16      # halt #

4 0 3   # increment counter #
0 0 7   # print counter #
0 6 6   # print newline #
13 8    # jump back to save position #
```

### abstraction layer 1

#### the biggest number

```sh
SET 6 10  # constant \n #
SET 7 0   # constant 0 #

SET 100 42
SET 101 64
SET 102 12

SET 12 66     # section print #

CPY 103 100   # copy R0 to R3 #
SUP 103 101   # R3 = R3 > R1  #
CPY 104 100   # copy R0 to R4 #
SUP 104 102   # R4 = R4 > R2  #

AND 103 104   # R3 = R3 && R4 #
CPY 42 100    # copy R0 to R42 #
GOTOIF 103 print

CPY 103 102   # copy R2 to R3 #
SUP 103 101   # R3 = R3 > R1  #
CPY 104 102   # copy R2 to R4 #
SUP 104 100   # R4 = R4 > R0  #

AND 103 104   # R3 = R3 && R4 #
CPY 42 102    # copy R2 to R42 #
GOTOIF 103 print

CPY 42 101    # copy R1 to R42 #

print:
DIS 42 7      # print R42 as number #
DIS 6 6       # print newline #
HLT
```
