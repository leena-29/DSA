#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX); // Initialize dp array with max value
    dp[0] = 0; // Base case: 0 amount requires 0 coins

    // Fill dp array for each amount from 1 to the given amount
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If dp[amount] is still INT_MAX, it means it's not possible to make the amount
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter the number of coin denominations: ";
    cin >> n;
    
    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter the amount: ";
    cin >> amount;

    int result = minCoins(coins, amount);

    if (result == -1) {
        cout << "It's not possible to make the amount with the given denominations." << endl;
    } else {
        cout << "Minimum number of coins required: " << result << endl;
    }

    return 0;
}

