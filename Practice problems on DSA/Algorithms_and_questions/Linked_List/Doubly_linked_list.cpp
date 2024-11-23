#include <iostream>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;

Node(int d){
this->data = d;
this-> prev = NULL;
this-> next = NULL;
}
};

void  Insert_at_head(Node*&head, int data){
Node*temp = new Node(data);
temp->next = head;
head->prev = temp;
head = temp;
}
void  Insert_at_tail(Node*&tail, int data){
Node*temp = new Node(data);
temp->prev = tail;
tail->next = temp;
tail = temp;
}
//treversing the doubly linked list
void print(Node*head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node* node1 = new Node(10);
    Node*head = node1;
    Node*tail = node1;
    Insert_at_head(head, 11);
    Insert_at_tail(tail, 9);
    print(head);
    return 0;
}