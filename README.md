# DSA C++ Core & Semester Archive

A comprehensive collection of **Data Structures and Algorithms (DSA)** in C++, featuring both modernized, template-based implementations and original university coursework.

---

## 📂 Project Structure

```text

├── 🚀 Modernized Version (C++17 Templates)
│   ├── bst/                # Binary Search Tree
│   ├── linked-list/        # Singly Linked List
│   ├── stack/              # Dynamic & Static Stacks
│   ├── sorting/            # Bubble & Selection Sort
│   ├── searching/          # Binary & Linear Search
│   └── array-operations/   # Base Array Operations
│
├── 🎓 Original Semester Archive
│   └── original-semester-codes/
│       ├── bst/
│       ├── linked-list/
│       ├── stack/
│       ├── sorting/
│       ├── searching/
│       └── array-operations/
│
├── 🛠️ Build System
│   └── Makefile           # Multi-target build script
└── 📖 README.md           # Documentation
```

---

## ✨ Features

### Modernized Version (Core)
- **Generic Programming**: All core structures use **C++ templates**, making them compatible with any data type (`int`, `double`, `std::string`, etc.).
- **Memory Safety**: Manual memory management with recursive destructors for dynamic structures.
- **Clean API**: Consistent method naming and improved readability.
- **Modern Standards**: Compiled using the `C++17` standard.

### Original Archive
- **Historical Reference**: The exact codes learned during the 3rd-semester university curriculum.
- **Fundamental Logic**: Great for quickly referencing basic C++ concepts without the complexity of templates.

---

## 🚀 Getting Started

### Prerequisites
- `g++` compiler supporting C++17.
- `make` (optional, for the automated build system).

### Build Modernized Files
Use the provided `Makefile` to compile all modern examples:
```bash
make
```
To build a specific version:
```bash
g++ -std=c++17 bst/bst.cpp -o bst_demo
./bst_demo
```

### Run Original Codes
Navigate to the `original-semester-codes/` directory and compile manually:
```bash
g++ bst/bst.cpp -o original_bst
./original_bst
```

---

## 🤝 Contribution
This is a personal learning archive, but feel free to fork it for your own practice!

---

## 📝 License
This project is for educational purposes.
