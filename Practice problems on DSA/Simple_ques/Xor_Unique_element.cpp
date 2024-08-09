// Problem statement
// You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].

// Now, in the given array/list, 'M' numbers are present twice and one number is present only once.

// You need to find and return that number which is unique in the array/list.

//  Note:
// Unique element is always present in the array/list according to the given condition.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^3
// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 2 3 1 6 3 6 2
// Sample Output 1:
// 1

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

int swapalt(int arr[], int size)
{

    int ans = 0;
    

    for (int i = 0; i < size; i++)
    {
       ans = ans^arr[i];
       
    }

    return ans;
    
}

int main()
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int arr[size];
    inputarray(arr, size);
    printarray(arr, size);

    int a = swapalt(arr, size);
    cout<<"The unique element is: "<< endl<<a <<endl;

    return 0;
}