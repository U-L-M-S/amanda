# 🔐 Amanda - Windows Keylogger

## 📖 What is Amanda?

Amanda is a simple keylogger application written in C++ that demonstrates low-level keyboard input capture on Windows systems. This project was created as an educational exercise to showcase C++ programming capabilities and Windows API usage.

## ⚙️ What does it do?

Amanda monitors and logs all keyboard input on a Windows machine. Every keystroke is captured and saved to a text file (`log.txt`) in the same directory where the program runs. The application runs silently in the background with a hidden console window.

## 🔄 How it works

1. **Starts silently** - The program hides its console window when launched
2. **Monitors keyboard** - Continuously checks for key presses using Windows API
3. **Logs keystrokes** - Records every key press to `log.txt` including:
   - Regular characters (letters, numbers, symbols)
   - Special keys (ENTER, BACKSPACE, TAB, ESC, etc.)
   - Arrow keys (←, ↑, ↓, →)
   - Modifier keys (SHIFT, CONTROL, ALT, CAPS LOCK)
4. **Runs indefinitely** - Continues logging until manually terminated

## 📋 Requirements

- 💻 Windows operating system (7, 8, 10, or 11)
- 🔧 C++ compiler with Windows API support (MinGW or MSVC)

## 🛠️ How to compile

### Option 1: Using MinGW (g++)

```bash
g++ main.cpp -o amanda.exe
```

### Option 2: Using Microsoft Visual C++ (MSVC)

```bash
cl main.cpp /Fe:amanda.exe
```

### Option 3: Using Visual Studio

1. Open Visual Studio
2. Create a new C++ Console Application project
3. Add `main.cpp` to the project
4. Build the solution (F7)

## 🚀 How to run

Simply execute the compiled program:

```bash
amanda.exe
```

The program will start logging keystrokes to `log.txt` in the current directory.

## 🛑 How to stop

### ✅ Option 1: Graceful Exit (Recommended)
Press `Ctrl + Alt + Q` to stop the program gracefully.

### 🔧 Option 2: Task Manager
1. Press `Ctrl + Shift + Esc` to open Task Manager
2. Find `amanda.exe` in the Processes tab
3. Click "End Task"

## 📄 Output

All captured keystrokes are saved in `log.txt` in the same directory as the executable.

The log file includes:
- ⏰ Session start/end timestamps
- ⌨️ All captured keystrokes
- 🔑 Special key indicators (ENTER, BACKSPACE, etc.)

Example log output:
```
=== Session started: 2025-10-21 14:30:15 ===
Hello World[ENTER]
This is a test[BACKSPACE][BACKSPACE][BACKSPACE][BACKSPACE]demo[ENTER]
=== Session ended: 2025-10-21 14:32:45 ===
```

## 🎓 Educational Purpose

This project is intended for **educational purposes only** to demonstrate:
- 🖥️ Windows API programming in C++
- ⌨️ Low-level keyboard input handling
- 📁 File I/O operations in C++
- 🔧 System-level programming concepts

⚠️ **IMPORTANT**: This software should only be used on your own computer or with explicit permission. Unauthorized use of keyloggers may violate privacy laws and ethical guidelines.

## 🪟 Platform

**Windows only** - This application uses Windows-specific APIs and will not work on Linux or macOS.