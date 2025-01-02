#include <iostream>
using namespace std;
//It is called a binary search tree because the time complexity of inserting one node into the BST is  O(logN) where N is the 
//total lenght of all the nodes connection

class Node{
    public:

    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }


};

Node* BST(Node* root, int d){
    if (root == NULL)
    {
        root = new Node(d);
        return root;

    }

    if (d <= root->data)
    {
        root->left = BST(root->left, d);
    }
    else if(d > root->data){
        root->right = BST(root->right, d);
    }
    
    return root;
    
    
}


void TakeInput(Node*& root){
    int d;
    cin>>d;
    while( d!= -1){
        root = BST(root, d);
        cin>>d;
    }
}

//Implementation of Level Order Traversal.
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*temp = q.front();
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


//Inorder traversal. Follows the LNR traversal
//Inorder of BST is in increasing order
void Inorder(Node*root){
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
void Preorder(Node*root){
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
void Postorder(Node*root){
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
    Node* root = NULL;
    cout<<"Enter the data for the root Node"<<endl;
    TakeInput(root);

    cout<<endl<<"level order traversal output: "<<endl;
    levelOrderTraversal(root);
    cout<<endl<<"Inorder output: "<<endl;

    Inorder(root);
    cout<<endl<<"preorder output: "<<endl;

    Preorder(root);
    cout<<endl<<"postorder output: "<<endl;

    Postorder(root);


    return 0;
}