
#include <iostream>
using namespace std;
//https://leetcode.com/problems/coin-change/submissions/1510304552/


class Solution {
public:

//This is the recursion and memoization method 
    int solve(vector<int>& coins, int amount, vector<int>& dp) {

        
        if (amount == 0) {
            dp[amount] = 0;
            return dp[amount];
        }

        if (amount < 0) {
            return INT_MAX;  // Handle negative cases
        }
        if (dp[amount] != -1) {
            return dp[amount];
        }

        int result = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            int temp = solve(coins, amount - coins[i], dp);
            if (temp != INT_MAX) {
                result = min(result, 1 + temp);  // Use min to avoid unnecessary updates
            }
        }
        dp[amount] = result;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);  // Initialize dp array up to `amount`
        int ans = solve(coins, amount, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};

class Solution {
public:

//this is the bottoms down approach

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);

        dp[0] = 0;
        for(int i = 1; i<= amount; i++){
            //now for each amount all coin combinations

            for (int j = 0; j < coins.size(); j++){
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
                
            }
        }
        if (dp[amount] == INT_MAX){
            return -1;
        
        }
        else{return dp[amount];}
        

    }
};