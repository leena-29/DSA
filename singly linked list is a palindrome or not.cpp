#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char val) : data(val), next(nullptr) {}
};

bool isPalindrome(Node* head) {
    stack<char> s;
    Node* temp = head;

    // Push all elements of the linked list onto the stack
    while (temp) {
        s.push(temp->data);
        temp = temp->next;
    }

    // Compare elements from the stack and the linked list
    temp = head;
    while (temp) {
        if (temp->data != s.top()) {
            return false;
        }
        s.pop();
        temp = temp->next;
    }
    return true;
}

void append(Node*& head, char data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head = nullptr;

    append(head, 'r');
    append(head, 'a');
    append(head, 'd');
    append(head, 'a');
    append(head, 'r');

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

