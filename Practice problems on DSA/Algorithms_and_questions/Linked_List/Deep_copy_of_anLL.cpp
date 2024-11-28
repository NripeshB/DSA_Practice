//https://leetcode.com/problems/copy-list-with-random-pointer/submissions/1464878381/
#include <iostream>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* temp = head;
        while (temp != NULL) {
            Node* copyTemp = new Node(temp->val);
            copyTemp->next = temp->next;
            temp->next = copyTemp;
            temp = copyTemp->next;
        }

        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            } else {
                temp->next->random = NULL;
            }
            temp = temp->next->next;
        }


        temp = head;
        Node* copyHead = head->next;
        Node* copyTemp = copyHead;
        while (temp != NULL) {
            temp->next = copyTemp->next;
            temp = temp->next;
            if (temp != NULL) {
                copyTemp->next = temp->next;
            }
            copyTemp = copyTemp->next;
        }

        return copyHead;

    }
};
int main() {
    return 0;
}