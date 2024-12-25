#include <iostream>
#include <queue>
using namespace std;
//Queue is a FIFO type data structure,that means it works on the principle 
//of first in first out.

//Queue STL;
int main() {
    queue<int> q;

    q.push(11); 
    cout<<q.back()<<endl;
    q.push(23); 
    cout<<q.back()<<endl;
    
    q.push(13); 
    cout<<q.back()<<endl;


    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    return 0;
}