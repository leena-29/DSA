#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        int height;
        
        Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
    };
    
    Node* root;
    
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }
    
    int getBalance(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }
    
    void updateHeight(Node* node) {
        if (node) {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }
    
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        updateHeight(y);
        updateHeight(x);
        
        return x;
    }
    
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        updateHeight(x);
        updateHeight(y);
        
        return y;
    }
    
    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        
        if (key < node->data) {
            node->left = insert(node->left, key);
        } else if (key > node->data) {
            node->right = insert(node->right, key);
        } else {
            return node; // Duplicate keys not allowed
        }
        
        updateHeight(node);
        
        int balance = getBalance(node);
        
        // Left Left Case
        if (balance > 1 && key < node->left->data) {
            return rotateRight(node);
        }
        
        // Right Right Case
        if (balance < -1 && key > node->right->data) {
            return rotateLeft(node);
        }
        
        // Left Right Case
        if (balance > 1 && key > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        
        // Right Left Case
        if (balance < -1 && key < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        
        return node;
    }
    
    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    
public:
    AVLTree() : root(nullptr) {}
    
    void insert(int key) {
        root = insert(root, key);
    }
    
    void printInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    
    cout << "Inorder traversal of AVL tree: ";
    tree.printInorder();
    
    return 0;
}
