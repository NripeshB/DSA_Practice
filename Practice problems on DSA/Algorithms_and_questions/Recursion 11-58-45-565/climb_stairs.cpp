#include <iostream>

using namespace std;

int climb(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return climb(n - 1) + climb(n - 2);
}

int main()
{
    int a = climb(5);
    int b = climb(3);
    cout << a << endl
         << b << endl;
    return 0;
}