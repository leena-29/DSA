#include <bits/stdc++.h>
using namespace std;

// Z-Algorithm to calculate string similarity efficiently
long long stringSimilarity(const string &s) {
    int n = s.size();
    vector<int> Z(n, 0);
    int L = 0, R = 0;
    long long sum = n; // Entire string matches with itself

    for (int i = 1; i < n; i++) {
        if (i <= R)
            Z[i] = min(R - i + 1, Z[i - L]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            Z[i]++;
        if (i + Z[i] - 1 > R)
            L = i, R = i + Z[i] - 1;
        sum += Z[i];
    }

    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << stringSimilarity(s) << endl;
    }
    return 0;
}
