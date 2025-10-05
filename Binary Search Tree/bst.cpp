#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// BST class
class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert a node recursively
    Node* insert(Node* root, int val) {
        if (!root) return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);
        return root;
    }

    // Search for a value
    bool search(Node* root, int key) {
        if (!root) return false;
        if (root->data == key) return true;
        if (key < root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    // Find minimum value node
    Node* findMin(Node* root) {
        while (root && root->left)
            root = root->left;
        return root;
    }

    // Delete a node
    Node* deleteNode(Node* root, int key) {
        if (!root) return nullptr;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            // Node found
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }

    // Traversals
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

// Main function to test BST
int main() {
    BST tree;
    int choice, val;

    while (true) {
        cout << "--- BST Menu ---";
        cout << "1. Insert";
        cout << "2. Delete";
        cout << "3. Search";
        cout << "4. Inorder Traversal";
        cout << "5. Preorder Traversal";
        cout << "6. Postorder Traversal";
        cout << "7. Exit";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            tree.root = tree.insert(tree.root, val);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            tree.root = tree.deleteNode(tree.root, val);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            cout << (tree.search(tree.root, val) ? "Found" : "Not Found") << "";
            break;
        case 4:
            cout << "Inorder: ";
            tree.inorder(tree.root);
            cout << "";
            break;
        case 5:
            cout << "Preorder: ";
            tree.preorder(tree.root);
            cout << "";
            break;
        case 6:
            cout << "Postorder: ";
            tree.postorder(tree.root);
            cout << "";
            break;
        case 7:
            cout << "Exiting.";
            return 0;
        default:
            cout << "Invalid choice. Try again.";
        }
    }
}
