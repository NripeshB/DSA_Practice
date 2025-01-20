#include <iostream>
using namespace std;

//this is the top down approach
class Solution {
public:

    int solve(vector<int>& values, int i, int j, vector<vector<int>>&dp){
        if( i+1 == j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

         int mini = INT_MAX;
        
        //we pass any two adjacent vertices and pass recursively for the rest of the loop
        for(int k = i+1; k<j; k++ ){
            mini = min(mini, values[i]*values[k]*values[j] + solve(values, i, k, dp) + solve(values, k, j, dp) );

        }

        dp[i][j] =  mini;
        return dp[i][j];  //memoisation
    }
    int minScoreTriangulation(vector<int>& values) {
       vector<vector<int>>dp(values.size(), vector<int>(values.size(), -1));
       //we choose i and j as the first and  the last element of the array as it is cyclic and is bound
       //to be the end of each
       int i = 0;
       int j = values.size()-1;
       int ans =  solve( values,i, j, dp); 
       return ans;
    }
};

int main() {
    return 0;
}