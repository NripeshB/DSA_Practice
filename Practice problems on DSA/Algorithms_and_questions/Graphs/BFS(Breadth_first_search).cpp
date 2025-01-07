#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;
//The helper function is a recursive block which handles the visited elements along with developing answer

void dfsHelper( unordered_map<int, list<int>> &adj,vector<int>& ans,  unordered_map<int, bool>&visited, int n){
    if(visited[n] == true){
        return;
    }
    visited[n] = true;
    ans.push_back(n);
        for(auto j : adj[n]){
            dfsHelper(adj, ans,visited ,j);
        }
}

vector<int> dfsTraversal(int n, unordered_map<int, list<int>> &adj) {
    vector<int> ans;
    unordered_map<int, bool> visited; // Keep track of visited nodes

    if (adj.empty()) return ans; // Handle edge case: empty graph

    for(auto&i: adj){
        int initial = i.first; // this loop keeps the disjoint graphs in check
        //this calls in the recursive block for the first element in a set
        if (!visited[initial]) {
            dfsHelper(adj, ans, visited, initial);
        }
        }
    return ans;
}


int main() {
    return 0;
}