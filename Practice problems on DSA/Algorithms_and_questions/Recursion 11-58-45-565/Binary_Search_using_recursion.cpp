#include <iostream>

using namespace std;

bool BS(int arr[], int s, int e, int key)
{
    int mid = s + ((e - s) / 2);
    bool ans;

    if (e <= s)
    {
        return false;
    }
    if (arr[mid] == key)
    {
        return true;
    }
    else if (arr[mid] > key)
    {
        e = mid - 1;
        ans = BS(arr, s, e, key);
    }
    else if (arr[mid] < key)
    {
        s = mid + 1;
        ans = BS(arr, s, e, key);
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool ans = BS(arr, 0, 8, 7);
    cout << ans;
    return 0;
}