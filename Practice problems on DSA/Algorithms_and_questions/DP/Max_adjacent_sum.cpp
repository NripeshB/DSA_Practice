//https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
#include <iostream>
using namespace std;
//This is the recursion + memoisation way top down
class Solution {
  public:
    int solve(int index, vector<int>& ans, vector<int>& dp){
        if( index >= ans.size()){
            return 0 ;
        }
        if(dp[index]!= -1){
            return dp[index];
        }
        
        int i = ans[index] + solve(index+2, ans, dp);
        int e = solve(index+1, ans,dp);
        
        dp[index] = max(i,e);
        return dp[index];
    }
    int findMaxSum(vector<int>& arr) {
        vector<int> dp(arr.size() + 1, -1);
        int index = 0;
       
        int ans  = solve(index, arr, dp);
        return ans;
    }
};


//This is the tabulation approach

class Solution {
  public:
    
    int findMaxSum(vector<int>& arr) {
        vector<int> dp(arr.size() + 1, 0);
       
       
        dp[0] = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int inc = arr[i];               // Include current element
            if (i > 1) {
                inc += dp[i - 2];           // Add dp[i-2] only if i > 1
            }
            int exc = dp[i - 1];            // Exclude current element
            dp[i] = max(inc, exc);          // Take the maximum of include and exclude
        }

        return dp[arr.size()-1];
    }
};

//Optimised the space complexity

class Solution {
  public:
    
    int findMaxSum(vector<int>& arr) {
        vector<int> dp(arr.size() + 1, 0);
       
        int p1 = arr[0];
        int p2 = 0;
        int curri = 0;
        int curre = 0;
        int ans = 0;

        for (int i = 1; i < arr.size(); i++) {
            curri = arr[i] + p2;              
            curre = p1;           
            ans = max(curri, curre); 
            p2 = p1;
            p1 = ans;
        }

        return ans;
    }
};


int main() {
    return 0;
}