#include <bits/stdc++.h>
using namespace std;

// Function to count number of islands created by substring 'sub' in string 's'
int countIslands(const string &s, const string &sub) {
    int n = s.size(), m = sub.size();
    vector<int> marked(n, 0);

    // Mark all positions that belong to any occurrence of 'sub'
    for (int i = 0; i + m <= n; i++) {
        if (s.compare(i, m, sub) == 0) {
            for (int j = i; j < i + m; j++)
                marked[j] = 1;
        }
    }

    // Count contiguous marked regions (islands)
    int islands = 0;
    for (int i = 0; i < n; i++) {
        if (marked[i] && (i == 0 || !marked[i - 1]))
            islands++;
    }

    return islands;
}

int main() {
    string s;
    int k;
    cin >> s >> k;

    unordered_set<string> uniqueSubs;
    int n = s.size();

    // Generate all unique substrings
    for (int i = 0; i < n; i++) {
        string sub = "";
        for (int j = i; j < n; j++) {
            sub += s[j];
            uniqueSubs.insert(sub);
        }
    }

    int result = 0;

    // Count substrings that produce exactly k islands
    for (auto &sub : uniqueSubs) {
        if (countIslands(s, sub) == k)
            result++;
    }

    cout << result << endl;
    return 0;
}
