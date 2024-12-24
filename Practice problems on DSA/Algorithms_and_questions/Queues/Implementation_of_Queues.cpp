#include <iostream>
#include <queue>
using namespace std;
//Queue is a FIFO type data structure,that means it works on the principle 
//of first in first out.

int main() {
    queue<int> q;

    q.push(11); 
    
    q.push(23); 
    
    q.push(13); 

    cout<<"Size of the queue is: "<<q.size()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<"Size of the queue is: "<<q.size()<<endl;
    return 0;
}