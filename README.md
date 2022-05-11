# ivra
interactive virtual rgt

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

## keywords

*in this part, register will be called as **rgt**.*

| keyword 		| description				| syntax				|
| ------------- | ------------------------- | --------------------- |
| `end`			| end of while loop			| end					|
| `while`		| while loop				| while *rgt != 0*		|
| `test_class`	| test ivra 				| test_class			|
| `set`			| set number on rgt			| set *rgt* *number*	|
| `cp`			| copy rgt					| cp *rgt* *rgt*		|
| `show`		| show rgt					| show *rgt*			|
| `br`			| print new line			| br					|
| `cout`		| print word in console		| cout *word*			|
| `add`			| add two rgts				| add *rgt* *rgt* *rgt*	|
| `sub`			| subtract two rgts			| sub *rgt* *rgt* *rgt*	|
| `mul`			| multiply two rgts			| mul *rgt* *rgt* *rgt*	|
| `div`			| divide two rgts			| sub *rgt* *rgt* *rgt*	|
| `is_egal`		| test if two r. are equal	| is_egal *rgt* *rgt*	|
| `is_sup`		| test if a r. is superior	| is_sup *rgt* *rgt*	|
| `or`			| boolean or				| or *rgt* *rgt* *rgt*	|
| `not`			| boolean not				| not *rgt* *rgt*		|

# Tips

-# the program will stop when the register 0 is equal to 0.
-# do not use register 0 😊
-# you can use while for condition.
-# use `test_class` for test your program.
-# put a period at the end of empty lines.
-# comment your code.

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

