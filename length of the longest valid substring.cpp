#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Function to find the length of the longest valid parentheses substring
int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1); // Initialize stack with -1 to handle the base case
    int maxLength = 0;
    
    // Traverse the string
    for (int i = 0; i < s.length(); i++) {
        // If opening parenthesis, push its index onto the stack
        if (s[i] == '(') {
            st.push(i);
        } else {
            // Pop the top element when encountering closing parenthesis
            st.pop();
            
            // If stack is not empty, calculate the valid substring length
            if (!st.empty()) {
                maxLength = max(maxLength, i - st.top());
            } else {
                st.push(i); // Push current index if stack is empty
            }
        }
    }
    
    return maxLength;
}

int main() {
    string s = "(()())";
    
    cout << "Length of Longest Valid Parentheses Substring: " << longestValidParentheses(s) << endl;
    
    return 0;
}

