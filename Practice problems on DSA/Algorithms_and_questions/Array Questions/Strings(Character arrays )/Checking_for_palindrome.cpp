// https://bit.ly/3E55FvF
// also the same question :https://leetcode.com/problems/valid-palindrome/submissions/1398449604/
#include <iostream>

using namespace std;
bool checkPalindrome(string s)
{

    int start = 0;
    int end = s.length() - 1;
    while (start <= end)
    {

        if (isalnum(s[start]) == false)
        {
            start++;
        }
        else if (isalnum(s[end]) == false)
        {
            end--;
        }

        else if (toupper(s[start++]) != toupper(s[end--]))
        {
            return false;
        }
    }
    return true;
}
int main()
{

    return 0;
}