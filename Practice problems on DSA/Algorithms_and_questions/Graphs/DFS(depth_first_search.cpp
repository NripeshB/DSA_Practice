#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

//here we are just picking the first mapped element in a graph and 
//saving its connected notes in the queue all the while popping it before going into the for loop
//alongside saving the data for the already visited nodes to prevent cycling

void dfsHelper(int n, unordered_map<int, list<int>> &adj){

}
vector<int> dfsTraversal(int n, unordered_map<int, list<int>> &adj) {
    vector<int> ans;
    queue<int> q; // Queue to store nodes for BFS
    unordered_map<int, bool> visited; // Keep track of visited nodes

    if (adj.empty()) return ans; // Handle edge case: empty graph

    for(auto&i: adj){
        int initial = i.first; // this loop keeps the disjoint graphs in check

    // Start BFS from node 0 (or any node present in the graph)
    //here we are assuming that the graph's starting element is 0
    q.push(initial);
    visited[initial] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // Process all neighbors of the current node
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true; // Mark as visited
            }
        }
    }
    }

    

    return ans;
}


int main() {
    return 0;
}