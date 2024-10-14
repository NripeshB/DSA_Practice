// https://leetcode.com/problems/count-primes/
#include <iostream>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> prime(n + 1, true);
        int count = 0;
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                count++;
                for (int j = 2 * i; j < n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        return count;
    }
};

// time complexity for this program is
// O(n) = n * log(logn)
// as it can be expressed as n* (1/2 + 1/3 + 1/5 + 1/7 + 1/11 ...)