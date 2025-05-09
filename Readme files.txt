=======================
Keylogger Project README
=======================

Authors: Omer Imran Siddiqui (2024523)
         Muhammad Saad (2024445)
File: KeyLogger.cpp

Description:
------------
This project is a basic keylogger written in C++. It captures keystrokes using Windows API functions
(GetAsyncKeyState) and logs them into a file named "testing.txt".

Features:
---------
- Logs common printable characters and special keys (enter, space, backspace, etc.)
- Uses polymorphism for flexible logging (to a file in this case)
- Hides the console window for stealth operation
- Outputs logs in plain text format

Usage:
------
1. Compile the program with a C++ compiler that supports Windows headers (e.g., MSVC or MinGW).
2. Run the executable. It will start logging keystrokes to "testing.txt" in the same directory.
3. To view the logs, use the included read file program or open "testing.txt" manually.

Disclaimer:
-----------
This software is intended **strictly for educational purposes** such as learning how keyloggers work 
or testing keylogging detection mechanisms in controlled environments.

**Do not use this program on systems you do not own or have explicit permission to test.**




