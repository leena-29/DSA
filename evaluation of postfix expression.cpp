#include <iostream>
using namespace std;

// Define a node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;  // Save the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move prev to current node
        current = next;        // Move to the next node
    }
    
    return prev; // Return the new head of the reversed list
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to add a node at the end of the list
void append(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;
    
    // Adding nodes to the linked list
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    
    cout << "Original List: ";
    printList(head);
    
    // Reversing the linked list
    head = reverseList(head);
    
    cout << "Reversed List: ";
    printList(head);
    
    return 0;
}

