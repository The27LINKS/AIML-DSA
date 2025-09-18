/*
Program to demonstrate the implementation of various operations on a linear queue represented using a linear array.
*/
#include <iostream>
using namespace std;

#define MAX 5

class LinearQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert more elements.\n";
            return;
        }
        if (front == -1) // First element
            front = 0;
        arr[++rear] = value;
        cout << "Inserted " << value << " into the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No elements to delete.\n";
            return;
        }
        cout << "Deleted element: " << arr[front] << endl;
        front++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    LinearQueue q;
    int choice, value;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Delete)\n";
        cout << "3. Peek (Front Element)\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

/*
✅ Features:
✔ Queue using Linear Array
✔ Menu-driven for easy testing
✔ Enqueue, Dequeue, Peek, Display implemented
✔ Handles Overflow & Underflow gracefully
*/
