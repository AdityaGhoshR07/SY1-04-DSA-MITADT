//Queue – Ticket Booking Counter Simulation. Implement a Queue using an array 
#include <iostream>

using namespace std;

class Queue {
public:
    int F;
    int R;
    int qt[100];

    Queue() {
        F = -1;
        R = -1;
        for (int i = 0; i < 100; i++) {
            qt[i] = 0;
        }
    }

    void insert(int x) {
        if (R == 99) {
            cout << "Queue Overflow" << endl;
            return;
        }

        R += 1;
        qt[R] = x;

        if (F == -1) {
            F = 0;
        }
    }

    int deleteElement() {
        if (F == -1) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int x = qt[F];

        if (F == R) {
            F = R = -1;
        } else {
            F += 1;
        }

        return x;
    }

    void peek() {
        if (F == -1) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << "Front Element = " << qt[F] << endl;
        }
    }

    void display() {
        if (F == -1) {
            cout << "Queue is Empty" << endl;
        } else {
            for (int i = F; i <= R; i++) {
                cout << qt[i] << " ";
            }
            cout << endl;
        }
    }
};

class TicketCounter {
private:
    Queue q;

public:
    void addCustomer(int id) {
        if (q.R == 99) {
            cout << "Line is full! Cannot add customer " << id << endl;
            return;
        }
        q.insert(id);
        cout << "Customer " << id << " joined the line." << endl;
    }

    void bookTicket() {
        int id = q.deleteElement();
        if (id != -1) {
            cout << "Ticket booked for Customer " << id << "!" << endl;
        }
    }

    void nextCustomer() {
        if (q.F == -1) {
            cout << "No customers in line." << endl;
            return;
        }
        cout << "Next customer to be served: " << q.qt[q.F] << endl;
    }

    void showQueue() {
        if (q.F == -1) {
            cout << "Line is currently empty." << endl;
            return;
        }
        cout << "Current line (Front to Rear): ";
        q.display();
    }
};

int main() {
    TicketCounter counter;

    counter.addCustomer(201);
    counter.addCustomer(202);
    counter.addCustomer(203);

    counter.showQueue();
    counter.nextCustomer();

    counter.bookTicket();
    counter.showQueue();

    counter.bookTicket();
    counter.bookTicket();
    counter.bookTicket();

    return 0;
}