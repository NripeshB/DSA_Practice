#include <iostream>
using namespace std;


int main() {
    return 0;
}

//this is the top down approach
//recursion + memoisation
class Solution {
public:

    int solve(vector<int>& days, vector<int>& costs, int i, vector<int>&dp){

        if(i >= days.size()){
            return 0 ;
        }

        if( dp[i]!= -1){
            return dp[i];
        }

        // for one days ticket

        int op1 = costs[0] + solve(days, costs, i+1, dp);

        //for seven days ticket

        int index ;

        //this loop is just for incrementing index to the apt value

        for( index = i; index < days.size() && days[index]< days[i]+7; index++)
        continue;
        
        int op2 = costs[1] + solve( days, costs, index,dp);


        int index1 ;

        //this loop is just for incrementing index to the apt value

        for( index1 = i; index1 < days.size() && days[index1]< days[i]+30; index1++);
        
        int op3 = costs[2] + solve( days, costs, index1, dp);

        dp[i] = min( op1 , min( op2, op3));
        return dp[i];

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(), -1);
        int ans = solve(days, costs, 0, dp);
        return ans;
    }
};

//tabulation method
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(), INT_MAX);
        dp[days.size()] = 0;
        int op1;
        int op2;
        int op3;

        for(int i = days.size()-1; i > 0 ; i++){
        //for one day
        op1 = costs[0] + dp[i+1];

        int index ;

        //this loop is just for incrementing index to the apt value

        for( index = i; index < days.size() && days[index]< days[i]+7; index++)
        continue;
        
         op2 = costs[1] + dp[index];


       

        //this loop is just for incrementing index to the apt value
         int index1 ;

        for( index1 = i; index1 < days.size() && days[index1]< days[i]+30; index1++);

        op3 = costs[2] + dp[index1];

        dp[i] = min(op1, min(op2,op3));

        }

        return dp[days.size()-1];
    }
};