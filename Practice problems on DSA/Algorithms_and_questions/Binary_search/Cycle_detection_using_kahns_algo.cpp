#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;


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

// Kahn's algorithm or topological sort using BFS

vector<int> Topological_Sort(graphs&graph) {
    vector<int> ans;
    queue<int> q; // Queue to store nodes for BFS
    unordered_map<int, int> indegrees; // Keep track of indegrees
    
  


    // Initialize indegree for all nodes
    for (auto &i : graph.adj) {
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
        int node = q.front();
        q.pop();
        ans.push_back(node);
        

        // Decrease indegree for neighbors
        for (int neighbor : graph.adj[node]) {
            indegrees[neighbor]--;
            if (indegrees[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    //This is the condition which checks the cycle in kahns algo
    //the loop would never become less than 1 hence it wont be added to the queue
    //thus at the end the topological sort have less no. of nodes than 
    //the total amount in the graph
    if(ans.size() != graph.adj.size()){
        cout<<"The graph contains a cycle!!"<<endl;
    }
    else{
        cout<<"The graph is acyclic."<<endl;
    }
    return ans;
}

int main() {
    graphs adj;

    // Example graph
    adj.add_edge(0, 1, true);
    adj.add_edge(1, 2, true);
    adj.add_edge(2, 3, true);
    adj.add_edge(3, 4, true);
    adj.add_edge(4, 1, true);
    adj.add_edge(4, 5, true);

    // Perform Topological Sort
    vector<int> result = Topological_Sort(adj);

    // Print the result
    
        cout << "Topological Sort: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;

    return 0;
}
