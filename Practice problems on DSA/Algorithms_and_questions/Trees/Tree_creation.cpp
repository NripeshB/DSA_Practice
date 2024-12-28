#include <iostream>
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

int main() {
    node*A;
    builder(A);
    return 0;
}