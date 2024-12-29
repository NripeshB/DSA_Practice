//https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
#include <iostream>
using namespace std;
//the following is for left but for right view the right fucntion would be called first 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

// Should return  right view of tree
class Solution
{
    public:
    void Left(Node* root, vector<int>&ans,int level){
      if(root == NULL){
          return ;
      }
      
      if(level == ans.size() ){
          ans.push_back(root->data);
      }
      Left(root->left,ans, level+1);
      Left(root->right, ans, level+1);
    
      
  }
    //Function to return list containing elements of right view of binary tree.
    vector<int> leftView(Node *root)
    {
       vector<int>ans;
        Left(root, ans, 0);
        return ans;
    }
};


int main() {
    return 0;
}