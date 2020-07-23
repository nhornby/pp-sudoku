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
 * Date: Wednesday, July 22 2020
 * University of Michigan
 * Class of 2023
 */ 

#include <iostream>
#include <set>

class Puzzle {
public:
    Puzzle(int * b)
    {
        for(int i = 0; i < 81; i++)
        {
            map[i] = b[i];
        }
    }
    void print_board() const
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
    void solve_board()
    {
        int * n = recurse_solve(map, 0);

        if(n == nullptr) {std::cout << "Fail to solve. Check that your puzzle is valid. :(" << std::endl; return;}
        for(int i = 0; i < 81; i++)
        {
            map[i] = n[i];
        }
    }
private:
    //REQUIRES: board is a valid 81-element array of integers, 0 <= r < 9, 0 <= c < 9
    //EFFECTS: returns false if any sudoku rules are violated at [r,c]
    bool valid_invariant(const int * board, const int r, const int c) const
    {
        int boxrow = r/3;
        int boxcol = c/3;

        //Test column
        std::set<int> vertical;
        for(int i = 0; i < 9; i++)
        {
            if(board[9*i + c] == 0) {continue;}
            if(!vertical.insert(board[9*i + c]).second) {return false;}
        }

        //Test row
        std::set<int> horizontal;
        for(int i = 0; i < 9; i++)
        {
            if(board[9*r + i] == 0) {continue;}
            if(!horizontal.insert(board[9*r + i]).second) {return false;}
        }
        
        //Test box
        std::set<int> box;
        for(int rr = 0; rr < 3; rr++)
        {
            for(int cc = 0; cc < 3; cc++)
            {
                int elem = board[9*(3*boxrow + rr) + (3*boxcol + cc)];

                if(elem == 0) {continue;}
                if(!box.insert(elem).second) {return false;}
            }
        }

        //If no invariants broken, return true :)
        return true;
    }
    //REQUIRES: board is an 81-element array of integers 1-9, 0 <= index < 81
    //EFFECTS: returns an 81-element array of integers 1-9, containing the solution
    int * recurse_solve(int * board, const int index) const
    {
        if(index > 80) {return board;}
        if(board[index] != 0) {return recurse_solve(board, index + 1);}

        for(int i = 1; i <= 9; i++)
        {
            board[index] = i;
            if(valid_invariant(board, index/9, index%9))
            {
                int * future = recurse_solve(board, index + 1);
                if(future != nullptr) {return future;}
            }
            board[index] = 0;
        }

        return nullptr;
    }
    //REQUIRES: board is an 81-element array of integers 1-9, 0 <= r < 9, 0 <= c < 9
    //EFFECTS: helper function for print_board()
    void print_element(const int * board, const int r, const int c) const
    {
        if(board[9*r + c] == 0) {std::cout << "  ";}
        else {std::cout << board[9*r + c] << " ";}
    }
    
    int map[];
};

#endif