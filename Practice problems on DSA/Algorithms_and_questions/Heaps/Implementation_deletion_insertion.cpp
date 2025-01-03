#include <iostream>
using namespace std;

void Heapify(int arr[], int n, int i);

class heap{
    public:
    int arr[100];
    int size = 0;

    heap(){
        arr[0] = -1;
        size = 0;
    }

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
        
        // After deleting the element, place the last swapped element correctly in the heap
        Heapify(arr, size, 1);
    }
};

// Heapify function to maintain heap property
void Heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if (left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        Heapify(arr, n, largest);
    }
}

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
    h.insert(65);
    h.printheap();

    int arr1[7] = {0, 1, 3, 4, 6, 7, 8}; // 1-based index array
    int n = 6;
    
    // Build heap (heapify from the last non-leaf node)
    //Leaf nodes in a cbt is always the indexes between n/2 and n
    //where n is the total no. of nodes in an heap.
    for (int i = n / 2; i > 0; i--){
        Heapify(arr1, n, i);
    }

    // Printing the heap after heapify
    for (int i = 1; i <= n; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}
