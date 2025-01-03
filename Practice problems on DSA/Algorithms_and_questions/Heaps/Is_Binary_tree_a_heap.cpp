//https://geeksforgeeks.org/problems/is-binary-tree-heap/1
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//a binary tree is a heap when it is a CBT and a MAX heap
//For checking CBT we check if the index doesnt exceed the node count
//and for max heap we check whether the child data is smaller or not than the parent data

int count(struct Node* tree){
    if( tree == NULL){
        return 0;}
        
    int ans = count(tree->left) + count(tree->right) + 1;
    return ans;
}

bool isCBT(struct Node* tree, int maxcount, int index){
    if(tree == NULL){
        return true;
    }
    
    if( index>= maxcount){
        return false;
    }
    
    else{
        bool ans = isCBT(tree->left, maxcount, 2*index+1) && isCBT(tree->right, maxcount, 2*index+2);
        return ans;
    }
    
}

bool isMaxHeap(struct Node* tree){
    if( tree->left == NULL && tree->right == NULL){
        return true;
    }
    
    if( tree->right == NULL ){
        return (tree->left->data < tree->data);
    }
    
    if( tree->right != NULL && tree->left != NULL){
        bool L = isMaxHeap(tree->left);
        bool R = isMaxHeap(tree->right);
        return (L&&R&& tree->data > tree->left->data &&tree->data > tree->right->data);
    }
        
}

class Solution {
  public:
    bool isHeap(struct Node* tree) {
        int index = 0;
        int maxcount = count(tree);
        if( isCBT (tree, maxcount, index) && isMaxHeap(tree)){
            return true;
        }
        else{return false;}
    }
};

int main() {
    return 0;
}