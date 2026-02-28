#include <iostream>
#include <string>
using namespace std;

// ─────────────────────────────────────────────
//  CourseNode
// ─────────────────────────────────────────────
class CourseNode {
public:
    string courseName;
    int    capacity;
    int    registeredStudents;
    CourseNode* left;
    CourseNode* right;

    CourseNode(const string& name, int cap)
        : courseName(name), capacity(cap), registeredStudents(0),
          left(nullptr), right(nullptr) {}

    ~CourseNode() { delete left; delete right; }
};

// ─────────────────────────────────────────────
//  DepartmentNode
// ─────────────────────────────────────────────
class DepartmentNode {
public:
    string       departmentName;
    CourseNode*  courseRoot;
    DepartmentNode* left;
    DepartmentNode* right;

    DepartmentNode(const string& name)
        : departmentName(name), courseRoot(nullptr),
          left(nullptr), right(nullptr) {}

    ~DepartmentNode() { delete courseRoot; delete left; delete right; }
};

// ─────────────────────────────────────────────
//  DepartmentTree  (BST of departments,
//                   each holding a BST of courses)
// ─────────────────────────────────────────────
class DepartmentTree {
public:
    DepartmentNode* root;

    DepartmentTree() : root(nullptr) {}
    ~DepartmentTree() { delete root; }

    // ── departments ──────────────────────────
    void addDepartment(const string& name) {
        root = insertDept(root, name);
    }

    DepartmentNode* searchDepartment(const string& name) {
        return findDept(root, name);
    }

    // ── courses ──────────────────────────────
    void addCourse(const string& deptName, const string& courseName, int capacity) {
        DepartmentNode* dept = searchDepartment(deptName);
        if (!dept) { cout << "Department not found!\n"; return; }
        dept->courseRoot = insertCourse(dept->courseRoot, courseName, capacity);
    }

    CourseNode* searchCourse(const string& deptName, const string& courseName) {
        DepartmentNode* dept = searchDepartment(deptName);
        if (!dept) { cout << "Department not found!\n"; return nullptr; }
        return findCourse(dept->courseRoot, courseName);
    }

    void displayCourses(const string& deptName) {
        DepartmentNode* dept = searchDepartment(deptName);
        if (!dept) { cout << "Department not found!\n"; return; }
        printCourses(dept->courseRoot);
    }

private:
    DepartmentNode* insertDept(DepartmentNode* node, const string& name) {
        if (!node) return new DepartmentNode(name);
        if      (name < node->departmentName) node->left  = insertDept(node->left,  name);
        else if (name > node->departmentName) node->right = insertDept(node->right, name);
        else cout << "Department already exists.\n";
        return node;
    }

    DepartmentNode* findDept(DepartmentNode* node, const string& name) {
        if (!node || node->departmentName == name) return node;
        return (name < node->departmentName)
               ? findDept(node->left, name)
               : findDept(node->right, name);
    }

    CourseNode* insertCourse(CourseNode* node, const string& name, int cap) {
        if (!node) return new CourseNode(name, cap);
        if      (name < node->courseName) node->left  = insertCourse(node->left,  name, cap);
        else if (name > node->courseName) node->right = insertCourse(node->right, name, cap);
        else cout << "Course already exists in this department.\n";
        return node;
    }

    CourseNode* findCourse(CourseNode* node, const string& name) {
        if (!node || node->courseName == name) return node;
        return (name < node->courseName)
               ? findCourse(node->left,  name)
               : findCourse(node->right, name);
    }

    void printCourses(CourseNode* node) {
        if (!node) return;
        printCourses(node->left);
        cout << "  " << node->courseName
             << " | Registered: " << node->registeredStudents
             << "/" << node->capacity << "\n";
        printCourses(node->right);
    }
};

// ─────────────────────────────────────────────
//  Queue  (waitlist)
// ─────────────────────────────────────────────
class QueueNode {
public:
    string     studentName;
    QueueNode* next;
    QueueNode(const string& name) : studentName(name), next(nullptr) {}
};

class Queue {
public:
    QueueNode* front;
    QueueNode* rear;

    Queue() : front(nullptr), rear(nullptr) {}
    ~Queue() { while (!isEmpty()) dequeue(); }

    void enqueue(const string& name) {
        QueueNode* node = new QueueNode(name);
        if (!rear) { front = rear = node; return; }
        rear->next = node;
        rear = node;
    }

