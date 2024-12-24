#include <iostream>
using namespace std;

//This approach has a TC of O(1) but the SC is of O(n):
/*class SpecialStack {
    stack<int> S;
    stack<int> mini;
    int num;
    public:
        
    void push(int data) {
        S.push(data);
        if(mini.empty()|| mini.top()>data){
           mini.push(data);
        }
        else{
            mini.push(mini.top());
        }
    }

    void pop() {
        S.pop();
        mini.pop();
    }

    int top() {
        int a = S.top();
        return a;
    }

    int getMin() {
        int a = mini.top();
        return a;
    }  
};  */





int main() {
    return 0;
}