#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>


using namespace std;

// Helper function for recursive DFS
void dfsHelper(unordered_map<int, list<int>>& adj, vector<int>& ans, unordered_map<int, bool>& visited, int node) {
    visited[node] = true; // Mark the node as visited
    ans.push_back(node);  // Add the current node to the result

    // Recur for all adjacent nodes
    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(adj, ans, visited, neighbor);
        }
    }
}

// DFS Traversal function
vector<int> dfsTraversal(int n, unordered_map<int, list<int>>& adj) {
    vector<int> ans;                 // Result vector to store traversal order
    unordered_map<int, bool> visited; // Keep track of visited nodes

    // Traverse all nodes (handle disjoint components or isolated nodes)
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsHelper(adj, ans, visited, i);
        }
    }
    return ans;
}

int main() {
    // Example graph as adjacency list
    unordered_map<int, list<int>> adj;
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {};
    adj[3] = {4};
    adj[4] = {};

    int numNodes = 5;

    // Perform DFS traversal
    vector<int> result = dfsTraversal(numNodes, adj);

    // Print the result
    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
