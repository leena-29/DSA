#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to print all permutations of a string
void printPermutations(string str, int index) {
    // Base case: If the index is at the end of the string
    if (index == str.length()) {
        cout << str << endl;
        return;
    }

    // Loop through all characters and permute
    for (int i = index; i < str.length(); i++) {
        // Swap the current index character with the loop index character
        swap(str[index], str[i]);
        
        // Recursive call to generate further permutations
        printPermutations(str, index + 1);

        // Backtrack to restore the original configuration
        swap(str[index], str[i]);
    }
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    
    cout << "All permutations of the string are:\n";
    printPermutations(str, 0);
    
    return 0;
}

