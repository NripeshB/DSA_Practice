#include <iostream>

using namespace std;

int Partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotindex = s + count;
    swap(arr[s], arr[pivotindex]);

    int i = s;
    int j = e;

    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotindex;
}

void Quicksort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int part = Partition(arr, s, e);
    Quicksort(arr, s, part - 1);
    Quicksort(arr, part + 1, e);
}

int main()
{
    int arr[] = {2, 3, 5, 2, 6, 8, 7, 10, 9, 4};
    Quicksort(arr, 0, 9);
    for (int i = 0; i <= 9; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}