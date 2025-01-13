#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

// Helper function for DFS
void dfsHelper(int node, int parent, vector<int>& disc, vector<int>& least, vector<bool>& visited, int& time, unordered_map<int, vector<int> >& adj, set<int>& articulationPoints) {
    visited[node] = true; // Mark the node as visited
    disc[node] = least[node] = ++time; // Set discovery and least time
    int childCount = 0; // Count of children in the DFS tree

    for (auto neighbor : adj[node]) {
        if (neighbor == parent) {
            continue; // Skip the edge to the parent
        }
        if (!visited[neighbor]) {
            // Recur for unvisited neighbor
            dfsHelper(neighbor, node, disc, least, visited, time, adj, articulationPoints);

            // Update the least value of the current node
            least[node] = min(least[node], least[neighbor]);

            // Check for articulation point
            if (least[neighbor] >= disc[node] && parent != -1) {
                articulationPoints.insert(node);
            }
            
            childCount++;
        } else {
            // For a back edge
            least[node] = min(least[node], disc[neighbor]);
        }
    }

    // Special case for root node
    if (parent == -1 && childCount > 1) {
        articulationPoints.insert(node);
    }
}

set<int> FindArticulationPoints(int n, unordered_map<int, vector<int> >& adj) {
    vector<int> disc(n, -1);     // Discovery time of each node
    vector<int> least(n, -1);    // Lowest discovery time reachable
    vector<bool> visited(n, false); // Visited array
    set<int> articulationPoints; // Store articulation points
    int time = 0;                // Timer to track discovery times

    // Handle all components of the graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsHelper(i, -1, disc, least, visited, time, adj, articulationPoints);
        }
    }

    return articulationPoints;
}

int main() {
    // Example graph as adjacency list
    unordered_map<int, vector<int> > adj;
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3};
    adj[3] = {1, 2, 4};
    adj[4] = {3};

    int numNodes = 5;

    // Find all articulation points in the graph
    set<int> articulationPoints = FindArticulationPoints(numNodes, adj);

    // Print the articulation points
    cout << "Articulation points in the graph:" << endl;
    for (auto point : articulationPoints) {
        cout << point << endl;
    }

    return 0;
}
