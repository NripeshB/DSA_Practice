// Create a program to swap the alternate numbers in an array

#include <iostream>
using namespace std;

void inputarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "The " << i << " element of the array is: " << endl;
        cin>> arr[i];
    }
}
void printarray(int arr[], int size)
{
    cout << "The array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void swapalt(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        if (i % 2 != 0)
        {
            swap(arr[i], arr[i - 1]);
        }
        else{
            continue;
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int arr[size];
    inputarray(arr, size);
    printarray(arr, size);

    swapalt(arr, size);
    printarray(arr, size);

    return 0;
}