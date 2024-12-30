#include <iostream>
#include <map>
using namespace std;


int main() {
    return 0;
}

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  
  void mapping(Node*root, map<Node*, Node*>& mapped){
      
      if(root == NULL){
          return;
      }
      
      if(root->left!=NULL){
           mapped[root->left] = root;
      }
     
      if(root->right!=NULL){
           mapped[root->right] = root;
      }
     
      
      
      mapping(root->left, mapped);
      mapping(root->right, mapped);
  }
  
  void position(Node* root, int target, Node*&start){
      if(root==NULL){
          return;
          
      }
      
      if(root->data == target){
          start = root;
          return;
      }
      
      position(root->left, target, start);
      position(root->right, target, start);
      
  }
  
 
      //Recursive method to calculate min time to burn a tree
      
      int BurnIt(Node* node, map<Node*, Node*>& mapped, map<Node*, bool>& visited) {
        if (node == NULL || visited[node]) {
            return 0;
        }

        visited[node] = true;

        // Burn left subtree
        int leftTime = BurnIt(node->left, mapped, visited);

        // Burn right subtree
        int rightTime = BurnIt(node->right, mapped, visited);

        // Burn parent node
        int parentTime = BurnIt(mapped[node], mapped, visited);

        // Return the maximum time taken to burn in all directions
        return 1+ max({leftTime, rightTime, parentTime});
    }
    


  
  
    int minTime(Node* root, int target) {
        map<Node* ,Node*> mapped;
        mapped[root] = NULL;
        mapping(root, mapped);
        
        
        Node* start = NULL;
        position(root, target, start);
        
        map<Node*, bool> visited;
        
        int Time = BurnIt(start,mapped, visited)  ;
        
        return Time-1;
        
        
    }
};