//https://leetcode.com/problems/min-cost-climbing-stairs/
#include <iostream>
using namespace std;



class Solution {
public:
//TC O(n); SC O(n) + O(n)
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

//TC O(n); SC O(n) 
//bottom up method
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        //using this to implement tabulation approach
        int dp[size];
        dp[0] = cost[0];
        dp[1] = cost[1]; 

        for (int i = 2; i < size; i++)
        {
            dp[i]  = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[size-1], dp[size -2]);

    }
};

//TC O(n); SC O(1) 
//optimised space
//bottom up method
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        //using this to implement tabulation approach
        
        int prev1 = cost[0];
        int prev2 = cost[1]; 
        int curr;

        for (int i = 2; i < size; i++)
        {
            curr  = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }

        return min(prev1, prev2);

    }
};