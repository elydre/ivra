# ivra
interactive virtual rgt

## Update Note

v1 is in progress, if you are looking for v0 (in c++) watch [the releases](https://github.com/elydre/ivra/releases)

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

### print 1 to 10

```py
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
