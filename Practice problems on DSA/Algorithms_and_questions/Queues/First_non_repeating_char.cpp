#include <iostream>
using namespace std;

string FirstNonRepeating(string &s) {
    int alphabets[26] = {0}; // To store the frequency of each character
    queue<char> q;          // Queue to track potential non-repeating characters
    string A = "";          // Resultant string

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        alphabets[ch - 'a']++; // Increment frequency of the character

        // Add the character to the queue
        q.push(ch);

        // Check for the first non-repeating character
        while (!q.empty() && alphabets[q.front() - 'a'] > 1) {
            q.pop(); // Remove characters that are no longer non-repeating
        }

        // Append the first non-repeating character or '#' if none exists
        if (!q.empty()) {
            A += q.front();
        } else {
            A += '#';
        }
    }

    return A;
}


int main() {
    return 0;
}