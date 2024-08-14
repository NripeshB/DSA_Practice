#include <iostream>
#include <vector>
using namespace std;

bool ispossible(vector<int> &arr, int M, int mid, int size)
{

    int check = 0;

    for (int i = 0; i < size; i++)
    {
        if ((arr[i] - mid) > 0)
        {

            check += (arr[i] - mid);
        }
    }

    if (check >= M)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int TreeHeight(vector<int> &arr, int M, int size)
{
    int s = 0;
    int ans = -1;
    int maxi = -1;
    for (int i = 0; i < size; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    int e = maxi;
    int mid = s + ((e - s) / 2);
    while (s <= e)
    {
        if (ispossible(arr, M, mid, size))
        {
            s = mid + 1;
            ans = mid;
        }

        else
        {
            e = mid - 1;
        }
        mid = s + ((e - s) / 2);
    }
    return ans;
}

int main()
{
    int t, M;
    vector<int> arr;
    cout << "Enter the number of trees in the forest and the amount of wood reqired: " << endl;
    cin >> t >> M;
    arr.resize(t);
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }

    int A = TreeHeight(arr, M, t);
    cout << A << endl;
    return 0;
}