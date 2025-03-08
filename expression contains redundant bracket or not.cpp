#include <iostream>
#include <stack>
using namespace std;

// Function to check if an expression contains redundant brackets
bool hasRedundantBrackets(string expr) {
    stack<char> st;
    
    // Traverse each character of the expression
    for (int i = 0; i < expr.length(); i++) {
        // If current character is closing bracket ')'
        if (expr[i] == ')') {
            char top = st.top();
            st.pop();
            
            bool isRedundant = true;
            
            // Check if the characters between brackets are operators
            while (top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
                }
                top = st.top();
                st.pop();
            }
            
            // If no operators found inside the brackets, it is redundant
            if (isRedundant) {
                return true;
            }
        } else {
            // Push other characters (operators, operands, and opening brackets)
            st.push(expr[i]);
        }
    }
    
    return false;
}

int main() {
    string expr = "(a + (b))";
    
    if (hasRedundantBrackets(expr)) {
        cout << "The expression contains redundant brackets." << endl;
    } else {
        cout << "The expression does not contain redundant brackets." << endl;
    }
    
    return 0;
}

