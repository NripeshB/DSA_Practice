#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;


    //defining the node structure
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;

    }

};
node* builder(node*root){
    cout<<"enter the data: "<< endl;
    int data;
    cin>>data;
    //forming a node named root
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    
    cout<<"enter the left node data for "<<data<<endl;
    root->left = builder(root->left);
    cout<<"enter the rigth node data for "<<data<<endl;
    root->right = builder(root->right);
    return root;


}


//Implementation of Level Order Traversal.
void levelOrderTrarsal(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node*temp = q.front();
        cout<<temp->data<< " ";
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }

        

        
    }
    

}

int main() {
    node*A = NULL;
    A = builder(A);
    /* 5
    6   7 
    8  9  13  22  
    11  -1  -1  10  -1  -1  6  7  
    ----------1    */
    levelOrderTrarsal(A);
    return 0;
}