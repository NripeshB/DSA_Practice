
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& rank, int m, int mid) {
    int totalDishes = 0;

    for (int i = 0; i < rank.size(); i++) {
        int time = 0;
        int dishes = 0;
        int j = 1;
        
        // Calculate the number of dishes this cook can make within the 'mid' time
        while (time + (rank[i] * j) <= mid) {
            time += rank[i] * j;
            dishes++;
            j++;
        }
        
        totalDishes += dishes;
        if (totalDishes >= m) return true;
    }
    
    return true;
}

int minCookTime(vector<int>& rank, int m) {
    int s = 1; // Minimum possible time is 1 minute
    int e = *max_element(rank.begin(), rank.end()) * (m * (m + 1)) / 2;
    int ans = e;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (isPossible(rank, m, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    return ans;
}