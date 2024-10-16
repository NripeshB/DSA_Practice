#include <iostream>

using namespace std;

class Solution
{
public:
    int Gcd(long long a, long long b)
    {
        if (a == 0)
        {
            return b;
        }

        else if (b == 0)
        {
            return a;
        }

        while (a != b)
        {
            if (a > b)
            {
                a -= b;
            }
            else if (b > a)
            {
                b -= a;
            }
        }
    }

    int findGCD(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 >= nums.size())
            {
                return nums[i + 1];
            }

            else
            {
                nums[i + 1] = Gcd(nums[i], nums[i + 1]);
            }
        }
    }
};