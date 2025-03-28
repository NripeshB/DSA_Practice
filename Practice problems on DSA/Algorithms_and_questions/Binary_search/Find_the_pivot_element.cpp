#include <iostream>
 using namespace std;

int Pivot(int arr[], int size){
    int start = 0; 
    int end = size - 1; 
    int Mid = start + ((end - start)/2) ;
    int Compare = arr[end];

    while (start < end) {
     if(arr[Mid] >= arr[0]){
        start = Mid + 1;

     }

     else {
        end = Mid;
    }
     Mid = start + ((end - start) / 2);
    }
    return start;
        
        
}

int main() {
    
    int Arr1[] = { 7, 8, 9, 1, 2, 3, 4, 5, 6};  
    int Arr2[] = { 7, 8, 9, 10, 12, 3, 4, 5};  
    int Arr3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};  
    int A = Pivot(Arr1, 9);
    int B = Pivot(Arr2, 8);
    int C = Pivot(Arr3, 9);
    cout<<A<<endl<<B<<endl<<C;

    return 0;
}

