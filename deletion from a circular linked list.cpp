#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> s;
    string reversed = "";

    // Push all characters of the string onto the stack
    for (char c : str) {
        s.push(c);
    }

    // Pop characters from the stack to form the reversed string
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string str = "Hello, World!";
    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reverseString(str) << endl;

    return 0;
}

