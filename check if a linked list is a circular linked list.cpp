#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to check if the linked list is circular
bool isCircular(Node* head) {
    if (head == NULL)
        return false;
    
    Node* temp = head;
    
    while (temp != NULL) {
        if (temp->next == head) {
            return true;
        }
        temp = temp->next;
    }
    
    return false;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head;  // Creating a circular linked list

    cout << "Is the linked list circular? " << (isCircular(head) ? "Yes" : "No") << endl;

    return 0;
}

