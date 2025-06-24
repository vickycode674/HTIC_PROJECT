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

---

## 𝐓𝐚𝐬𝐤 𝟐: 𝐄𝐧𝐜𝐫𝐲𝐩𝐭𝐞𝐝 𝐆𝐞𝐨𝐠𝐫𝐚𝐩𝐡𝐢𝐜𝐚𝐥 𝐅𝐢𝐥𝐞 𝐒𝐭𝐨𝐫𝐚𝐠𝐞 - 𝐂++ 𝐂𝐨𝐧𝐬𝐨𝐥𝐞 𝐀𝐩𝐩𝐥𝐢𝐜𝐚𝐭𝐢𝐨𝐧
## 📌 Overview

This console-based C++ application allows users to securely **store** and **retrieve** text files containing geographical and descriptive data using a **hierarchical folder structure** (Country → State → District). All file contents are **encrypted** before being saved to disk and decrypted during retrieval.
## 🚀 Features

* 🌍 Geographical folder hierarchy: `./data/<Country>/<State>/<District>/`
* 🔐 File encryption and decryption using a simple algorithm
* 📁 Saves files in encrypted form (`.txt`, `.dat`, etc.)
* 📖 Retrieves and displays readable decrypted content
* ⚠️ Robust error handling for missing directories or files

---

## 🧭 Application Flow

### 📌 On Launch

User is prompted with two options:

```
1. Store a new file
2. Retrieve and view a file
```

---

### ✍️ 1. Store a New File

* Prompts the user to enter:

  * Country
  * State
  * District
  * Description
* Creates a nested folder structure:

  ```
  ./data/<Country>/<State>/<District>/
  ```
* Saves the information in an encrypted format inside a file (e.g., `info.txt`)
* Example file content before encryption (for reference):

  ```
  Country: India
  State: Maharashtra
  District: Pune
  Description: A city known for its education and culture.
  ```

---

### 🔓 2. Retrieve and View a File

* Prompts the user to enter:

  * Country
  * State
  * District
* Locates the corresponding encrypted file
* Decrypts the content and displays it in the console
* If the file or directory does not exist, an appropriate error message is shown

---

## 🔐 Encryption Details

* A simple encryption method is used (e.g., Caesar Cipher or XOR Cipher) for demonstration.
* You can easily switch or improve the encryption logic as needed.

---

## ⚙️ How to Compile & Run

### Compile

```bash
g++ main.cpp -o geo_encrypt
```

### Run

```bash
./geo_encrypt
```


## 𝐓𝐚𝐬𝐤 3: 𝐕𝐢𝐝𝐞𝐨 𝐂𝐚𝐩𝐭𝐮𝐫𝐞 𝐀𝐩𝐩𝐥𝐢𝐜𝐚𝐭𝐢𝐨𝐧 (𝐂++ & 𝐎𝐩𝐞𝐧𝐂𝐕)
This project is a multithreaded C++ application using OpenCV that:

Captures live video from your webcam

Saves the video in real-time to a file

Allows you to take snapshots with a key press

Runs smoothly with no freezing, thanks to multithreading

🧠 Features
✅ Live webcam video feed in a window

✅ Real-time video recording (output.avi)

✅ Press 's' to save a snapshot (as snap_TIMESTAMP.jpg)

✅ Press 'q' to exit the program

✅ Runs with multithreading for performance (recording & snapshot in background)

🛠️ Requirements
C++17 or later

OpenCV (version 4.x or compatible)

MSVC (cl.exe) compiler via:

Visual Studio Developer Command Prompt, OR

x64 Native Tools for VS command prompt

✅ Tested on Windows with OpenCV built for MSVC.

📂 Project Structure
bash
Copy
Edit
project/
│
├── main.cpp          # Main application source code
├── README.md         # You're reading this!
└── .vscode/          # Optional VSCode config
    └── tasks.json    # (For build task setup)
⚙️ Setup Instructions
🔁 1. Install OpenCV (Windows)
Download OpenCV from: https://opencv.org/releases/

Extract it somewhere, e.g., C:\opencv

Note these folders:

C:\opencv\build\include — for headers

C:\opencv\build\x64\vc16\lib — for .lib files

C:\opencv\build\x64\vc16\bin — for .dll files (add to your PATH)

🛠️ 2. Build with MSVC (from Command Prompt)
Open x64 Native Tools for VS 2019 or 2022 and run:

bash
Copy
Edit
cl main.cpp /EHsc /std:c++17 ^
 /I "C:\opencv\build\include" ^
 /link /LIBPATH:"C:\opencv\build\x64\vc16\lib" opencv_world470.lib
🔄 Replace 470 with your OpenCV version if different
📎 Make sure opencv_world470.dll is in your PATH or in the same folder as main.exe

▶️ 3. Run the App
bash
Copy
Edit
main.exe
You’ll see the webcam feed in a window. Use:

's' → Take a snapshot

'q' → Quit the app

🧬 Application Flow
lua
Copy
Edit
[ main() ] --> Opens webcam + GUI loop
     |--- Updates shared frame for threads
     |
     |--- [ Thread 1 ] --> Records video to file (output.avi)
     |--- [ Thread 2 ] --> Saves snapshot when 's' is pressed
     |
     --> Cleans up on 'q' (quits safely)
💡 Notes
OpenCV must be properly installed and linked.

App is built and tested for Windows + MSVC only.

Use VSCode with a tasks.json if you prefer building from editor (optional).


