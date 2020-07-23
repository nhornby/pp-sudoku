#include <iostream>
#include "Puzzle.h"

/* 
 * Author: Nolan Hornby
 * Date: Wednesday, July 22 2020
 * University of Michigan
 * Class of 2023
 */ 

using namespace std;

int main()
{
    int arr[81];
    for(int i = 0; i < 81; i++) {cin >> arr[i];}
    Puzzle puz(arr);

    cout << "unsolved puzzle: " << endl;
    puz.print_board();
    
    puz.solve_board();

    cout << "solved puzzle: " << endl;
    puz.print_board();
}