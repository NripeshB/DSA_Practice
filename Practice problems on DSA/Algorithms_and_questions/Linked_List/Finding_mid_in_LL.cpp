#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

int getlength(Node* head){
    int count = 1;
    while (head->next != NULL) {
      head = head->next;
      count++;
   }
   return count;
}
Node *findMiddle(Node *head) {
    int length = getlength(head);
    int Mid = -1;
    if(length&1){
        Mid = ((length+1)/2);
    }
    else{
        Mid = ((length)/2)+1;
    }

    int count = 1;
    while (count < Mid) {
      head = head->next;
      count++;
   }
   return head;
}

int main() {
    return 0;
}