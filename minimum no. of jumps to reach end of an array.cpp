#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str) {
    int start = 0;
    int end = str.length() - 1;

    // Check characters from both ends of the string
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str)) {
        cout << "The string is a palindrome.\n";
    } else {
        cout << "The string is not a palindrome.\n";
    }

    return 0;
}

