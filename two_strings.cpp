#include <bits/stdc++.h>
using namespace std;

string twoStrings(string s1, string s2) {
    unordered_set<char> letters;

    // Store all characters from s1
    for (char c : s1)
        letters.insert(c);

    // Check if any character of s2 is also in s1
    for (char c : s2) {
        if (letters.count(c))
            return "YES";
    }
    return "NO";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << twoStrings(s1, s2) << endl;
    }
    return 0;
}
