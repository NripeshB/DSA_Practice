//https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
//Below is the solution to the above question.
#include <iostream>
#include <vector>
using namespace std;

int Pivot1(vector<int>& arr, int size){
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
    int Pivot = start;
    return Pivot;
        
        
}

int Solution(vector<int> &arr, int start,int end, int k) {
    int Mid = start + ((end - start) / 2);
    while (start <= end) {
        if (arr[Mid] == k) {
        return Mid;
        break;
         }

        if (arr[Mid] > k) {
            end = Mid - 1;
        }
         
        else
            {
                start = Mid + 1 ;
            }
        
        Mid = start + ((end - start) / 2);
        
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    int A;
    int Pivot = Pivot1(arr, n );
    int end = n - 1;
    int start = 0;
    if (k >= arr[Pivot] && k <= arr[end]) {
        A = Solution(arr, Pivot,end, k);
     }

    else {
        A = Solution(arr, start, Pivot -1, k);
    }
    
    return A;

   
}


int main() {
    //use the code below with putting in values in search function
    //search();
    return 0;
}