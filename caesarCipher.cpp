#include <bits/stdc++.h>
using namespace std;

string caesarCipher(string s, int k) {
    string result = "";
    k = k % 26; // To handle large shift values
    
    for (char c : s) {
        if (isupper(c)) {
            // For uppercase letters
            result += char('A' + (c - 'A' + k) % 26);
        } 
        else if (islower(c)) {
            // For lowercase letters
            result += char('a' + (c - 'a' + k) % 26);
        } 
        else {
            // Non-alphabetic characters remain unchanged
            result += c;
        }
    }
    
    return result;
}

int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;
    
    cout << caesarCipher(s, k);
    return 0;
}
