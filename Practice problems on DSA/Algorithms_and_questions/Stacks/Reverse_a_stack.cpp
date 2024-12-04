//https://bit.ly/3HCBnD4
#include <iostream>
using namespace std;



void insertAtBottom(stack<int>& S, int x){
    if(S.empty()){
        S.push(x);
        return ;
    }

    int a = S.top();
    S.pop();
    insertAtBottom(S, x);
    S.push(a);
}

void Reverse(stack<int>&stack){
if(stack.empty()){
    return;
}

int a = stack.top();
stack.pop();
Reverse(stack);
insertAtBottom(stack, a);

}

void reverseStack(stack<int> &stack) {
    Reverse(stack);
}

int main() {
    return 0;
}