#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> unionArrays(int arr1[], int arr2[], int size1, int size2) {
    unordered_set<int> elements;
    vector<int> result;

    // Insert elements from the first array
    for (int i = 0; i < size1; i++) {
        elements.insert(arr1[i]);
    }

    // Insert elements from the second array
    for (int i = 0; i < size2; i++) {
        elements.insert(arr2[i]);
    }

    // Copy the set to a vector for displaying the result
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

    vector<int> result = unionArrays(arr1, arr2, size1, size2);

    cout << "The union of the two arrays is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

