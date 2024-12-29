#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
  
  int maxH(struct Node*node, int& h){
      if(node== NULL){
          return 0;
      }
      
      int lef = maxH(node->left, h);
      int rig = maxH(node->right, h);
      h = max(lef, rig)+1;
      return h;
      
      
  }
    // Function to find the height of a binary tree.
    int height(struct Node* node) {
        
        int h = 0;
        h = maxH(node, h);
        return (h-1);
    }
};

int main() {
    return 0;
}