#include <iostream>
using namespace std;

//this is top down method( recursion & memoisation)
class Solution {
  public:
  
  int solve( int n, vector<int>&dp){
      if(n == 0){
          return 0;
      }
      
      if(dp[n] != -1){
          return dp[n];
      }
      
      int ans = n;
      
      for( int i = 1; i*i <= n; i++){
          ans = min(ans,  solve( n - i*i, dp) + 1);
      }
      dp[n] = ans;
      return dp[n];
  }
    int MinSquares(int n) {
        vector<int> dp(n+1, -1 );
        int ans = solve( n, dp);
        return ans;
    }
};

//tabulation method 
class Solution {
  public:
  

    int MinSquares(int n) {
        vector<int> dp(n+1, INT_MAX );
        dp[0] = 0;

        for(int i = 1; i <= n; i++ ){
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];



    }
};



int main() {
    return 0;
}