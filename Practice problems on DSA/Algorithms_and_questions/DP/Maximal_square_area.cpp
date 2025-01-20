//https://leetcode.com/problems/maximal-square/
#include <iostream>
using namespace std;


//Top down approach (recursion + memoisation)
class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j, int& maxi, vector<vector<int>>&dp) {
        // Base case: Out of bounds
        if (i >= matrix.size() || j >= matrix[0].size()) {
            return 0;
        }

        if(dp[i][j]!= -1){
                return dp[i][j];
            }

        // Recursive calls for right, diagonal, and down cells
        int right = solve(matrix, i, j + 1, maxi, dp);
        int diag = solve(matrix, i + 1, j + 1, maxi, dp);
        int down = solve(matrix, i + 1, j, maxi, dp);

        // If the current cell is '1', calculate the size of the square
        if (matrix[i][j] == '1') {
            int ans = 1 + min(right, min(diag, down));
            maxi = max(maxi, ans);
            dp[i][j] = ans; // Return the size of the square ending at this cell
            return dp[i][j];
        }
         else {
            dp[i][j] = 0; // Cell is '0', no square possible
            return dp[i][j];
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp (matrix.size(), vector<int>(matrix[0].size(), -1));
        int maxi = 0; // Initialize maxi to 0 (minimum possible square size)
        solve(matrix, 0, 0, maxi, dp); // Start recursion from the top-left corner
        return maxi * maxi; // Return the area of the largest square
    }
};

// tabulation method

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0; // Handle empty matrix case
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxi = 0; // To track the largest square's side length

        // Create a DP table with the same dimensions as the matrix
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // Iterate over each cell in the matrix
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // If the current cell in the matrix is '1'
                if (matrix[i][j] == '1') {
                    // If it's the first row or first column, it can only be a 1x1 square
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        // Otherwise, calculate the size of the square ending at this cell
                        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    }

                    // Update the maximum square side length
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }

        // The area of the largest square is the square of its side length
        return maxi * maxi;
    }
};



int main() {
    return 0;
}