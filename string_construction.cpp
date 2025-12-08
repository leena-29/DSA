#include <bits/stdc++.h>
using namespace std;

int stringConstruction(string s) {
    unordered_set<char> unique_chars(s.begin(), s.end());
    return unique_chars.size();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << stringConstruction(s) << endl;
    }
    return 0;
}
