//https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
  void summation(int len, int&maxlen, Node* root, int sum, int&maxsum){
      if(root == NULL){
          if(len>maxlen){
              maxlen = len;
              maxsum = sum;
          }
          else if(len == maxlen){
              maxsum = max(maxsum, sum);
          }
          return;
      }
      sum += root->data;
      
      summation(len+1, maxlen, root->left, sum, maxsum);
      summation(len+1, maxlen, root->right, sum, maxsum);
  }
    int sumOfLongRootToLeafPath(Node *root) {
        int len = 0;
        int maxlen = 0;
        
        int sum = 0;
        int maxsum = INT_MIN;
        
        summation(len, maxlen, root, sum, maxsum);
        
        return maxsum;
        
    }
};

int main() {
    return 0;
}