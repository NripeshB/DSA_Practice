//https://bit.ly/3rfFdfV
#include <iostream>
using namespace std;


    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first ==NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    Node<int>* HEAD = NULL;
    Node<int>* TEMP = NULL;

    Node<int>* i = first;
    Node<int>* j = second;

    if(i->data >= j->data){
        HEAD = j;
        TEMP = j;
        j = j->next;
    }
    else{
        HEAD = i;
        TEMP = i;
        i = i->next;
    }
    while(i != NULL && j != NULL){
        if(i->data >= j->data){
            TEMP->next = j;
            TEMP = j;
            j = j->next;
        }
        else if(i->data < j->data){
            TEMP ->next = i;
            TEMP = i;
            i = i->next;
        }
    }

    while(i != NULL){
        TEMP->next = i;
        TEMP = i;
        i=i->next;

    }
    while(j !=NULL){
        TEMP ->next = j;
        TEMP = j;
        j = j->next;
    }

    return HEAD;


}


int main() {
    return 0;
}