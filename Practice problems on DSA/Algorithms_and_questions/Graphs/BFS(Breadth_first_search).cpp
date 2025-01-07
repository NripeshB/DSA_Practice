#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

vector<int> bfsTraversal(int n, unordered_map<int, list<int>> &adj) {
    vector<int> ans;
    queue<int> q; // Queue to store nodes for BFS
    unordered_map<int, bool> visited; // Keep track of visited nodes

    if (adj.empty()) return ans; // Handle edge case: empty graph

    // Start BFS from node 0 (or any node present in the graph)
    //here we are assuming that the graph's starting element is 0
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // Process all neighbors of the current node
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true; // Mark as visited
            }
        }
    }

    return ans;
}


int main() {
    return 0;
}