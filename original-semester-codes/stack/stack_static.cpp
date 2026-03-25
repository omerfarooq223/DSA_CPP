#include <iostream>
using namespace std;

class Stack {
public:
    int arr[20];
    int top;
    int max_size;

    Stack() {
        max_size = 20;
        top = -1;
    }

    void push(int data) {
        if (!isFull()) {
            top++;
            arr[top] = data;
            cout << data << " pushed to stack\n";
        } else {
            cout << "Stack Overflow\n";
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    void peek() {
        if (!isEmpty())
            cout << "Top element is: " << arr[top] << "\n";
        else
            cout << "Stack is empty\n";
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == max_size - 1;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.peek();

    cout << stack.pop() << " popped from stack\n";
    stack.peek();

    if (stack.isEmpty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";

    return 0;
}
