#include <iostream>
using namespace std;

void reverse(queue < int > & q) {
    stack<int>S;
    int num1 = q.size();
    for(int i = 0; i<num1; i++){
        S.push(q.front());
        q.pop();
    }
    int num = S.size();
    for(int i= 0; i<num; i++){
        q.push(S.top());
        S.pop();
    }
}

int main() {
    return 0;
}