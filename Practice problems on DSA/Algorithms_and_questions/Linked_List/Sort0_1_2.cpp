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

//Approach One, with changing the data;
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
//Approach Two, without changing the data:

void insertAtTail(Node*&tail, Node*curr){
    tail->next = curr;
    tail= curr;
}

Node *sortList(Node *head) {
     Node *head0 = new Node(-1);
     Node* tail0 = head0;
     Node *head1 = new Node(-1);
     Node* tail1 = head1;
     Node *head2 = new Node(-1);
     Node* tail2 = head2;
    

    Node *curr = head;

    while(curr!=NULL){
        int value = curr->data;

        if(value == 0){
            insertAtTail(tail0,curr);
        }
        else if(value == 1){
            insertAtTail(tail1,curr);
        }
        else if(value == 2){
            insertAtTail(tail2,curr);
        }
        curr = curr->next;
    }

    //merging the three sublists:
    
     if(head1 ->next !=NULL){
         tail0->next = head1->next;
         tail1->next = head2->next;
         tail2->next =NULL;
     }
     else{
         tail0->next = head2->next;
         tail2->next = NULL;
     }
      
      if(head0->next !=NULL){
          head = head0->next;
      }
      else if(head1->next != NULL){
          head = head1->next;
      }
      return head;
     





    }
int main() {
    return 0;
}