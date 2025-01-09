#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;
//The helper function is a recursive block which handles the visited elements along with developing answer
//Function to check for a cycle in one connected component using DFS
bool isCycleDFS(int start, unordered_map<int, vector<int>> &Adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &DFSVisited) {
    visited[start] = true;
    //marking as visited for the recursive call
    DFSVisited[start] = true;

    for (auto neighbor : Adj[start]) {
        if (!visited[neighbor]) {
            // Recur for unvisited neighbors
            if (isCycleDFS(neighbor, Adj, visited,DFSVisited)) {
                return true;
            }
            //for directed graphs the only condition that if its visited both in normal and dfs one 
        } else if ( DFSVisited[neighbor]) {
            // If the neighbor is visited and not the parent, cycle detected
            return true;
        }
    }
    //backtracking
    DFSVisited[start] = false;
    return false;
}


// Function to detect cycles in the entire graph
void DetectCycle(unordered_map<int, vector<int>> &Adj) {
    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSVisited;

    for (auto &entry : Adj) {
        int node = entry.first;
        //If the first node is not visited then the entire subgraph is not visited as the iscycle 
        //goes through the entire connected graph.
        

        if (!visited[node]) {
            if (isCycleDFS(node, Adj, visited, DFSVisited)) {
                cout << "A cycle is detected." << endl;
                return;
            }
        }
    }
    cout << "No cycle exists." << endl;
}

int main() {

    return 0;
}
