//https://leetcode.com/problems/reverse-nodes-in-k-group/


#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    // here its node *next as next is a pointer to another node and not to an integer.
    Node *next;

    // creating a constructor for the Node.
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        if(this->next != NULL){
            delete this->next;
            this-> next = NULL;
        }
    }
};
void Insert_at_Head(Node *&head, int d)
{
    // creating a temp node which saves the address fort he prev head and takes up the head title.
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void Insert_at_Tail(Node *&tail, int d)
{
    // creating a temp node which saves the address fort he prev head and takes up the head title.
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void Insert(Node *&head, Node *&tail, int position, int data)
{

    Node *temp = head;
    // count starts at 1 so it grabs the node just before the the position where the new node is to be inserted.
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    // if insertion happens at head
    if (position == 1)
    {
        Insert_at_Head(head, data);
        return;
    }
    // if insertion happens at tail;
    if (temp->next == NULL)
    {
        Insert_at_Tail(tail, data);
        return;
    }

    Node *nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void DeleteNode(int position, Node*&head ){
    if (position==1)
    {
        Node*temp = head;
        head = head->next;
        //freeing the memory for the previously made head
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node*curr = head;
        Node*prev = NULL;
        int count = 1;
        while(count< position){
            prev = curr;
            curr = curr->next;

        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        
    }
}
void Print(Node *&head)
{
    // pointing the temp node at head and then traversing it.
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* kgroup(Node*head, int k){

    if (head == NULL)
    {
        return NULL;
    }

    int measure = 0;
    Node*temp = head;
    while(temp!=NULL){
        temp = temp->next;
        measure++;
    }
    if(measure<k){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    int condition = 0;

    while(curr!= NULL && condition < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        condition++;

    }

    if(forward!= NULL){
        head->next = kgroup(forward, k);
    }

    return prev;
    
}

int main()
{
    Node *Node1 = new Node(8);
    cout << Node1->data << endl;
    cout << Node1->next << endl;
    // creating a head for the first node.
    Node *head = Node1;
    Node *tail = Node1;
    Insert_at_Head(head, 7);
    Insert_at_Head(head, 6);
    Insert_at_Head(head, 5);
    Insert_at_Head(head, 4);
    Insert_at_Head(head, 3);
    Insert_at_Head(head, 2);
    Insert_at_Head(head, 1);
    Print(head);
    Node * N1 = kgroup(head, 5);
    Print(N1);


//this starts a chain reaction by calling the destructor and deleting the entire linked list
    delete head;
    return 0;
}