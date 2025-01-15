#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {
    vector<int> dp(n, 1);  // Initialize dp array to store lengths of LIS

    // Compute the length of LIS for each element
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // Find the maximum length in the dp array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = longestIncreasingSubsequence(arr, n);

    cout << "Length of the longest increasing subsequence: " << result << endl;

    return 0;
}

