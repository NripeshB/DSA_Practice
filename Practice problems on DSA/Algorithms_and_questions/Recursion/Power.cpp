#include <iostream>

using namespace std;

int power(int n, int x)
{
    if (n == 0)
    {
        return 1;
    }
    return x * power(n - 1, x);
}

int main()
{
    int a = power(3, 3);
    int b = power(3, 2);
    int c = power(3, 4);
    int d = power(3, 5);
    cout << a << endl
         << b << endl
         << c << endl
         << d << endl;

    return 0;
}