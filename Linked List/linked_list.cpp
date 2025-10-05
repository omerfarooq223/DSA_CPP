#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
};

// LinkedList class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning.";
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at the end.";
    }

    // Insert after a given value
    void insertAfterValue(int target, int value) {
        Node* temp = head;
        while (temp && temp->data != target)
            temp = temp->next;

        if (!temp) {
            cout << "Node with value " << target << " not found.";
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << target << ".";
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty.";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning.";
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty.";
            return;
        }

        if (!head->next) {
            cout << "Deleted " << head->data << " from end.";
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;

        cout << "Deleted " << temp->next->data << " from end.";
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete a specific value
    void deleteByValue(int value) {
        if (!head) {
            cout << "List is empty.";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted node with value " << value << ".";
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value)
            temp = temp->next;

        if (!temp->next) {
            cout << "Node with value " << value << " not found.";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Deleted node with value " << value << ".";
        delete toDelete;
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty.";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

// Main function to test
int main() {
    LinkedList list;
    int choice, value, target;

    while (true) {
        cout << "--- Linked List Menu ---";
        cout << "1. Insert at Beginning";
        cout << "2. Insert at End";
        cout << "3. Insert After a Value";
        cout << "4. Delete from Beginning";
        cout << "5. Delete from End";
        cout << "6. Delete by Value";
        cout << "7. Display List";
        cout << "8. Exit";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter target value: ";
            cin >> target;
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAfterValue(target, value);
