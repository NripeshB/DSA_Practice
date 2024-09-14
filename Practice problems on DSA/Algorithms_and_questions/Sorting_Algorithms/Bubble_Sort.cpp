#include <iostream>
//  https://bit.ly/3pvCTz9
using namespace std;

void Bubble_Sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    cout << "Array Elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arri[] = {2, 44, 5, 3, 44, 2, 67, 898};
    Bubble_Sort(arri, (sizeof(arri) / sizeof(arri[1])));
    return 0;
}