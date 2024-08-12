//https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
//Below is the solution to the above question
#include <vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int end = n-1;
        int start = 0;
        int Mid = start + ((end - start)/2) ;
        int temp;
        while (start <= end ){
            if (arr[Mid] > arr[Mid + 1] && arr[Mid] > arr[Mid - 1]){
                temp = Mid;
                break;
            }

            if (arr[Mid]> arr[Mid + 1] && arr[Mid] < arr[Mid -1]){
            end = Mid - 1;
            Mid = start + ((end - start)/2) ;}
            
            else{ start = Mid + 1; Mid = start + ((end - start)/2) ;}
            }

        return temp;
    }
};