#include <iostream>

using namespace std;

//works on the mathematical principle that |num1 - num2| repeat it till num1 = num2, and return num1 or num2 obv.
// example 10 and 2. 10 -2 = 8; 8-2 = 6; 6 -2 = 4; 4-2 = 2; ans is 2. 36 and 17 . 36 -17 = 19; 19 -17 = 2 ; 17 -2 ... leads to 1 as answer,

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