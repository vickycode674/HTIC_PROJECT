# C++ Developer - Technical Assignment

This repository contains the solution for the **C++ Developer Technical Assignment**, demonstrating proficiency in multithreading, file I/O with encryption, and real-time multimedia processing using OpenCV.

---

## 📁 Contents

| Task No. | Description |
|----------|-------------|
| Task 1   | Multithreaded printing of even and odd numbers |
| Task 2   | File encryption/decryption and hierarchical storage |
| Task 3   | Real-time video capture with OpenCV and multithreading |

---

## 🔧 Setup Instructions

### 🔹 Prerequisites

- **C++17 or later**
- **OpenCV 4.x**
- **CMake (optional, or configure build manually)**
- **Compiler**:
  - Windows: `MSVC` (preferred) or `MinGW + OpenCV GCC build`
  - Linux/macOS: `g++` and `pkg-config` for OpenCV

---

## 🧵 Task 1: Multithreaded Even-Odd Printer

### ✅ Description
Two threads alternately print even and odd numbers using `std::thread` and mutex-based synchronization.

### 🔹 Compile and Run

```bash
g++ -std=c++17 task1_even_odd.cpp -o even_odd
./even_odd
