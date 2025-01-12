#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function prototype for merge function
int merge(int arr[], int temp[], int left, int mid, int right);

int mergeAndCount(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (left < right) {
        mid = (left + right) / 2;
        inv_count += mergeAndCount(arr, temp, left, mid);
        inv_count += mergeAndCount(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left; 
    int j = mid + 1; 
    int k = left; 
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    int temp[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = mergeAndCount(arr, temp, 0, n - 1);

    cout << "Number of inversions are: " << result << endl;
    return 0;
}

