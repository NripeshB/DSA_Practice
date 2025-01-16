#include <iostream>
using namespace std;

//there are two major methods to implement DP; 1st is the TOP DOWN approach using, Recursion and memoization.
//the other method is bottom up which uses tabulation





//implementing the top down approach on a simple question.
vector<int> ans; // Used for memoization.

int fib(int n) {
    ans.resize(n+1); // Ensure the vector is large enough for n.

    if (n == 0 || n == 1) {
        return n; // Base cases.
    }

    if (ans[n]) { // Check if already computed.
        return ans[n];
    }

    ans[n] = fib(n-1) + fib(n-2); // Compute and store the result.
    return ans[n]; // Return the stored result.
}

//Implementing the tabulation method on a simple question
class Solution {
public:
    int fib(int n) {

        if(n == 1 || n == 0){
            return n;
        }
        int arr[n+1];
        arr[0] = 0;
        arr[1] = 1;


        for(int i = 2; i <= n; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }

        return arr[n];

    }
};


//Implementing the tabulation method and OPTIMISING IT
class Solution {
public:
    int fib(int n) {

        if(n == 1 || n == 0){
            return n;
        }
        int prev1 = 0; 
        int prev2 = 1; 
        int curr;

        for(int i = 2; i <= n; i++){
           curr = prev1+ prev2;
           prev1 = prev2;
           prev2 = curr;
        }

        return curr;

    }
};


int main() {
    return 0;
}