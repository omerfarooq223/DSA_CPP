#include <iostream>
#include <string>

template <typename T>
class Stack {
public:
    int top;
    int capacity;
    T* arr;

    Stack(int size) : top(-1), capacity(size) {
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T value) {
        if (top >= capacity - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
        std::cout << value << " pushed to stack\n";
    }

    T pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return T(); // Return default value for type T
        }
        return arr[top--];
    }

    T peek() {
        if (top < 0) {
            std::cout << "Stack is empty\n";
            return T();
        }
        return arr[top];
    }

    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the stack: ";
    if (!(std::cin >> size)) return 1;

    Stack<int> stack(size);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element is: " << stack.peek() << "\n";
    std::cout << stack.pop() << " popped from stack\n";
    std::cout << "Top element is: " << stack.peek() << "\n";

    if (stack.isEmpty())
        std::cout << "Stack is empty\n";
    else
        std::cout << "Stack is not empty\n";

    return 0;
}
