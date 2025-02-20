#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) return "";

    bool dp[n][n];
    int start = 0, maxLength = 1;

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Check for substrings of length 2 to n
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;

            // If the characters at both ends match and the substring is palindrome
            if (s[i] == s[j]) {
                if (len == 2) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            } else {
                dp[i][j] = false;
            }

            // Update the maximum length palindrome substring
            if (dp[i][j] && len > maxLength) {
                maxLength = len;
                start = i;
            }
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;

    return 0;
}

