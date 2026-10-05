// Student Admission Record Management: Design a BST to store
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    int rollNo;
    string name;
    string course;
    Student* left;
    Student* right;

    Student(int r, string n, string c) {
        rollNo = r;
        name = n;
        course = c;
        left = nullptr;
        right = nullptr;
    }
};

class AdmissionBST {
private:
    Student* root;

    Student* insertRecord(Student* node, int r, string n, string c) {
        if (node == nullptr) {
            return new Student(r, n, c);
        }

        if (r < node->rollNo) {
            node->left = insertRecord(node->left, r, n, c);
        } else if (r > node->rollNo) {
            node->right = insertRecord(node->right, r, n, c);
        } else {
            cout << "Record with Roll No " << r << " already exists." << endl;
        }

        return node;
    }

    Student* searchRecord(Student* node, int r) {
        if (node == nullptr || node->rollNo == r) {
            return node;
        }

        if (r < node->rollNo) {
            return searchRecord(node->left, r);
        }
        return searchRecord(node->right, r);
    }

    void displaySorted(Student* node) {
        if (node != nullptr) {
            displaySorted(node->left);
            cout << "Roll No: " << node->rollNo 
                 << " | Name: " << node->name 
                 << " | Course: " << node->course << endl;
            displaySorted(node->right);
        }
    }

public:
    AdmissionBST() {
        root = nullptr;
    }

    void insert(int r, string n, string c) {
        root = insertRecord(root, r, n, c);
    }

    void search(int r) {
        Student* res = searchRecord(root, r);
        if (res == nullptr) {
            cout << "Student with Roll No " << r << " not found." << endl;
        } else {
            cout << "Record Found -> Roll No: " << res->rollNo 
                 << ", Name: " << res->name 
                 << ", Course: " << res->course << endl;
        }
    }

    void displayAll() {
        if (root == nullptr) {
            cout << "No admission records found." << endl;
            return;
        }
        cout << "\n--- Student Admission Records (Sorted by Roll No) ---\n";
        displaySorted(root);
        cout << "-----------------------------------------------------\n";
    }
};

int main() {
    AdmissionBST bst;

    bst.insert(105, "Alice", "Computer Science");
    bst.insert(102, "Bob", "Information Technology");
    bst.insert(108, "Charlie", "Mechanical");
    bst.insert(101, "Diana", "Civil");
    bst.insert(104, "Evan", "Electronics");

    bst.displayAll();

    cout << "\nSearching for Roll No 104:\n";
    bst.search(104);

    cout << "\nSearching for Roll No 110:\n";
    bst.search(110);

    return 0;
}