#include <iostream>
using namespace std;

class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

Node *removeDuplicates(Node *head)
{
    Node* i = head;
    Node* j = head;
    while(j!=NULL){
        if(j->next == NULL){
            j = j->next;break;}

        j = j->next;
        if(j->data == i->data){
            i->next = j->next;
        }
        
    }

    while(i != NULL){
        i = i->next;
        while(j!=NULL){
        if(j->next == NULL){
            j = j->next;break;}

        j = j->next;
        if(j->data == i->data){
            i->next = j->next;
        }
        
    }
    }
    return head;
}

int main() {
    return 0;
}