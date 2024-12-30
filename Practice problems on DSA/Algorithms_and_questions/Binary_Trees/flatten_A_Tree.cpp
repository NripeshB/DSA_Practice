//https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
#include <iostream>
using namespace std;

  struct Node {
     int data;
    Node *left;
     Node *right;
  };
 

class Solution
{
    public:
    void flatten(Node *root)
    {
        Node*current = root;
        
        while(current!= NULL){
            if(current->left == NULL){
                current = current->right;
            }
            
            else{
                Node* prev = current->left;
                
                while(prev->right != NULL ){
                    prev = prev->right;
                   }
                
                if(prev->right ==NULL){
                    prev->right = current ->right;
                    current->right = current->left;
                    current->left = NULL;
                   }
                    
            }
        }
    }
};

int main() {
    return 0;
}