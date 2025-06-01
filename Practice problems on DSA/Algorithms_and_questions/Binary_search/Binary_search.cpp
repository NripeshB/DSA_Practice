// The code below implements binary search.
// It only works on monotonous data sets. Here it works only with ascending ordered arrays.

#include <iostream>
using namespace std;

int Binary_Search(int arr[], int size, int Key)
{ 
    int end = size - 1, start = 0;
    int Mid = start + ((end - start) / 2);
    // Below also works but for the integers with values of order 2^31 it misbehaves
    // int Mid = (end + start)/2;

    while (start <= end)
    {
        int Mid = start + ((end - start) / 2);
        //  int Mid = (end + start)/2;

        if (arr[Mid] == Key)
        {
            return Mid;
        }

        if (arr[Mid] > Key)
        {
            end = Mid - 1;
        }
        else
        {
            start = Mid + 1;
        }
    }

    return -1;
}

int main()
{
    int EvenArr[] = {4, 7, 12, 16, 20, 22, 48, 77};
    int OddArr[] = {4, 7, 12, 16, 20, 22, 48};

    int A = Binary_Search(EvenArr, 8, 77);
    int B = Binary_Search(OddArr, 7, 22);
    int C = Binary_Search(OddArr, 7, 45);
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
    return 0;
}