#include <iostream>
using namespace std;


int main() {
    return 0;
}

//This is the recursive approach

class Solution {
public:

    int solve(vector<int>&obstacles,int point,int lane, int count){
        if(point == obstacles.size()-1){
            return count;
        }

        int ans= INT_MAX;

        if(obstacles[point+1] != lane ){
            ans = min(ans,solve(obstacles, point+1, lane, count));
        }

        else{
            for(int i = 1; i<= 3; i++){
                if(i == lane|| obstacles[point] == i){
                    continue;
                }
                    ans =min(ans, solve(obstacles, point,i,count +1 ));  
            }
        }
        return ans;
    }

    int minSideJumps(vector<int>& obstacles) {
        int count = 0;
        int point = 0;
        int lane = 2;
        int ans = solve( obstacles, point, lane,count);

        return ans;
    }
};

//top down approach or recursion + memoisation
class Solution {
public:

    int solve(vector<int>&obstacles,int point,int lane, vector<vector<int>>&dp){
        if(point == obstacles.size()-1){
            return 0;
        }
        if(dp[point][lane] != -1){
            return dp[point][lane];
        }

        int ans= INT_MAX;
        if(obstacles[point+1] != lane ){
            ans = min(ans,solve(obstacles, point+1, lane,dp));
            
        }

        else{
            for(int i = 1; i<= 3; i++){
                if(i == lane|| obstacles[point] == i){
                    continue;
                }
                    ans = min(ans,1+solve(obstacles, point+1, i,dp));
                   

                    
            }
        }
         dp[point][lane] = ans;
        return  ans;

    }

    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>>dp(obstacles.size(),vector<int>(4, -1));
        int point = 0;
        int lane = 2;
        int ans = solve( obstacles, point, lane, dp);

        return ans;
    }
};