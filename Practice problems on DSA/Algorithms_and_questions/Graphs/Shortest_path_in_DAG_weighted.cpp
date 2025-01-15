#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

// DFS Helper to compute Topological Sort
void dfsHelper(unordered_map<int, vector<pair<int, int>>>& adj, vector<bool>& visited, int node, stack<int>& S) {
    visited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor.first]) {
            dfsHelper(adj, visited, neighbor.first, S);
        }
    }

    S.push(node); // Push the node to the stack after all its neighbors are visited
}

// Function to perform Topological Sort
vector<int> topologicalSort(int n, unordered_map<int, vector<pair<int, int>>>& adj) {
    vector<int> topoOrder;
    vector<bool> visited(n, false);
    stack<int> S;

    // Perform DFS for all nodes to handle disconnected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsHelper(adj, visited, i, S);
        }
    }

    // Retrieve topological order from stack
    while (!S.empty()) {
        topoOrder.push_back(S.top());
        S.pop();
    }

    return topoOrder;
}

// Function to compute Shortest Path in a Weighted DAG
void shortestPathDAG(int n, unordered_map<int, vector<pair<int, int>>>& adj, int source) {
    vector<int> topoOrder = topologicalSort(n, adj);
    vector<int> distance(n, INT_MAX);

    // Initialize distance to source as 0
    distance[source] = 0;

    // Process nodes in topological order
    for (int node : topoOrder) {
        if (distance[node] != INT_MAX) {
            for (auto neighbor : adj[node]) {
                int dest = neighbor.first;
                int weight = neighbor.second;

                if (distance[node] + weight < distance[dest]) {
                    distance[dest] = distance[node] + weight;
                }
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX) {
            cout << "Distance from " << source << " to " << i << ": Unreachable" << endl;
        } else {
            cout << "Distance from " << source << " to " << i << ": " << distance[i] << endl;
        }
    }
}

int main() {
    unordered_map<int, vector<pair<int, int>>> adj;

    // Input the graph
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 2});
    adj[0].push_back({3, 2});
    adj[0].push_back({4, 7});
    adj[2].push_back({3, 3});
    adj[3].push_back({1, 2});
    adj[4].push_back({1, 6});
    adj[4].push_back({5, -3});
    adj[5].push_back({1, -2});

    int n = 6; // Number of nodes
    int source = 0; // Source node

    shortestPathDAG(n, adj, source);

    return 0;
}
