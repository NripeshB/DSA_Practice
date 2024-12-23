//https://www.naukri.com/code360/problems/the-celebrity-problem_982769?leftPanelTabValue=PROBLEM
#include <iostream>
#include <stack>
using namespace std;
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
int knows(int a, int b){
    //the knows function is defined in the problem statement internally
    //but if the question is given in the form of a 2D array it can be checked by
    //searching for element at ARR[a][b] .

}

int findCelebrity(int n) {
	stack<int> S;
	for(int i =0; i<n ; i++){
		S.push(i);
	}
	int Ans;
	while(S.size()> 1){
		int A = S.top();
		S.pop();
		
		
		int B = S.top();
		S.pop();
		if(knows(A,B)){
			S.push(B);
		}
		else if(knows(B,A)){
			S.push(A);
		}
		
	}
	if(S.empty()){
		return -1;
	}
	Ans = S.top();
	bool check = true;
	for(int i =0; i<n ; i++){
		if(Ans == i){
			continue;
		};
		if(knows(Ans,i)||!knows(i, Ans)){
			check = false;
			break;
		}
	}

	

	if(check == false){
		return -1;
	}
	else{return Ans;}

}
int main() {
    return 0;
}