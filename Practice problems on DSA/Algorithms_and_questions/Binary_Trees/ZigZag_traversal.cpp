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

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> returner;
    	queue<Node*>q;
    	q.push(root);
    	bool lefttoright = true;
    	while(!q.empty()){
    	    int size = q.size();
    	    int ans[size];
    	    
    	    for(int i =0; i<size; i++){
    	        Node* temp = q.front();
    	        q.pop();
    	        
    	        int index = (lefttoright)?  i: size-i-1;
    	        
    	        ans[index] = temp->data;
    	        
    	        if(temp->left){
    	            q.push(temp->left);
    	        }
    	        if(temp->right){
    	            q.push(temp->right);
    	        }
    	    }
    	    lefttoright = !lefttoright;
    	    for(auto i: ans){
    	        returner.push_back(i);
    	    }
    	    
    	}
    	return returner;
    }
};

int main() {
    return 0;
}