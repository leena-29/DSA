
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int findMin(Node* root) {
    if (!root) return -1;
    while (root->left) {
        root = root->left;
    }
    return root->data;
}

int findMax(Node* root) {
    if (!root) return -1;
    while (root->right) {
        root = root->right;
    }
    return root->data;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->right->right = new Node(40);

    cout << "Minimum value in BST: " << findMin(root) << endl;
    cout << "Maximum value in BST: " << findMax(root) << endl;

    return 0;
}
