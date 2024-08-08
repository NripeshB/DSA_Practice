/*
    Determinant Calculator

    Description:
    This program calculates the determinant of a square matrix of user-defined size. 
    The user is prompted to enter the size of the matrix and the matrix elements. 
    The program supports matrices of any size, but it's primarily demonstrated with 
    \(4 \times 4\) matrices. 

    Features:
    - Dynamic memory allocation for creating and managing a 2D matrix.
    - Recursive algorithm for computing the determinant of the matrix.
    - Memory cleanup to prevent memory leaks.
    
    Usage:
    1. Run the program.
    2. Enter the size of the matrix when prompted (e.g., 4 for a \(4 \times 4\) matrix).
    3. Enter the elements of the matrix row by row.
    4. The program will output the determinant of the matrix.

    This program is a practical implementation of determinant calculation, utilizing 
    recursion and dynamic memory management in C++.

*/

#include <iostream>
using namespace std;

class Determinant
{
public:
    int x, y;
    int **arr;

    
    Determinant() : x(0), y(0), arr(nullptr)
    {
    }
    
    ~Determinant()
    {
        for (int i = 0; i < x; ++i)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }

    void set_xy()
    {
        int a;
        cout << "What size of determinant do you want to enter? : " << endl;
        cin >> a;
        x = a, y = a;
    }

    int **Create_A_Determinant()
    {

        
        arr = new int *[x];
        
        for (int i = 0; i < x; ++i)
        {
            arr[i] = new int[y];
        }

        
        for (int i = 0; i < x; i++)
        {
            cout << endl;
            for (int j = 0; j < y; j++)
            {
                cout << "Enter the " << "[" << i << "]" << "[" << j << "]" << " element of the determinant: " << endl;
                cin >> arr[i][j];
            }
        }

        return arr;
    }

    double solve_Determinant(int **array, int size)
    {
        if (size == 1)
        {
            return array[0][0];
        }
        if (size == 2)
        {
            return (array[0][0] * array[1][1] - array[1][0] * array[0][1]);
        }

        int **submatrix;
        submatrix = new int *[size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            submatrix[i] = new int[size - 1];
        }

        double det = 0;

        for (int i = 0; i < size; i++)
        {
            double temp;
            temp = array[0][i];
            int n1 = 0;
            for (int j = 1; j < size; j++)
            {

                int n2 = 0;
                for (int k = 0; k < size; k++)
                {
                    if (k == i)
                        continue;
                    submatrix[n1][n2] = array[j][k];
                    n2++;
                }
                n1++;
            }

            det += (i % 2 == 0 ? 1 : -1) * temp * solve_Determinant(submatrix, size - 1);
        }
        
        for (int i = 0; i < size - 1; ++i)
        {
            delete[] submatrix[i];
        }
        delete[] submatrix;

        return det;
    }

    void Print_Det()
    {
        {
            for (int i = 0; i < x; i++)
            {
                cout << endl;
                for (int j = 0; j < y; j++)
                {
                    cout << arr[i][j] << "  ";
                }
            }
            cout << endl
                 << endl;
        }
    }
};

int main()
{
    Determinant D;
    double Ans;
    int **Array;
    D.set_xy();
    Array = D.Create_A_Determinant();
    D.Print_Det();
    Ans = D.solve_Determinant(Array, D.x);
    cout << Ans << endl;
    return 0;
}