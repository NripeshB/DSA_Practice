#include <iostream>
using namespace std;

 template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

//This is a less optimised recursive method.ß
void solve(BinaryTreeNode<int> *root, int x, bool& ans){
    if(root == NULL){
        ans = false;
        return ;
    }
    if(root->data == x){
        ans = true;
    }
    if(root->data<x){
        solve(root->right, x, ans);
    }

    else if (root->data>x){
        solve(root->left, x, ans);
    }

    
}

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    bool ans;
    solve(root,  x, ans);
    return ans;
}

int main() {
    return 0;
}