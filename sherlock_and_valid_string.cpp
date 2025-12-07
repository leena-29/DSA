#include <bits/stdc++.h>
using namespace std;

string isValid(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    unordered_map<int, int> countFreq;
    for (auto &p : freq) countFreq[p.second]++;

    if (countFreq.size() == 1)
        return "YES";

    if (countFreq.size() == 2) {
        auto it = countFreq.begin();
        int f1 = it->first, c1 = it->second;
        ++it;
        int f2 = it->first, c2 = it->second;

        if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1))
            return "YES";

        if ((abs(f1 - f2) == 1) && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)))
            return "YES";
    }

    return "NO";
}

int main() {
    string s;
    cin >> s;
    cout << isValid(s);
    return 0;
}
