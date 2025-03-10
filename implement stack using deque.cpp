#include <iostream>
#include <deque>
using namespace std;

class StackUsingDeque {
private:
    deque<int> dq;

public:
    // Push element to stack
    void push(int x) {
        dq.push_back(x);
    }

    // Pop element from stack
    int pop() {
        if (dq.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int front = dq.back();
        dq.pop_back();
        return front;
    }

    // Get the top element of the stack
    int top() {
        if (dq.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return dq.back();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return dq.empty();
    }
};

int main() {
    StackUsingDeque stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Top element after pop: " << stack.top() << endl;

    return 0;
}

