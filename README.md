# 🧠 Memory Block Allocation Simulator using Linked List (C++)

This project is a **simulation of memory management in an operating system**, implemented using a **Singly Linked List in C++**.  
It demonstrates how memory blocks are allocated, freed, split, and merged dynamically.

The project is designed for **beginners** to clearly understand **Linked Lists with a real-world application**.

---

## 📌 Features

- Uses **Linked List** to represent memory blocks
- Implements **First Fit memory allocation strategy**
- Supports:
  - Allocate memory
  - Free memory
  - Merge adjacent free blocks
  - Display memory layout
- Prevents memory fragmentation
- Menu-driven and easy to use

---

## 🧩 Data Structure Used

**Singly Linked List**

Each node represents a memory block with:
- Block ID
- Block Size
- Block Status (FREE / USED)
- Pointer to the next block

---

## 🏗 Project Workflow

1. Initialize total memory as one large FREE block
2. Allocate memory using **First Fit**
3. Split blocks if required
4. Free memory blocks by ID
5. Merge adjacent FREE blocks
6. Display current memory state

---



