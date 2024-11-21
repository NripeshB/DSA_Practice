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

void Print(Node *&head)
{
    // pointing the temp node at head and then traversing it.
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *Node1 = new Node(10);
    cout << Node1->data << endl;
    cout << Node1->next << endl;
    // creating a head for the first node.
    Node *head = Node1;
    Node *tail = Node1;
    Insert_at_Head(head, 12);
    Insert_at_Tail(tail, 15);
    Insert_at_Tail(tail, 16);
    Print(head);

    return 0;
}