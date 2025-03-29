#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor to initialize the queue
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation (Add element to queue)
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation (Remove element from queue)
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow: The queue is empty!" << endl;
            return -1;
        }

        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    // Display the queue elements
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    // Display the queue
    cout << "Queue elements: ";
    queue.display();

    // Dequeue an element
    cout << "Dequeued: " << queue.dequeue() << endl;

    // Display the queue after dequeue
    cout << "Queue elements after dequeue: ";
    queue.display();

    return 0;
}

