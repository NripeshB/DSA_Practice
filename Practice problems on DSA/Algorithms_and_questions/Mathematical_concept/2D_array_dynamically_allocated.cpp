#include <iostream>

using namespace std;

void free_memory(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            delete[] arr[j];
        }
    }

    delete[] arr;
}

int main()
{
    int n;
    int m;
    cout << "enter the first number: " << endl;
    cin >> n;
    cout << "enter the second number: " << endl;
    cin >> m;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter the " << i << j << "element of the 2D array." << endl;
            cin >> arr[i][j];
        }
    }
    free_memory(arr, n, m);

    return 0;
}