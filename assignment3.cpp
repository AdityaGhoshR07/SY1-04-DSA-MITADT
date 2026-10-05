//Singly Linked List – Dynamic Library Catalog. Insert at beginning, Insert at end, Delete from beginning, and Display operations.
#include <iostream>
using namespace std;

class Node {
public:
    int bookId;
    Node* next;
    Node(int id) {
        bookId = id;
        next = nullptr;
    }
};

class LibraryCatalog {
public:
    Node* head;
    LibraryCatalog() {
        head = nullptr;
    }
    void insertAtBeginning(int id) {
        Node* newNode = new Node(id);
        newNode->next = head;
        head = newNode;
        cout << "Book ID " << id << " added at beginning." << endl;
    }
    void insertAtEnd(int id) {
        Node* newNode = new Node(id);
        if (head == nullptr) {
            head = newNode;
            cout << "Book ID " << id << " added at end." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Book ID " << id << " added at end." << endl;
    }
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "Catalog is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Book ID " << temp->bookId << " removed from beginning." << endl;
        delete temp;
    }
    void display() {
        if (head == nullptr) {
            cout << "Catalog is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Catalog: ";
        while (temp != nullptr) {
            cout << temp->bookId << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LibraryCatalog catalog;
    while (true) {
        cout << "\n----- DYNAMIC LIBRARY CATALOG -----" << endl;
        cout << "1. Insert Book at Beginning\n2. Insert Book at End\n3. Delete Book from Beginning\n4. Display Catalog\n5. Exit" << endl;
        int ch;
        cout << "Enter your choice: ";
        cin >> ch;
        if (ch == 1) {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;
            catalog.insertAtBeginning(id);
        } else if (ch == 2) {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;
            catalog.insertAtEnd(id);
        } else if (ch == 3) {
            catalog.deleteFromBeginning();
        } else if (ch == 4) {
            catalog.display();
        } else if (ch == 5) {
            cout << "Program Ended." << endl;
            break;
        } else {
            cout << "Invalid Choice." << endl;
        }
    }
    return 0;
}