//https://www.naukri.com/code360/problems/convert-bst-to-min-heap_920498?leftPanelTabValue=SUBMISSION
#include <iostream>
using namespace std;


	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

//to convert a bst into heaps, it must be a cbt and also should have the largest value on top, plus an extra condition
//that left child should be smaller than right child. hence, N<Lchild and also Lchilc < Rchild. Thus
// condition becomes N < L< R which is preorder . Thus after inorder array we push in preorder manner.

void inorder(vector<int>& order,BinaryTreeNode* root ){
	if(root == NULL){
		return ;
	}

	inorder(order, root->left);

	order.push_back(root->data);

	inorder(order, root->right);
}

BinaryTreeNode* preorderPush(BinaryTreeNode*& root, vector<int>order,int&i ){
	if(root == NULL){
		return NULL;
	}

	root->data = order[i++];
	root->left = preorderPush(root->left,  order, i);
	root->right = preorderPush(root->right,  order,  i);
	return root;
 }

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> order;
	inorder(order,root);
	int i = 0;
	root = preorderPush(root, order, i);
	return root;

}

int main() {
    return 0;
}