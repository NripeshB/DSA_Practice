//https://www.geeksforgeeks.org/problems/sum-tree/1
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

// Should return true if tree is Sum Tree, else false
class Solution {
    pair<bool, int> helper(Node* root){
        if(root == NULL ){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool, int>leftsum = helper(root->left);
        pair<bool, int>rightsum = helper(root->right);
        
        bool leftbool = leftsum.first;
        bool rightbool = rightsum.first;
        bool val = root->data == leftsum.second + rightsum.second;
        
        pair<bool, int> ans;
        if(leftbool && rightbool && val){
            ans.first = true;
            ans.second = 2*(root->data);
        }
        else{
            ans.first = false;
        }
        
        return ans;
    }
  public:
    bool isSumTree(Node* root) {
        return (helper(root).first);
    }
};

int main() {
    return 0;
}