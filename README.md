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
set 1 1	 // stop
set 2 0	 // i
set 3 42	// max
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
set 12 0		// temp
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

### Fist numbers

```
set 2 2	 // i
set 3 20000 // max
.
while 0
	.
	add 2 0 2
	.
	set 4 1	 // stop
	set 5 1	 // i
	.
	while 4
		.
		add 5 0 5
		.
		mod 2 5 4
		is_egal 5 2 1
		.
		while 1
			show 2
			br
			set 1 0
			end
		.
		end
	is_egal 2 3 0
	not 0
	.
	end
```