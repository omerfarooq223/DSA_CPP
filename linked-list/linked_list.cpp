#include <iostream>
#include <string>
// Node structure
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T val) : data(val), next(nullptr) {}
};

// LinkedList class
template <typename T>
class LinkedList {
public:
    Node<T>* head;

    LinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert at beginning
    void insertAtBeginning(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        std::cout << "Inserted " << value << " at the beginning.\n";
    }

    // Insert at end
    void insertAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        std::cout << "Inserted " << value << " at the end.\n";
    }

    // Insert after a given value
    void insertAfterValue(T target, T value) {
        Node<T>* temp = head;
        while (temp && temp->data != target)
            temp = temp->next;

        if (!temp) {
            std::cout << "Node with value " << target << " not found.\n";
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        newNode->next = temp->next;
        temp->next = newNode;
        std::cout << "Inserted " << value << " after " << target << ".\n";
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        std::cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }

        if (!head->next) {
            std::cout << "Deleted " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* temp = head;
        while (temp->next->next)
            temp = temp->next;

        std::cout << "Deleted " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete a specific value
    void deleteByValue(T value) {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            std::cout << "Deleted node with value " << value << ".\n";
            delete temp;
            return;
        }

        Node<T>* temp = head;
        while (temp->next && temp->next->data != value)
            temp = temp->next;

        if (!temp->next) {
            std::cout << "Node with value " << value << " not found.\n";
            return;
        }

        Node<T>* toDelete = temp->next;
        temp->next = temp->next->next;
        std::cout << "Deleted node with value " << value << ".\n";
        delete toDelete;
    }

    // Display the list
    void display() {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }

        Node<T>* temp = head;
        std::cout << "Linked List: ";
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

// Main function to test
int main() {
    LinkedList<int> list;
    int choice, value, target;

    while (true) {
        std::cout << "\n--- Linked List Menu ---\n";
        std::cout << "1. Insert at Beginning\n";
        std::cout << "2. Insert at End\n";
        std::cout << "3. Insert After a Value\n";
        std::cout << "4. Delete from Beginning\n";
        std::cout << "5. Delete from End\n";
        std::cout << "6. Delete by Value\n";
        std::cout << "7. Display List\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice)) break;

        switch (choice) {
        case 1:
            std::cout << "Enter value: ";
            std::cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            std::cout << "Enter value: ";
            std::cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            std::cout << "Enter target value: ";
            std::cin >> target;
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            list.insertAfterValue(target, value);
            break;
        case 4:
            list.deleteFromBeginning();
            break;
        case 5:
            list.deleteFromEnd();
            break;
        case 6:
            std::cout << "Enter value: ";
            std::cin >> value;
            list.deleteByValue(value);
            break;
        case 7:
            list.display();
            break;
        case 8:
            std::cout << "Exiting.\n";
            return 0;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
