//https://leetcode.com/problems/two-sum/
#include <iostream>
using namespace std;


int main() {
    return 0;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for( int i= 0; i< nums.size(); i++){
            auto j = hashmap.find(target - nums[i]);
            if( j != hashmap.end() ){
                return {i, j->second};
            }
            hashmap[nums[i]] = i;

        }

        return {};
    }
};