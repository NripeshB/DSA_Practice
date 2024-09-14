#include <iostream>
// https://bit.ly/3EstWN7
using namespace std;

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int check = arr[j + 1];
        while (j >= 0 && arr[j] > check)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = check;
    }
}

int main()
{

    return 0;
}