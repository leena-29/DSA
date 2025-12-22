#include <bits/stdc++.h>
using namespace std;

vector<string> weightedUniformStrings(string s, vector<int> queries) {
    unordered_set<int> weights;
    int currentWeight = 0;
    char prevChar = '\0';

    for (char c : s) {
        int weight = c - 'a' + 1;
        if (c == prevChar) {
            currentWeight += weight;
        } else {
            currentWeight = weight;
            prevChar = c;
        }
        weights.insert(currentWeight);
    }

    vector<string> result;
    for (int q : queries) {
        if (weights.find(q) != weights.end())
            result.push_back("Yes");
        else
            result.push_back("No");
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;
    vector<int> queries(n);
    for (int i = 0; i < n; i++)
        cin >> queries[i];

    vector<string> result = weightedUniformStrings(s, queries);
    for (string ans : result)
        cout << ans << endl;

    return 0;
}
