#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class graphs {
public:
    unordered_map<T, vector<T> > adj;

    void add_edge(T u, T v, bool is_directed) {
        adj[u].push_back(v);
        if (!is_directed) {
            adj[v].push_back(u);
        }
    }
};

// Kahn's algorithm or topological sort using BFS
template <typename T>
vector<T> Topological_Sort(graphs<T> &graph) {
    vector<T> ans;
    queue<T> q; // Queue to store nodes for BFS
    unordered_map<T, int> indegrees; // Keep track of indegrees

    // Initialize indegree for all nodes
    for (auto &i : graph.adj) {
        indegrees[i.first] = 0; // Ensure all nodes exist in indegrees map
        for (auto &neighbor : i.second) {
            indegrees[neighbor]++;
        }
    }

    // Add all nodes with indegree 0 to the queue
    for (auto &i : graph.adj) {
        if (indegrees[i.first] == 0) {
            q.push(i.first);
        }
    }

    // Start BFS and topological sorting
    while (!q.empty()) {
        T node = q.front();
        q.pop();
        ans.push_back(node);

        // Decrease indegree for neighbors
        for (T neighbor : graph.adj[node]) {
            indegrees[neighbor]--;
            if (indegrees[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return ans;
}

int main() {
    graphs<int> adj;

    // Example graph
    adj.add_edge(1, 2, true);
    adj.add_edge(2, 3, true);
    adj.add_edge(3, 4, true);
    adj.add_edge(4, 5, true);
    adj.add_edge(5, 6, true);

    // Perform Topological Sort
    vector<int> result = Topological_Sort(adj);

    // Print the result
    if (!result.empty()) {
        cout << "Topological Sort: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "The graph contains a cycle or is empty." << endl;
    }

    return 0;
}
