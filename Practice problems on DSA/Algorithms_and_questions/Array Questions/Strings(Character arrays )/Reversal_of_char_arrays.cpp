
// https://leetcode.com/problems/reverse-string/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    void reverseString(vector<char> &s)
    {
        int start = 0, e = s.size() - 1;
        while (start <= e)
        {
            swap(s[start++], s[e--]);
        }
    }
};

int main()
{

    return 0;
}