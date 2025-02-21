#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestRecurringSubsequence(string str) {
    int n = str.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Building the dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str[i - 1] == str[j - 1] && i != j) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;

    cout << "Length of Longest Recurring Subsequence: " << longestRecurringSubsequence(str) << endl;

    return 0;
}

