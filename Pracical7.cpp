/*
Program to demonstrate the implementation of various operations on a queue represented using a linear linked list (linked queue).
*/
#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Queue class using linked list
class LinkedQueue {
private:
    Node* front;
    Node* rear;

public:
    LinkedQueue() {
        front = rear = nullptr;
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;  // First element in queue
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued into queue.\n";
    }

    // Function to remove an element from the queue (dequeue)
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow! Cannot dequeue.\n";
            return;
        }

        Node* temp = front;
        cout << temp->data << " dequeued from queue.\n";
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;  // Queue becomes empty
        }

        delete temp;
    }

    // Function to display all elements in the queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~LinkedQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// Main function to test the linked queue
int main() {
    LinkedQueue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
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
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
/*
✅ Features Covered:
Uses linked list for queue implementation.
Performs enqueue, dequeue, display operations.
Handles underflow condition when dequeue is called on an empty queue.
Proper memory cleanup using a destructor.
*/
