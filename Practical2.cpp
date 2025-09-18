/*
Write a menu driven program that maintains a linear linked list whose elements are stored in ascending order and implements the following operations (using separate functions):
  1. Insert a new element
  2. Delete an existing element
  3. Search an element
  4. Display all the elements
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList() {
        head = nullptr;
    }

    // Function to insert while maintaining ascending order
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr || value < head->data) {
            newNode->next = head;
            head = newNode;
        } 
        else {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->data < value) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Element inserted successfully!\n";
    }

    // Function to delete a node by value
    void deleteElement(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Element not found!\n";
            return;
        }

        if (prev == nullptr) { // Deleting head node
            head = head->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Element deleted successfully!\n";
    }

    // Function to search for an element
    void search(int value) {
        Node* temp = head;
        int position = 0;
        bool found = false;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Element found at position: " << position << endl;
                found = true;
            }
            temp = temp->next;
            position++;
        }

        if (!found)
            cout << "Element not found!\n";
    }

    // Function to display all elements
    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List elements (Ascending Order): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SortedLinkedList list;
    int choice, value;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Search Element\n";
        cout << "4. Display Elements\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insert(value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteElement(value);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;

        case 4:
            list.display();
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
✔ Ascending Order Insertion (maintains sorted order automatically)
✔ Delete Element by Value (works for head, middle, and last node)
✔ Search Element (shows position if found)
✔ Display All Elements (prints in ascending order)
✔ Menu-Driven & User-Friendly
  */
