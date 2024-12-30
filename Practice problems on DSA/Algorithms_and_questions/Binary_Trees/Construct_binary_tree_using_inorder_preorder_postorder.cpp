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

//Given inorder and postorder to construct a binary tree.
//https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

class Solution {
  public:
  void findIndex(vector<int>in ,map<int,int>&Inordermap, int size){
      for(int i= 0; i<size; i++){
          Inordermap[in[i]] = i;
      }
  }
  Node* solve(vector<int> &in, vector<int> &post ,int indexstart, int indexend, int& ind, int size, map<int,int>& Inordermap){
      if(ind < 0 || indexstart> indexend){
          return NULL;
      }
      
      int element = post[ind--];
      Node* root = new Node(element);
      int position = Inordermap[element];
      
      //The only hard thing is to realise that the call goes first for the right side of the tree
      // we are starting from the end of the postorder which ecompasses the right side of the tree.
      //hence the right recursive call comes first, and in preorder one left one does first.
      root->right = solve(in, post, position+1, indexend, ind, size, Inordermap);
      root->left = solve(in, post, indexstart, position -1, ind, size, Inordermap);
      return root;
  }
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        int index = inorder.size()-1;
        map<int, int> Inordermap;
        findIndex(inorder,Inordermap, inorder.size());
        Node*ans = solve(inorder, postorder, 0, inorder.size()-1, index, inorder.size(), Inordermap );
        return ans;
        
    }
};


int main() {
    return 0;
}
