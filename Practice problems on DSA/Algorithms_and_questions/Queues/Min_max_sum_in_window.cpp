//https://www.naukri.com/code360/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTabValue=SUBMISSION
#include <iostream>
using namespace std;


long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	deque<int> maxindex;
	deque<int> minindex;

	long long sum = 0;
	int mini =  0;
	int maxi = 0;
	for(int i=0; i<k;i++){
		while (!maxindex.empty() && nums[maxindex.back()] <= nums[i]) {
            maxindex.pop_back();
        }
        maxindex.push_back(i);

        // Maintain increasing order in minindex
        while (!minindex.empty() && nums[minindex.back()] >= nums[i]) {
            minindex.pop_back();
        }
        minindex.push_back(i);

	}
    sum += nums[maxindex.front()] + nums[minindex.front()];


	for(int i = k; i<n; i++){
		
		while(!maxindex.empty() &&maxindex.front() <= i-k){
			maxindex.pop_front();
		}
		
		while(!minindex.empty() &&minindex.front() <= i-k){
			minindex.pop_front();
		}
		while(!maxindex.empty() &&nums[maxindex.back()] <= nums[i]){
			maxindex.pop_back();
		}
		maxindex.push_back(i);
		while(!minindex.empty() && nums[minindex.back()] >= nums[i]){
			minindex.pop_back();
		}
		minindex.push_back(i);

        
		sum += nums[maxindex.front()] + nums[minindex.front()];

        }
		return sum;
		
}


int main() {
    return 0;
}