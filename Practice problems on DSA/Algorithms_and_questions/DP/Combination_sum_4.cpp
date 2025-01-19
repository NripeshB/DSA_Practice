//https://leetcode.com/problems/combination-sum-iv/
#include <iostream>
using namespace std;


int main() {
    return 0;
}


//Recursion + memoisation approach
class Solution {
public:

    int solve(vector<int>& nums, int target, vector<int>& dp){
        if(target == 0){
        return 1;
       }
       if(target <0){
        return 0;
       } 

       if( dp[target]!= -1){
        return dp[target];
       }
       
       int ans = 0;
       for(auto i : nums){
       ans += solve(nums, target-i,dp);
       }
       dp[target] = ans;

       return dp[target];
    }
    

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp (target + 1, -1);
        int ans = solve(nums, target, dp);
        return ans;
    }
};


//tabulation approach
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector< unsigned int> dp(target + 1, 0);

        dp[0] = 1; // Base case: One way to make target 0 (empty set)

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] = (dp[i] + dp[i - num]) ;
                }
            }
        }

        return dp[target];
    }
};
