
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

bool searchBST(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    if (key < root->data) return searchBST(root->left, key);
    return searchBST(root->right, key);
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    int key = 6;
    if (searchBST(root, key))
        cout << key << " found in BST.";
    else
        cout << key << " not found in BST.";
    return 0;
}
