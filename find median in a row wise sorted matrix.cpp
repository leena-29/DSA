#include <iostream>
#include <vector>
using namespace std;

void findCommonElements(int arr1[], int arr2[], int size1, int size2) {
    int i = 0, j = 0;
    vector<int> commonElements;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            i++;
        }
        else if (arr1[i] > arr2[j]) {
            j++;
        }
        else {
            commonElements.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    if (commonElements.empty()) {
        cout << "No common elements" << endl;
    } else {
        cout << "Common elements are: ";
        for (int element : commonElements) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    int size1, size2;

    cout << "Enter the size of first array: ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of second array: ";
    cin >> size2;
    int arr2[size2];
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    findCommonElements(arr1, arr2, size1, size2);

    return 0;
}

