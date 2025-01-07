//https://leetcode.com/problems/sudoku-solver/
#include <iostream>
using namespace std;

class Solution {
public:

//this checks the condition if insertion of the char num is valid or not
    bool isSafe(vector<vector<char>>& board, int y, int x, char num) {
        // Check the column
        for (int i = 0; i < 9; i++) {
            if (board[i][x] == num) {
                return false;
            }
        }

        // Check the row
        for (int i = 0; i < 9; i++) {
            if (board[y][i] == num) {
                return false;
            }
        }

        // Check the 3x3 block
        int blockRowStart = (y / 3) * 3;
        int blockColStart = (x / 3) * 3;
        for (int i = blockRowStart; i < blockRowStart + 3; i++) {
            for (int j = blockColStart; j < blockColStart + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solveSudokuHelper(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {  // Find an empty cell
                    for (char num = '1'; num <= '9'; num++) {  // Try digits 1 to 9
                        if (isSafe(board, i, j, num)) {
                            board[i][j] = num;  // Place the number
                            if (solveSudokuHelper(board)) {
                                return true;  // If solved, return true
                            }
                            board[i][j] = '.';  // Backtrack if not solved
                        }
                    }
                    // if this returns false ie no valid number exists that can be put in that place
                    // this is only possible when we have assumed a past number which is invalid for 
                    // the rest of the sudoku but was valid for that instance
                    return false;  // If no valid number, return false
                }
            }
        }
//this is executed when the function doesnt pass into the '.' if condition and traverses the entire sudoku.
        return true;  // All cells are filled, return true
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);  // Start solving
    }
};


int main() {
    return 0;
}