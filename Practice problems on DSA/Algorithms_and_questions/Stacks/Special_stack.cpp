//https://www.naukri.com/code360/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems%3Fsource%3Dyoutube&campaign=Codestudio_Lovebabbar&utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Lovebabbar&leftPanelTabValue=SUBMISSION
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


  //And this approach has a TC of 1 and ST also of 1


class SpecialStack {
    stack<int> S;
    
    int mini;
    public:
        
    void push(int data) {
        if(S.empty()){
            S.push(data);
            mini = data;
        }
        else{
            if(data<mini){
                S.push(2*data - mini);
                mini = data;
            }
            else{
                S.push(data);
            
            }
        }
    }

    void pop(){
        int curr = S.top();
        S.pop();
        if(curr<mini){
        mini = 2*mini - curr; 
               }
    }

    int top() {
        if(S.empty()){
            return -1;
        }

        int curr = S.top();

        if(curr<mini){
            return mini;
        }

        else{
            return curr;
        }
    }

    int getMin() {
        
        return mini;
    }  
};


int main() {
    return 0;
}