//https://www.naukri.com/code360/problems/validate-bst_799483?leftPanelTab=0&leftPanelTabValue=SUBMISSION
#include <iostream>
using namespace std;
//there are two methods, one is to confirm if the In order traversal is in increasing order
// the second is to recursively check each element being smaller and greater on left and right


    class Node 
    {
    public : 
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


bool solve(Node *root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root->data>= min && root->data<= max){
        bool L = solve(root->left, min, root->data);
        bool R = solve(root->right, root->data,max );

        return L&&R;
    }
    return false;
}

bool validateBST(Node *root) {
    bool ans = solve( root, INT_MIN, INT_MAX);
    return ans;    
}

int main() {
    return 0;
}