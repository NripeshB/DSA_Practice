#include <iostream>

using namespace std;

int modularExponentiation(int x, int n, int m)
{
    int res = 1;
    x = x % m; // Handle case when x is greater than m

    while (n > 0)
    {
        if (n & 1)
        {
            res = (1LL * res * (x) % m) % m;
        }
        x = 1LL * (x % m) * (x % m) % m; // Ensure modular reduction
        n >>= 1;
    }
    return res;
}
