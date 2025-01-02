//https://www.naukri.com/code360/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=SUBMISSION
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



pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{

    TreeNode* temp = root;
    int succ = -1;
    int pred = -1;

    while(temp != NULL &&temp->data != key){
    if(temp->data > key){
        succ = temp->data;
        temp = temp->left;
    }
    else{
        pred = temp->data;
        temp = temp->right;
    }

    }
     if (temp == NULL) {
        return {pred, succ};
    }
    TreeNode* L   = temp->left;

    while( L!= NULL){
        pred = L->data;
        L =L->right;
    }
    TreeNode* R   = temp->right;
    while( R!= NULL){
        succ = R->data;
        R =R->left;
    }

    pair<int, int> p = make_pair(pred, succ);
    return p;
    
}

int main() {
    return 0;
}