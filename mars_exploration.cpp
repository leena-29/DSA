#include <bits/stdc++.h>
using namespace std;

int marsExploration(string s) {
    string sos = "SOS";
    int count = 0;
    
    for (int i = 0; i < s.size(); i++) {
        // Compare each character with the expected SOS pattern
        if (s[i] != sos[i % 3]) {
            count++;
        }
    }
    
    return count;
}

int main() {
    string s;
    cin >> s;
    
    cout << marsExploration(s);
    return 0;
}
