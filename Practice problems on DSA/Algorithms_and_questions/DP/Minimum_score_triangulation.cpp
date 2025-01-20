//https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
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



class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill the DP table
        for (int i = n - 1; i >= 0; i--) {  // Start from the end for smaller ranges
            for (int j = i + 2; j < n; j++) {  // j should be at least 2 steps ahead of i
                dp[i][j] = INT_MAX;  // Initialize dp[i][j] to maximum value
                for (int k = i + 1; k < j; k++) {  // Try every k between i and j
                    dp[i][j] = min(dp[i][j], values[i] * values[k] * values[j] 
                                  + dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp[0][n - 1];  // Minimum triangulation cost for the entire polygon
    }
};


int main() {
    return 0;
}