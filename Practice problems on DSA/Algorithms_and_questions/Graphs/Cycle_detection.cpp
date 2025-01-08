#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, vector<T>> adj;

    void add_edge(int u, int v, bool is_directed) {
        adj[u].push_back(v);
        if (!is_directed) {
            adj[v].push_back(u);
        }
    }
};

//Function to check for a cycle in one connected component using DFS
bool isCycleDFS(int start, int parent, unordered_map<int, vector<int>> &Adj, unordered_map<int, bool> &visited) {
    visited[start] = true;

    for (auto neighbor : Adj[start]) {
        if (!visited[neighbor]) {
            // Recur for unvisited neighbors
            if (isCycleDFS(neighbor, start, Adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            // If the neighbor is visited and not the parent, cycle detected
            return true;
        }
    }
    return false;
}

// Function to check for a cycle in one connected component using BFS
bool isCycleBFS(int start, unordered_map<int, vector<int>> &Adj, unordered_map<int, bool> &visited) {
    queue<int> q;
    unordered_map<int, int> parent;

    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbor : Adj[node]) {
            if (visited[neighbor]) {
                // If the neighbor is not visited and the node is not the parent for the neighbor then it suggests there is a cycle
                if (parent[node] != neighbor) {
                    return true;
                }
            } else {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = node;
            }
        }
    }
    return false;
}

// Function to detect cycles in the entire graph
void DetectCycle(unordered_map<int, vector<int>> &Adj) {
    unordered_map<int, bool> visited;

    for (auto &entry : Adj) {
        int node = entry.first;
        //If the first node is not visited then the entire subgraph is not visited as the iscycle 
        //goes through the entire connected graph.
        if (!visited[node]) {
            if (isCycleBFS(node, Adj, visited)) {
                cout << "A cycle is detected." << endl;
                return;
            }
        }

        if (!visited[node]) {
            if (isCycleDFS(node,-1, Adj, visited)) {
                cout << "A cycle is detected." << endl;
                return;
            }
        }
    }
    cout << "No cycle exists." << endl;
}

int main() {
    Graph<int> A;

    // Example graph input
    A.add_edge(1, 2, false);
    A.add_edge(2, 3, false);
    A.add_edge(3, 4, false);
    A.add_edge(4, 1, false); // This creates a cycle

    DetectCycle(A.adj);

    return 0;
}
