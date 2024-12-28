//https://bit.ly/3Lyh6kC
#include <iostream>
using namespace std;

template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
void preorder(BinaryTreeNode<int>* node, int &count){
    if(node == NULL){
        return ;
    }
    if(node->left == NULL && node->right == NULL){
        count++;
    }
    preorder(node->left, count);
    preorder(node->right, count);
    
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count=0;
    preorder(root, count);
    return count;
}
int main() {
    return 0;
}