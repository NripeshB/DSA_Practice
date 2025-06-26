#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <set>
using namespace std;

// applicable in directed/undirected graphs, which can be cyclic or acyclic and non-negative weighted.

// The comparator class used to define the behavior of the set for sorting pairs based on the weight.
class compare
{
public:
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.second < p2.second; // Min-heap based on the second value (weight)
    }
};

//

//// Function to calculate the shortest distances from the source node to all other nodes
void Shortest_dist(set<pair<int, int>, compare> &Set, vector<int> &distance, unordered_map<int, vector<pair<int, int>>> adj)
{
    while (!Set.empty())
    {
        pair<int, int> p = *Set.begin(); // Get the node with the smallest distance
        Set.erase(Set.begin());          // Remove it from the set

        // Iterate through all adjacent nodes of the current node
        for (auto i : adj[p.first])
        {
            // If the distance to node i is greater than the sum of current node's distance and edge weight
            if (distance[i.first] > i.second + p.second)
            {
                distance[i.first] = i.second + p.second;                // Update the distance
                Set.insert(pair<int, int>(i.first, distance[i.first])); // Insert the updated distance back into the set
            }
        }
    }
}

int main()
{
    unordered_map<int, vector<pair<int, int>>> adj; // Adjacency list to store graph
    set<pair<int, int>, compare> Set;               // Set to hold nodes and their distances (min-heap)

    // Constructing the graph
    adj[0].push_back(make_pair(1, 1)); // Edge from node 0 to 1 with weight 1
    adj[0].push_back(make_pair(2, 2)); // Edge from node 0 to 2 with weight 2
    adj[0].push_back(make_pair(3, 2)); // Edge from node 0 to 3 with weight 2
    adj[0].push_back(make_pair(4, 7)); // Edge from node 0 to 4 with weight 7

    adj[1] = vector<pair<int, int>>(); // No edges for node 1

    adj[2].push_back(make_pair(3, 3)); // Edge from node 2 to 3 with weight 3
    adj[3].push_back(make_pair(1, 2)); // Edge from node 3 to 1 with weight 2
    adj[4].push_back(make_pair(1, 6)); // Edge from node 4 to 1 with weight 6
    adj[4].push_back(make_pair(5, 1)); // Edge from node 4 to 5 with weight 1
    adj[5].push_back(make_pair(1, 2)); // Edge from node 5 to 1 with weight 2

    int n = 6; // Total number of nodes

    // Initializing all distances as infinite
    vector<int> distance(n, INT_MAX);

    // Taking the source node as 0
    int source = 0;

    // Marking the distance to itself as 0
    distance[source] = 0;

    pair<int, int> p = make_pair(source, 0);
    Set.insert(p); // Insert the source node into the set with distance 0

    // Calling the function to calculate shortest distances
    Shortest_dist(Set, distance, adj);

    // Printing the shortest distances from source node to all other nodes
    for (int i = 0; i < n; i++)
    {
        cout << "Distance of 0 to " << i << " is: " << distance[i] << endl;
    }

    return 0;
}
