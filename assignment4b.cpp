//Library Catalog Navigation: Develop a Binary Tree to represent
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(string val) {
        category = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* create() {
    string name;
    cout << "Enter Section/Category name (enter 'none' to stop): ";
    cin >> name;

    if (name == "none") {
        return nullptr;
    }

    Node* root = new Node(name);

    cout << "Enter left sub-category of [" << name << "]:\n";
    root->left = create();

    cout << "Enter right sub-category of [" << name << "]:\n";
    root->right = create();

    return root;
}

void preorder(Node* temp) {
    if (temp != nullptr) {
        cout << "[" << temp->category << "] ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(Node* temp) {
    if (temp != nullptr) {
        inorder(temp->left);
        cout << "[" << temp->category << "] ";
        inorder(temp->right);
    }
}

void postorder(Node* temp) {
    if (temp != nullptr) {
        postorder(temp->left);
        postorder(temp->right);
        cout << "[" << temp->category << "] ";
    }
}

int main() {
    cout << "=== LIBRARY CATALOG HIERARCHY SETUP ===\n";
    Node* root = create();

    cout << "\n--- Library Directory Browsing (Preorder - Top-Down Directory) ---\n";
    preorder(root);
    cout << endl;

    cout << "\n--- Library Sub-sections (Inorder - Left to Right Navigation) ---\n";
    inorder(root);
    cout << endl;

    cout << "\n--- Catalog Clean-up / Bottom-Up Summary (Postorder) ---\n";
    postorder(root);
    cout << endl;

    return 0;
}