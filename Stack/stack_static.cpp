#include <iostream>
#include <string>

template <typename T, int Size = 20>
class Stack {
public:
    T arr[Size];
    int top;

    Stack() : top(-1) {}

    void push(T data) {
        if (!isFull()) {
            arr[++top] = data;
            std::cout << data << " pushed to stack\n";
        } else {
            std::cout << "Stack Overflow\n";
        }
    }

    T pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return T();
        }
        return arr[top--];
    }

    void peek() {
        if (!isEmpty())
            std::cout << "Top element is: " << arr[top] << "\n";
        else
            std::cout << "Stack is empty\n";
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == Size - 1;
    }
};

int main() {
    Stack<int, 20> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.peek();

    std::cout << stack.pop() << " popped from stack\n";
    stack.peek();

    if (stack.isEmpty())
        std::cout << "Stack is empty\n";
    else
        std::cout << "Stack is not empty\n";

    return 0;
}
