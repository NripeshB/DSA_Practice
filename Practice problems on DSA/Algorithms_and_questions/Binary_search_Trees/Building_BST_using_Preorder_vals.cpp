//https://www.naukri.com/code360/problems/preorder-traversal-to-bst_893111?leftPanelTab=0&leftPanelTabValue=SUBMISSION
#include <iostream>
using namespace std;


    class BinaryTreeNode {
       public : 
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
 
//You would have to pass minimum and maximum range for which the next num can lie in a subtree.
//for ex: at first from INT_MIN to INT_MAX, then for root->left range becomes INT_MIN to root->data.
//doing this recursively gives the ans. tip: we can do it without minimum val too.

BinaryTreeNode* solve(vector<int> &preorder, int mini, int maxi, int &i){
    if(i>=preorder.size()){
        return NULL;
    }

    if(preorder[i]> maxi || preorder[i]< mini){
        return NULL;
    }

    BinaryTreeNode* root = new BinaryTreeNode(preorder[i++]);

    root->left = solve(preorder, mini, root->data, i );
    root->right = solve(preorder,  root->data,maxi , i );

    return root;

}

BinaryTreeNode* preorderToBST(vector<int> &preorder) {
    int i = 0;
    int mini = INT_MIN;
    int maxi = INT_MAX;

    BinaryTreeNode* ans = solve(preorder, mini, maxi, i);
    return ans;

}

int main() {
    return 0;
}