#include <iostream>
#include <limits.h>
using namespace std;
class Solution {
  public:
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

int main() {
    return 0;
}