#include <iostream>

using namespace std;

bool issorted(int arr[], int size)
{
    if (size == 1 || size == 0)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remained = issorted(arr + 1, size - 1);
        return remained;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 9, 7, 8, 9};
    bool val = issorted(arr, 9);
    cout << val;
    return 0;
}