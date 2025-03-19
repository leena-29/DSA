#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front, rear, size;

public:
    // Constructor to initialize the queue
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            cout << "Queue Overflow: The queue is full!" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation
    int dequeue() {
        if (front == -1) {
            cout << "Queue Underflow: The queue is empty!" << endl;
            return -1;
        }
        int value = arr[front];
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % size;
        }
        return value;
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
        cout << arr[rear] << endl; // print last element
    }
};

int main() {
    CircularQueue queue(5);

    // Enqueue elements to queue
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    // Display queue
    cout << "Queue elements: ";
    queue.display();

    // Dequeue an element from queue
    cout << "Dequeued: " << queue.dequeue() << endl;

    // Display queue again
    cout << "Queue elements after dequeue: ";
    queue.display();

    return 0;
}

