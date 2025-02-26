#include <iostream>
#include <vector>
using namespace std;

// Function to find the celebrity in the party
int findCelebrity(const vector<vector<int>>& matrix, int n) {
    int celebrity = 0;

    // Step 1: Find a potential celebrity
    for (int i = 1; i < n; i++) {
        if (matrix[celebrity][i] == 1) {
            celebrity = i;
        }
    }

    // Step 2: Verify if the potential celebrity is the true celebrity
    for (int i = 0; i < n; i++) {
        // A celebrity should not know anyone, and everyone should know the celebrity
        if ((i != celebrity && matrix[celebrity][i] == 1) || matrix[i][celebrity] == 0) {
            return -1; // No celebrity found
        }
    }

    return celebrity; // Return the celebrity if all conditions are satisfied
}

int main() {
    int n;
    cout << "Enter the number of people in the party: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the matrix (0 means doesn't know, 1 means knows):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int celebrity = findCelebrity(matrix, n);

    if (celebrity == -1) {
        cout << "There is no celebrity in the party." << endl;
    } else {
        cout << "The celebrity is person " << celebrity << "." << endl;
    }

    return 0;
}

