#include <bits/stdc++.h>
using namespace std;

// Function to count minimum swaps required to sort the array
int countSwaps(vector<int> arr) {
    int n = arr.size();
    vector<pair<int, int>> v(n);

    // Store elements with their original indices
    for (int i = 0; i < n; i++) {
        v[i] = {arr[i], i};
    }

    // Sort by array value
    sort(v.begin(), v.end());

    vector<bool> visited(n, false);
    int swaps = 0;

    // Perform cycle detection for minimum swaps
    for (int i = 0; i < n; i++) {
        if (visited[i] || v[i].second == i)
            continue;

        int cycleSize = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = v[j].second;
            cycleSize++;
        }

        if (cycleSize > 1)
            swaps += (cycleSize - 1);
    }

    return swaps;
}

int lilysHomework(vector<int> arr) {
    // Count swaps for ascending order
    int asc = countSwaps(arr);

    // Count swaps for descending order
    reverse(arr.begin(), arr.end());
    int desc = countSwaps(arr);

    // Return the smaller of the two
    return min(asc, desc);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << lilysHomework(arr) << endl;
    return 0;
}
