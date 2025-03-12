#include <iostream>
#include <stack>
using namespace std;

// Queue class using two stacks
class Queue {
private:
    stack<int> s1, s2;

public:
    // Push operation to enqueue elements
    void enqueue(int x) {
        s1.push(x);
    }

    // Pop operation to dequeue elements
    int dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }

            // Move elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    q.enqueue(40);
    cout << "Dequeued element: " << q.dequeue() << endl;

    return 0;
}

