//https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0&leftPanelTabValue=SUBMISSION
#include <iostream>
using namespace std;
// you can write the same code using morris traversal for O(1) SC
// you can also save the answer from inorder traversal in a vector and iterate to the kth element
    class BinaryTreeNode 
    {
    public : 
        int data;
        BinaryTreeNode  *left;
        BinaryTreeNode  *right;

        BinaryTreeNode (int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


int solve(BinaryTreeNode* root, int k, int& i){
    if( root== NULL){
        return -1;
    }

    int L = solve(root->left, k, i);
    if(L != -1){
        return L;
    }

    i++;
    if(i == k){
        return root->data;
    }
    
    return  solve( root->right, k, i);

    
}
int kthSmallest(BinaryTreeNode* root, int k) {
    // Write your code here.
    int i =0;
    int ans = solve(root, k, i);
    return ans;
}

int main() {
    return 0;
}