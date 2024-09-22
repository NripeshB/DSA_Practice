//  https://bit.ly/3DXfsDZ
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Reverse_array(vector<int> &ans)
{
    int e = ans.size() - 1;
    int s = 0;
    while (s <= e)
    {
        swap(ans[s], ans[e]);

        s++;
        e--;
    }
    return ans;
}
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{

    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    vector<int> arr;
    while (i >= 0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[j];
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        arr.push_back(sum);
        i--;
        j--;
    }
    while (i >= 0)
    {

        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        arr.push_back(sum);
        i--;
    }
    while (j >= 0)
    {

        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        arr.push_back(sum);
        j--;
    }
    while (carry != 0)
    {

        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        arr.push_back(sum);
    }
    arr = Reverse_array(arr);
    return arr;
}

int main()
{

    return 0;
}