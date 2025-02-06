#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to detect loop in the linked list
bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// Function to remove loop from the linked list
void removeLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Detect loop first
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    // If loop exists, remove it
    if (slow == fast) {
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL; // Remove the loop
    }
}

// Function to print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);

    // Creating a loop for testing
    head->next->next->next->next = head->next->next;

    if (detectLoop(head)) {
        cout << "Loop detected!" << endl;
        removeLoop(head);
        cout << "Loop removed!" << endl;
    } else {
        cout << "No loop detected!" << endl;
    }

    cout << "List after removing loop: ";
    printList(head);

    return 0;
}

