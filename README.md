Personal Project: Sudoku Solver
=======================

Author: Nolan Hornby <nhornby@umich.edu>

Date: Saturday, March 13th, 2021

# Purpose
This program uses tree recursion and "back-tracking" to solve sudoku puzzles. It takes in a file of strings representing sudoku puzzles, (left-to-right, top-to-bottom, in one line), where 0s represent blank spaces.

This is an extremely lightweight solution to the below challenge:

https://codegolf.stackexchange.com/questions/190727/the-fastest-sudoku-solver

The average time for the "most difficult" (17-clue) sudoku puzzles is around 0.9 seconds of computation per puzzle.

The average time for "typical" (25-clue) sudoku puzzles is less than 0.01 seconds 

# Quick start
```console
$ g++ -O3 main.cpp -o main.exe
./main.exe < sudoku_in.txt
```

# Example Input File ("sudoku_in.txt") (2 puzzles)
```console
000075400000000008080190000300001060000000034000068170204000603900000020530200000
300000000050703008000028070700000043000000000003904105400300800100040000968000200
```

# Example Output ("output.txt")
```console
693875412145632798782194356357421869816957234429368175274519683968743521531286947
387419526259763418641528379716285943594631782823974165472396851135842697968157234
```
