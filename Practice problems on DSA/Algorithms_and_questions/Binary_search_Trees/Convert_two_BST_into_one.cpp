#include <iostream>
using namespace std;



// Node structure for the BST and DLL
struct TreeNode {
    int data;
    TreeNode* left;  // Acts as "prev" in DLL
    TreeNode* right; // Acts as "next" in DLL

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Step 1: Convert a BST into a doubly linked list
void bstToDoublyLinkedList(TreeNode* root, TreeNode*& prev, TreeNode*& head) {
    if (!root) return;

    // Recur on the left subtree
    bstToDoublyLinkedList(root->left, prev, head);

    // Process the current node
    if (!prev) {
        head = root; // This is the leftmost node, the head of the DLL
    } else {
        prev->right = root;
        root->left = prev;
    }

    prev = root; // Update previous node

    // Recur on the right subtree
    bstToDoublyLinkedList(root->right, prev, head);
}

// Step 2: Merge two sorted doubly linked lists
TreeNode* mergeSortedDLLs(TreeNode* head1, TreeNode* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    TreeNode* head = nullptr;
    TreeNode* tail = nullptr;

    // Merge the two DLLs
    while (head1 && head2) {
        TreeNode* smaller = nullptr;
        if (head1->data < head2->data) {
            smaller = head1;
            head1 = head1->right;
        } else {
            smaller = head2;
            head2 = head2->right;
        }

        // Add the smaller node to the merged DLL
        if (!head) {
            head = smaller; // First node
            tail = smaller;
        } else {
            tail->right = smaller;
            smaller->left = tail;
            tail = smaller;
        }
    }

    // Append remaining nodes
    TreeNode* remaining = head1 ? head1 : head2;
    while (remaining) {
        tail->right = remaining;
        remaining->left = tail;
        tail = remaining;
        remaining = remaining->right;
    }

    return head;
}

// Step 3: Convert a sorted DLL into a balanced BST
TreeNode* sortedDLLToBST(TreeNode*& head, int n) {
    if (n <= 0 || !head) return nullptr;

    // Recursively build the left subtree
    TreeNode* left = sortedDLLToBST(head, n / 2);

    // Make the current node the root
    TreeNode* root = head;
    root->left = left;

    // Move the head pointer to the next node
    head = head->right;

    // Recursively build the right subtree
    root->right = sortedDLLToBST(head, n - n / 2 - 1);

    return root;
}

// Utility function to count nodes in a doubly linked list
int countNodes(TreeNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->right;
    }
    return count;
}

// Utility function to print the DLL
void printDLL(TreeNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

// Utility function for in-order traversal of a BST
void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Driver code
int main() {
    // Create first BST
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);

    // Create second BST
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);

    // Convert both BSTs to DLLs
    TreeNode *head1 = nullptr, *prev1 = nullptr;
    bstToDoublyLinkedList(root1, prev1, head1);

    TreeNode *head2 = nullptr, *prev2 = nullptr;
    bstToDoublyLinkedList(root2, prev2, head2);

    // Merge the two DLLs
    TreeNode* mergedDLL = mergeSortedDLLs(head1, head2);

    // Convert the merged DLL to a balanced BST
    int totalNodes = countNodes(mergedDLL);
    TreeNode* mergedBST = sortedDLLToBST(mergedDLL, totalNodes);

    // Print the in-order traversal of the merged BST
    cout << "In-order traversal of the merged BST: ";
    inOrder(mergedBST);
    cout << endl;

    return 0;
}

/*
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
}*/