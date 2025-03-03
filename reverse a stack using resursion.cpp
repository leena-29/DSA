#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& s, int x) {
    // Base case: if the stack is empty, push the element
    if (s.empty()) {
        s.push(x);
        return;
    }
    
    // Hold all items in the stack and pop the top element
    int temp = s.top();
    s.pop();
    
    // Recursively call insertAtBottom for the rest of the stack
    insertAtBottom(s, x);
    
    // Push the popped element back into the stack
    s.push(temp);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int>& s) {
    // Base case: if the stack is empty, return
    if (s.empty()) {
        return;
    }
    
    // Pop the top element
    int x = s.top();
    s.pop();
    
    // Recursively reverse the rest of the stack
    reverseStack(s);
    
    // Insert the popped element at the bottom of the stack
    insertAtBottom(s, x);
}

int main() {
    stack<int> s;
    
    // Pushing elements to the stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    
    cout << "Original Stack: ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the stack
    reverseStack(s);
    
    cout << "Reversed Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

