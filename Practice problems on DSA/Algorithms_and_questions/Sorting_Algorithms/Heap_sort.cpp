#include <iostream>
using namespace std;

//The following function sorts a given array of number using heap
// its time complexit is nlogn


// Heapify function to maintain heap property
//it stores the largest value and compares it from the left and the right child.
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

void HeapSort(int arr[], int i){
    int size = i;

    while(size>1){
        swap(arr[size], arr[1]);

        size--;

        Heapify(arr, size, 1);
    }
    
}
void printheap(int arr[], int size){
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
    }



int main() {
    int arr[8] = {-1, 2,5,2,3,6,7,4};
    //making the array into a max heap first
    for (int i = 7 / 2; i > 0; i--){
        Heapify(arr, 7, i);
    }
    HeapSort(arr, 7);
    printheap(arr, 7);

    return 0;
}