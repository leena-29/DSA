#include <iostream>
using namespace std;

void sortArray(int arr[], int n) {
    int count0 = 0, count1 = 0, count2 = 0;

    // Count the occurrences of 0, 1, and 2
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    // Fill the array with sorted values
    for (int i = 0; i < count0; i++)
        arr[i] = 0;
    for (int i = count0; i < count0 + count1; i++)
        arr[i] = 1;
    for (int i = count0 + count1; i < n; i++)
        arr[i] = 2;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array (only 0, 1, 2):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortArray(arr, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

