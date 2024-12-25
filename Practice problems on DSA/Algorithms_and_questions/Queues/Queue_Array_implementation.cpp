#include <iostream>
using namespace std;

class Queue{
    int* arr;
    int Front;
    int rear;
    int size;



    public:
    Queue(){
        size = 10001;
        arr = new int[size]; 
        Front = 0;
        rear = 0;


    }

    bool isEmpty(){
        bool ans = (Front == rear)? true: false;
        return ans;
    }

    void enqueue(int data){
        if(rear == size){
            cout<<"The queue is full."<<endl;
        }
        else{
            arr[rear] = data;
            rear++;  
        }
    }
    
    int dequeue(){
        if(Front== rear){ 
            cout<<"The queue is empty."<<endl;
        }

        else{
            int ans = arr[Front];
            arr[Front]= -1;
            Front++;  
            if(Front== rear){
            Front = 0;
            rear = 0;}

            return ans;
        }
    }
    int front(){
        int ans = (Front==rear)? -1 : arr[Front];
        return ans; 
    }

};

int main() {
    return 0;
}