//https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <iostream>
using namespace std;
//follows the same logic as merging k arrays
//firs form a min heap with all the heads of k LLs and then iterating though them add succesive nodes and pop
//with each iteration and update the tail 
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

class compare{
    public:
    bool operator()(Node* a , Node* b ){
        return a->data > b->data;
    }
};
Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*, vector<Node*> , compare> mini;

    int k = listArray.size();

    if(k == 0){
        return NULL;
    }

    for(int i = 0; i<k;i++){
        if(listArray[i] != NULL){
            mini.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(!mini.empty()){
        Node* top  = mini.top();
        mini.pop();


        if(top->next != NULL){
            mini.push(top->next);
        }
        if(head == NULL){
            head = top;
            tail = top;
        }

        else {
            tail->next = top;
            tail = top;
        }
    }
    return head;
}


int main() {
    return 0;
}