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

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addOne(Node* head) {
    head = reverse(head);
    Node* temp = head;
    int carry = 1;

    while (temp != NULL) {
        int sum = temp->data + carry;
        carry = sum / 10;
        temp->data = sum % 10;

        if (temp->next == NULL && carry == 1) {
            Node* newNode = new Node();
            newNode->data = carry;
            newNode->next = NULL;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return reverse(head);
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    push(head, 9);
    push(head, 9);
    push(head, 9);
    push(head, 9);
    cout << "Original number: ";
    printList(head);

    head = addOne(head);

    cout << "After adding 1: ";
    printList(head);

    return 0;
}

