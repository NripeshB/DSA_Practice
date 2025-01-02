//https://www.naukri.com/code360/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0&leftPanelTabValue=PROBLEM
#include <iostream>
using namespace std;

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
//In this code just save the data from the inorder in a vector and just recursively
// run the code for addig mid of the array and same on the left and right parts of the subtrees

void inorder(TreeNode<int>* root, vector<int>&nums){
    if(root == NULL){
        return ;
    }

    inorder(root->left, nums );

    nums.push_back(root->data);

    inorder(root->right, nums );
    
}

TreeNode<int>* solve(vector<int> &nums, int s, int e) {

    if(s>e){
        return NULL ;
    }
    int mid = s+ (e-s)/2;
    TreeNode<int>* rootnew = new TreeNode<int>(nums[mid]); 

    rootnew->left = solve( nums, s, mid -1);
    rootnew->right = solve( nums, mid+1, e);
    return rootnew;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> nums;
    inorder(root, nums);
    TreeNode<int>* ans = solve( nums, 0 , nums.size()-1);
    return ans;
}

int main() {
    return 0;
}