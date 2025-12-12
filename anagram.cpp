#include <bits/stdc++.h>
using namespace std;

int anagram(string s) {
    int n = s.length();
    if (n % 2 != 0) return -1;  // cannot split equally

    string s1 = s.substr(0, n / 2);
    string s2 = s.substr(n / 2);

    vector<int> freq(26, 0);

    for (char c : s1) freq[c - 'a']++;
    for (char c : s2) freq[c - 'a']--;

    int changes = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0)
            changes += freq[i];
    }
    return changes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << anagram(s) << "\n";
    }

    return 0;
}
