/*
 * main.cpp
 * c-ssolver
 *
 * Lightweight Sudoku Solver to attempt the below challenge
 * https://codegolf.stackexchange.com/questions/190727/the-fastest-sudoku-solver
 * Average 45-clue time: 0.00002 s
 * Average 40-clue time: 0.00004 s
 * Average 35-clue time: 0.00009 s
 * Average 30-clue time: 0.00046 s
 * Average 25-clue time: 0.00946 s
 * Average 17-clue time: 0.93749 s
 * Created by Nolan Hornby on 3/7/21.
 */

#include <iostream>
#include <string>
#include <vector>
#include "Timer.hpp"

class BacktrackSolver {
public:
    std::string * backtrack_solve(std::string * temp, unsigned spot = 0) {
        if(spot == 81) { return temp; }
        if((*temp)[spot] != '0') {return backtrack_solve(temp, spot+1);}
        
        for(char i = '1';i<='9';++i) {
            (*temp)[spot] = i;
            if(invariant(temp, spot)) {
                if(backtrack_solve(temp, spot+1) != nullptr) {return temp;}
            }
        }
        (*temp)[spot] = '0';
        return nullptr;
    }
private:
    bool invariant(const std::string * temp, const int spot) {
        int row = spot/9; // the row of the "spot"
        int col = spot%9; // the column of the "spot"

        char new_elem = (*temp)[9*row + col]; // the newly inserted element.

        // check row and col
        for(size_t i = 0; i < 9; ++i) {
            if(i != col && (*temp)[9*row + i] == new_elem) {return false;}
            if(i != row && (*temp)[9*i + col] == new_elem) {return false;}
        }
        
        int boxRowStart = 3*(row/3);
        int boxRowEnd = 3*(row/3) + 3;
        int boxColStart = 3*(col/3);
        int boxColEnd = 3*(col/3) + 3;
            
        // check box
        for(size_t r = boxRowStart; r < boxRowEnd; ++r) {
            for(size_t c = boxColStart; c < boxColEnd; ++c) {
                if(r != row && c != col) {
                    if((*temp)[9*r + c] == new_elem) {return false;}
                }
            }
        }
                
        return true;
    }
};


int main(int argc, char * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    BacktrackSolver bs;
    Timer t;
    std::string puzzle;
    unsigned count = 0;
    
    t.start();                              // Timer Start
    while(getline(std::cin, puzzle)) {
        bs.backtrack_solve(&puzzle);        // 1. Solve Puzzle
        std::cout << puzzle << "\n";        // 2. Print Puzzle
        count++;                            // 3. Increment Count
    }
    t.stop();                               // Timer Stop
    
    std::cout << "Statistics:\n";
    std::cout << "- Time: " << t.seconds() << "s\n";
    std::cout << "- Puzzles: " << count << "\n";
    std::cout << "- Time/Puzzle: " << t.seconds()/count << "s\n";
}
