//https://www.geeksforgeeks.org/problems/k-sum-paths/1
#include <iostream>
using namespace std;

struct Node
{
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
  
  void yummers(Node*root, int k, vector<int>&nodes, int& count){
      if(root == NULL){
         
          return;
      }
      
       nodes.push_back(root->data);
        
        // Traverse the current path to check for sums
        int sum = 0;
        for (int i = nodes.size() - 1; i >= 0; i--) {
            sum += nodes[i];
            if (sum == k) {
                count++;
            }
        }
      yummers(root->left, k, nodes, count);
      yummers(root->right, k, nodes, count);
      
      nodes.pop_back();
      
      
  }
    int sumK(Node *root, int k) {
        vector<int>nodes;
        int count = 0;
        yummers(root, k, nodes, count);
        return count;
        
    }
};

int main() {
    return 0;
}