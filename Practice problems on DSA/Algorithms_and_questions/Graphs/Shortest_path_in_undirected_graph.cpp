#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


//this function finds out the shortest length between two nodes in a undirected unweighted graphs
class graphs {
public:
    unordered_map<int, vector<int> > adj;

    void add_edge(int u, int v, bool is_directed) {
        adj[u].push_back(v);
        if (!is_directed) {
            adj[v].push_back(u);
        }
    }
};

vector<int> Shortest_path(int start, int end, graphs &graph) {
    queue<int> q; // Queue to store nodes for BFS
    unordered_map<int, bool> visited; // Keep track of visited nodes
    unordered_map<int, int> parent; // Map to reconstruct the path

    // Initialize BFS
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    // Perform BFS
    bool found = false; // Flag to indicate when the target is found
    while (!q.empty() && !found) {
        int node = q.front();
        q.pop();

        // Process neighbors
        for (size_t i = 0; i < graph.adj[node].size(); ++i) {
            int neighbor = graph.adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);

                // Stop BFS early if we reach the target node
                if (neighbor == end) {
                    found = true;
                    break; // Exit the loop processing neighbors
                }
            }
        }
    }

    // Reconstruct the shortest path from `end` to `start`
    if (!visited[end]) {
        return vector<int>(); // No path exists; so returning an empty vector
    }

    vector<int> path;
    for (int at = end; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    //reversing using an algorithm, you can also do this by saving it in a stack and then popping it out
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // Create a directed graph
    graphs adj;
    adj.add_edge(0, 1, true);
    adj.add_edge(1, 2, true);
    adj.add_edge(2, 3, true);
    adj.add_edge(3, 4, true);
    adj.add_edge(4, 6, true);
    adj.add_edge(4, 5, true);

    int start = 0, end = 4;

    // Find the shortest path
    vector<int> result = Shortest_path(start, end, adj);

    if (!result.empty()) {
        cout << "Shortest path: ";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}