#include <iostream>
using namespace std;


int main() {
    return 0;
}
class Solution {
public:

    int solve(int index, vector<int>& nums, vector<int>& dp, int end) {
        if (index >= end) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        int include = nums[index] + solve(index + 2, nums, dp, end); // Include current house
        int exclude = solve(index + 1, nums, dp, end);              // Skip current house

        dp[index] = max(include, exclude);
        return dp[index];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n == 0) return 0;             // Edge case: No houses
        if (n == 1) return nums[0];      // Edge case: Single house

        // Solve case 1: Include houses from 0 to n-2
        vector<int> dp1(n, -1);
        int ans1 = solve(0, nums, dp1, n - 1);

        // Solve case 2: Include houses from 1 to n-1
        vector<int> dp2(n, -1);
        int ans2 = solve(1, nums, dp2, n);

        return max(ans1, ans2);

        
    }
};
