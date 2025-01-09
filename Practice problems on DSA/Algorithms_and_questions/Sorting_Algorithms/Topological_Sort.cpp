#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

//Topo sort only works on directed acyclic graphs (DAG)
using namespace std;
//The helper function is a recursive block which handles the visited elements along with developing answer

void dfsHelper( unordered_map<int, list<int>> &adj, unordered_map<int, bool>&visited, int n, stack<int>&S){
   visited[n] = true; // Mark the node as visited

    // Recur for all adjacent nodes
    for (auto neighbor : adj[n]) {
        if (!visited[neighbor]) {
            dfsHelper(adj, visited, neighbor, S);
        }
    }

    // Push the current node to the stack after visiting all its neighbors
    S.push(n);
}

vector<int> topologicalSort(int n, unordered_map<int, list<int>> &adj) {
    vector<int> ans;
    unordered_map<int, bool> visited; // Keep track of visited nodes
    stack<int> S;
    if (adj.empty()) return ans; // Handle edge case: empty graph

    for(auto&i: adj){
        int initial = i.first; // this loop keeps the disjoint graphs in check
        //this calls in the recursive block for the first element in a set
        if (!visited[initial]) {
            dfsHelper(adj, visited, initial, S);
        }
        }

        while (!S.empty())
        {
            ans.push_back(S.top());
            S.pop();
        }
        


    return ans;
}


int main() {
    return 0;
}