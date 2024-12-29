//https://geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left, * right;
}; 

class Solution {
    
    void traverseLeft(Node*root, vector<int>&ans){
        if(root== NULL||(root->left == NULL && root->right == NULL)){
            return;
            
        }
        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left, ans);
        }
        else {
            traverseLeft(root->right, ans);
        }
        
    }
    
    void traverseLeaf(Node*root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL&& root->right == NULL){
            ans.push_back(root->data);
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
    
    void traverseRight(Node*root, vector<int>&temp){
        if(root== NULL||(root->left == NULL && root->right == NULL)){
            return;
            
        }
        
        temp.push_back(root->data);
        if(root->right){
            traverseRight(root->right, temp);
        }
        else {
            traverseRight(root->left, temp);
        }
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        vector<int> temp;
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->data);
        traverseLeft(root->left, ans);
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right , ans);
        
        traverseRight(root->right, temp);
        
        for(int i = temp.size()-1;i>=0;i-- ){
            ans.push_back(temp[i]);
        }
        return ans;
    }
    
};


int main() {
    return 0;
}