//https://www.naukri.com/code360/problems/median-in-a-stream_975268?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//A stream of integers is given which we have to continuosly find the median of. The array of integers is imagined
//as two sets on left a min heap and on right, a max heap. The element is inserted and such that the net diff
//btw booth the heaps reamains <= 1. and median is calculated via the formula


// Helper function to calculate the signum of two integers
int signum(int a, int b) {
    if (a == b) return 0;
    return (a > b) ? 1 : -1;
}

// Function to calculate and update the median after each insertion
void callmedian(int element, priority_queue<int>& maxi, priority_queue<int, vector<int>, greater<int>>& mini, int& median) {
    switch (signum(maxi.size(), mini.size())) {
        case 0: // Both heaps are of equal size
            if (element > median) {
                mini.push(element);
                median = mini.top();
            } else {
                maxi.push(element);
                median = maxi.top();
            }
            break;

        case 1: // maxi heap has more elements
            if (element > median) {
                mini.push(element);
            } else {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
            }
            median = (maxi.top() + mini.top()) / 2;
            break;

        case -1: // mini heap has more elements
            if (element > median) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
            } else {
                maxi.push(element);
            }
            median = (maxi.top() + mini.top()) / 2;
            break;
    }
}

// Main function to find the median after every insertion
vector<int> findMedian(vector<int>& arr, int n) {
    vector<int> ans;
    priority_queue<int> maxheap; // Max-heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minheap; // Min-heap for the upper half
    int median = 0; // Initial median

    for (int i = 0; i < n; i++) {
        callmedian(arr[i], maxheap, minheap, median);
        ans.push_back(median);
    }

    return ans;
}

int main() {
    return 0;
}