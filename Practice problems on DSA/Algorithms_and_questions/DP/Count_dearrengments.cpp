//https://www.naukri.com/code360/problems/count-derangements_873861?leftPanelTabValue=SUBMISSION
#include <vector>
#include <iostream>
using namespace std;


int main() {
    return 0;
}

//this is the recursive + memoisation (top down) approach
#define MOD 1000000007
long long int solve(int n, vector<long long int> &dp) {
    if(n == 0|| n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] =( (n-1)* ((solve(n-1,dp)%MOD) + (solve(n-2, dp)%MOD)))%MOD;

    return dp[n];
}

long long int countDerangements(int n) {
    vector< long long int> dp(n+1, -1);
    long long int ans = solve(n, dp);
    return ans;
}

//this is the tabulation approach (bottoms up)

long long int countDerangements(int n) {
    vector< long long int> dp(n+1, -1);
    dp[0] = dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i-1)*( ( dp[i-1] )%MOD + ( dp[i-2] )%MOD) %MOD;
    }

    
    return dp[n] ;
}



//This is with space optimisation
long long int countDerangements(int n) {
    if(n ==0 || n == 1){
        return 0;
    }
    if(n ==2){
        return 1;
    }
    long long int p1 = 1;
    long long int p2 = 0; 
    long long int curr = 0;
    for (int i = 3; i <= n; i++)
    {
        curr = (i-1)%MOD *( ( p1)%MOD + ( p2 )%MOD) %MOD;
        p2 = p1;
        p1 = curr;
    }

    
    return curr ;
}