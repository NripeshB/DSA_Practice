#include <iostream>

using namespace std;

void swaps(string &s, int i, int j)
{

    if (i > j)
    {
        return;
    }
    swap(s[i], s[j]);
    i++;
    j--;
    swaps(s, i, j);
}

int main()
{
    string s = "Nripesh";
    swaps(s, 0, s.length() - 1);
    cout << s;
    return 0;
}