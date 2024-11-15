#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void Rat(vector<vector<int>> &arr, int n, vector<string> &answer, string path, int i, int j)
    {
        if (i == n - 1 && j == n - 1)
        {
            answer.push_back(path);
            return;
        }

        arr[i][j] = 0;
        if (i + 1 <= n - 1 && arr[i + 1][j] != 0)
        {

            Rat(arr, n, answer, path + "D", i + 1, j);
        }
        if (i - 1 >= 0 && arr[i - 1][j] != 0)
        {

            Rat(arr, n, answer, path + "U", i - 1, j);
        }
        if (j + 1 <= n - 1 && arr[i][j + 1] != 0)
        {

            Rat(arr, n, answer, path + "R", i, j + 1);
        }
        if (j - 1 >= 0 && arr[i][j - 1] != 0)
        {

            Rat(arr, n, answer, path + "L", i, j - 1);
        }
        arr[i][j] = 1;
    };

public:
    vector<string> findPath(vector<vector<int>> &arr)
    {
        int n;
        n = arr[0].size();
        vector<string> answer;
        if (arr[0][0] == 0)
        {
            return {"-1"};
        }

        string path = "";
        Rat(arr, n, answer, path, 0, 0);
        return answer;
    }
};

int main()
{

    return 0;
}
