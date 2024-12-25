#include <iostream>
using namespace std;


//Using Stack
void reverse1(queue < int > & q) {
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

//Using recursion
void Opp(queue<int>&q ){
    if(q.empty()){
        return;
    }

    int F= q.front();
    q.pop();
    Opp(q);
    q.push(F);
}

void reverse2(queue < int > & q) {
    Opp(q);
}

int main() {
    return 0;
}