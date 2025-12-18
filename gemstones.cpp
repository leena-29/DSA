#include <bits/stdc++.h>
using namespace std;

int gemstones(vector<string> arr) {
    vector<int> count(26, 0); // 26 letters a-z

    for (string s : arr) {
        set<char> uniqueMinerals(s.begin(), s.end());
        for (char c : uniqueMinerals) {
            count[c - 'a']++;
        }
    }

    int gemstonesCount = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] == arr.size())
            gemstonesCount++;
    }

    return gemstonesCount;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << gemstones(arr);
    return 0;
}
