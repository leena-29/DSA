#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    unordered_set<string> seen;
    vector<int> ans;
    string prefix;

    for (int i = 0; i < n; i++) {
        prefix += s[i];
        seen.clear();

        for (int start = 0; start <= i; start++) {
            string sub = prefix.substr(start, i - start + 1);

            // Build pattern for pseudo-isomorphic comparison
            unordered_map<char, int> mp;
            string pattern;
            int next_id = 0;
            for (char c : sub) {
                if (mp.find(c) == mp.end()) mp[c] = next_id++;
                pattern.push_back('a' + mp[c]);
            }

            seen.insert(pattern);
        }

        ans.push_back(seen.size());
    }

    for (int x : ans) cout << x << "\n";
    return 0;
}
