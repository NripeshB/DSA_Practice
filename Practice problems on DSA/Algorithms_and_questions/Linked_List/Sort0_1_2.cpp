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


Node* sortList(Node *head){
    Node*temp= head;

    int count0 =0;
    int count1 =0;
    int count2 =0;

    while(temp != NULL){
        if(temp->data == 0){
            count0++;
        }
        else if(temp->data == 1){
            count1++;
        }
        else if(temp->data == 2){
            count2++;
        }
        temp = temp->next;
    }
    
    temp = head;
    while(count0>0){
        temp->data = 0;
        temp = temp->next;
        count0--;
    }
    while(count1>0){
        temp->data = 1;
        temp = temp->next;
        count1--;
    }
    while(count2>0){
        temp->data = 2;
        temp = temp->next;
        count2--;
    }

    return head;
}
int main() {
    return 0;
}