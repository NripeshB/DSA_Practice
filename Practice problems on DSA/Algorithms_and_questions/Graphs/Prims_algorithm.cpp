#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Function to find the vertex with the minimum key value
int minKey(vector<int> &key, vector<bool> &mstSet, int V) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the MST
void printMST(vector<int> &parent, vector<vector<int>> &graph, int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

// Function to implement Prim's Algorithm
void primMST(vector<vector<int>> &graph, int V) {
    vector<int> parent(V);  // Stores the MST
    vector<int> key(V, INT_MAX);  // Minimum weight edge to a vertex
    vector<bool> mstSet(V, false);  // Track vertices included in MST

    key[0] = 0;  // Start with the first vertex
    parent[0] = -1;  // First vertex has no parent

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph, V);

    return 0;
}
