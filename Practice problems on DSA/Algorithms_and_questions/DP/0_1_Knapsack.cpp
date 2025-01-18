#include <iostream>
#include <limits.h>
using namespace std;
class Solution {
  public:


  //normal recursive approach  
  int solve(int capacity, vector<int> &val, vector<int> &wt, int&ans, int size){
      if( size == 0){
          if(wt[0]> capacity){
              return 0;
          }
          else{
              return val[0];
          }
      }
      int inc = 0;
      
      if(wt[size] <= capacity){
          inc = val[size] + solve(capacity-wt[size], val, wt, ans, size-1);
      }
     int exc = 0 + solve(capacity, val, wt, ans, size-1);
           
       
      
      
      ans =  max(inc, exc);
      return ans;
  }
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int size = val.size()-1;
        int diff = INT_MIN;
    int ans =  solve(capacity, val, wt, diff, size);
    return ans;
    }
};


//This is the recursion + memoisation approach.
//this is different than a normal dp as it is 2d dp; ie it has 2 variables that changes in the recursion
//here those are the capacity and size variables, hence we assign a 2d array or vector to handle it
class Solution {
  public:
  int solve(int capacity, vector<int> &val, vector<int> &wt, int&ans, int size, vector<vector<int> >&dp){
      if( size == 0){
          if(wt[0]> capacity){
              return 0;
          }
          else{
              return val[0];
          }
      }
      
      if(dp[size][capacity]!= -1){
          return dp[size][capacity];
      }
      int inc = 0;
      
      if(wt[size] <= capacity){
          inc = val[size] + solve(capacity-wt[size], val, wt, ans, size-1,dp);
      }
     int exc = 0 + solve(capacity, val, wt, ans, size-1,dp);
           
       
      
      
      dp[size][capacity] =  max(inc, exc);
      return dp[size][capacity];
  }
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int size = val.size()-1;
        int diff = INT_MIN;
        vector<vector<int> > dp(size+1, vector<int>(capacity+1, -1));
    int ans =  solve(capacity, val, wt, diff, size, dp);
    return ans;
    }
};
int main() {
    return 0;
}

//Using tabulation method

#include <vector>
#include <limits.h>
using namespace std;

class Solution {
  public:

    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int size = val.size();
        
        // Initialize a dp table with dimensions (size+1) x (capacity+1)
        vector<vector<int>> dp(size + 1, vector<int>(capacity + 1, 0));

        // Bottom-up approach
        for (int index = 1; index <= size; index++) {
            for (int w = 0; w <= capacity; w++) {
                int inc = 0;
                if (wt[index - 1] <= w) {  // Correct index for `wt` array
                    inc = val[index - 1] + dp[index - 1][w - wt[index - 1]];
                }
                int exc = dp[index - 1][w];
                dp[index][w] = max(inc, exc);
            }
        }

        return dp[size][capacity];
    }
};
int main() {
    return 0;
}