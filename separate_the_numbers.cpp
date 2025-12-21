#include <bits/stdc++.h>
using namespace std;

void separateNumbers(string s) {
    int n = s.length();
    bool found = false;
    string firstNum;

    for (int len = 1; len <= n / 2; len++) {
        string first = s.substr(0, len);
        if (first[0] == '0') continue; 

        long long num = stoll(first);
        string temp = first;

        while (temp.length() < n) {
            num++;
            temp += to_string(num);
        }

        if (temp == s) {
            found = true;
            firstNum = first;
            break;
        }
    }

    if (found)
        cout << "YES " << firstNum << endl;
    else
        cout << "NO" << endl;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        separateNumbers(s);
    }
    return 0;
}
