
# 🧠 C++ Developer - Technical Assignment

This repository contains the solution for a C++ Developer Technical Assignment. It demonstrates proficiency in:

- Multithreading  
- File I/O with encryption  
- Real-time multimedia processing using OpenCV  

---

## 📁 Project Contents

| Task No. | Description                                      |
|----------|--------------------------------------------------|
| Task 1   | Multithreaded printing of even and odd numbers   |
| Task 2   | File encryption/decryption and hierarchical storage |
| Task 3   | Real-time video capture with OpenCV and multithreading |

---

## 🔧 Setup Instructions

### 🔹 Prerequisites

- **C++17** or later  
- **OpenCV 4.x** (for Task 3)  
- **CMake** (optional)  
- **Compiler**:
  - Windows: MSVC (preferred) or MinGW with OpenCV
  - Linux/macOS: g++ and pkg-config (for OpenCV)

---

## 🧵 Task 1: Multithreaded Even-Odd Printer

### ✅ Description

A simple C++ application that uses two threads to alternately print even and odd numbers using `std::thread` and `std::mutex`.

### 🛠️ Compile and Run

```bash
g++ -std=c++17 task1_even_odd.cpp -o even_odd
./even_odd
````

---

## 🔐 Task 2: Encrypted Geographical File Storage

### 📌 Overview

This console-based C++ application allows users to securely **store** and **retrieve** text files based on a hierarchical geographical structure:
**Country → State → District**.
All file contents are **encrypted** before saving and decrypted during retrieval.

### 🚀 Features

* 🌍 Directory structure: `./data/<Country>/<State>/<District>/`
* 🔐 Simple encryption algorithm (e.g., Caesar Cipher or XOR)
* 📁 Encrypted file storage
* 📖 Console output of decrypted file contents
* ⚠️ Error handling for missing paths and files

### 🧭 Application Flow

#### ➕ Store a New File

1. Prompts user to enter:

   * Country
   * State
   * District
   * Description
2. Creates nested folders as:

   ```
   ./data/<Country>/<State>/<District>/
   ```
3. Saves encrypted content into a file (e.g., `info.txt`)

#### 🔓 Retrieve and View a File

1. Prompts user for Country, State, and District
2. Locates the encrypted file
3. Decrypts and displays its content in the console

### 🛠️ Compile and Run

```bash
g++ -std=c++17 task2_geo_encrypt.cpp -o geo_encrypt
./geo_encrypt
```

---

## 🎥 Task 3: Real-Time Video Capture App (C++ & OpenCV)

### ✅ Features

* 📷 Live webcam feed in a display window
* 💾 Real-time video recording (`output.avi`)
* 📸 Press `'s'` to take a snapshot (`snap_TIMESTAMP.jpg`)
* ❌ Press `'q'` to quit the app
* 🧵 Multithreaded design for smooth performance

### 🛠️ Requirements

* C++17 or later
* OpenCV 4.x
* MSVC or compatible compiler (tested on Windows)

---

## ⚙️ Build Instructions (Windows + OpenCV)

### 1️⃣ Install OpenCV

Download from [OpenCV.org](https://opencv.org/releases/)
Extract to a location, e.g., `C:\opencv`

### 2️⃣ Build the App with MSVC

Open the **x64 Native Tools Command Prompt** for Visual Studio and run:

```bash
cl task3_video_capture.cpp /EHsc /std:c++17 ^
/I "C:\opencv\build\include" ^
/link /LIBPATH:"C:\opencv\build\x64\vc16\lib" opencv_world470.lib
```

> Replace `470` with your actual OpenCV version.

Make sure `opencv_world470.dll` is either:

* In your system PATH
* In the same directory as the `main.exe`

---

### ▶️ Run the App

```bash
main.exe
```

### 🎮 Controls

* Press `'s'` → Save snapshot
* Press `'q'` → Quit

---

## 📂 Project Structure

```
project/
├── task1_even_odd.cpp        # Task 1 source code
├── task2_geo_encrypt.cpp     # Task 2 source code
├── task3_video_capture.cpp   # Task 3 source code
├── README.md                 # This file
└── .vscode/                  # Optional: VSCode build configs
    └── tasks.json
```

---

## 💡 Notes

* OpenCV must be installed and properly linked.
* Tested primarily on Windows using MSVC.
* You can use `tasks.json` in VSCode for a smoother build experience.

---

---
