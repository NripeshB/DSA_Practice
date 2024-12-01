//https://bit.ly/3ovTIu2
#include <iostream>
using namespace std;


void solve(stack<int>&Stack, int count, int size, int mid){
   if(count == mid){
      Stack.pop();
      return;
   }

   int num = Stack.top();
   Stack.pop();

   solve(Stack, count + 1, size, mid);
   Stack.push(num);

}

void deleteMiddle(stack<int>&inputStack, int N){
   int size = inputStack.size();
   int count =0;
   int mid =0;
   if(size&1){
      mid = size/2;
   }
   else{
      mid = (size/2 ) -1;
   }
   solve(inputStack, count, size, mid );
 }



int main() {
    return 0;
}