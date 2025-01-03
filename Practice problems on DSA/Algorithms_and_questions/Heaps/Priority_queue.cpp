#include <iostream>
#include <queue>
using namespace std;


int main() {
    //Stl for max heap
    priority_queue<int> pq;

    pq.push(5);
    pq.push(6);
    pq.push(4);
    pq.push(9);
    pq.push(2);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.size()<<endl;
    cout<<pq.empty()<<endl;

    // for applying min heap using stl

      priority_queue<int, vector<int>, greater<int> > minHeap;

      minHeap.push(5);
    minHeap.push(6);
    minHeap.push(4);
    minHeap.push(9);
    minHeap.push(2);

    cout<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<minHeap.size()<<endl;
    cout<<minHeap.empty()<<endl;


    return 0;
}