//Create a binary tree and perform Inorder, Preorder, Postorder recursive traversal
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* create() {
    int x;
    cout << "Enter the data (-1 for no node): ";
    cin >> x;

    if (x == -1) {
        return nullptr;
    }

    Node* root = new Node(x);

    cout << "Enter left of " << x << endl;
    root->left = create();

    cout << "Enter right of " << x << endl;
    root->right = create();

    return root;
}

void preorder(Node* temp) {
    if (temp != nullptr) {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(Node* temp) {
    if (temp != nullptr) {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

void postorder(Node* temp) {
    if (temp != nullptr) {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}

int main() {
    Node* root = create();

    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}