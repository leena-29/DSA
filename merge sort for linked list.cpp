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

Node* reverseInGroups(Node* head, int k) {
    if (!head || k == 1)
        return head;
    
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    // Reverse the first 'k' nodes
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Now 'head' is the last node of the reversed part, so link it to the result of the next part
    if (next != NULL) {
        head->next = reverseInGroups(next, k);
    }

    // 'prev' is the new head of the reversed list
    return prev;
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

    // Add elements to the list
    push(head, 8);
    push(head, 7);
    push(head, 6);
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);

    int k = 3;
    cout << "Original list: ";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "List after reversing in groups of " << k << ": ";
    printList(head);

    return 0;
}