    string dequeue() {
        if (!front) return "";
        QueueNode* temp = front;
        string name = temp->studentName;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        return name;
    }

    bool isEmpty() const { return front == nullptr; }
};

// ─────────────────────────────────────────────
//  Stack  (undo history)
// ─────────────────────────────────────────────
class StackNode {
public:
    string     action, departmentName, courseName;
    StackNode* next;
    StackNode(const string& act, const string& dept, const string& course)
        : action(act), departmentName(dept), courseName(course), next(nullptr) {}
};

class Stack {
public:
    StackNode* top;

    Stack() : top(nullptr) {}
    ~Stack() { string d, c; while (!isEmpty()) pop(d, c); }

    void push(const string& action, const string& dept, const string& course) {
        StackNode* node = new StackNode(action, dept, course);
        node->next = top;
        top = node;
    }

    string pop(string& dept, string& course) {
        if (!top) return "";
        StackNode* temp = top;
        string action   = temp->action;
        dept   = temp->departmentName;
        course = temp->courseName;
        top = top->next;
        delete temp;
        return action;
    }

    bool isEmpty() const { return top == nullptr; }
};

// ─────────────────────────────────────────────
//  LinkedList  (student's registered courses)
// ─────────────────────────────────────────────
class ListNode {
public:
    string    courseName;
    ListNode* next;
    ListNode(const string& course) : courseName(course), next(nullptr) {}
};

class LinkedList {
public:
    ListNode* head;
    int       count;

    LinkedList() : head(nullptr), count(0) {}
    ~LinkedList() { ListNode* cur = head; while (cur) { ListNode* t = cur->next; delete cur; cur = t; } }

    void addCourse(const string& course) {
        ListNode* node = new ListNode(course);
        node->next = head;
        head = node;
        ++count;
    }

    void removeCourse(const string& course) {
        ListNode* cur = head, *prev = nullptr;
        while (cur && cur->courseName != course) { prev = cur; cur = cur->next; }
        if (!cur) return;
        if (!prev) head = cur->next;
        else        prev->next = cur->next;
        delete cur;
        --count;
    }

    void display() const {
        ListNode* cur = head;
        if (!cur) { cout << "  (none)\n"; return; }
        while (cur) { cout << "  - " << cur->courseName << "\n"; cur = cur->next; }
    }
};

// ─────────────────────────────────────────────
//  Helpers
// ─────────────────────────────────────────────
static const int MAX_COURSES     = 6;
static const int MAX_CAPACITY    = 50;

void printMenu() {
    cout << "\n====================================================\n";
    cout << "        University Course Registration System\n";
    cout << "====================================================\n";
    cout << "  1. Add Department\n";
    cout << "  2. Add Course\n";
    cout << "  3. Search Course\n";
    cout << "  4. Register for Course\n";
    cout << "  5. Drop Course\n";
    cout << "  6. Undo Last Action\n";
    cout << "  7. Display My Courses\n";
    cout << "  8. Exit\n";
    cout << "----------------------------------------------------\n";
    cout << "Choice: ";
}

// Safe single-token input (flushes the newline)
string readToken(const string& prompt) {
    string val;
    cout << prompt;
    cin >> val;
    return val;
}

