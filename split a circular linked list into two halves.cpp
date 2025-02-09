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

// Function to merge two sorted circular linked lists
Node* mergeSortedCircularLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* mergedHead = NULL;
    Node* mergedTail = NULL;

    // Merge the two lists
    while (temp1->next != head1 && temp2->next != head2) {
        if (temp1->data <= temp2->data) {
            if (!mergedHead) {
                mergedHead = temp1;
                mergedTail = temp1;
            } else {
                mergedTail->next = temp1;
                mergedTail = temp1;
            }
            temp1 = temp1->next;
        } else {
            if (!mergedHead) {
                mergedHead = temp2;
                mergedTail = temp2;
            } else {
                mergedTail->next = temp2;
                mergedTail = temp2;
            }
            temp2 = temp2->next;
        }
    }

    while (temp1->next != head1) {
        mergedTail->next = temp1;
        mergedTail = temp1;
        temp1 = temp1->next;
    }

    while (temp2->next != head2) {
        mergedTail->next = temp2;
        mergedTail = temp2;
        temp2 = temp2->next;
    }

    // Close the merged list in a circular fashion
    mergedTail->next = mergedHead;

    return mergedHead;
}

// Function to print a circular linked list
void printList(Node* head) {
    Node* temp = head;
    if (head) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
}

int main() {
    Node* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(5);
    head1->next->next->next = head1;  // Circular

    Node* head2 = newNode(2);
    head2->next = newNode(4);
    head2->next->next = newNode(6);
    head2->next->next->next = head2;  // Circular

    cout << "First Circular List: ";
    printList(head1);

    cout << "Second Circular List: ";
    printList(head2);

    Node* mergedHead = mergeSortedCircularLists(head1, head2);
    cout << "Merged Circular List: ";
    printList(mergedHead);

    return 0;
}

