#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int value) {
        data = value;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBegin(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at the beginning" << endl;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted " << value << " at the end" << endl;
    }

    // Delete from the beginning
    void deleteFromBegin() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        cout << "Deleted from the beginning" << endl;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        cout << "Deleted from the end" << endl;
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Insertion operations
    list.insertAtBegin(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBegin(5);

    // Display list after insertion
    cout << "List after insertion: ";
    list.display();

    // Deletion operations
    list.deleteFromBegin();
    list.deleteFromEnd();

    // Display list after deletion
    cout << "List after deletion: ";
    list.display();

    return 0;
}

