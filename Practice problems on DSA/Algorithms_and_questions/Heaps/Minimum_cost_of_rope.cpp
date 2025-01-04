//https://geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
#include <iostream>
using namespace std;

class Solution {
  public:
  // make a min heap and add two cosequent tops by popping and then push the sum in pq along with saving in the ans
    
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int> > p;
        for(int i = 0; i< arr.size(); i++){
            p.push(arr[i]);
        }
        
        int ans = 0;
        while(p.size() > 1){
            int sum = 0;
            
            int a = p.top();
            p.pop();
            int b = p.top();
            p.pop();
            
            sum = a+b;
            p.push(sum);
            ans+= sum;
            
        }
        
        return ans;
        
    }
};

int main() {
    return 0;
}