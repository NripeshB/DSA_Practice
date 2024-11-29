//https://www.naukri.com/code360/problems/flatten-a-linked-list_1112655?source=youtube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=SUBMISSION
#include <iostream>
using namespace std;



  class Node {
   public:
 	int data;
		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  };

Node* merge(Node* left, Node* right) {
    Node* dummy = new Node(0);
    Node* temp = dummy;

    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->child = left;
            left = left->child;
        } else {
            temp->child = right;
            right = right->child;
        }
        temp = temp->child;
    }

    // Attach the remaining nodes
    if (left != NULL) {
        temp->child = left;
    } else {
        temp->child = right;
    }

    Node* result = dummy->child;
    delete dummy; // Clean up dummy node
    return result;
}


Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL){
		return head;
	}

	head->next = flattenLinkedList(head->next);
	head = merge(head, head->next);
	return head; 

	
}

int main() {
    return 0;
}