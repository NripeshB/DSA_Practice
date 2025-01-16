#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i; // Each node is its own parent initially
        }
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]); // Path compression
        }
        return parent[node];
    }

    void unionByRank(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Comparator for the priority queue
struct compare {
    bool operator()(const vector<int>& edge1, const vector<int>& edge2) {
        return edge1[2] > edge2[2]; // Min-heap based on weight (3rd element)
    }
};

int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    // Min-heap for edges
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    //we put all the edges in
    for (auto& edge : edges) {
        pq.push(edge);
    }

    DisjointSet ds(n);
    int mstWeight = 0;
    int edgeCount = 0;

    while (!pq.empty() && edgeCount < n - 1) {
        vector<int> edge = pq.top();
        pq.pop();

        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        // Check if including this edge creates a cycle
        if (ds.find(u) != ds.find(v)) {
            ds.unionByRank(u, v);
            mstWeight += weight;
            edgeCount++;
        }
    }

    return mstWeight;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 3},
        {3, 4, 1},
        {4, 5, 5},
        {2, 5, 4},
        {3, 5, 6}
    };

    int mstWeight = minimumSpanningTree(edges, n);
    cout << "Minimum Spanning Tree weight: " << mstWeight << endl;
    return 0;
}
