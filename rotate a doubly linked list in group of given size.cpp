#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* getNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = getNewNode(data);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* rotateInGroups(Node* head, int k) {
    if (!head || k <= 1)
        return head;

    Node* curr = head;
    Node* prevTail = nullptr;
    Node* newHead = nullptr;

    while (curr) {
        Node* groupHead = curr;
        Node* prev = nullptr;
        int count = 0;

        while (curr && count < k) {
            Node* next = curr->next;
            curr->next = prev;
            curr->prev = next;
            prev = curr;
            curr = next;
            count++;
        }

        if (!newHead)
            newHead = prev;

        if (prevTail) {
            prevTail->next = prev;
            prev->prev = prevTail;
        }

        prevTail = groupHead;
    }
    return newHead;
}

int main() {
    Node* head = nullptr;
    int n, k;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertAtEnd(&head, data);
    }

    cout << "Enter group size (k): ";
    cin >> k;

    cout << "Original List: ";
    printList(head);

    head = rotateInGroups(head, k);

    cout << "Rotated List in groups of " << k << ": ";
    printList(head);

    return 0;
}

