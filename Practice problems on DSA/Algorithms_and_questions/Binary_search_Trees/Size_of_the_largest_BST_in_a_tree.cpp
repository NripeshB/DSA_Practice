//https://www.naukri.com/code360/problems/largest-bst-subtree_893103?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
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


    //Defining a class for storing info for each recursive traversal in the tree.
    //It stores minimum maximum vals that a node can take and also returns if it itself is a 
    //valid tree node or not. Also passes the size for returning the ans.

class info{
    public: 
    int mini;
    int maxi;
    bool isBST;
    int size;
};

info solve( TreeNode* root, int& ans){
    if ( root == NULL){
        return {INT_MAX, INT_MIN, true, 0};
    }

    info L = solve(root->left, ans);
    info R = solve(root->right, ans);

    info curr;
    curr.size = L.size + R.size + 1;
    curr.maxi = max(root->data, R.maxi);
    curr.mini = min(root->data, L.mini);

    if( L.isBST && R.isBST && L.maxi< root->data && R.mini > root->data){
        curr.isBST = true;
    }
    else{
        curr.isBST = false;
    }

    if( curr.isBST ){
        ans = max(ans, curr.size);
    }

    return curr;
}
int largestBST(TreeNode * root){
    int ans = 0;
    info temp = solve( root, ans);
    return ans;
}

int main() {
    return 0;
}