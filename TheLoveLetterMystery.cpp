#include <bits/stdc++.h>
using namespace std;

int theLoveLetterMystery(string s) {
    int n = s.size();
    int operations = 0;
    
    // Compare characters from both ends toward the center
    for(int i = 0; i < n / 2; i++) {
        operations += abs(s[i] - s[n - i - 1]);
    }
    
    return operations;
}

int main() {
    int q;
    cin >> q;
    
    while(q--) {
        string s;
        cin >> s;
        cout << theLoveLetterMystery(s) << endl;
    }
    
    return 0;
}
