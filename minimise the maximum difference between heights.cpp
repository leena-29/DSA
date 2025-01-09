#include <iostream>
#include <unordered_map>
using namespace std;

char firstNonRepeatingCharacter(const string& str) {
    unordered_map<char, int> freq;

    // Count the frequency of each character
    for (char ch : str) {
        freq[ch]++;
    }

    // Find the first character with a frequency of 1
    for (char ch : str) {
        if (freq[ch] == 1) {
            return ch;
        }
    }

    // If no non-repeating character is found, return '-1'
    return '-1';
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    char result = firstNonRepeatingCharacter(str);

    if (result != '-1') {
        cout << "The first non-repeating character is: " << result << endl;
    } else {
        cout << "No non-repeating character found.\n";
    }

    return 0;
}

