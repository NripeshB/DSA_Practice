//https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <iostream>
using namespace std;


// This code uses min heap which inserts the values from the three arrays and thus forms a sorted array
//however the apporach is uncommon as it uses a comparator class creation.
//it first adds one element form each array into the heap, then going through the heap, it iterates over all the 
//elements in the first input sub array( first row of the 2d array) and once the row is empty, it moves onto the next;
class Node {
public:
    int data; // Value of the element
    int i;    // Index of the array from which the element is taken
    int j;    // Index of the element in the array

    Node(int value, int arrayIndex, int elementIndex) {
        data = value;
        i = arrayIndex;
        j = elementIndex;
    }
};

// Comparator class for the priority queue
class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // Min-heap based on the value of data
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    priority_queue<Node*, vector<Node*>, compare> Minheap;
    vector<int> result;

    // Step 1: Insert the first element of each array into the heap
    for (int i = 0; i < k; i++) {
        if (!kArrays[i].empty()) {
            Minheap.push(new Node(kArrays[i][0], i, 0));
        }
    }

    // Step 2: Process the min-heap
    while (!Minheap.empty()) {
        // Extract the smallest element
        Node* temp = Minheap.top();
        Minheap.pop();

        // Add the smallest element to the result
        result.push_back(temp->data);

        // Push the next element from the same array into the heap
        int nextIndex = temp->j + 1;
        if (nextIndex < kArrays[temp->i].size()) {
            Minheap.push(new Node(kArrays[temp->i][nextIndex], temp->i, nextIndex));
        }

        delete temp; // Free memory allocated for the node
    }

    return result;
}

int main() {
    return 0;
}