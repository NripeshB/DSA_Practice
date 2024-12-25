#include <iostream>
using namespace std;

class CircularQueue{
    int* arr;
    int Front;
    int rear;
    int size;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
    size = n;
    arr = new int[size]; 
    Front = -1;
    rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if ((rear+1)%size == Front) {
            return false;
        }
        
        
        if (Front == -1) {
            // First element being added
            Front = rear = 0;
        } else {
            // Increment rear (wrap around if needed)
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        return true;
    }
    

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(Front == -1){
            return -1;
        }
        else if(Front == rear){
            int ans = arr[Front];
            arr[Front] = -1;
            Front = rear = -1;
            return ans;
        }
        else if(Front== size-1&& rear<Front){
            int ans = arr[Front];
            arr[Front] = -1;
            Front = 0;
            return ans;
        }
        else{
            int ans = arr[Front];
            arr[Front] = -1;
            Front++;
            return ans;
        }
    }
};

int main() {
    return 0;
}