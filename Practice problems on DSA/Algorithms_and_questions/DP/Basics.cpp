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


int main() {
    return 0;
}