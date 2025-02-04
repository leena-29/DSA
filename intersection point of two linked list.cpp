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

int getCount(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getIntersectionNode(Node* head1, Node* head2) {
    int count1 = getCount(head1);
    int count2 = getCount(head2);
    
    int diff = abs(count1 - count2);

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    // Move the pointer of the longer list by 'diff' nodes
    if (count1 > count2) {
        for (int i = 0; i < diff; i++) {
            ptr1 = ptr1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            ptr2 = ptr2->next;
        }
    }

    // Traverse both lists and check for intersection
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL; // No intersection
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    // First list: 3 -> 6 -> 9 -> 15 -> 30
    push(head1, 30);
    push(head1, 15);
    push(head1, 9);
    push(head1, 6);
    push(head1, 3);

    // Second list: 10 -> 15 -> 30
    push(head2, 30);
    push(head2, 15);
    push(head2, 10);

    Node* intersection = getIntersectionNode(head1, head2);
    if (intersection != NULL) {
        cout << "Intersection at node with data: " << intersection->data << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}

