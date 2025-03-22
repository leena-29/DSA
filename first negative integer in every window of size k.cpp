#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << value << endl;
    }

    // Pop operation
    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow: The stack is empty!" << endl;
            return -1;
        }

        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Display stack elements
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    // Push elements
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    // Display stack
    cout << "Stack elements: ";
    stack.display();

    // Pop an element
    cout << "Popped: " << stack.pop() << endl;

    // Display stack again
    cout << "Stack elements after pop: ";
    stack.display();

    return 0;
}

