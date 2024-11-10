// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <iostream>

using namespace std;

class Solution
{

    void Letter_resolution(vector<string> &ans, vector<string> keypad, string digits, int i, string object)
    {
        if (i >= digits.length())
        {
            ans.push_back(object);
            return;
        }

        int key = digits[i] - '0';
        string iterator = keypad[key];
        for (int j = 0; j < iterator.length(); j++)
        {

            Letter_resolution(ans, keypad, digits, i + 1, object + iterator[j]);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
        {
            vector<string> a = {};
            return a;
        }

        vector<string> keypad;
        keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        Letter_resolution(ans, keypad, digits, 0, "");
        return ans;
    }
};

int main()
{

    return 0;
}
