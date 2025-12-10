#include <bits/stdc++.h>
using namespace std;

string gameOfThrones(string s) {
    vector<int> freq(26, 0);

    // Count frequency of each character
    for (char c : s)
        freq[c - 'a']++;

    int oddCount = 0;

    // Count how many characters have odd frequency
    for (int f : freq) {
        if (f % 2 != 0)
            oddCount++;
    }

    // For palindrome:
    // → At most one character can have an odd count
    if (oddCount > 1)
        return "NO";
    else
        return "YES";
}

int main() {
    string s;
    cin >> s;
    cout << gameOfThrones(s);
    return 0;
}
