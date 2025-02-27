#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to perform arithmetic operations
int performOperation(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

// Function to evaluate the arithmetic expression
int evaluateExpression(const string& expr) {
    stack<int> values;
    stack<char> ops;
    
    for (int i = 0; i < expr.size(); i++) {
        if (isspace(expr[i])) continue; // Skip spaces

        // If the current character is a number
        if (isdigit(expr[i])) {
            int val = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            i--; // Adjust to the last number character
            values.push(val);
        }

        // If the current character is an opening parenthesis
        else if (expr[i] == '(') {
            ops.push(expr[i]);
        }

        // If the current character is a closing parenthesis
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(performOperation(val1, val2, op));
            }
            ops.pop(); // Pop '('
        }

        // If the current character is an operator
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            while (!ops.empty() && (ops.top() == '*' || ops.top() == '/' || ops.top() == '+' || ops.top() == '-')) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(performOperation(val1, val2, op));
            }
            ops.push(expr[i]);
        }
    }

    // Apply remaining operations
    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(performOperation(val1, val2, op));
    }

    return values.top(); // The final result is at the top of the stack
}

int main() {
    string expr;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expr);

    int result = evaluateExpression(expr);
    cout << "The result of the expression is: " << result << endl;

    return 0;
}

