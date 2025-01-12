#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

void dfsHelper(int node, int parent, vector<int>& disc, vector<int>& least, vector<bool>& visited, int& time, unordered_map<int, vector<int> >& adj, vector<pair<int, int> >& bridges) {
    visited[node] = true; // Mark the node as visited
    disc[node] = least[node] = ++time; // Set discovery and least time

    for (auto neighbor : adj[node]) {
        if (neighbor == parent) {
            continue; // Skip the edge to the parent
        }
        if (!visited[neighbor]) {
            // Recur for unvisited neighbor
            dfsHelper(neighbor, node, disc, least, visited, time, adj, bridges);

            //as all nodes have been traversed, so now all back edges have been incorporated
            //so, update the least value of the current node
            least[node] = min(least[node], least[neighbor]);


            // Check if the edge is a bridge
            if (least[neighbor] > disc[node]) {
                bridges.push_back({node, neighbor});
            }
        } else {
            //if the neighboring node is already visited then it is bound to be a back edge
            // Update the least value for a back edge
            least[node] = min(least[node], disc[neighbor]);
        }
    }
}

vector<pair<int, int> > FindBridges(int n, unordered_map<int, vector<int> >& adj) {
    vector<int> disc(n, -1);     // Discovery time of each node
    vector<int> least(n, -1);    // Lowest discovery time reachable
    vector<bool> visited(n, false); // Visited array
    vector<pair<int, int> > bridges; // Store the bridges
    int time = 0;                // Timer to track discovery times

    // Handle all components of the graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsHelper(i, -1, disc, least, visited, time, adj, bridges);
        }
    }

    return bridges;
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

    // Find all bridges in the graph
    vector<pair<int, int> > bridges = FindBridges(numNodes, adj);

    // Print the bridges
    cout << "Bridges in the graph:" << endl;
    for (auto bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << endl;
    }

    return 0;
}
