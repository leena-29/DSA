#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
private:
    queue<int> q1, q2;

public:
    // Push element to stack
    void push(int x) {
        q2.push(x);
        
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap q1 and q2 to make q1 the main queue
        swap(q1, q2);
    }

    // Pop element from stack
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int front = q1.front();
        q1.pop();
        return front;
    }

    // Get the top element of the stack
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
    StackUsingQueue stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Top element after pop: " << stack.top() << endl;

    return 0;
}

