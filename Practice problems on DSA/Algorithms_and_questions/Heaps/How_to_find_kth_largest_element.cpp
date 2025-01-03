//https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
#include <iostream>
using namespace std;

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    

    // The algo used :
    //first make a max heap or priority queue containing first k elements;
    //then push the rest iff the element is smaller than top.
    //then youd be left with the kth largest element on the top.
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> p ;
        for(int i = 0 ; i<k; i++){
            p.push(arr[i]);
        }
        
        for(int i = k; i< arr.size(); i++){
            if(arr[i]<p.top()){
                p.pop();
                p.push(arr[i]);
            }
        }
        return p.top();
    }
};

int main() {
    return 0;
}