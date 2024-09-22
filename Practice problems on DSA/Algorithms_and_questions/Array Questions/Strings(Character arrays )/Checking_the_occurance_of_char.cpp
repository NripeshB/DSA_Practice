#include <iostream>

using namespace std;

int main()
{

    return 0;
}

char highestOccurringChar(char input[])
{
    int length = strlen(input);
    int i = 0;
    int chars[26] = {0};
    while (i < length)
    {
        int number = 0;
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            number = input[i] - 'a';
        }

        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            number = input[i] - 'A';
        }
        chars[number]++;
        i++;
    }

    int maxCount = -1;
    int maxIndex = 0;
    for (int i = 0; i < 26; i++)
    {
        if (chars[i] > maxCount)
        {
            maxCount = chars[i];
            maxIndex = i;
        }
    }
    return 'a' + maxIndex;
}