#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool IsEqual(int a[26], int b[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
            {
                return 0;
            }
        }
        return 1;
    }

    bool checkInclusion(string s1, string s2)
    {
        int check1[26] = {0};
        int check2[26] = {0};

        // Initialize the frequency count for s1
        for (int i = 0; i < s1.length(); i++)
        {
            int a = s1[i] - 'a';
            check1[a]++;
        }

        int window = s1.length();
        int i = 0;

        // Initialize the first window for s2
        while (i < window && i < s2.length())
        {
            int a = s2[i] - 'a';
            check2[a]++;
            i++;
        }

        // Check the first window
        if (IsEqual(check1, check2))
        {
            return 1;
        }

        // Slide the window over s2
        while (i < s2.length())
        {
            char newchar = s2[i];
            int index = newchar - 'a';
            check2[index]++;

            char oldchar = s2[i - window];
            int index1 = oldchar - 'a';
            check2[index1]--;

            if (IsEqual(check1, check2))
            {
                return 1;
            }
            i++;
        }

        return 0;
    }
};
