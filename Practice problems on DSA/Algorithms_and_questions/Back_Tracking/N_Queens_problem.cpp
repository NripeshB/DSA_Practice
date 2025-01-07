#include <iostream>
using namespace std;

//Optimised method, still has the complexity of O(n!) but is faster due to using hashmaps
// thus to fetch true and false it takes O(1) instead of O(n)
class Solution {
public:
    void solve(int col, vector<string>& board, unordered_map<int, bool>& leftRow,
               unordered_map<int, bool>& upperDiagonal, unordered_map<int, bool>& lowerDiagonal,
               vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            // Check if the position is safe

            // for uninitialised mappings in hashmap the value is defaulted to false
            if (!leftRow[row] && !lowerDiagonal[row + col] && !upperDiagonal[col - row]) {
                // Place the queen
                board[row][col] = 'Q';
                leftRow[row] = true;
                // as doing row+ cols results in negative slope daigs to have same values
                lowerDiagonal[row + col] = true;
                // as doing col - row results in positive slope daigs to have same values
                upperDiagonal[col - row] = true;

                // Recur to place the next queen
                solve(col + 1, board, leftRow, upperDiagonal, lowerDiagonal, ans, n);

                // Backtrack: remove the queen
                board[row][col] = '.';
                leftRow[row] = false;
                lowerDiagonal[row + col] = false;
                upperDiagonal[col - row] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // Initialize an empty board

        // Hashmaps to track constraints
        unordered_map<int, bool> leftRow;              // Tracks occupied rows
        unordered_map<int, bool> upperDiagonal;       // Tracks upper diagonals (\ direction)
        unordered_map<int, bool> lowerDiagonal;       // Tracks lower diagonals (/ direction)

        solve(0, board, leftRow, upperDiagonal, lowerDiagonal, ans, n);
        return ans;
    }
};

//Unoptimised method... almost brute force
class Solution {
public:

void pushans(vector<vector<string> >& ans, vector<vector<int> > board, int size){
    string s = "";
    vector<string> subS;

    for( int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            if(board[i][j] == 1){
                s = s + "Q";
            }
            else{
                s = s+ ".";
            }
        }
        subS.push_back(s);
        s.clear();
    }
    ans.push_back(subS);
}

bool isSafe( vector<vector<int> > board, int col, int row, int n){
    //check only on the left of the queen 
    int column = col;
    int Row = row;
    while(column >=0){
        if(board[Row][column] == 1){
            return false;
        }
        column--;
    }

    // no need to check up or down as we are inserting columns wise

    //no need to check right side at all as we start queen insertion from the left

    column = col;
    Row = row;
    //checking upper diag
    while(column>= 0 && Row>=0){
        if(board[Row][column] == 1){
            return false;
            
        }

        column --;
        Row --;
    }


    column = col;
    Row = row;
    //checking lower diag
    while(column>= 0 && Row<n){
        if(board[Row][column] == 1){
            return false;
            
        }

        column --;
        Row ++;
    }

    return true;

}

void solve(vector<vector<string> >& ans, vector<vector<int> > board, int n, int col){
    if(col == n){
        pushans(ans, board,n);
        return;
    }

    for(int i = 0; i< n; i++){
        if(isSafe(board, col, i, n)){

            board[i][col] = 1;
            solve(ans, board, n, col+1);
            board[i][col] = 0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<vector<int> > board(n, vector<int>(n,0));
        int col = 0;
        solve(ans, board, n, col); 
        return ans;
    }
};

int main() {
    return 0;
}