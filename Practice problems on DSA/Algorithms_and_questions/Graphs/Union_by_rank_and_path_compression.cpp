#include <iostream>
using namespace std;

//this function finds out the shortest length between two nodes in a undirected unweighted graphs
class DisjointSet {
public:
   vector<int> parent;
   vector<int> rank;
   DisjointSet(int n){
    parent.resize(n+1);
    //resiing the rank vector to a size of n+1 and initialising every index with a value of 0
    rank.resize(n+1, 0);
   }


int find(int node){
    if (node == parent[node]){
        return node;
    }

    parent[node] = find(parent[node]);
    return parent[node];
}

void unionJoint(int u, int v){
    if(rank[u] == rank[v]){
        int p = find(u);
        rank[u]++;
        parent[v] = p;
    }

    else if(rank [u]> rank[v]){
       int p = find(u);
       parent[v] = p;

    }

    else{
        int p = find(v);
        parent[u] = p;
    }
}

};





int main() {


for (int i = 0; i < 8; i++)
{
    cout<< i <<endl;
}


    DisjointSet DS = DisjointSet(5);
    for (int i = 1; i <= 5; i++)
    {
        DS.parent[i] = i;
    }

    DS.unionJoint(1,2);
    DS.unionJoint(1,5);
    DS.unionJoint(3,4);
    DS.unionJoint(1,3);
    


    return 0;
}