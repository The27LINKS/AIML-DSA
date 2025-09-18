/*
Program to demonstrate the use of stack (implemented using linear linked list) in evaluating arithmetic expression in postfix notation.
*/
#include <iostream>
#include <cctype>
#include <cmath>
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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        Node* temp = top;
        int popped = temp->data;
        top = top->next;
        delete temp;
        return popped;
    }

    int peek() {
        if (isEmpty())
            return -1;
        return top->data;
    }
};

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    Stack s;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert char to int
        } 
        else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (ch) {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            case '^':
                s.push(pow(val1, val2));
                break;
            default:
                cout << "Invalid Operator: " << ch << endl;
            }
        }
    }
    return s.pop();
}

int main() {
    string postfix;

    cout << "Enter a postfix expression (single-digit operands only): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);

    cout << "Result of postfix evaluation: " << result << endl;

    return 0;
}
/*
✅ Features:
✔ Stack implemented with Linked List
✔ *Supports +, -, , /, ^ operators
✔ Works with single-digit operands (you can extend for multi-digit if needed)
✔ Evaluates and prints final result
*/
