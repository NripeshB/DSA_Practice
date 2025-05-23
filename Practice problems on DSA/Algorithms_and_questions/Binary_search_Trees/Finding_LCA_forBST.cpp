//https://www.naukri.com/code360/problems/lca-in-a-bst_981280?leftPanelTab=0&leftPanelTabValue=SUBMISSION
#include <iostream>
using namespace std;


    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };


//using the logic that LCA would lie in between both the values or would be one of the values
//for a binary search tree.

    TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    if(root == NULL){
        return NULL;
    }

    if(root->data< P->data && root->data < Q->data){
        return LCAinaBST(root->right, P, Q);
    }
    if(root->data > P->data && root->data > Q->data){
        return LCAinaBST(root->left, P, Q);
    }
    return root;
}
    

int main() {
    return 0;
}