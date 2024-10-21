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

inline int Inlinefunc(int &a, int &b)
{ // inline function replaces the function statment directly in the lines of code
    // int& is a method to pass the variables directly and avoid creating a copy of them while passing through a function.
    return (a > b) ? a : b; // This is a statement for writing the if else statement in one line.
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

    int a, b;
    cin >> a;
    cin >> b;
    int Ans = Inlinefunc(a, b);
    cout << Ans;

    return 0;
}