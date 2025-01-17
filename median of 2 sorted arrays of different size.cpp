#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int largestSubarrayWithZeroSum(const vector<int>& arr) {
    unordered_map<int, int> prefixSumMap;
    int maxLength = 0;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // If sum is 0, update maxLength
        if (sum == 0) {
            maxLength = i + 1;
        }

        // If sum is already present in the map, calculate the length of subarray
        if (prefixSumMap.find(sum) != prefixSumMap.end()) {
            maxLength = max(maxLength, i - prefixSumMap[sum]);
        } else {
            // Store the index of the first occurrence of the prefix sum
            prefixSumMap[sum] = i;
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

    int result = largestSubarrayWithZeroSum(arr);

    cout << "Length of the largest subarray with sum 0 is: " << result << endl;

    return 0;
}

