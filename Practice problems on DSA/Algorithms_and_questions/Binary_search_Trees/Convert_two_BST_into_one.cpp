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


//This is one of the two approaches to merge two BST

//First take out the inorder for both which comes out sorted
    void inorder(TreeNode *root, vector<int>&nums){
    if(root == NULL){
        return;
    }

    inorder(root->left, nums);

    nums.push_back(root->data);

    inorder(root->right, nums);

    
}

//Then use those two arrays to merge together into one using the basics

void merge(vector<int>nums1 , vector<int>nums2 , vector<int>& merged){
    int i = 0;
    int j = 0;
    while( i< nums1.size()&& j < nums2.size()){
        if(nums1[i]>=nums2[j]){
            merged.push_back(nums2[j]);
            j++;
        }
        else {
            merged.push_back(nums1[i]);
            i++;
        }

    }
    while( i< nums1.size()){
        merged.push_back(nums1[i]);
            i++;
    }
    while(j < nums2.size()){
        merged.push_back(nums2[j]);
            j++;
    }

}

//Then using that merged array to build a balanced BST like already done.
TreeNode* VectorToBalancedBST(vector<int> &nums, int s, int e) {

    if(s>e){
        return NULL ;
    }
    int mid = s+ (e-s)/2;
    TreeNode* rootnew = new TreeNode(nums[mid]); 

    rootnew->left = VectorToBalancedBST( nums, s, mid -1);
    rootnew->right = VectorToBalancedBST( nums, mid+1, e);
    return rootnew;
}

TreeNode* mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> nums1;
    vector<int> nums2;

    inorder(root1, nums1);
    inorder(root2, nums2);

    vector<int> merged;

    merge(nums1, nums2, merged);

    TreeNode* ans = VectorToBalancedBST(merged, 0, merged.size()-1);
    return ans;


}

int main() {
    return 0;
}