#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

template <typename T>
class graphs{
    public:
    unordered_map<T, list<T> > adj;

    void add_edge(int u, int v, bool isdirected){

        adj[u].push_back(v);

        if(!isdirected){
        adj[v].push_back(u);
        }


    }

    void print_adj_list(){
        for( auto i : adj){
            cout<< i.first<<" =>";
            for(auto j : i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

};

int main() {

    graphs<int> A;
    A.add_edge(1,2, false);
    A.add_edge(1,5, false);
    A.add_edge(2,3, false);
    A.add_edge(2,4, false);
    A.add_edge(3,4, false);
    A.add_edge(4,5, false);

    A.print_adj_list();

    return 0;
}