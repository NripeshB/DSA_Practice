#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;
//the following code gives the shortest path in dire ted
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


//here we are just picking the first mapped element in a graph and 
//saving its connected notes in the queue all the while popping it before going into the for loop
//alongside saving the data for the already visited nodes to prevent cycling

vector<int> Shortest_path(int start,int end, graphs &adj) {
    vector<int> ans;
    queue<int> q; // Queue to store nodes for BFS
    unordered_map<int, bool> visited; // Keep track of visited nodes
    unordered_map<int, int> parent; // Keep track of visited nodes

   
        int initial = start; // this loop keeps the disjoint graphs in check

    // Start BFS from node 0 (or any node present in the graph)
    //here we are assuming that the graph's starting element is 0
    parent[initial] = -1;
    q.push(initial);
    visited[initial] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // Process all neighbors of the current node
        for (int neighbor : adj.adj[node]) {
            if (!visited[neighbor]) {
                parent[neighbor] = node;
                q.push(neighbor);
                visited[neighbor] = true; // Mark as visited
            }
        }
    }
    stack<int> s;
    int search = end ;
    while(search != start){
        s.push(search);
        search = parent[search];
    }
    s.push(search);

    vector<int> realans;
    while(!s.empty()){
        realans.push_back(s.top());
        s.pop();
    }
    

    return realans;
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
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }


    return 0;
}
