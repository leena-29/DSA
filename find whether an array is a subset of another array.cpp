#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubarrayWithSumZero(const vector<int>& arr) {
    unordered_map<int, int> prefixSumMap;
    int maxLength = 0;
    int prefixSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            maxLength = i + 1;
        }

        if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
            maxLength = max(maxLength, i - prefixSumMap[prefixSum]);
        } else {
            prefixSumMap[prefixSum] = i;
        }
    }

    return maxLength;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = longestSubarrayWithSumZero(arr);

    cout << "Length of the longest subarray with sum 0 is: " << result << endl;

    return 0;
}

