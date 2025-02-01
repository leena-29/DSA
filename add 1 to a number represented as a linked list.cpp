#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> differenceArrays(int arr1[], int arr2[], int size1, int size2) {
    unordered_set<int> elements;
    vector<int> result;

    // Insert elements from the first array
    for (int i = 0; i < size1; i++) {
        elements.insert(arr1[i]);
    }

    // Remove elements from the set that are found in the second array
    for (int i = 0; i < size2; i++) {
        elements.erase(arr2[i]);
    }

    // Copy the remaining elements from the set to the result vector
    for (auto it = elements.begin(); it != elements.end(); it++) {
        result.push_back(*it);
    }

    return result;
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

    vector<int> result = differenceArrays(arr1, arr2, size1, size2);

    cout << "The difference of the two arrays is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

