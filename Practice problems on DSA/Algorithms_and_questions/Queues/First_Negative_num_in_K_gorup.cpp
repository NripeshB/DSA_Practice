#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& A, int k) {
     
         deque< int> dq;
         vector<int> ans;
         int negative = -1;
         
         //process first window
         for(int i=0; i<k; i++) {
             if(A[i] < 0) {
                 dq.push_back(i);
             }
         }
         
         //push ans for FIRST window
         if(dq.size() > 0) {
             ans.push_back(A[dq.front()]);
         }
         else
         {
             ans.push_back(0);
         }
         int N = A.size();
         //now process for remaining windows
         for(int i = k; i<N; i++) {
             //first pop out of window element
             
             
             if(!dq.empty() && (i - dq.front())>=k ) {
                 dq.pop_front();
             }
             
             //then push current element
             if(A[i] < 0)
                dq.push_back(i);
             
            // put in ans
            if(dq.size() > 0) {
                 ans.push_back(A[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
         }
         return ans;
 }

    };


int main() {
    return 0;
}