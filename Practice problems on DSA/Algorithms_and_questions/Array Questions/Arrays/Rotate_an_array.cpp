#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int arr[nums.size()];
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = (i + k) % nums.size();
            arr[temp] = nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = arr[i];
        }
    }
};

int main()
{

    return 0;
}