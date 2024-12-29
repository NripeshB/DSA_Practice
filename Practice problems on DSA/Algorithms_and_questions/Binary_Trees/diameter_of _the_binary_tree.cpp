//https://leetcode.com/problems/diameter-of-binary-tree/
#include <iostream>
using namespace std;


  struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {

public:
    // Helper function to calculate the height of the tree and update the diameter.
    int maxHeight(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0; // Base case: height of an empty tree is 0
        }

        // Recursively calculate the height of the left and right subtrees
        int leftHeight = maxHeight(node->left, diameter);
        int rightHeight = maxHeight(node->right, diameter);

        // Update the diameter: it's the maximum of the current diameter and the path passing through this node
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; // Initialize diameter
        maxHeight(root, diameter); // Call helper function
        return diameter; // Return the final diameter
    }
};



int main() {
    return 0;
}