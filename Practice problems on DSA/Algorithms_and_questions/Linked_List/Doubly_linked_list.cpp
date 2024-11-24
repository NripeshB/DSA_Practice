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
void Insert(Node*&head, Node*&tail, int position,int data){
    if(position==1){
        Insert_at_head(head, data);
        return;
    }
    Node*temp = head;
    Node*insert= new Node(data);
    int count =1;
    while (count< position-1)
    {
        temp = temp->next;
        count++;
    }
    if(temp->next ==NULL){
        Insert_at_tail(tail, data);
        return;
    }

    Node*nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;

    
    
    
    
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
    Insert(head, tail, 1, 1);
    Insert(head, tail, 3  , 2);
    Insert(head, tail, 4  , 100);
  

    print(head);
    return 0;
}