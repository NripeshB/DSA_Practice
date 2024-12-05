#include <iostream>
using namespace std;



void sortedInsert(stack<int>& stack, int x){
if (stack.empty() || stack.top() < x){
		stack.push(x);
		return;
	}
	int a = stack.top();

	stack.pop();
	sortedInsert(stack, x);
	stack.push(a);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}

	int a = stack.top();
	stack.pop();

	sortStack(stack);

	sortedInsert(stack, a);
}

int main() {
    return 0;
}