#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumIndex(const vector<int>& arr) {
    int n = arr.size();
    
    // Find total sum of the array
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int leftSum = 0;
    for (int i = 0; i < n; i++) {
        // Subtract the current element from totalSum
        totalSum -= arr[i];

        // Check if leftSum equals to remaining right sum
        if (leftSum == totalSum) {
            return i;
        }

        // Update leftSum for next iteration
        leftSum += arr[i];
    }

    return -1;  // If no equilibrium index is found
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

    int result = findEquilibriumIndex(arr);

    if (result != -1) {
        cout << "Equilibrium index is: " << result << endl;
    } else {
        cout << "No equilibrium index found." << endl;
    }

    return 0;
}

