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

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* head1, Node* head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    // Initialize the merged list
    Node* mergedHead = NULL;

    // Compare the nodes of both lists and merge them
    if (head1->data <= head2->data) {
        mergedHead = head1;
        mergedHead->next = mergeSortedLists(head1->next, head2);
    } else {
        mergedHead = head2;
        mergedHead->next = mergeSortedLists(head1, head2->next);
    }

    return mergedHead;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(5);

    Node* head2 = newNode(2);
    head2->next = newNode(4);
    head2->next->next = newNode(6);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Node* mergedHead = mergeSortedLists(head1, head2);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}

