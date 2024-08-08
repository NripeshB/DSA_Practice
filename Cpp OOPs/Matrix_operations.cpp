// This program demonstrates basic matrix operations using classes in C++.
// It includes the creation of 2D matrices, addition, subtraction, and multiplication of matrices.
// The program defines three main classes: Matrix, Matrix_addition, and Matrix_multiplication.
// - Matrix class handles the creation, initialization, and printing of 2D matrices.
// - Matrix_addition class handles the addition and subtraction of two matrices, inheriting from the Matrix class.
// - Matrix_multiplication class handles the multiplication of two matrices, also inheriting from the Matrix class.
// The main function demonstrates these operations by creating multiple matrix objects and performing the respective operations.

#include <iostream>
using namespace std;

class Matrix_multiplication;
class Matrix_addition;
class Matrix
{
protected:
    int x, y;
    // Creating a pointer to a pointer to an int for implementing a 2D array.
    int **arr;
    friend Matrix_addition;
    friend Matrix_multiplication;

public:
    // intializing default values for the private members using a constructor.
    Matrix() : x(0), y(0), arr(nullptr)
    {
    }
    // Creating a destructor for freeing up the dynamically allocated space after using the objects.
    ~Matrix()
    {
        for (int i = 0; i < x; ++i)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }

    void set_xy()
    {
        cout << endl;
        cout << "Enter the number of rows: " << endl;
        cin >> x;
        cout << "Enter the number of columns: " << endl;
        cin >> y;
    }

    // Function overloading, parameterised input.
    void set_xy(int a, int b)
    {
        x = a;
        y = b;
    }

    void Create_A_Matrix()
    {

        // creating an array of x number of pointers (rows)
        arr = new int *[x];
        // pointing each pointer inside that pointer array to point to y number of pointers (columns)
        for (int i = 0; i < x; ++i)
        {
            arr[i] = new int[y];
        }

        // Using the for loops to assign each pointer to a pointer to an integer, hence creating the 2D array
        for (int i = 0; i < x; i++)
        {
            cout << endl;
            for (int j = 0; j < y; j++)
            {
                cout << "Enter the " << "[" << i << "]" << "[" << j << "]" << " element of the matrix: " << endl;
                cin >> arr[i][j];
            }
        }
    }

    // Printing the created array
    void Print_array()
    {
        for (int i = 0; i < x; i++)
        {
            cout << endl;
            for (int j = 0; j < y; j++)
            {
                cout << arr[i][j] << "  ";
            }
        }
    }
};

class Matrix_addition : public Matrix
{

public:
    ~Matrix_addition()
    {
        for (int i = 0; i < x; ++i)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }

    void Create_A_Matrix_Addition(Matrix &a, Matrix &b)
    {

        // creating an array of x number of pointers (rows)
        arr = new int *[x];
        // pointing each pointer inside that pointer array to point to y number of pointers (columns)
        for (int i = 0; i < x; ++i)
        {
            arr[i] = new int[y];
        }

        // Using the for loops to assign each pointer to a pointer to the addition of the corresponding index of two arrays
        for (int i = 0; i < x; i++)
        {
            cout << endl;
            for (int j = 0; j < y; j++)
            {
                arr[i][j] = a.arr[i][j] + b.arr[i][j];
            }
        }
    }

    void Create_A_Matrix_Subtraction(Matrix &a, Matrix &b)
    {

        // creating an array of x number of pointers (rows)
        arr = new int *[x];
        // pointing each pointer inside that pointer array to point to y number of pointers (columns)
        for (int i = 0; i < x; ++i)
        {
            arr[i] = new int[y];
        }

        // Using the for loops to assign each pointer to a pointer to the addition of the corresponding index of two arrays
        for (int i = 0; i < x; i++)
        {
            cout << endl;
            for (int j = 0; j < y; j++)
            {
                arr[i][j] = a.arr[i][j] - b.arr[i][j];
            }
        }
    }
    int adding(Matrix &a, Matrix &b)
    {
        if (a.x == b.x && a.y == b.y)
        {

            cout << endl
                 << "The addition of the given matracies is: " << endl;
            set_xy(a.x, a.y);
            Create_A_Matrix_Addition(a, b);
            Print_array();
        }

        else
        {
            cout << "Enter two matracies with same rows and colums for addition or subtraction. " << endl;
        }
    }

    int subtracting(Matrix &a, Matrix &b)
    {
        if (a.x == b.x && a.y == b.y)
        {

            cout << endl
                 << "The subtraction of the given matracies is: " << endl;
            set_xy(a.x, a.y);
            Create_A_Matrix_Subtraction(a, b);
            Print_array();
        }

        else
        {
            cout << "Enter two matracies with same rows and colums for addition or subtraction. " << endl;
        }
    }
};

class Matrix_multiplication : public Matrix
{
public:
    void Create_A_Matrix_Multiplication(Matrix &a, Matrix &b)
    {
        set_xy(a.x, b.y);

        // creating an array of x number of pointers (rows)
        arr = new int *[x];
        // pointing each pointer inside that pointer array to point to y number of pointers (columns)
        for (int i = 0; i < x; ++i)
        {
            arr[i] = new int[y];
        }

        // This nested loop executes matrix multiplication.
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                arr[i][j] = 0;
                for (int k = 0; k < a.y; k++)
                {
                    arr[i][j] += a.arr[i][k] * b.arr[k][j];
                }
            }
        }
    }

    void multiplying(Matrix &a, Matrix &b)
    {
        if (a.y == b.x)
        {
            cout << endl
                 << "The multiplication of the given matrices is: " << endl;
            Create_A_Matrix_Multiplication(a, b);
            Print_array();
        }
        else
        {
            cout << "Enter two matrices where the number of columns of the first matrix is equal to the number of rows of the second matrix for multiplication. " << endl;
        }
    }
};

int main()
{
    cout << endl
         << "A 2D matrix has 2 dimentions, represented with X*Y." << endl
         << "Where X represents number of rows,and y, the number of columns" << endl;
    Matrix a;
    Matrix b;
    Matrix x;
    Matrix y;
    a.set_xy();
    a.Create_A_Matrix();
    a.Print_array();
    b.set_xy();
    b.Create_A_Matrix();
    b.Print_array();
    Matrix_addition c;
    c.adding(a, b);
    c.subtracting(a, b);
    c.subtracting(b, a);
    Matrix_multiplication d;
    x.set_xy();
    x.Create_A_Matrix();
    x.Print_array();
    y.set_xy();
    y.Create_A_Matrix();
    y.Print_array();
    d.multiplying(x, y);

    return 0;
}