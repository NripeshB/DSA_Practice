//https://bit.ly/3GsXWsz
#include <iostream>
using namespace std;


    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };

node* Merge(node* left, node* right) {
    node* ans = new node(0); // Dummy node for easier merging
    node* nexter = ans;

    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            nexter->next = left;
            left = left->next;
        } else {
            nexter->next = right;
            right = right->next;
        }
        nexter = nexter->next;
    }

    // Attach any remaining nodes in the left or right list
    if (left != NULL) {
        nexter->next = left;
    } else {
        nexter->next = right;
    }

    node* result = ans->next;
    delete ans; // Clean up the dummy node to avoid memory leak
    return result;
}




node* mergeSort(node* head) {
    if (!head || !head->next) {
        return head;
    }

    // Count total nodes
    node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Find the middle node
    node* mid = head;
    for (int i = 1; i < count / 2; ++i) {
        mid = mid->next;
    }

    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return Merge(left, right);
}

int main() {
    return 0;
}