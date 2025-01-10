
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
//Shortest path in directed, weighted, acyclic graphs

//Topo sort only works on directed acyclic graphs (DAG)
//The helper function is a recursive block which handles the visited elements along with developing answer

//the pair in the list has data as Pair<node, weight>
void dfsHelper( unordered_map<int, vector<pair<int, int> > > &adj, unordered_map<int, bool>&visited, int n, stack<int>&S){
   visited[n] = true; // Mark the node as visited

    // Recur for all adjacent nodes
    for (auto neighbor : adj[n]) {
        if (!visited[neighbor.first]) {
            dfsHelper(adj, visited, neighbor.first, S);
        }
    }

    // Push the current node to the stack after visiting all its neighbors
    S.push(n);
}

vector<int> topologicalSort(int n, unordered_map<int, vector<pair<int, int> > > &adj) {
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

void Shortest_dist( int iter,vector<int>&distance,vector<int> ans, int src,int curr, unordered_map<int, vector<pair<int, int> > > adj){
    if(iter == ans.size()){
        return ; 
    }
    for( auto i : adj[curr]){
        if (curr == src){
            if(distance[i.first] == INT_MAX){
            distance[i.first] = i.second;
            }
        }
        else{if(distance[curr]!= INT_MAX){
            if(distance[curr]+ i.second < distance[i.first]  ){
                distance[i.first] = distance[curr]+ i.second ;
            }
        }
        }   
    }
    curr = ans[iter++];
    Shortest_dist( iter,distance, ans, src, curr, adj );
}




int main() {

     unordered_map<int, vector<pair<int, int> > > adj;

    adj[0].push_back(make_pair(1, 1));
    adj[0].push_back(make_pair(2, 2));
    adj[0].push_back(make_pair(3, 2));
    adj[0].push_back(make_pair(4, 7));
    adj[1] = vector<pair<int, int> >();  // No edges for node 1
    adj[2].push_back(make_pair(3, 3));
    adj[3].push_back(make_pair(1, 2));
    adj[4].push_back(make_pair(1, 6));
    adj[4].push_back(make_pair(5, -3));
    adj[5].push_back(make_pair(1, -2));

     int n = 6;

    vector<int> ans = topologicalSort(n, adj);

    
    //initialising all the distances as infinite
    vector<int> distance(n, INT_MAX);
    
    //lets take the source node as 0
    int source = 0;

   

    //marking the distance to itself as 0
    distance[source] = 0;

    Shortest_dist(0,distance, ans, source,source, adj);

    for (int i = 0; i < n; i++)
    {
        cout<< "Distance of 0 to "<< i<<" is: "<< distance[i]<<endl;
    }
    

   
    return 0;
}

