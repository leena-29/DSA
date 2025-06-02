
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node(int val) : data(val), left(NULL), right(NULL), next(NULL) {}
};

void populateNextUtil(Node* root, Node* &next) {
    if (!root) return;
    populateNextUtil(root->right, next);
    root->next = next;
    next = root;
    populateNextUtil(root->left, next);
}

void populateNext(Node* root) {
    Node* next = NULL;
    populateNextUtil(root, next);
}

void printSuccessors(Node* root) {
    if (!root) return;
    printSuccessors(root->left);
    if (root->next)
        cout << "Next of " << root->data << " is " << root->next->data << endl;
    else
        cout << "Next of " << root->data << " is -1" << endl;
    printSuccessors(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);

    populateNext(root);
    printSuccessors(root);

    return 0;
}
