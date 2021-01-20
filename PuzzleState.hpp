#include <iostream>
#include <string>

class PuzzleState {
public:
    PuzzleState(std::string line_in) {
        puzzle = new unsigned int[81];
        for(int i=0;i<81;i++) {
            puzzle[i] = (line_in[i] - 48);
        }
    }
    ~PuzzleState() {
        delete [] puzzle;
        puzzle = nullptr;
    }
    
    void display_puzzle() const {
        for(size_t i=0;i<81;++i) {
            if(i % 9 == 0) {std::cout << "\n  ";}
            if(puzzle[i] == 0) {std::cout << ". ";}
            else {std::cout << puzzle[i] << " ";}
        }
        std::cout << "\n\n";
    }
    void solve_puzzle() { puzzle = recurse_solve(puzzle, 0); }
    std::string get_puzzle() { 
        if(puzzle == nullptr) {return "";}
        std::string line_out = "";
        for(int i=0;i<81;i++) {
            line_out.push_back(puzzle[i] + 48);
        }
        return line_out;
    }
private:
    bool valid_placement(const unsigned int * temp, const int spot) const {
        int row = spot/9; // the row of the "spot"
        int col = spot%9; // the column of the "spot"
        int boxrow = row/3; // the box row of the "spot"
        int boxcol = col/3; // the box column of the "spot"

        unsigned int new_elem = temp[9*row + col]; // the newly inserted element.

        // check row.
        for(size_t c=0; c<9; ++c) {
            if(c != col) {
                if(temp[9*row + c] == new_elem) {return false;}
            }
        }
        // check box.
        for(size_t r=3*boxrow;r<3*boxrow + 3;++r) {
            for(size_t c=3*boxcol;c<3*boxcol + 3;++c) {
                if(r != row || c != col) {
                    if(temp[9*r + c] == new_elem) {return false;}
                }
            }
        }
        // check column.
        for(size_t r=0; r<9; ++r) {
            if(r != row) {
                if(temp[9*r + col] == new_elem) {return false;}
            }
        }
        return true;
    }
    unsigned int * recurse_solve(unsigned int * temp, int spot) const {
        if(spot > 80) {return temp;}
        if(temp[spot] != 0) {return recurse_solve(temp, spot+1);}
        
        for(unsigned int i=1;i<10;++i) {
            temp[spot] = i;
            if(valid_placement(temp, spot)) {
                if(recurse_solve(temp, spot+1) != nullptr) {
                    return temp;
                }
            }
        }
        temp[spot] = 0;
        return nullptr;
    }
    
    unsigned int * puzzle;
};