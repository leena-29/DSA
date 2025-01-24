#include <iostream>
#include <unordered_set>
using namespace std;

bool isSubset(int arr1[], int arr2[], int size1, int size2) {
    unordered_set<int> elements;

    for (int i = 0; i < size1; i++) {
        elements.insert(arr1[i]);
    }

    for (int i = 0; i < size2; i++) {
        if (elements.find(arr2[i]) == elements.end()) {
            return false;  // Element from arr2 not found in arr1
        }
    }

    return true;  // All elements of arr2 are in arr1
}

int main() {
    int size1, size2;

    cout << "Enter the size of the first array: ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> size2;
    int arr2[size2];
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    if (isSubset(arr1, arr2, size1, size2)) {
        cout << "Yes, the second array is a subset of the first array." << endl;
    } else {
        cout << "No, the second array is not a subset of the first array." << endl;
    }

    return 0;
}

