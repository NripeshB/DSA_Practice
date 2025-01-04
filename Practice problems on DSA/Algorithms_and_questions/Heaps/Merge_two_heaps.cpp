//https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
#include <iostream>
using namespace std;


//this code works as a normal merging of two arrays, given these are max heaps;
//if the merging logic hadn't worked, we would have used the heapify logic after merging
class Solution{
    public:
    
    vector<int> merge( vector<int>& a, vector<int>&b){
        int sizea = a.size();
        int sizeb = b.size();
        vector<int> c;
        int i = 0;
        int j = 0;
        while( sizea>i && sizeb>j){
            if( a[i]>= b[j]){
                c.push_back(a[i]);
                i++;
            }
        else{
            c.push_back(b[j]);
            j++;
            }
        
        }
        
        while( sizea>i){
            c.push_back(a[i]);
            i++;
        }
        
        while( sizeb>j){
            c.push_back(b[j]);
            j++;
        }
        
        return c;
    }
    
  /* void Heapify(vector<int>&ans, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (right <= n && ans[largest] < ans[right]){
        largest = right;
    }
    if (left <= n && ans[largest] < ans[left]){
        largest = left;
    }

    if(largest != i){
        swap(ans[largest], ans[i]);
        Heapify(ans, n, largest);
    }
}*/
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans = merge(a, b);
        //Heapify(ans, m+n, 1);
        return ans;
    }
};

int main() {
    return 0;
}