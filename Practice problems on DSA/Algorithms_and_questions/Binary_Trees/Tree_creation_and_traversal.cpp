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
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();


        if (temp == NULL)
        {
            cout<<endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
            
                }

        else{ 
            cout<<temp->data<< " ";
            
            if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
            }
        }      
    }
}

//Implementation of Level Order Traversal.
void levelOrderCreator(node*& root){
    queue<node*> q;
    cout<<"enter data: "<<endl;
    int data;
    cin>>data;
    root =new node( data);
    q.push(root);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();

        cout<<"enter left data: "<<temp->data<<endl;
        int left_data;
        cin>>left_data;
            if (left_data!=-1)
            {
                temp->left = new node(left_data);
                q.push(temp->left);
            }
            
        cout<<"enter right data: "<<temp->data <<endl;
        int right_data;
        cin>>right_data;
            if (right_data!=-1)
            {
                temp->right = new node(right_data);
                q.push(temp->right);
            }
        }      
    }

//Inorder traversal. Follows the LNR traversal
void Inorder(node*root){
    if (root == NULL)
    {
        return ;
    }
//left
    Inorder(root->left);
//printing node
    cout<<root->data<< " ";
//right
    Inorder(root->right);

    }


//Preorder traversal. Follows the NLR traversal
void Preorder(node*root){
    if (root == NULL)
    {
        return ;
    }
//printing node
    cout<<root->data<< " ";
//left
    Preorder(root->left);
//right
    Preorder(root->right);

    }
    



//Postorder traversal. Follows the LRN traversal
void Postorder(node*root){
    if (root == NULL)
    {
        return ;
    }

//left
    Postorder(root->left);
//right
    Postorder(root->right);
//printing node
    cout<<root->data<< " ";

    }
    

int main() {
    node*A = NULL;
    /*A = builder(A);
    /* 5 6 8 11 -1 -1 -1 9 -1 10 -1 -1 7 13 -1 -1 22 6 -1 -1 7 -1 -1 
    ----------1    
    levelOrderTrarsal(A);
    Inorder(A);
    Preorder(A);
    Postorder(A);*/
    levelOrderCreator(A); 
    levelOrderTraversal(A);
    return 0;
}