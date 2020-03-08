# SudokuSolver
This is an implementation of recursive backtracking to solve Sudoku Puzzles on user input. There are two main implementations:
C++ and Java. The C++ implementation interfaces with the commmand line as a Command Line program. The Java implementation, still under development, will use the command line and eventually JavaFX to solve GUI Java problems with the same algorithm.

Recursive Backtracking is a useful method for solving problems when Choices are well defined, we have constraints on the choices we have to make, and we have a well defined goal. Solving a sudoku grid is an excellent reason to use this. A recursive problem solves sub problems, before solving a large one. Backtracking allows us to roll back previous attempted solutions in the event that the attempted solution does not apply any more, this is especially useful in solving Sudoku problems.

Using the program:

C++ - download the cpp folder, open up a bash command line and type `make`.
Once you have ran the makefile in a bash command terminal type the command: `./sudoku-solver`
This then creates an empty input where you insert the Sudoku board. The formatting for the input is:
The Zero ASCII Character - 0, represents empty space. Numbers represent the numbers in the puzzle. Finally each number or empty value must be separated by white space. A full input format looks like the examples provided in the SamplePuzzles file or the example below.

```
0 2 0 0 0 0 0 0 0
0 0 0 6 0 0 0 0 3
0 7 4 0 8 0 0 0 0
0 0 0 0 0 3 0 0 2
0 8 0 0 4 0 0 1 0
6 0 0 5 0 0 0 0 0
0 0 0 0 1 0 7 8 0
5 0 0 0 0 9 0 0 0
0 0 0 0 0 0 0 4 0
```



Java - This was built in IntelliJ, but should work great with your favorite Java IDE directly!
