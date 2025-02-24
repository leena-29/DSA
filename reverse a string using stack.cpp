#include <iostream>
#include <string>
using namespace std;

// Function to split binary string into two substrings with equal number of 0's and 1's
bool splitBinaryString(string str) {
    int count0 = 0, count1 = 0;
    
    // Traverse through the string and count 0's and 1's
    for (char ch : str) {
        if (ch == '0') count0++;
        else if (ch == '1') count1++;
    }
    
    // If the number of 0's and 1's are equal, return true
    return count0 == count1;
}

int main() {
    string str;
    cout << "Enter a binary string: ";
    cin >> str;
    
    if (splitBinaryString(str)) {
        cout << "The binary string can be split into two substrings with equal 0's and 1's." << endl;
    } else {
        cout << "The binary string cannot be split into two substrings with equal 0's and 1's." << endl;
    }
    
    return 0;
}

