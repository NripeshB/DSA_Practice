#include <iostream>
#include <vector>

using namespace std;
void possible_permutations(string s, int i, vector<string> &answer)
{

    if (i >= s.length())
    {
        answer.push_back(s);
        return;
    }
    for (int j = i; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        possible_permutations(s, i + 1, answer);
        swap(s[i], s[j]);
    }
}

int main()
{
    string s = "abcef";
    vector<string> answer;
    possible_permutations(s, 0, answer);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}