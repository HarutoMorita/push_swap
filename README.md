*This project has been created as part of the 42 curriculum by hmorita.*

# Push_swap

## Description
**Push_swap** is the project of 42 common core to learn sorting algorithms and complexity. The goal of this project is to sort a set of integers using 2 stacks and 11 types of stack operations within a limited number of operations.

### Goals
- Implementation of sorting algorithms.
- Understanding of complexity.
- Management of the stack data structure.
- Achievement of proficiency in C.

### Overview
The `push_swap` program receives a list of integers as command line arguments, then prints the sequence of stack operations to sort those integers to **standard output**.\
The `checker` program receives a list of integers as command line arguments too, then judges if operations entered from **standard input** correctly sort those integers.

## Instructions

### Compilation
To compile the program, run these commands at the root directory.
```bash
make        # Compile push_swap.
make checker  # Compile checker.
make clean  # Remove object files.
make fclean # Remove object files and executables.
make re     # Re-compile push_swap.
```

### Execution and Usage

#### push_swap
`push_swap` takes a list of integers as command line arguments.\
Then displays stack operations to sort those integers.\
It starts with operations on **Stack A** as the received integers represent its initial state.
```bash
# Run with integers.(3 is at the top of the initial stack)
./push_swap 3 2 1
ra
sa

# Run with a string of integers.
./push_swap "3 1 2"
ra

# Run with a variable containing integers.
ARG="2 1 3"; ./push_swap $ARG
sa

# Run with no arguments(no output).
./push_swap
```
`push_swap` displays **Error** to **standard output** if invalid arguments are passed.
```bash
# Some arguments are non-integers.
./push_swap 3 a 1
Error

# Some arguments are numbers exceeding the integer limits.
./push_swap 3 2 -2147483648
Error

# There is the presence of duplicates.
./push_swap 3 2 2
Error

# Internal errors(e.g., malloc failure) occurred.
./push_swap 3 2 1
Error
```

#### checker
`checker` takes a list of integers as command line arguments.
```bash
# Run with integers. (3 is at the top of the initial stack)
./checker 3 2 1

# Run with a string of integers.
./checker "3 1 2"

# Run with a variable containing integers.
ARG="2 1 3"; ./checker $ARG

# Run with no arguments(no output).
./checker
```

`checker` receives stack operation commands from **standard input**.\
Press `Enter` to send each command.\
Press `Ctrl + D` to send the EOF to start judging result.\
It will display **OK** if the stack is sorted, or **KO** if it is not.
```bash
# Commands correctly sort integers.
./checker 3 2 1
sa
rra
# enter ctrl + D here.
OK

# Commands do not correctly sort integers.
./checker 3 2 1
ra
rra
# enter ctrl + D here.
KO

# You can pipe the output of push_swap into checker.
./push_swap 3 2 1 | ./checker 3 2 1
OK
```

`checker` displays **Error** to **standard output** if invalid arguments are passed or invalid commands are entered.
```bash
# Some arguments are non-integers.
./checker 3 a 1
Error

# Some arguments are numbers exceeding the integer limits.
./checker 3 2 -2147483648
Error

# There is the presence of  duplicates.
./checker 3 2 2
Error

# Internal errors(e.g., malloc failure) occurred.
./checker 3 2 1
Error

# An invalid command is entered(immediately stops).
./checker 3 2 1
sa
rc
Error
```

## Resources

### References

Chunk Sort explanation(My implementation is based on this)\
https://qiita.com/MoriP-K/items/54ee96dc634148cf40a8

Understanding of basic sort algorithms\
https://play.google.com/store/apps/details?id=wiki.algorithm.algorithms&pli=1

Radix Sort explanation\
https://ja.wikipedia.org/wiki/%E5%9F%BA%E6%95%B0%E3%82%BD%E3%83%BC%E3%83%88\
https://en.wikipedia.org/wiki/Radix_sort

Turk Sort explanation\
https://medium.com/@ayogun/push-swap-c1f5d2d41e97

Complexity\
https://sevendays-study.com/algorithm/ex-day1.html
https://www.bigocheatsheet.com/

push_swap_tester\
https://github.com/nafuka11/push_swap_tester

push_swap_visualizer\
https://github.com/o-reo/push_swap_visualizer

### Description of AI Usage

- **Makefile & Build Logic**:\
  AI was used to debug and refine the `Makefile` structure, specifically to refine `ifdef` logic for the bonus target.
- **Algorithm Selection**:\
  AI gave me advice for selecting the algorithm to sort by listing up pro and cons of radix sort, turk sort and chunk sort.
- **Code Refinement**:\
  AI helped in detecting logical error and potential memory leak that I overlooked, and calculating the optimal range of chunk size to test.
- **Document Outline**:\
  AI assisted in outlining this README to make sure that it meets the project's requirements.
