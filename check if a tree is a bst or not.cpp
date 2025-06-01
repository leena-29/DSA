
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

bool isBSTUtil(Node* node, Node* &prev) {
    if (!node) return true;
    if (!isBSTUtil(node->left, prev)) return false;
    if (prev != NULL && node->data <= prev->data) return false;
    prev = node;
    return isBSTUtil(node->right, prev);
}

bool isBST(Node* root) {
    Node* prev = NULL;
    return isBSTUtil(root, prev);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(7);

    if (isBST(root)) {
        cout << "The tree is a BST" << endl;
    } else {
        cout << "The tree is not a BST" << endl;
    }

    return 0;
}
