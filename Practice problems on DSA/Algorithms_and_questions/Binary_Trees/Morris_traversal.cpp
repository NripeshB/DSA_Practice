
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Function for inorder traversal 
// using Morris Traversal
vector<int> InOrder_MorrisTraversal(Node* root) {
    Node* current = root;
    vector<int> ans ;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            ans.push_back(current->data);
            current = current->right;
        }
        else{
            Node*prev = current->left;

            while (prev->right != NULL && prev->right != current)
            {
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = current;
                current = current->left;
            }

            else if(prev->right == current){
                prev->right = NULL;
                ans.push_back(current->data);
                current = current->right;

            }
            
        }
        
    }
    return ans;
    
}


int main() {
  
    // Representation of input binary tree:
    //           1
    //           
    //         2   3
    //               
    //           4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = InOrder_MorrisTraversal(root);
  
     for (int data : result) {
        cout << data << " ";
    }
    
    return 0;
}