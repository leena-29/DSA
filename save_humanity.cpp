#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isMatch(const string &a, const string &b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string p, v;
        cin >> p >> v;
        int n = p.size(), m = v.size();
        vector<int> result;

        for (int i = 0; i <= n - m; i++) {
            string sub = p.substr(i, m);
            if (isMatch(sub, v)) {
                result.push_back(i);
            }
        }

        if (result.empty()) {
            cout << "No Match!" << endl;
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i > 0) cout << " ";
                cout << result[i];
            }
            cout << endl;
        }
    }
    return 0;
}
