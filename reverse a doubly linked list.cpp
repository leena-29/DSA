#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void reverseDoublyLinkedList(Node*& head) {
    Node* temp = nullptr;
    Node* current = head;

    // Swap next and prev for all nodes
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Update head to the last node
    if (temp != nullptr) {
        head = temp->prev;
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original List: ";
    printList(head);

    reverseDoublyLinkedList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}

