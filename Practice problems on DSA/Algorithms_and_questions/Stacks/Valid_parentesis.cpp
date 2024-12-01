//https://bit.ly/34kxPaq
#include <iostream>
using namespace std;



bool isValidParenthesis(string s)
{
    stack<char> Stack;
    int size = s.length();
    int i = 0;
    while(i< size){
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
        Stack.push(s[i]);
      }
        else {
            if (!Stack.empty()) {
                char a = Stack.top();
            if (s[i] == '}' && a != '{') {
                return false;
          }
            else if (s[i] == ')' && a != '(') {
                return false;
          }
            else if (s[i] == ']' && a != '[') {
                return false;
          }
          Stack.pop();
        }
        else{
            return false;
        }
      }

        i++;
    }

    if(Stack.empty()){
        return true;
    }
    else{
        return false;
    }
} 


int main() {
    return 0;
}