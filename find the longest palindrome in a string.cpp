#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* queue;
    int front;
    int rear;
    int size;

public:
    // Constructor to initialize the queue
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }

    // Enqueue operation (Add element to queue)
    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            cout << "Queue Overflow: The queue is full!" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation (Remove element from queue)
    int dequeue() {
        if (front == -1) {
            cout << "Queue Underflow: The queue is empty!" << endl;
            return -1;
        }

        int value = queue[front];
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % size;
        }
        return value;
    }

    // Display the queue elements
    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % size;
        }
        cout << queue[rear] << endl;
    }
};

int main() {
    CircularQueue queue(5);

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    // Display the queue
    cout << "Queue elements: ";
    queue.display();

    // Try to enqueue when the queue is full
    queue.enqueue(60);

    // Dequeue an element
    cout << "Dequeued: " << queue.dequeue() << endl;

    // Display the queue after dequeue
    cout << "Queue elements after dequeue: ";
    queue.display();

    // Enqueue more elements
    queue.enqueue(60);
    queue.enqueue(70);

    // Display the final queue
    cout << "Final Queue elements: ";
    queue.display();

    return 0;
}

