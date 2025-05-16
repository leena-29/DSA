
#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void reverseLevelOrder(Node* root, const string& filename) {
    if (!root) return;

    queue<Node*> q;
    stack<Node*> s;

    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        s.push(curr);

        if (curr->right) q.push(curr->right);
        if (curr->left) q.push(curr->left);
    }

    ofstream file(filename);
    while (!s.empty()) {
        file << s.top()->data << " ";
        s.pop();
    }
    file.close();
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    string filename = "reverse_level_order_output.txt";
    reverseLevelOrder(root, filename);

    cout << "Reverse Level Order Traversal saved to: " << filename << endl;
    return 0;
}
