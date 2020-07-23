Project 7
=======================
Sudoku Solver

Author: Nolan Hornby <nhornby@umich.edu>
Date: Wednesday, July 22 2020

# Purpose
This program uses tree recursion and "back-tracking" to solve sudoku puzzles. It takes in a 9x9 matrix of integers from a file, with 0s representing blank spaces in the puzzle.

# Quick start
```console
$ g++ solve.cpp -o solve.exe
./solve.exe < sudoku_in.txt
```

# Example Input File ("sudoku_in.txt")
```console
1 0 6 0 0 2 3 0 0
0 5 0 0 0 6 0 9 1
0 0 9 5 0 1 4 6 2
0 3 7 9 0 5 0 0 0
5 8 1 0 2 7 9 0 0
0 0 0 4 0 8 1 5 7
0 0 0 2 6 0 5 4 0
0 0 4 1 5 0 6 0 9
9 0 0 8 7 4 2 1 0
```

# Example Output
```console
unsolved puzzle: 

  1   6       2   3      
    5         6     9 1  
      9   5   1   4 6 2  

    3 7   9   5          
  5 8 1     2 7   9      
          4   8   1 5 7  

          2 6     5 4    
      4   1 5     6   9  
  9       8 7 4   2 1    

solved puzzle: 

  1 4 6   7 9 2   3 8 5  
  2 5 8   3 4 6   7 9 1  
  3 7 9   5 8 1   4 6 2  

  4 3 7   9 1 5   8 2 6  
  5 8 1   6 2 7   9 3 4  
  6 9 2   4 3 8   1 5 7  

  7 1 3   2 6 9   5 4 8  
  8 2 4   1 5 3   6 7 9  
  9 6 5   8 7 4   2 1 3  
```