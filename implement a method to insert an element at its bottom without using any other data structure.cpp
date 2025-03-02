#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    // Push an element onto the stack
    void push(int x) {
        q2.push(x);  // Push the element to the second queue
        
        // Push all elements of q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap q1 and q2 so that q1 contains the stack elements
        swap(q1, q2);
    }

    // Pop the top element from the stack
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        
        int x = q1.front();
        q1.pop();
        return x;
    }

    // Return the top element of the stack
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues stack;
    
    // Pushing elements to the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << "Top element: " << stack.top() << endl;  // Output: 30
    
    cout << "Popped element: " << stack.pop() << endl;  // Output: 30
    cout << "Popped element: " << stack.pop() << endl;  // Output: 20
    cout << "Top element: " << stack.top() << endl;  // Output: 10
    
    return 0;
}

