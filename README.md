# Project 3

__Due date: Saturday, April 21 at 11:55pm.__

---
**You may discuss any of the assignments with your classmates and instructors
**(or anyone else) but all work for all assignments must be entirely your own.
**Any sharing or copying of assignments will be considered cheating (this
**includes posting of partial or complete solutions on Piazza, GitHub public
**repositories or any other public forum). If you get significant help  from
**anyone, you should acknowledge it in your submission (and your grade will be
**proportional to the part  that you completed on your own). You are responsible
**for every line in your program: you need to know what it does and why.**

## Programming requirements:

- The programs should be leak-free: any memory that is allocated should be freed before the program terminates.

- The programs have to be documented! Any file that you edit should have preamble including
your name as the author, description of the purpose of the program and inline comments
in the functions that you implement.
- The code has to follow C programming conventions.
- The code has to be formatted properly.
- The C code has to look like a high level programming language: it should not be accessing
the registers directly, it should not name variables using names of registers, it should simplify
all calculations as much as possible (for example, `( x + 2* x) << 2` should be simplified to `12*x`). [This is not to
say that you are not allowed to use a bit-level operations, but when you translate assembly back to C, make sure that the
resulting code looks like something you might actually write in C. ]

In addition, you are required to make at least 5 commits to your repository.
Each time you make a significant change/improvement to your solutions, you
should commit and push the changes to the remote repository. This way, if there
are any problems with your local copy of the files, you have a recent version of
the code available. Your commits should be distributed over time - they should
not be all made within an hour before the due date.



## Problem 1

The source code for `problem1.c` is given. You may quickly realize that the code
has some serious issues. But it does compile and  run. In some cases the run
terminates with a segmentation fault.

If you run this program with no command line arguments, it uses the default
values for the struct members. These value do not cause  any memory corruption
while the program is running and the run terminates normally after displaying:

```
First:     Joe                 
Last:      Fox                 
Initial:   L                   
Age:       21                  
Salary:    70000
```

The program can also be executed with user specified command line arguments. You
will investigate what happens when the program is given those command line
arguments.  The command line arguments should be a first name and a last name (in that order). For the purpose of solving this problem you will
use _versions_ of your own name. Think of your first name and last name as
endless repeats of the same string (which is your actual first or last name).
For example, if your first name is "Joe", then for the purpose of this problem,
think of your first name as "JoeJoeJoeJoeJoeJoeJoe...." (repeating indefinitely. )
Same applies to the last name.

You should run the program with the following command line arguments
- RUN 1: first __three__ letters of your first name, first __three__ letters of your last name
- RUN 2: first __five__ letters of your first name, first __three__ letters of your last name
- RUN 3: first __three__ letters of your first name, first __ten__ letters of your last name
- RUN 4: first __three__ letters of your first name, first __eleven__ letters of your last name
- RUN 5: first __three__ letters of your first name, first __thirteen__ letters of your last name

For each of the five program runs, you need to
- show the output of the program,
- state if the program run terminated normally or not,
- if the output of the program is not as expected, or if the program crashes,
explain what happened
-  show the byte by byte content
of the structure `p` at the three locations indicated in the code.

__Showing the structure__

You should realize that the structure `p` is 24 bytes in size with the following layout:

```
     5 bytes   5 bytes  1   5 bytes      8 bytes
   -----------------------------------------------------
   |         |         |  |         |                  |
   -----------------------------------------------------
     first      last    m   padding    personal_record
```

Assume that the address of `p` is `m`, and that `m+1` increments the address by
1 byte (for example, if `&p` is `0x7fffffffdb12`, then `m = 0x7fffffffdb12` and
  `m+1 = 0x7fffffffdb13`).

Then the byte by byte representation of the structure `p` is as follows (the values
  for each byte in hex and as a `char` are for you to populate).


  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| | | | | | | |
  char representation| | | | | | | |
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| | | | | | | |
  char representation| | | | | | | |
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| | | | | | | |
  char representation| | | | | | | |

_Note_: for some of the bytes, the character representation may be a char that is
not printable or that does not have standard "keyboard" representation. If that is
the case, then leave that entry in the table blank. You still should specify
the hex value stored in that byte.    

