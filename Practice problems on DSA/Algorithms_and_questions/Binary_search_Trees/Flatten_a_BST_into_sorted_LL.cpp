//https://www.naukri.com/code360/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0&leftPanelTabValue=SUBMISSION
#include <iostream>
using namespace std;

    template <typename T>
    class TreeNode {
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
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };




void inorder(TreeNode<int>* root, vector<int>&nums){
    if(root == NULL){
        return ;
    }

    inorder(root->left, nums );

    nums.push_back(root->data);

    inorder(root->right, nums );
    
}


TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> nums;
    inorder(root, nums);
    TreeNode<int>* newroot = new TreeNode<int>(nums[0]);
    TreeNode<int>* curr =newroot;


    for(int i = 1; i< nums.size(); i++){
        TreeNode<int>* temp =new TreeNode<int>(nums[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newroot;
}

int main() {
    return 0;
}