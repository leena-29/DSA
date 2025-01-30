#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> intersectionArrays(int arr1[], int arr2[], int size1, int size2) {
    unordered_set<int> elements;
    vector<int> result;

    // Insert elements from the first array
    for (int i = 0; i < size1; i++) {
        elements.insert(arr1[i]);
    }

    // Check for common elements in the second array
    for (int i = 0; i < size2; i++) {
        if (elements.find(arr2[i]) != elements.end()) {
            result.push_back(arr2[i]);
            elements.erase(arr2[i]); // To avoid duplicate elements in result
        }
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

    vector<int> result = intersectionArrays(arr1, arr2, size1, size2);

    cout << "The intersection of the two arrays is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

