// Sudoku Solver
// Author: Nolan Hornby <nhornby@umich.edu>
// Date: January 19th, 2021

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "PuzzleState.hpp"

int main(int argc, char *argv[]) {
    // speed up i/o
    std::ios_base::sync_with_stdio(false);

    // output to "output.txt"
    std::ofstream os("output.txt");

    // start time.
    auto start = std::chrono::high_resolution_clock::now();

    // solution read/solve/write loop
    std::string line_in;
    while(std::cin >> line_in) {
        PuzzleState solver(line_in);
        solver.solve_puzzle();
        std::string line_out;
        line_out = solver.get_puzzle();
        os << line_out << "\n";
    }

    // end time. send to console.
    auto end = std::chrono::high_resolution_clock::now();
    double time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "time: " << time / 1000 << " seconds." << std::endl;
}