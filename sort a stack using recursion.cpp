#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element in sorted order
void insertSorted(stack<int>& s, int x) {
    // Base case: if the stack is empty or the top element is less than x
    if (s.empty() || s.top() <= x) {
        s.push(x);
        return;
    }
    
    // Pop the top element and call insertSorted recursively
    int temp = s.top();
    s.pop();
    
    insertSorted(s, x);
    
    // Push the popped element back into the stack
    s.push(temp);
}

// Function to sort the stack using recursion
void sortStack(stack<int>& s) {
    // Base case: if the stack is empty, return
    if (s.empty()) {
        return;
    }
    
    // Pop the top element
    int x = s.top();
    s.pop();
    
    // Sort the rest of the stack
    sortStack(s);
    
    // Insert the popped element in sorted order
    insertSorted(s, x);
}

int main() {
    stack<int> s;
    
    // Pushing elements to the stack
    s.push(30);
    s.push(10);
    s.push(50);
    s.push(20);
    
    cout << "Original Stack: ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Sort the stack
    sortStack(s);
    
    cout << "Sorted Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

