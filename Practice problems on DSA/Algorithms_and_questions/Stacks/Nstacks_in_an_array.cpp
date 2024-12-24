#include <iostream>
using namespace std;

class NStack
{
    int*arr;
    int*top;
    int*next;

    int n;
    int s;
    
    int freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        next = new int[s];
        top = new int[n];

        for(int i = 0; i<n; i++){
            top[i] = -1;
        }

        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;

        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freespot == -1){
            return false;
        }

        //fetch freespot
        int index = freespot;

        //update freespot
        freespot = next[index];

        //insert element
        arr[index]=x;

        //update next array to now point to element next to the final element
        next[index] = top[m-1];

        //update top 
        top[m-1] = index;

        return true;

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]== -1){
            return -1;
        }
        int index;
        
        //just do the opposite of push
        index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};


int main() {
    return 0;
}