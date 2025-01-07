//https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <iostream>
using namespace std;

class Solution {
  public:
  void solve( vector<vector<int> >&visited, string cycle,vector<vector<int> > &mat, vector<string>& ans, int column, int row){
      int size = mat[0].size()-1;
      if(row == column && row == size){
          ans.push_back(cycle);
          return ;
      }
      //backtracking happens when a function done, is undone after one recursion takes place
      visited[column][row] = 1;
      
      // checking for D
      if(column + 1 <= size && visited[column+1][row]!= 1&&mat[column+1][row] != 0){
          
     
          solve(visited,cycle + "D", mat, ans, column+1, row );
          
      }
      
       // checking for L
      if(row - 1 >= 0 && visited[column][row -1]!= 1&&mat[column][row-1] != 0){

          solve(visited, cycle + "L", mat, ans, column, row-1 );
        
      }
      
       // checking for R
      if(row + 1 <= size && visited[column][row+1]!= 1&&mat[column][row+1] != 0){
        

          solve(visited, cycle+ "R", mat, ans, column, row+1 );
        
      }
      
       // checking for U
      if(column - 1 >=0 && visited[column-1][row]!= 1 && mat[column-1][row] != 0){
        

          solve(visited, cycle + "U", mat, ans, column-1, row );
          
      }
      
      // reversing the change done in the visited array;
      visited[column][row] = 0;
      
      return;
      
      
  }
  
    vector<string> findPath(vector<vector<int>> &mat) {
      
         if (mat.empty() || mat[0].empty() || mat[0][0] == 0 || mat[mat.size() - 1][mat[0].size() - 1] == 0) {
            return {};
        }
        
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        
        vector<string> ans;
        int column = 0;
        int row = 0;
        string cycle = "";
        
        solve(visited,cycle, mat, ans, column, row );
        return ans;
    }
};


int main() {
    return 0;
}