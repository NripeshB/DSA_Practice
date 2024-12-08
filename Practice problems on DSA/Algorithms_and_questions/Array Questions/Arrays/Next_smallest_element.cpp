#include <iostream>
using namespace std;

void func(vector<int> &arr, vector<int> &ans, int n, int i) {
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
}

int main() {
    return 0;
}