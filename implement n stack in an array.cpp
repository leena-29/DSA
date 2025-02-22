#include <iostream>
#include <string>
using namespace std;

// Function to print all subsequences of a string
void printSubsequences(string str, string subsequence, int index) {
    // Base condition: If we've reached the end of the string
    if (index == str.length()) {
        cout << subsequence << endl;
        return;
    }
    
    // Recursive call to include the current character in the subsequence
    printSubsequences(str, subsequence + str[index], index + 1);
    
    // Recursive call to exclude the current character from the subsequence
    printSubsequences(str, subsequence, index + 1);
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    
    cout << "All subsequences of the string are:\n";
    printSubsequences(str, "", 0);
    
    return 0;
}

