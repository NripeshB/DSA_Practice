#include <map>
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
  void findIndex(vector<int>in ,map<int,int>&Inordermap, int size){
      for(int i= 0; i<size; i++){
          Inordermap[in[i]] = i;
      }
     
  }
  Node* solve(vector<int> &in, vector<int> &pre ,int indexstart, int indexend, int& ind, int size, map<int, int>& Inordermap){
      if(ind >= size || indexstart> indexend){
          return NULL;
      }
      
      int element = pre[ind++];
      Node* root = new Node(element);
      int position = Inordermap[element];
      
      root->left = solve(in, pre, indexstart, position -1, ind, size, Inordermap);
      root->right = solve(in, pre, position+1, indexend, ind, size, Inordermap);
      
      return root;
  }
  
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int index = 0;
        map<int, int> Inordermap;
        findIndex(inorder,Inordermap, inorder.size());
        Node*ans = solve(inorder, preorder, 0, inorder.size(), index, inorder.size(), Inordermap );
        return ans;
    }
};

int main() {
    return 0;
}
