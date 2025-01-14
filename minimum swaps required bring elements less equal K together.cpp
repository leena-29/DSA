#include <iostream>
#include <vector>
using namespace std;

void rearrangeArray(int arr[], int n) {
    int i = 0, j = n - 1;
    
    // Loop until both pointers meet
    while (i <= j) {
        if (arr[i] < 0 && arr[j] < 0) {
            i++;
        } else if (arr[i] >= 0 && arr[j] >= 0) {
            j--;
        } else if (arr[i] >= 0 && arr[j] < 0) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        } else {
            i++;
            j--;
        }
    }
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

    rearrangeArray(arr, n);

    cout << "Array after rearranging: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

