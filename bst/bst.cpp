#include <iostream>
#include <string>

// Node structure
template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T val) : data(val), left(nullptr), right(nullptr) {}
};

// BST class
template <typename T>
class BST {
private:
    // Helper for recursive deletion
    void clear(Node<T>* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    Node<T>* root;

    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    // Insert a node recursively
    Node<T>* insert(Node<T>* current, T val) {
        if (!current) return new Node<T>(val);
        if (val < current->data)
            current->left = insert(current->left, val);
        else if (val > current->data)
            current->right = insert(current->right, val);
        return current;
    }

    // Search for a value
    bool search(Node<T>* current, T key) {
        if (!current) return false;
        if (current->data == key) return true;
        if (key < current->data)
            return search(current->left, key);
        else
            return search(current->right, key);
    }

    // Find minimum value node
    Node<T>* findMin(Node<T>* current) {
        while (current && current->left)
            current = current->left;
        return current;
    }

    // Delete a node
    Node<T>* deleteNode(Node<T>* current, T key) {
        if (!current) return nullptr;

        if (key < current->data)
            current->left = deleteNode(current->left, key);
        else if (key > current->data)
            current->right = deleteNode(current->right, key);
        else {
            // Node found
            if (!current->left && !current->right) {
                delete current;
                return nullptr;
            } else if (!current->left) {
                Node<T>* temp = current->right;
                delete current;
                return temp;
            } else if (!current->right) {
                Node<T>* temp = current->left;
                delete current;
                return temp;
            } else {
                Node<T>* temp = findMin(current->right);
                current->data = temp->data;
                current->right = deleteNode(current->right, temp->data);
            }
        }
        return current;
    }

    // Traversals
    void inorder(Node<T>* current) {
        if (!current) return;
        inorder(current->left);
        std::cout << current->data << " ";
        inorder(current->right);
    }

    void preorder(Node<T>* current) {
        if (!current) return;
        std::cout << current->data << " ";
        preorder(current->left);
        preorder(current->right);
    }

    void postorder(Node<T>* current) {
        if (!current) return;
        postorder(current->left);
        postorder(current->right);
        std::cout << current->data << " ";
    }
};

// Main function to test BST
int main() {
    BST<int> tree;
    int choice, val;

    while (true) {
        std::cout << "\n--- BST Menu ---\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Search\n";
        std::cout << "4. Inorder Traversal\n";
        std::cout << "5. Preorder Traversal\n";
        std::cout << "6. Postorder Traversal\n";
        std::cout << "7. Exit\n";
        std::cout << "Choice: ";
        if (!(std::cin >> choice)) break;

        switch (choice) {
        case 1:
            std::cout << "Enter value: ";
            std::cin >> val;
            tree.root = tree.insert(tree.root, val);
            break;
        case 2:
            std::cout << "Enter value to delete: ";
            std::cin >> val;
            tree.root = tree.deleteNode(tree.root, val);
            break;
        case 3:
            std::cout << "Enter value to search: ";
            std::cin >> val;
            std::cout << (tree.search(tree.root, val) ? "Found" : "Not Found") << "\n";
            break;
        case 4:
            std::cout << "Inorder: ";
            tree.inorder(tree.root);
            std::cout << "\n";
            break;
        case 5:
            std::cout << "Preorder: ";
            tree.preorder(tree.root);
            std::cout << "\n";
            break;
        case 6:
            std::cout << "Postorder: ";
            tree.postorder(tree.root);
            std::cout << "\n";
            break;
        case 7:
            std::cout << "Exiting.\n";
            return 0;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
