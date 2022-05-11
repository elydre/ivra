# ivra
interactive virtual register

## Compile and run

create `out` directory:
```
mkdir out
cd out
```

compile:
```
cmake .. && make
```

run:
```
./ivra/ivra
```

## Example

### For loop like

```
set 1 1     // stop
set 2 0     // i
set 3 42    // max
.
while 1
add 2 1 2
show 2
is_egal 2 3 1
not 1
end
.
set 0 0
```

### Fibonacci

```
set 1 1
.
set 10 2
set 11 3
set 12 0        // temp
.
set 13 100000   // max
.
while 1
.
show 10
.
cp 11 12
add 10 11 11
cp 12 10
is_sup 13 11 1
.
end
.
set 0 0
```