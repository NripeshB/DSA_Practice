#include <iostream>

using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int COL = 0; COL < mCols; COL++)
    {
        if (COL % 2 == 0)
        {
            for (int i = 0; i <= nRows - 1; i++)
            {
                ans.push_back(arr[i][COL]);
            }
        }
        else
        {
            for (int i = nRows - 1; i >= 0; i--)
            {
                ans.push_back(arr[i][COL]);
            }
        }
    }

    return ans;
}