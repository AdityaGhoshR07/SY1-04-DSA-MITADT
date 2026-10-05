//Stack – Library Book Return Management. Implement a stack to manage returned books
#include <iostream>
using namespace std;
class Stack {
public:
    int TOP;
    int st[100];

    Stack() {
        TOP = -1;
        for (int i = 0; i < 100; i++) {
            st[i] = 0;
        }
    }
    void push(int x) {
        if (TOP == 99) {
            cout << "Stack Overflow" << endl;
            return;
        }

        TOP += 1;
        st[TOP] = x;
    }
    int pop() {
        if (TOP == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int x = st[TOP];
        TOP -= 1;
        return x;
    }
};
class LibraryManager {
private:
    Stack s;
public:
    void returnBook(int id) {
        if (s.TOP == 99) {
            cout << "Bin full!" << endl;
            return;
        }
        s.push(id);
        cout << "Returned book ID: " << id << endl;
    }
    void reshelfBook() {
        int id = s.pop();
        if (id != -1) {
            cout << "Reshelving book ID: " << id << endl;
        }
    }
    void peek() {
        if (s.TOP == -1) {
            cout << "No books in bin." << endl;
            return;
        }
        cout << "Next to reshelf: " << s.st[s.TOP] << endl;
    }
    void display() {
        if (s.TOP == -1) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Returned books:" << endl;
        for (int i = s.TOP; i >= 0; i--) {
            cout << s.st[i] << endl;
        }
    }
};
int main() {
    LibraryManager lib;

    lib.returnBook(101);
    lib.returnBook(102);
    lib.returnBook(103);

    lib.display();
    lib.peek();

    lib.reshelfBook();
    lib.display();

    return 0;
}