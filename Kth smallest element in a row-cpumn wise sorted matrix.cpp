#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int arr[], int size) {
    unordered_set<int> unique_elements;
    vector<int> result;

    // Insert elements into the set to remove duplicates
    for (int i = 0; i < size; i++) {
        unique_elements.insert(arr[i]);
    }

    // Copy unique elements from the set to the result vector
    for (auto it = unique_elements.begin(); it != unique_elements.end(); it++) {
        result.push_back(*it);
    }

    return result;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> result = removeDuplicates(arr, size);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

