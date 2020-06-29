#include <iostream>
#include "Puzzle.h"
/* solve.cpp
 * Program that uses tree recursion and "back-tracking" to solve
 * sudoku puzzles. Takes in a 9x9 matrix of integers through the 
 * input stream, with 0s representing unfilled/blank spaces in the
 * puzzle.
 * 
 * USAGE:
 * Compile:      g++ solve.cpp -o solve.exe
 * Run:          ./solve.exe < sudoku_in.txt > sudoku_out.txt
 * 
 * sudoku_in.txt example:
 * 0s represent blank spaces in the puzzle
 * 1-9 represents digits in the puzzle
 * 1 0 6 0 0 2 3 0 0
 * 0 5 0 0 0 6 0 9 1
 * 0 0 9 5 0 1 4 6 2
 * 0 3 7 9 0 5 0 0 0
 * 5 8 1 0 2 7 9 0 0
 * 0 0 0 4 0 8 1 5 7
 * 0 0 0 2 6 0 5 4 0
 * 0 0 4 1 5 0 6 0 9
 * 9 0 0 8 7 4 2 1 0
 * 
 * Author: Nolan Hornby
 * Date: Sunday, June 28 2020
 * University of Michigan
 * Class of 2023
 */ 

using namespace std;

int main()
{
    //Blank 9x9 matrix represented by an 81-element array
    int mat[81];
    for(int i = 0; i < 81; i++) {mat[i] = 0;}
    
    //Read in information into the 81-element array
    int index = 0;
    while(cin >> mat[index] && index < 81) {index++;}

    //Create a sudoku puzzle with this 81-element array
    Puzzle puz(mat);

    //Print unsolved puzzle
    cout << "unsolved puzzle: " << endl;
    puz.print_board();
    if(!puz.valid_puzzle_invariant(puz.get_board()))
    {
        cout << "preemptive failure: ";
        cout << "puzzle clues did not pass sudoku invariant" << endl;
        return 1;
    }
    
    //Solve the puzzle
    puz.solve_board();

    //Print solved puzzle
    cout << "solved puzzle: " << endl;
    puz.print_board();
}