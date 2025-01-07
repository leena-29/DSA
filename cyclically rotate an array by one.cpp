#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<int, int> findSmallestSumPair(const vector<int>& arr) {
    int n = arr.size();
    int minSum = INT_MAX;
    pair<int, int> result;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (sum < minSum) {
                minSum = sum;
                result = {arr[i], arr[j]};
            }
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = findSmallestSumPair(arr);

    cout << "The pair with the smallest sum is: " << result.first << " and " << result.second << endl;

    return 0;
}

