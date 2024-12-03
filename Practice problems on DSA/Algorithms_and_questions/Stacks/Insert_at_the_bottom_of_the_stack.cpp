//https://bit.ly/34qqmGL
#include <iostream>
using namespace std;

void solve(stack<int>& S, int x){
    if(S.empty()){
        S.push(x);
        return ;
    }

    int a = S.top();
    S.pop();
    solve(S, x);
    S.push(a);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}


int main() {
    return 0;
}