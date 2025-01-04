//https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


//This approach uses a min heap of k elements 
// and pushes in next elements in the mim heap iff the top is greater than that element, thus ending up with
//kth largest element on the top.

//TC = n^2logk and SC is k;  hence is more space efficient
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> p;

    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;

        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];

            // Push the current sum into the priority queue
            p.push(sum);

            // If the size exceeds k, remove the smallest element
            if (p.size() > k) {
                p.pop();
            }
        }
    }

    // The top element of the priority queue is the k-th largest sum
    return p.top();
}





/// this approach uses sorting algo and saves the result in a vector and returns the kth element
//it has time complexity of n^2logn and space complexity of n^2

int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sumans;

	for(int i = 0; i< arr.size(); i++){
		int sum = 0;                                // TC = n

		for(int j = i; j< arr.size(); j++){
			sum+= arr[j];                           //TC = n
			sumans.push_back(sum);                  //TC = logk
		}
	}

	sort(sumans.begin(), sumans.end());

	return sumans[sumans.size()-k];
}

int main() {
    return 0;
}