// ─────────────────────────────────────────────
//  RegistrationSystem
// ─────────────────────────────────────────────
class RegistrationSystem {
private:
    DepartmentTree departmentTree;
    Queue          waitlist;
    Stack          undoStack;
    LinkedList     studentRecords;
    string         studentName;

public:
    void run() {
        cout << "Enter your name: ";
        getline(cin, studentName);   // safe — called before any cin >>

        int choice = 0;
        do {
            printMenu();
            cin >> choice;
            cin.ignore();            // consume trailing newline once, here

            switch (choice) {
                case 1: handleAddDepartment();  break;
                case 2: handleAddCourse();      break;
                case 3: handleSearchCourse();   break;
                case 4: handleRegister();       break;
                case 5: handleDrop();           break;
                case 6: handleUndo();           break;
                case 7: handleDisplay();        break;
                case 8: cout << "Goodbye!\n";  break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 8);
    }

private:
    // ── case 1 ───────────────────────────────
    void handleAddDepartment() {
        string name = readToken("Department name: ");
        departmentTree.addDepartment(name);
        cout << "Department added.\n";
    }

    // ── case 2 ───────────────────────────────
    void handleAddCourse() {
        string dept   = readToken("Department name: ");
        string course = readToken("Course name: ");

        string code;
        cout << "Course code: "; cin >> code;
        // Freshman if numeric part is 100-199
        int numericCode = 0;
        for (char ch : code) if (isdigit(ch)) numericCode = numericCode * 10 + (ch - '0');
        cout << ((numericCode >= 100 && numericCode <= 199) ? "Level: Freshman\n" : "Level: Sophomore+\n");

        int capacity = 0;
        do {
            cout << "Capacity (1-" << MAX_CAPACITY << "): ";
            if (!(cin >> capacity)) {
                cin.clear();
                cin.ignore(1000, '\n');
                capacity = 0;
            }
            if (capacity < 1 || capacity > MAX_CAPACITY)
                cout << "Invalid capacity. Must be between 1 and " << MAX_CAPACITY << ".\n";
        } while (capacity < 1 || capacity > MAX_CAPACITY);

        departmentTree.addCourse(dept, course, capacity);
        cout << "Course added.\n";
    }

    // ── case 3 ───────────────────────────────
    void handleSearchCourse() {
        string dept   = readToken("Department name: ");
        string course = readToken("Course name: ");

        CourseNode* c = departmentTree.searchCourse(dept, course);
        if (c) {
            cout << "Course   : " << c->courseName      << "\n"
                 << "Capacity : " << c->capacity        << "\n"
                 << "Registered: " << c->registeredStudents << "\n";
        } else {
            cout << "Course not found.\n";
        }
    }

    // ── case 4 ───────────────────────────────
    void handleRegister() {
        if (studentRecords.count >= MAX_COURSES) {
            cout << "You are already registered for " << MAX_COURSES << " courses (maximum).\n";
            return;
        }

        string dept   = readToken("Department name: ");
        string course = readToken("Course name: ");

        CourseNode* c = departmentTree.searchCourse(dept, course);
        if (!c) { cout << "Course not found.\n"; return; }

        if (c->registeredStudents < c->capacity) {
            c->registeredStudents++;
            studentRecords.addCourse(course);
            undoStack.push("register", dept, course);
            cout << "Successfully registered for " << course << ".\n";
        } else {
            waitlist.enqueue(studentName);
            cout << "Course is full. " << studentName << " added to waitlist.\n";
        }
    }

    // ── case 5 ───────────────────────────────
    void handleDrop() {
        string dept   = readToken("Department name: ");
        string course = readToken("Course name: ");

        CourseNode* c = departmentTree.searchCourse(dept, course);
        if (!c) { cout << "Course not found.\n"; return; }

        if (c->registeredStudents == 0) {
            cout << "No students registered for this course.\n";
            return;
        }

        c->registeredStudents--;
        studentRecords.removeCourse(course);
        undoStack.push("drop", dept, course);
        cout << "Dropped " << course << ".\n";

        if (!waitlist.isEmpty()) {
            string next = waitlist.dequeue();
            c->registeredStudents++;
            cout << next << " from the waitlist has been enrolled.\n";
        }
    }

    // ── case 6 ───────────────────────────────
    void handleUndo() {
        if (undoStack.isEmpty()) { cout << "Nothing to undo.\n"; return; }

        string dept, course;
        string action = undoStack.pop(dept, course);
        CourseNode* c = departmentTree.searchCourse(dept, course);
        if (!c) { cout << "Could not locate course for undo.\n"; return; }

        if (action == "register" && c->registeredStudents > 0) {
            c->registeredStudents--;
            studentRecords.removeCourse(course);
            cout << "Undone: registration for " << course << ".\n";
        } else if (action == "drop" && c->registeredStudents < c->capacity) {
            c->registeredStudents++;
            studentRecords.addCourse(course);
            cout << "Undone: drop of " << course << ".\n";
        } else {
            cout << "Undo not possible for this action.\n";
        }
    }

    // ── case 7 ───────────────────────────────
    void handleDisplay() {
        cout << "Registered courses for " << studentName << ":\n";
        studentRecords.display();
    }
};

// ─────────────────────────────────────────────
//  main
// ─────────────────────────────────────────────
int main() {
    RegistrationSystem system;
    system.run();
    return 0;
}