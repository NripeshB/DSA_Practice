//https://www.naukri.com/code360/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <iostream>
#include <limits.h>
using namespace std;


int main() {
    return 0;
}

//using top down approach

int solve(int n, int x, int y, int z, vector<int>dp){
	if(n == 0){
		dp[n] = 0 ;
		return dp[n];
	}

	if(n<0){
		return INT_MIN;
	}

	if(dp[n] != -1){
		return dp[n];
	}
	
	int a = solve(n-x, x,  y, z, dp) + 1 ;
	int b = solve(n-y, x,  y, z, dp) + 1 ;
	int c = solve(n-z, x,  y, z, dp) + 1 ;

	dp[n] = max(a,max(b,c));
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, -1);
	int ans =  solve(n, x, y ,z, dp);
	if(ans<0){
		return 0;
	}
	else{
		return ans;
	}
}

//using bottom's up approach


#include <limits.h>
int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, INT_MIN);
	dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
      if(i-x>=0 && dp[i-x] != -1)
      dp[i] = max(dp[i], dp[i-x] + 1) ;

      if(i-y>=0 && dp[i-y] != -1)
      dp[i] = max(dp[i], dp[i-y] + 1) ;

      if(i-z>=0 && dp[i-z] != -1)
      dp[i] = max(dp[i], dp[i-z] + 1) ;
    }

    if(dp[n] < 0){
        return 0;
    }

    else{
        return dp[n];
    }
    
}