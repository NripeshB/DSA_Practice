#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int size = nums.size();
            if (nums[(i + 1) % size] < nums[i])
            {
                count++;
            }
            else if (nums[(i + 1) % size] == nums[i])
            {
                temp++;
            }
        }
        if ((count == 1 && temp >= 0) || temp == nums.size())
        {
            return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}