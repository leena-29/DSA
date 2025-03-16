#include <iostream>
using namespace std;

// Node structure for queue
struct Node {
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

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        
        if (rear == nullptr) {
            front = rear = newNode;
            cout << "Enqueued: " << value << endl;
            return;
        }
        
        rear->next = newNode;
        rear = newNode;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation
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

    // Display queue elements
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    // Enqueue elements to queue
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

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

