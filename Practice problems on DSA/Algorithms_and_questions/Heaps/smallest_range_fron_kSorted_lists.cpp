//https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

// Key Steps:
// 1. Initialize the min-heap with the first element from each list. Track the maximum element among them (`currentMax`).
// 2. Continuously extract the smallest element (`currentMin`) from the heap and check if the range [currentMin, currentMax]
// is smaller than the current range.
// 3. If a smaller range is found, update the range boundaries (`rangeStart`, `rangeEnd`).
// 4. Push the next element from the list of the extracted smallest element into the heap. Update `currentMax` accordingly.
// 5. Stop processing when any list is exhausted, as we can no longer include elements from all k lists.
// 
// The final result is the length of the smallest range that includes at least one number from each of the k sorted lists.


class Node {
public:
    int value; // Current element value
    int listIndex; // Index of the list
    int elementIndex; // Index within the list

    Node(int value, int listIndex, int elementIndex)
        : value(value), listIndex(listIndex), elementIndex(elementIndex) {}
};

// Custom comparator for the min-heap
struct Compare {
    bool operator()(Node a, Node b) {
        return a.value > b.value; // Min-heap based on the value
    }
};

int kSorted(vector<vector<int>>& nums, int k, int n) {
    priority_queue<Node, vector<Node>, Compare> minHeap;

    int currentMax = INT_MIN;
    int rangeStart = 0, rangeEnd = INT_MAX;

    // Push the first element of each list into the heap
    for (int i = 0; i < nums.size(); i++) {
        minHeap.push(Node(nums[i][0], i, 0));
        currentMax = max(currentMax, nums[i][0]);
    }

    // Process the heap
    while (minHeap.size() == nums.size()) {
        Node current = minHeap.top();
        minHeap.pop();

        int currentMin = current.value;

        // Update the range if a smaller range is found
        if (currentMax - currentMin < rangeEnd - rangeStart) {
            rangeStart = currentMin;
            rangeEnd = currentMax;
        }

        // Add the next element from the current list to the heap
        int nextElementIndex = current.elementIndex + 1;
        if (nextElementIndex < nums[current.listIndex].size()) {
            int nextValue = nums[current.listIndex][nextElementIndex];
            minHeap.push(Node(nextValue, current.listIndex, nextElementIndex));
            currentMax = max(currentMax, nextValue);
        } else {
            break; // One of the lists is exhausted
        }
    }

    return rangeEnd - rangeStart + 1; // Length of the smallest range
}


int main() {
    return 0;
}