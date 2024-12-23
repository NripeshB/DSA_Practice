//https://leetcode.com/problems/maximal-rectangle/
#include <iostream>
using namespace std;

class Solution {
private:
void next(vector<int>&next , vector<int>histogram, int n){
    stack<int> S;
    S.push(-1);
    for(int i = n-1 ; i >= 0; i--){
        int a = histogram[i];
        while(S.top() != -1 && histogram[i]<=histogram[S.top()]){
            S.pop();
        }
        next[i] = (S.top() == -1) ? n : S.top();  
        S.push(i); 
    }

}
void previous(vector<int>&p , vector<int>histogram, int n){
    stack<int> S;
    S.push(-1);
    for(int i = 0 ; i < n; i++){
        int a = histogram[i];
        while(S.top() != -1 && histogram[i]<=histogram[S.top()]){
            S.pop();
        }
        p[i] =S.top();
        S.push(i); 
    }

}

int maxAreainHistogram(vector<int> histogram, int row){

    vector<int> n(row, -1);
    vector<int> p(row, -1);

    next(n, histogram , row);
    previous(p, histogram, row );
    int range = 0;
    int ans = -1;
    for(int i = 0; i<row; i++){
        int Next = n[i];
        int Prev = p[i];

        

        range = Next - Prev - 1;
        ans = max(ans, (range)*(histogram[i]));
            
        }
        return ans;
    }



public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<int> histogram(column, 0); 
        if(column == 0){
            return 0;
        }



        int maxRectangleArea = 0;
        for(int i = 0; i<row; i++){
            for(int j = 0; j<column; j++){
                histogram[j] = (matrix[i][j] == '1') ? histogram[j] + 1 : 0;


            }
            maxRectangleArea = max(maxRectangleArea, maxAreainHistogram(histogram, column));
        }
        return maxRectangleArea;
    }
 
};

int main() {
    return 0;
}