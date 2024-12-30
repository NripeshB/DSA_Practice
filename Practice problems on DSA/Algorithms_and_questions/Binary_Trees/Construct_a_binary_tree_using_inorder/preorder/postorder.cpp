#include <iostream>
using namespace std;


//Given inorder, preorder to make the binary tree.
//https://www.geeksforgeeks.org/problems/construct-tree-1/1
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
  int findIndex(int n, vector<int>&in, int size){
      for(int i= 0; i<size; i++){
          if(in[i] == n){
              return i;
          }
      }
      return -1;
  }
  Node* solve(vector<int> &in, vector<int> &pre ,int indexstart, int indexend, int& ind, int size){
      if(ind >= size || indexstart> indexend){
          return NULL;
      }
      
      int element = pre[ind++];
      Node* root = new Node(element);
      int position = findIndex(element, in, size);
      
      root->left = solve(in, pre, indexstart, position -1, ind, size);
      root->right = solve(in, pre, position+1, indexend, ind, size);
      
      return root;
  }
  
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int index = 0;
        Node*ans = solve(inorder, preorder, 0, inorder.size(), index, inorder.size() );
        return ans;
    }
};

int main() {
    return 0;
}