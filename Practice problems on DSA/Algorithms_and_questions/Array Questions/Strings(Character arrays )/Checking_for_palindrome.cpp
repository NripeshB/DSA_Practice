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