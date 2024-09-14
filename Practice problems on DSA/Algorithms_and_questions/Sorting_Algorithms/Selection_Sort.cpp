#include <iostream>

using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
int main()
{
    int arr1[] = {2, 3, 1, 4, 5, 7, 6, 8};
    selectionSort(arr1, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr1[i] << " ";
    }

    return 0;
}