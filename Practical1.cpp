/*
  Write a menu-driven program (using object-oriented approach in C++) to perform the following operations on a linear array:
    Insert a new element at the end as well as at a given position
    Delete an element from a given position or by value
    Find the location of a given element
    Display all elements of the array
*/
#include <iostream>
using namespace std;

class LinearArray {
private:
    int arr[100];
    int size;

public:
    LinearArray() {
        size = 0;
    }

    void insertAtEnd(int value) {
        arr[size++] = value;
        cout << "Element inserted at end successfully!\n";
    }

    void insertAtPosition(int value, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position!\n";
            return;
        }
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        size++;
        cout << "Element inserted at position " << pos << " successfully!\n";
    }

    void deleteByPosition(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!\n";
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element at position " << pos << " deleted successfully!\n";
    }

    void deleteByValue(int value) {
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << "Value not found!\n";
            return;
        }
        deleteByPosition(pos);
    }

    void findElement(int value) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                cout << "Element found at position: " << i << endl;
                found = true;
            }
        }
        if (!found)
            cout << "Element not found!\n";
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    LinearArray obj;
    int choice, value, pos;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Position\n";
        cout << "3. Delete by Position\n";
        cout << "4. Delete by Value\n";
        cout << "5. Find Element\n";
        cout << "6. Display Array\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            obj.insertAtEnd(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position (0-based): ";
            cin >> pos;
            obj.insertAtPosition(value, pos);
            break;

        case 3:
            cout << "Enter position (0-based): ";
            cin >> pos;
            obj.deleteByPosition(pos);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            obj.deleteByValue(value);
            break;

        case 5:
            cout << "Enter value to find: ";
            cin >> value;
            obj.findElement(value);
            break;

        case 6:
            obj.display();
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
/*✅ Features:
✔ Object-Oriented Design (class LinearArray with functions)
✔ Menu-Driven (loop continues until user exits)
✔ Supports Insert at End & Position
✔ Supports Delete by Position & Value
✔ Find Element (prints all positions if multiple exist)
✔ Displays Current Array
*/
