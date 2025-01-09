  if(ans.size() != graph.adj.size()){
        cout<<"The graph contains a cycle!!"<<endl;
    }
    else{
        cout<<"The graph is acyclic."<<endl;
    }
    return ans;