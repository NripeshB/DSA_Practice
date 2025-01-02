//https://www.naukri.com/code360/problems/two-sum-in-a-bst_1062631?leftPanelTab=0&leftPanelTabValue=SUBMISSION
#include <iostream>
using namespace std;

class BinaryTreeNode {
    public : 
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode*right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void inorder(BinaryTreeNode* root, int target, vector<int>&nums){
    if(root == NULL){
        return ;
    }

    inorder(root->left,target, nums );

    nums.push_back(root->data);

    inorder(root->right,target, nums );
    
}

bool twoSumInBST(BinaryTreeNode* root, int target) {
	vector<int> nums;
   
    inorder(root, target, nums);

    int i =0;
    int j = nums.size()-1;
    bool ans = false;

    while( i<j){
        
        if(nums[i] + nums[j]> target){
            j--;
        }
        else if(nums[i] + nums[j]< target){
            i++;
        }
        else{
            ans = true;
            break;
        }
    }

    return ans;
    

}

int main() {
    return 0;
}