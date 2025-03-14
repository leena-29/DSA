#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor to initialize the queue
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int val) {
        if ((rear + 1) % size == front) {
            cout << "Queue Overflow: The queue is full!" << endl;
            return;
        }
        if (front == -1) {
            front = 0; // First element to be added
        }
        rear = (rear + 1) % size;
        arr[rear] = val;
        cout << "Enqueued: " << val << endl;
    }

    // Dequeue operation
    int dequeue() {
        if (front == -1) {
            cout << "Queue Underflow: The queue is empty!" << endl;
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = rear = -1; // Only one element was in the queue
        } else {
            front = (front + 1) % size;
        }
        return val;
    }

    // Display queue elements
    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    CircularQueue q(5); // Queue size of 5

    // Enqueue some elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Display the queue
    cout << "Queue elements: ";
    q.display();

    // Dequeue an element
    cout << "Dequeued: " << q.dequeue() << endl;

    // Display the queue again
    cout << "Queue elements after dequeue: ";
    q.display();

    // Enqueue more elements
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    // Display the queue
    cout << "Queue elements after more enqueue: ";
    q.display();

    return 0;
}

