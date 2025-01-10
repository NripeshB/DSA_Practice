
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <set>
using namespace std;
// applicable in directed/undirected graphs, which can be cyclic or acyclic and non-negative weighted.




//the pair in the list has data as Pair<node, weight>


class compare{
    public:
    bool operator()(const pair<int, int>&p1,const pair<int, int>&p2){
        return p1.second < p2.second;
    }
};

void Shortest_dist(  set<pair<int, int>, compare >&Set,vector<int>&distance, unordered_map<int, vector<pair<int, int> > > adj){
    while(!Set.empty()){
        pair<int, int> p = *Set.begin(); 
        Set.erase(Set.begin());

    for( auto i : adj[p.first]){
          if(distance[i.first]> i.second+ p.second ){
            distance[i.first] = i.second+ p.second ;
            Set.insert(pair<int, int>(i.first, i.second));

          }
    }
    }
    

}





int main() {

     unordered_map<int, vector<pair<int, int> > > adj;
     set<pair<int, int>, compare > Set;

    adj[0].push_back(make_pair(1, 1));
    adj[0].push_back(make_pair(2, 2));
    adj[0].push_back(make_pair(3, 2));
    adj[0].push_back(make_pair(4, 7));
    adj[1] = vector<pair<int, int> >();  // No edges for node 1
    adj[2].push_back(make_pair(3, 3));
    adj[3].push_back(make_pair(1, 2));
    adj[4].push_back(make_pair(1, 6));
    adj[4].push_back(make_pair(5, 1));
    adj[5].push_back(make_pair(1, 2));

     int n = 6;


    
    //initialising all the distances as infinite
    vector<int> distance(n, INT_MAX);
    
    //lets take the source node as 0
    int source = 0;


    //marking the distance to itself as 0
    distance[source] = 0;

    pair<int, int> p = make_pair(source, 0);
    Set.insert(p);

    Shortest_dist( Set ,distance, adj);

    for (int i = 0; i < n; i++)
    {
        cout<< "Distance of 0 to "<< i<<" is: "<< distance[i]<<endl;
    }
    

   
    return 0;
}

