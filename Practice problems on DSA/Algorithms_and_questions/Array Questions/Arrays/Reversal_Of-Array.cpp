#include <iostream>
#include <vector>

using namespace std;

int TreeHeight(vector<int> &arr, int m, int size)
{
    int s = m + 1;
    int e = arr.size() - 1;
    while (s <= e)
    {
        swap(arr[e], arr[s]);
        s++;
        e--;
    }
    return 0;
}