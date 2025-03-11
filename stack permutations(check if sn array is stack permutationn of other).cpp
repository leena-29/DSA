#include <iostream>
#include <stack>
using namespace std;

// Function to check if the given sequence is a stack permutation
bool isStackPermutation(int input[], int output[], int n) {
    stack<int> s;
    int j = 0;

    // Traverse the input sequence
    for (int i = 0; i < n; i++) {
        // Push the current element of the input array into the stack
        s.push(input[i]);

        // Check if the top of the stack matches the output array element
        while (!s.empty() && s.top() == output[j]) {
            s.pop();
            j++;
        }
    }

    // If the stack is empty after processing, it is a valid stack permutation
    return s.empty();
}

int main() {
    int input[] = {1, 2, 3, 4, 5};
    int output[] = {4, 5, 3, 2, 1};
    int n = sizeof(input) / sizeof(input[0]);

    if (isStackPermutation(input, output, n)) {
        cout << "Yes, it is a stack permutation!" << endl;
    } else {
        cout << "No, it is not a stack permutation!" << endl;
    }

    return 0;
}

