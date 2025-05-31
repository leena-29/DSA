
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* findPredecessor(Node* root, Node* target) {
    Node* predecessor = NULL;
    while (root) {
        if (target->data <= root->data) {
            root = root->left;
        } else {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}

Node* findSuccessor(Node* root, Node* target) {
    Node* successor = NULL;
    while (root) {
        if (target->data >= root->data) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

Node* search(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    Node* root = NULL;
    int keys[] = {20, 8, 22, 4, 12, 10, 14};
    for (int key : keys) root = insert(root, key);

    int targetVal = 10;
    Node* target = search(root, targetVal);
    if (!target) {
        cout << "Node not found\n";
        return 0;
    }

    Node* pred = findPredecessor(root, target);
    Node* succ = findSuccessor(root, target);

    if (pred) cout << "Inorder Predecessor of " << targetVal << ": " << pred->data << endl;
    else cout << "No Inorder Predecessor found\n";

    if (succ) cout << "Inorder Successor of " << targetVal << ": " << succ->data << endl;
    else cout << "No Inorder Successor found\n";

    return 0;
}
