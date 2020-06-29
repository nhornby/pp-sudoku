#ifndef PUZZLE_H
#define PUZZLE_H

/* Puzzle.h
 * 
 * Constructed from an 81-element array of digits from 1-9
 * Contains algorithms to solve, print, and test the map, 
 *             as if it were a sudoku puzzle
 * Digits 1-9 in the array represent digits in a sudoku puzzle
 * Digit 0 in the array represents a blank space in a sudoku puzzle
 * 
 * int map[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10...   }
 * represents a 9x9 matrix (ex): 
 *             0   1   2   3   4   5   6   7   8
 *             9   10  11  12  13  14  15  16  17
 *             18  19  20  21  22  23  24  25  26
 *             27  28  29 ...
 * 
 * Author: Nolan Hornby
 * Date: Sunday, June 28 2020
 * University of Michigan
 * Class of 2023
 */ 

#include <iostream>
#include <set>

class Puzzle {
public:
    Puzzle(int map_in[])
    {
        for(int i = 0; i < 81; i++)
        {
            map[i] = map_in[i];
        }
    }
    Puzzle(const Puzzle &other)
    {
        for(int i = 0; i < 81; i++)
        {
            map[i] = other.map[i];
        }
    }
    Puzzle &operator=(const Puzzle &rhs)
    {
        if(this == &rhs) {return *this;}

        for(int i = 0; i < 81; i++)
        {
            map[i] = rhs.map[i];
        }
        return *this;
    }
    
    //REQUIRES: board is a valid 81-element array of integers
    //MODIFIES: none
    //EFFECTS: prints the board to the console
    void print_board()
    {
        std::cout << std::endl;
        for(int r = 0; r < 9; r++)
        {
            std::cout << "  ";
            print_element(map, r, 0);
            print_element(map, r, 1);
            print_element(map, r, 2);
            std::cout << "  ";
            print_element(map, r, 3);
            print_element(map, r, 4);
            print_element(map, r, 5);
            std::cout << "  ";
            print_element(map, r, 6);
            print_element(map, r, 7);
            print_element(map, r, 8);
            std::cout << " " << std::endl;
            if((r + 1) % 3 == 0)
            {
                std::cout << std::endl;
            }
        }
    }
    //REQUIRES: board is a valid 81-element array of integers
    //MODIFIES: none
    //EFFECTS: returns false if any sudoku rules are violated, else returns true
    bool valid_puzzle_invariant(const int * board)
    {
        std::set<int> rows[9];
        std::set<int> cols[9];
        std::set<int> boxes[3][3];
        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                if(element_at(board, r, c) == 0) {continue;}

                if(!(rows[r].insert(element_at(board, r, c)).second)) {return false;}
                if(!(cols[c].insert(element_at(board, r, c)).second)) {return false;}
                if(!(boxes[r/3][c/3].insert(element_at(board, r, c)).second)) {return false;}
            }
        }
        return true;
    }
    //REQUIRES: none
    //MODIFIES: map - solves the sudoku puzzle "map"
    //EFFECTS: solves the puzzle :)
    void solve_board()
    {
        int * m = recurse_solve(map, 0);

        if(m == nullptr) {std::cout << "Fail to solve. :(" << std::endl;}
        for(int i = 0; i < 81; i++)
        {
            map[i] = m[i];
        }
    }
    //REQUIRES: none
    //MODIFIES: none
    //EFFECTS: returns map
    const int * get_board()
    {
        return map;
    }

private:
    //REQUIRES: board is an 81-element array of integers 1-9, 0 <= index < 81
    //MODIFIES: none
    //EFFECTS: returns an 81-element array of integers 1-9, containing the solution
    int * recurse_solve(int * board, const int index)
    {
        if(index > 80) {return board;} //IF BOARD FILLED?
        if(board[index] != 0) {return recurse_solve(board, index + 1);} //IF CURRENT SPOT FILLED?

        for(int i = 1; i <= 9; i++) //TEST DIGITS 1-9 AT INDEX
        {
            board[index] = i;

            if(!valid_puzzle_invariant(board)) //IF DOESN'T WORK, GO TO NEXT DIGIT
            {
                board[index] = 0;
                continue;
            }
            else //IF IT WORKS, GO TO NEXT INDEX
            {
                int * future = recurse_solve(board, index + 1);

                if(future == nullptr) {board[index] = 0;} //IF NO SOLUTION IN THE FUTURE, TRY A NEW DIGIT
                else {return future;} //IF THERE IS A SOLUTION IN THE FUTURE, RETURN IT
            }
        }

        return nullptr; //IF NONE WORK
    }
    //REQUIRES: board is an 81-element array of integers 1-9, 0 <= r < 9, 0 <= c < 9
    //MODIFIES: none
    //EFFECTS: returns the element at row r and column c of "board"
    int element_at(const int * board, const int r, const int c)
    {
        return board[9*r + c];
    }  
    //REQUIRES: board is an 81-element array of integers 1-9, 0 <= r < 9, 0 <= c < 9
    //MODIFIES: none
    //EFFECTS: prints the element at row r and column c of "board", and then a blank space
    //         if the element there is a 0, does not print the element, just two blank spaces
    void print_element(const int * board, const int r, const int c)
    {
        if(element_at(board, r, c) == 0)
        {
            std::cout << "  ";
        }
        else
        {
            std::cout << element_at(board, r, c) << " ";
        }
    }
    
    int map[];
};

#endif