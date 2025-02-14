#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size, capacity;
    int* queue;

public:
    CircularQueue(int cap) {
        capacity = cap;
        queue = new int[capacity];
        size = 0;
        front = 0;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return queue[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Queue after enqueues: ";
    q.display();

    cout << "Front element: " << q.frontElement() << endl;

    q.dequeue();
    cout << "Queue after dequeue: ";
    q.display();

    return 0;
}

