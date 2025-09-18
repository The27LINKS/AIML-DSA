/*
Program to demonstrate the implementation of various operations on a circular queue represented using a linear array.
*/
#include <iostream>
using namespace std;

#define MAX 5  // Size of the circular queue

class CircularQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Function to check if queue is full
    bool isFull() {
        return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
    }

    // Function to check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to insert element in the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }
        if (front == -1) // First element insertion
            front = 0;

        rear = (rear + 1) % MAX;
        arr[rear] = value;
        cout << "Inserted: " << value << endl;
    }

    // Function to delete element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot delete." << endl;
            return;
        }
        cout << "Deleted: " << arr[front] << endl;

        if (front == rear) { // Queue has only one element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    // Function to display elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Operations ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
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
            q.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
/*
✅ Explanation:
enqueue() adds elements in a circular manner using (rear + 1) % MAX.
dequeue() removes elements and moves front circularly.
When front == rear, it resets the queue (empty condition).
Menu-driven approach lets you repeatedly choose operations until you exit.
*/
