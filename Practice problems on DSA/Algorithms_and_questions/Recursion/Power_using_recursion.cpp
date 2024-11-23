#include <iostream>

using namespace std;
// optimised method for finding the powers for huge powers.
// for finding 2^1000 we would need to run a loop for 1000 times. but with recursion, the same process takes 11
int tothepower(int num, int power)
{
    if (power == 0)
    {
        return 1;
    }
    if (power & 1)
    {
        return num * (tothepower(num, power / 2)) * (tothepower(num, power / 2));
    }
    else
    {
        return (tothepower(num, power / 2)) * (tothepower(num, power / 2));
    }
}

int main()
{
    int ans = tothepower(3, 4);
    cout << ans;
    return 0;
}