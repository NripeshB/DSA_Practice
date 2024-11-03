#include <iostream>

using namespace std;

void Merge(int arr[], int s, int e, int mid)
{
    int lis1[mid - s + 1];
    int lis2[e - mid];

    for (int i = 0; i < mid - s + 1; i++)
    {
        lis1[i] = arr[s + i];
    }

    for (int i = 0; i < e - mid; i++)
    {
        lis2[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = s;

    while (i < mid - s + 1 && j < e - mid)
    {
        if (lis1[i] >= lis2[j])
        {
            arr[k++] = lis1[i++];
        }
        else if (lis1[i] < lis2[j])
        {
            arr[k++] = lis2[j++];
        }
    }

    while (i < mid - s + 1)
    {
        arr[k++] = lis1[i++];
    }

    while (j < e - mid)
    {
        arr[k++] = lis2[j++];
    }
}

void Mergesort(int arr[], int s, int e)
{

    int mid = s + ((e - s) / 2);

    if (s >= e)
    {
        return;
    }

    Mergesort(arr, s, mid);
    Mergesort(arr, mid + 1, e);
    Merge(arr, s, e, mid);
}

int main()
{
    int arr[] = {2, 3, 5, 2, 6, 8, 7, 10, 9, 4};
    Mergesort(arr, 0, 9);
    for (int i = 0; i <= 9; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}