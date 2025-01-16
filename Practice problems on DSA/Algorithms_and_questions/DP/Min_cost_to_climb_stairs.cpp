//https://leetcode.com/problems/min-cost-climbing-stairs/
#include <iostream>
using namespace std;



class Solution {
public:

    int solve(int size, vector<int>&cost, vector<int>&dp){
        //returning the memoization if exists
        if(dp[size] != -1){
            return dp[size];
        }
        if(size == 1 || size == 0){
            dp[size] =  ( cost[size]);
            return dp[size];
        }

        if( size == cost.size()){
            dp[size]= min( solve(size-1,cost,dp), solve( size-2, cost, dp) );
            return dp[size];
        }

        dp[size]= min((solve(size-1, cost, dp) + cost[size]), (solve(size-2, cost, dp) + cost[size]));
        return dp[size];
    }
   
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        //using this to handle memoization
        vector<int> dp(size+1, -1);

        int ans =  solve(size, cost, dp);
        return ans;
    }
};