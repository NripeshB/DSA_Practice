#include <iostream>
using namespace std;

queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> S;
    int n = q.size();

    for(int i=0; i<k; i++){
        S.push(q.front());
        q.pop();
    }

    for(int i=0; i<k; i++){
        q.push(S.top());
        S.pop();
    }
    for(int i =0; i<n-k; i++){
        int a = q.front();
        q.push(a);
        q.pop();
    }
    return q;
}



int main() {
    return 0;
}