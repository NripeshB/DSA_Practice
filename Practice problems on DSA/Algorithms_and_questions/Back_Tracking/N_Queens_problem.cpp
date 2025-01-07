#include <iostream>
using namespace std;

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