#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to find the next greater element for each element in the array
void nextGreaterElement(vector<int>& arr) {
    stack<int> s; // Stack to keep track of elements for which we need the next greater element
    vector<int> result(arr.size(), -1); // Initialize result array with -1

    // Traverse the array from right to left
    for (int i = arr.size() - 1; i >= 0; i--) {
        // Pop elements from the stack that are less than or equal to the current element
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        
        // If stack is not empty, top element is the next greater element for arr[i]
        if (!s.empty()) {
            result[i] = s.top();
        }

        // Push the current element onto the stack for future comparison
        s.push(arr[i]);
    }

    // Print the result
    cout << "Next greater elements: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    nextGreaterElement(arr);

    return 0;
}

