//https://bit.ly/3gr4wW8
#include <iostream>
using namespace std;


class TwoStack {
    int top1;
    int top2; 
    int size;
    int *arr;

public:
    // Initialize TwoStack with size s.
    TwoStack(int s) {
        size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s]; 
    }
    
    // Push in stack 1.
    void push1(int num) {
        if (top2 - top1 > 1) {  // Check for available space.
            arr[++top1] = num;
        } else {
            
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if (top2 - top1 > 1) {  // Check for available space.
            arr[--top2] = num;
        } else {
            
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
        
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            
            return -1;
        }
    }
};

int main() {
    return 0;
}