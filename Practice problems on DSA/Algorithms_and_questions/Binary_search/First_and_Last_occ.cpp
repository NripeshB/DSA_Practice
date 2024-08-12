#include <iostream>
#include <vector>
using namespace std;


int first(vector<int> &arr, int n, int k) {
    int end = n - 1 ;
    int start = 0;
    int Mid = start + ((end - start)/2);
    int place = -1;
    while (start <= end) {
      if (arr[Mid] == k){
          place = Mid;
          end = Mid - 1; 
          
      }

      else if (arr[Mid] > k) {
          end = Mid - 1;
          
      } 
      
      else {
          start = Mid + 1; 
          
      }
      Mid = start + ((end - start)/2);

    }
    return place; 
}


int last(vector<int> &arr, int n, int k) {
    int end = n -1 ;
    int start = 0;
    int Mid = start + ((end - start)/2);
    int place = -1;

    while (start <= end) {
      if (arr[Mid] == k){
          place = Mid;
          start = Mid + 1; 
          
      }

      else if (arr[Mid] > k) {
          end = Mid - 1;
          
      } 
      
      else {
          start = Mid + 1; 
          
      }
      Mid = start + ((end - start)/2);

    }
    return place;
}



pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int, int> p;
    p.first = first(arr, n, k);
    p.second = last(arr, n, k);

    return p;
}


