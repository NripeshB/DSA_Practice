// https://leetcode.com/problems/count-primes/
#include <iostream>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        int prime[n + 1];
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            prime[i] = 1;
        }
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (prime[i] == 1)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == 1)
            {
                cnt++;
            }
        }
        return cnt;
    }
};

// time complexity for this program is
// O(n) = n * log(logn)
// as it can be expressed as n* (1/2 + 1/3 + 1/5 + 1/7 + 1/11 ...)