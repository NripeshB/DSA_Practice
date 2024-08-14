//This program is quite similar to the book allocation problem.
#include <iostream>
#include <vector>
using namespace std;


bool ispossible(vector<int> &boards, int k, int n, int mid){
    int painters = 1;
    int board = 0;
    for(int i = 0; i < n; i++){

      if (board + boards[i] <= mid) {
        board += boards[i];
      }

      else{
          painters++;
           if(painters > k || boards[i] > mid ){
               return false;
           }
           board = boards[i];
        }
           }
    return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    if(boards.size() < k){
        return -1;
    }
    int e, s, sum, mid, ans;
    ans = -1;
    s = 0;
    sum = 0;
    for(int i = 0 ; i< boards.size(); i ++){
        sum += boards[i];
    }

    e = sum;
    mid = s + ((e-s)/2);

    while(s <= e){
        if(ispossible(boards, k , boards.size(), mid)){
            e = mid -1 ;
            ans = mid;
        }
        else{
            s = mid + 1;
        }
        mid = s + ((e-s)/2);

    }
    return ans;
}

int main() {
    //use any array here and input in findLargestMinDistance()
    return 0;
}