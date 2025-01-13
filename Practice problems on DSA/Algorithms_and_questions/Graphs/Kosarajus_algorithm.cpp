#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

using namespace std;
//This algorithm returns all the strongly connected nodes in a graph and returns it.



// Helper function for DFS to fill the stack or TOPOLOGICAL SORT
void dfsHelper(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node, stack<int> &S) {
    visited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(adj, visited, neighbor, S);
        }
    }

    S.push(node); // Add node to stack after processing all its neighbors
}

// Function to reverse the graph
unordered_map<int, list<int>> reverseGraph(unordered_map<int, list<int>> &adj) {
    unordered_map<int, list<int>> reversed;

    for (auto &entry : adj) {
        int node = entry.first;
        for (auto neighbor : entry.second) {
            reversed[neighbor].push_back(node); // Reverse the direction of the edge
        }
    }

    return reversed;
}

// Helper function for DFS traversal to find SCCs
void dfsSCC(unordered_map<int, list<int>> &reversedAdj, unordered_map<int, bool> &visited, int node, vector<int> &component) {
    visited[node] = true;
    component.push_back(node);

    for (auto neighbor : reversedAdj[node]) {
        if (!visited[neighbor]) {
            dfsSCC(reversedAdj, visited, neighbor, component);
        }
    }
}

// Kosaraju's Algorithm to find strongly connected components
vector<vector<int>> kosaraju(int n, unordered_map<int, list<int>> &adj) {
    stack<int> S;
    unordered_map<int, bool> visited;

    // Step 1: Perform topological sort using DFS
    for (auto &entry : adj) {
        int node = entry.first;
        if (!visited[node]) {
            dfsHelper(adj, visited, node, S);
        }
    }

    // Step 2: Reverse the graph
    unordered_map<int, list<int>> reversedAdj = reverseGraph(adj);

    // Step 3: Process nodes in topological order from the stack
    vector<vector<int>> stronglyConnectedComponents;
    visited.clear(); // Reset the visited map

    while (!S.empty()) {
        int node = S.top();
        S.pop();

        if (!visited[node]) {
            vector<int> component;
            dfsSCC(reversedAdj, visited, node, component);
            stronglyConnectedComponents.push_back(component);
        }
    }

    return stronglyConnectedComponents;
}

int main() {
    // Example graph
    unordered_map<int, list<int>> adj;

    // Add edges to the graph
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(6);
    adj[6].push_back(4);

    int n = 6; // Number of nodes

    // Find SCCs
    vector<vector<int>> sccs = kosaraju(n, adj);

    // Print SCCs
    cout << "Strongly Connected Components:" << endl;
    for (auto &component : sccs) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
