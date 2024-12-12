//https://www.naukri.com/code360/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=SUBMISSION
#include <iostream>
#include<stack>
using namespace std;

/*void func(vector<int> &arr, vector<int> &ans, int n, int i) {
    if (i >= n) {
        return;
    }

    // Find next smaller element after index `i`
    int A = -1; // Default value when no smaller element exists
    for (int j = i + 1; j < n; j++) { // Fixed loop range to iterate within bounds
        if (arr[j] < arr[i]) {
            A = arr[j];
            break;
        }
    }
    ans[i] = A; // Update the answer for index `i`

    // Recursive call
    func(arr, ans, n, i + 1);
}

// Function to return next smaller element for all indexes
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> Ans(n,-1); // Ensure the result vector is properly sized with default values
    func(arr, Ans, n, 0);
    return Ans;
}*/


//Stack Implementation code:


vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}



int main() {
    return 0;
}   