_Hint_: remember that the multi-byte values of are stored using little-endian convention. You
should be using gdb to come up with the values of each byte (although as some point
  you may notice some patterns).

__Your answer should be submitted in the file called `problem1_answers.md`.__


## Problem 2

You are given two object files `problem2.o` and `p2_given.o`. The first one
contains the `main` function, the second contains other functions and a
structure definition used in those functions. Your task is to write C code for
the code in `p2_given.o`. Your code may not end up being identical to
the one in the given file, but it should be equivalent (i.e., given the same
inputs, it should produce the same output).

The `main()` function executes a few tests of the functions implemented in `p2_given.o`. These are not exhaustive tests and passing them does not
guarantee correctness, but it should be a pretty good indicator that your code is on the right track.

Building and running the given code:

```
gcc -o problem2_given p2_given.o problem2.o`
./problem2_given
```

__Your own function should be implemented in the file `p2.c`.__ In order to build the object file, run :

```
gcc -c -Og p2.c
```

In order to build and run your code:

```
gcc -o problem2 p2.o problem2.o`
./problem2
```

If there is no output produced by the code, the function passed the simple tests in `main`.

## Problem 3

Your task for this problem is to optimize three functions from the point of view of their cache performance.

Your repository contains the following files

-  `problem3.c` - the actual program that calls all the functions and performs preliminary correctness checks (should not be modified);
-  `problem3.h` - the header file containing structure definitions, and function declarations (should not be modified);
-  `level_0.c`, ..., `level_3.c` - functions that you need to optimize (`level_0.c` file is
  just a solved example)
-  `Makefile` - the makefile for this problem - it will simplify compiling, building
and testing your solution

__ Compiling and Building the Code__

You can compile and build the code by running

    $ make clean
    $ make

This produces `problem3` program that shows which of the functions completed and
if the results produced by the optimized functions match the results produced by
the unoptimized functions (note, that this program does not perform a complete
check, but should be a good indicator if the functions are setting the right
values). The sample output is shown below:

```
$ ./problem3
level_0 completed
level_0_opt completed
    level_0_opt PASSED
level_1 completed
level_1_opt completed
    level_1_opt FAILED
level_2 completed
level_2_opt completed
    level_2_opt FAILED
level_3 completed
level_3 completed
    level_3_opt FAILED
$
```
__Checking Cache Performance of the Code__

When you complete each level, you should run the program in the cache simulator
to see its cache performance. To do so, execute

```
make run
```

followed by

```
make results
```

The sample outputs are shown below:

```
$ make run
valgrind --tool=cachegrind --D1=1024,2,128 --cachegrind-out-file=cache.trace ./problem3 > valgrind.log 2>&1

$ make results
cg_annotate --threshold=0.001 --show=D1mr,D1mw  --sort=D1mr,D1mw cache.trace  |grep level_[0-3]
1,359,874 1,048,577  /home/asia/Data/project3/level_1.c:level_1
1,202,305         0  /home/asia/Data/project3/level_3.c:level_3
1,048,578         0  /home/asia/Data/project3/level_0.c:level_0
   32,771         0  /home/asia/Data/project3/level_0.c:level_0_opt
   18,753         0  /home/asia/Data/project3/level_2.c:level_2

```

You can also run a single command

```
make run_test
```

to trigger compilation of the source code, run of the executable and cache
performance evaluation, but if there are errors along the way, you will still
need to track them down using separate commands.

The table contains numbers of cache read misses (D1mr) and cache write misses
(D1mw). You should be looking at the lines that show the results of all of the
level_N and level_N_opt functions. In the above example you can see that the
level_0 function had 1,048,578 cache read misses and the level_1_opt function
had 32,771 cache read misses (this is almost two orders of magnitude
difference!!!). The reduction in the number of cache misses will not be always
so large. You want both numbers (for cache read and write misses) to be as low
as possible. (Note, that sometime reducing one of those implies the other one
goes up. This is fine, as long as there is overall benefit.) The other optimized
versions of functions will appear on the list when you write their
implementation.
