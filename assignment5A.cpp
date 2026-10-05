//Create a binary search tree and perform Inorder and Preorder non-recursive
#include <iostream>
#include <stack>

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

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

void nonRecursiveInorder(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";
        curr = curr->right;
    }
}

void nonRecursivePreorder(Node* root) {
    if (root == nullptr) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();

        cout << curr->data << " ";

        if (curr->right != nullptr) {
            st.push(curr->right);
        }
        if (curr->left != nullptr) {
            st.push(curr->left);
        }
    }
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nNon-Recursive Inorder Traversal: ";
    nonRecursiveInorder(root);
    cout << endl;

    cout << "Non-Recursive Preorder Traversal: ";
    nonRecursivePreorder(root);
    cout << endl;

    return 0;
}