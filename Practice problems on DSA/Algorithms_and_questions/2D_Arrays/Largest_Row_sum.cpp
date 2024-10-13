#include <iostream>
using namespace std;

int Counter(int arr[][4], int row)
{
    int largest = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += arr[i][j];
        }
        if (largest < sum)
        {
            largest = sum;
        }
    }
    return largest;
}

int main()
{
    int arr[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    int Integer = Counter(arr, 3);
    cout << Integer;

    return 0;
}