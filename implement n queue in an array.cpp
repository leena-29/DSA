#include <iostream>
using namespace std;

// Queue class to implement "n" queues in a single array
class NQueue {
private:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int n, s;
    int freeSpot;

public:
    // Constructor to initialize the queue
    NQueue(int n, int s) {
        this->n = n;
        this->s = s;
        arr = new int[s];
        front = new int[n];
        rear = new int[n];
        next = new int[s];

        // Initialize all values
        for (int i = 0; i < n; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < s; i++) {
            next[i] = i + 1;
        }
        next[s - 1] = -1;
        freeSpot = 0;
    }

    // Enqueue operation
    void enqueue(int queueNum, int val) {
        // Check if the queue is full
        if (freeSpot == -1) {
            cout << "Overflow: No space left in the queue" << endl;
            return;
        }

        // Find the next available spot
        int index = freeSpot;
        freeSpot = next[index];

        // If the queue is empty, set the front of the queue
        if (front[queueNum] == -1) {
            front[queueNum] = index;
        } else {
            // Update the next pointer for the previous rear
            next[rear[queueNum]] = index;
        }

        // Update the rear and the value at the index
        rear[queueNum] = index;
        arr[index] = val;
        next[index] = -1;
    }

    // Dequeue operation
    int dequeue(int queueNum) {
        // Check if the queue is empty
        if (front[queueNum] == -1) {
            cout << "Underflow: Queue is empty" << endl;
            return -1;
        }

        int index = front[queueNum];
        front[queueNum] = next[index];

        // Free the spot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    // Check if a queue is empty
    bool isEmpty(int queueNum) {
        return front[queueNum] == -1;
    }
};

int main() {
    NQueue nq(3, 10); // 3 queues, 10 elements total in the array

    nq.enqueue(0, 10);
    nq.enqueue(1, 20);
    nq.enqueue(2, 30);

    cout << "Dequeued from Queue 0: " << nq.dequeue(0) << endl;
    cout << "Dequeued from Queue 1: " << nq.dequeue(1) << endl;
    cout << "Dequeued from Queue 2: " << nq.dequeue(2) << endl;

    return 0;
}

