#include <iostream>
#include <algorithm> // For sorting
using namespace std;

void findKthMinMax(int arr[], int n, int k) {
    sort(arr, arr + n); // Sort the array

    if (k > 0 && k <= n) {
        cout << "The " << k << "th minimum element is: " << arr[k - 1] << endl;
        cout << "The " << k << "th maximum element is: " << arr[n - k] << endl;
    } else {
        cout << "Invalid value of k!" << endl;
    }
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    findKthMinMax(arr, n, k);

    return 0;
}

