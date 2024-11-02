#include <iostream>

using namespace std;

int sum(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }
    return arr[0] + sum(arr + 1, size - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ans = sum(arr, 9);
    cout << ans;
    return 0;
}