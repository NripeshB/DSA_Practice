#include <iostream>
using namespace std;

class Node{
public:
int data;
 Node* next;

 Node(int d){
    this->data = d;
    this->next = NULL;
 }

 ~Node(){
    if(this->next !=NULL){
        delete next; 
        next = NULL;
    }
 }

};

void Insert(Node*&tail, int element, int d){
       if (tail == NULL)
       {
        //list is empty rn
        Node * newnode = new Node(d);
        tail = newnode;
        newnode->next = newnode;
       }

       else{
        //non empty list;
        Node* curr = tail;
        while(curr->data!= element){
            curr = curr-> next;
        }

        Node*temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;

       }
       
}
void print(Node*tail){

    Node*temp = tail;
    do{ cout << tail -> data<<" ";
    
    tail = tail -> next;

    }while(tail!=temp);
    cout<<endl;
}

int main() {
    Node*tail = NULL;
    Insert(tail, 5, 3);
    Insert(tail, 3, 4);
    Insert(tail, 4, 5);
    Insert(tail, 5, 6);
    print(tail);
    return 0;
}