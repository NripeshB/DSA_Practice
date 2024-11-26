#include <iostream>
using namespace std;


  class Node {
  public:
       int data;
       Node *prev;
       Node *next;
       Node() {
           this->data = 0;
           this->prev = NULL;
        this->next = NULL;
       }
       Node(int data) {
           this->data = data;
          this->prev = NULL;
           this->next = NULL;
       }
       Node (int data, Node *next, Node *prev) {
          this->data = data;
           this->prev = prev;
           this->next = next;
       }
  };
 

Node * removeDuplicates(Node *head)
{
    Node*temp = head;
    while (temp != NULL) {
      if (temp->next == NULL){
            temp = temp->next;
    }
        else if(temp->data != temp->next->data){
            temp = temp->next;
        }
        else{
            temp->next = temp->next->next;
        }
    }
    return head;
}

int main() {
    return 0;
}