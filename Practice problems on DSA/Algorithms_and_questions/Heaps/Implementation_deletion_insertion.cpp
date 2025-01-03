#include <iostream>
using namespace std;

//In a heap, the indexing is like in a tree data structure, starting from left to the right;
//eg: (the indexing)
//               1
//         2           3
//      4     5      6    7  
//   8   9  10  11 12 13 14  15
//heap is a complete binary tree ;
//and it either follows a min heap or max heap; ie
// IN min heap, root element is smaller than childern, while in max heap its the opposite.


class heap{
    public:
    int arr[100];
    int size = 0;

    heap(){
        arr[0] = -1;
        size = 0;
    }

// the value for the left chld for a root at  n index  can be found by 2n and
//for right child as 2n +1;
//similarly the parent for a child at n or n+1 can be found by n/2 or n+1/2;


    void insert(int data){
        size += 1;
        int index  = size;
        arr[index] = data;

        while(index>1){
            int parent = index/2;

            if( arr[parent]< arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{return;}
        }
    } 

    void printheap(){
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
        
    }

    void deleteinHeap(){
        if(size == 0){
            cout<< "Nothing to delete"<<endl;
        }

        arr[1]  = arr[size];
        size--;

        int i =1;
        while(i< size){
            int leftchild = 2*i;
            int rightchild = 2*i +1;


            if(leftchild <= size && arr[leftchild]> arr[i]){
                if (rightchild < size && arr[rightchild]> arr[i])
                {
                    swap(arr[rightchild],arr[i]);
                    i = rightchild;
                }
                else{
                
                swap(arr[leftchild],arr[i]);
                i = leftchild;}
            }
            else if(rightchild <= size && arr[rightchild]> arr[i]){
                swap(arr[rightchild],arr[i]);
                i = rightchild;
            }
            else{
                return;
            }
        }
    }
};


int main() {

    heap h;
    h.insert(55);
    h.insert(40);
    h.insert(35);
    h.insert(60);
    h.insert(65);
    h.insert(70);
    h.printheap();
    h.deleteinHeap();
    h.printheap();
    return 0;
}