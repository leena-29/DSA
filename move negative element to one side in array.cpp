#include <iostream>
using namespace std;

void rearrangeArray(int arr[], int n) {
    int j = 0; // Index for placing negatives
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j) {
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    rearrangeArray(arr, n);

    cout << "Array after moving negatives to one side: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

