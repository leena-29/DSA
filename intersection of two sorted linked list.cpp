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

Node* addTwoLists(Node* first, Node* second) {
    Node* result = NULL;
    Node* temp = NULL;
    Node* prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = sum / 10;
        sum = sum % 10;

        push(result, sum);

        if (first) first = first->next;
        if (second) second = second->next;
    }

    if (carry > 0) {
        push(result, carry);
    }

    return result;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* first = NULL;
    Node* second = NULL;

    // First number: 7 -> 5 -> 9
    push(first, 9);
    push(first, 5);
    push(first, 7);

    // Second number: 8 -> 4 -> 3
    push(second, 3);
    push(second, 4);
    push(second, 8);

    cout << "First number: ";
    printList(first);

    cout << "Second number: ";
    printList(second);

    Node* result = addTwoLists(first, second);

    cout << "Sum: ";
    printList(result);

    return 0;
}

