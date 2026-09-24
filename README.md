# 🔐 Login & Registration System — CodeAlpha Internship

### C++ Programming Internship — Task 2

A **console-based Login and Registration System** developed in **C++** as part of the **CodeAlpha C++ Programming Internship**.

The application allows users to create accounts, validates registration information, prevents duplicate usernames, stores account credentials in a local file, and verifies user credentials during login.

---

## 📌 Project Overview

The **Login & Registration System** is a simple authentication application designed to demonstrate fundamental C++ programming concepts through a practical user-management system.

The program provides two main operations:

* **User Registration**
* **User Login**

During registration, the application validates the username and password before saving the account information to a local `users.txt` file.

During login, the program reads the stored credentials and compares them with the information entered by the user.

---

## 🎯 Internship Task

This project was completed as **Task 2: Login and Registration System** for the **CodeAlpha C++ Programming Internship**.

### Task Requirements

The internship task required the application to:

* Create a registration function that accepts username and password.
* Validate user inputs.
* Check for duplicate usernames.
* Store user credentials in a file.
* Implement a login function.
* Read stored credentials and verify the user's identity.
* Display appropriate success or error messages.

This implementation fulfills these requirements with additional input validation, password confirmation, hidden password input, exception handling, and a menu-driven console interface.

---

## ✨ Features

### 👤 User Registration

Users can create a new account by providing:

* Username
* Password
* Password confirmation

The system checks the provided information before creating the account.

### 🔎 Username Validation

The username must:

* Contain at least **3 characters**
* Contain only letters, numbers, and underscores

Examples of valid usernames:

```text
sultan
sultan123
sultan_01
user2026
```

Invalid characters such as spaces and special symbols are rejected.

### 🚫 Duplicate Username Detection

Before registering a new account, the program searches the existing `users.txt` file.

If the username already exists, registration is rejected.

```text
Error: This username is already registered.
```

### 🔑 Password Validation

The system requires passwords to contain at least **6 characters**.

The `|` character is also rejected because it is used as the separator between usernames and passwords in the database file.

### 👁️ Hidden Password Input

Passwords are not displayed directly while being entered.

Instead, each typed character is represented by:

```text
*
```

The program also supports **Backspace** while entering passwords.

### 🔐 Password Confirmation

During registration, users must enter their password twice.

If both passwords do not match, registration is cancelled.

```text
Error: Passwords do not match.
```

### 💾 File-Based User Storage

Registered accounts are stored in:

```text
users.txt
```

Each record follows this format:

```text
username|password
```

For example:

```text
sultan123|MyPassword123
ali_01|HelloWorld
```

### 🔓 Login Verification

During login, the system:

1. Reads the entered username.
2. Reads the entered password.
3. Opens `users.txt`.
4. Searches through the stored records.
5. Compares the entered credentials with saved credentials.
6. Displays an appropriate result.

Successful login:

```text
Login successful. Welcome, sultan123!
```

Failed login:

```text
Login failed. Incorrect username or password.
```

### 🎨 Colored Console Interface

The program uses Windows console colors to improve readability.

Different colors are used for:

* Titles
* Borders
* User prompts
* Menu options
* Success messages
* Error messages
* User input

---

## 🖥️ Main Menu

When the program starts, users are presented with:

```text
==========================================================
              LOGIN & REGISTRATION SYSTEM
==========================================================

  [1] Register New User
  [2] Login
  [3] Exit

Enter your choice:
```

---

## 🔄 Registration Workflow

```text
                  ┌──────────────────────┐
                  │   Start Program      │
                  └──────────┬───────────┘
                             │
                             ▼
                  ┌──────────────────────┐
                  │   Select Register    │
                  └──────────┬───────────┘
                             │
                             ▼
                  ┌──────────────────────┐
                  │   Enter Username     │
                  └──────────┬───────────┘
                             │
                             ▼
                  ┌──────────────────────┐
                  │ Validate Username    │
                  └──────────┬───────────┘
                             │
                    Valid? ──┴── No
                             │
                             ▼
                    Display Error
                             │
                             │ Yes
                             ▼
                  ┌──────────────────────┐
                  │ Check Duplicate      │
                  │ Username             │
                  └──────────┬───────────┘
                             │
                    Exists? ─┴─ Yes
                             │
                             ▼
                    Display Error
                             │
                             │ No
                             ▼
                  ┌──────────────────────┐
                  │ Enter Password       │
                  └──────────┬───────────┘
                             │
                             ▼
                  ┌──────────────────────┐
                  │ Validate Password    │
                  └──────────┬───────────┘
                             │
                             ▼
                  ┌──────────────────────┐
                  │ Confirm Password     │
                  └──────────┬───────────┘
                             │
                             ▼
                  ┌──────────────────────┐
                  │ Save Account to      │
                  │ users.txt            │
                  └──────────┬───────────┘
                             │
                             ▼
                  Registration Successful
```

---

## 🔄 Login Workflow

```text
                  ┌──────────────────────┐
                  │    Select Login      │
                  └──────────┬───────────┘
                             │
                             ▼
                  ┌──────────────────────┐
                  │ Enter Username       │
                  └──────────┬───────────┘
                             │
                             ▼
                  ┌──────────────────────┐
                  │ Enter Password       │
                  └──────────┬───────────┘
                             │
                             ▼
                  ┌──────────────────────┐
                  │ Open users.txt       │
                  └──────────┬───────────┘
                             │
                             ▼
                  ┌──────────────────────┐
                  │ Read Stored          │
                  │ Credentials          │
                  └──────────┬───────────┘
                             │
                             ▼
                  ┌──────────────────────┐
                  │ Compare Username &   │
                  │ Password             │
                  └──────────┬───────────┘
                             │
                    Match? ──┴── No
                             │
                             ▼
                    Login Failed
                             │
                             │ Yes
                             ▼
                    Login Successful
```

---

## 🛠️ Technologies Used

* **C++**
* **File Handling**
* **Windows API**
* **Console Application**
* Standard C++ libraries

### Libraries Used

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <conio.h>
#include <windows.h>
```

---

## 💻 C++ Concepts Demonstrated

This project demonstrates several important C++ programming concepts.

### Functions

The program is divided into reusable functions, including:

```cpp
setColor()
clearScreen()
printLine()
printTitle()
pauseScreen()
readPassword()
isValidUsername()
usernameExists()
registerUser()
loginUser()
```

This keeps the program organized and separates different responsibilities.

---

### File Handling

The application uses:

```cpp
ifstream
ofstream
```

to read and write user account information.

Registration appends new users to:

```text
users.txt
```

Login reads the same file to verify credentials.

---

### String Manipulation

The program uses `string` operations for:

* Username processing
* Password handling
* Searching for the `|` separator
* Extracting stored usernames
* Extracting stored passwords

For example:

```cpp
string savedUsername = line.substr(0, separatorPosition);
string savedPassword = line.substr(separatorPosition + 1);
```

---

### Input Validation

The program validates:

* Username length
* Username characters
* Duplicate usernames
* Password length
* Password confirmation
* Reserved separator characters
* Menu selections

---

### Exception Handling

The program uses:

```cpp
try
catch
throw
```

to handle file-related errors and prevent unexpected program termination.

For example, if the user database cannot be opened, the program reports an appropriate error.

---

### Character Handling

The program uses character validation through:

```cpp
isalnum()
```

to ensure usernames contain only permitted characters.

---

### Console Input Control

The project uses:

```cpp
_getch()
```

from `<conio.h>` to:

* Hide password characters
* Display `*` instead
* Detect Enter
* Handle Backspace
* Pause the application

---

### Windows Console API

The program uses:

```cpp
SetConsoleTextAttribute()
```

through `<windows.h>` to create a colored console interface.

---

## 📂 Data Storage

The application uses a local text file named:

```text
users.txt
```

The storage format is:

```text
username|password
```

Example:

```text
sultan123|Password123
maira_01|Hello123
student2026|CppProject
```

The `|` character separates the username and password.

The program therefore prevents users from including `|` in their passwords.

---

## 🔐 Security Considerations

This project demonstrates the **basic structure of an authentication system** for educational purposes.

It includes:

* Password masking during input
* Password confirmation
* Minimum password length
* Username validation
* Duplicate username prevention
* Credential verification
* File-access error handling

### ⚠️ Important Limitation

The current implementation stores passwords in **plain text** inside `users.txt`.

For example:

```text
username|password
```

This is suitable for demonstrating basic C++ file handling and authentication logic, but it should **not be considered production-level credential storage**.

A production authentication system should use secure password hashing and appropriate credential-protection mechanisms instead of storing raw passwords.

---

## 🧪 Example Registration

```text
==========================================================
              NEW USER REGISTRATION
==========================================================

Enter username: sultan123
Enter password: ************
Confirm password: ************

Registration successful! You can now log in.
```

---

## 🧪 Example Login

```text
==========================================================
                    USER LOGIN
==========================================================

Enter username: sultan123
Enter password: ************

Login successful. Welcome, sultan123!
```

---

## ❌ Example Failed Login

```text
==========================================================
                    USER LOGIN
==========================================================

Enter username: sultan123
Enter password: ********

Login failed. Incorrect username or password.
```

---

## 🚫 Example Duplicate Username

```text
Enter username: sultan123

Error: This username is already registered.
```

---

## 📁 Project Structure

```text
CodeAlpha_LoginAndRegistrationSystem/
│── 1. Screenshot.jpg
│── 2. Screenshot.jpg
│── 3. Screenshot.jpg
├── 4. Screenshot.jpg
├── README.md
└── main.cpp
```

> `users.txt` is created/used by the program when account information is stored.

---

## ⚙️ Requirements

To compile and run this project, you need:

* Windows operating system
* C++ compiler
* Visual Studio or another compatible C++ IDE/compiler
* Support for Windows-specific headers such as:

  * `windows.h`
  * `conio.h`

The project is designed primarily for a **Windows console environment** because it uses Windows console APIs and `_getch()`.

---

## 🚀 How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/5ultaan/CodeAlpha_LoginAndRegistrationSystem.git
```

### 2. Open the Project

Open `main.cpp` in:

* Visual Studio
* Code::Blocks
* Another compatible C++ development environment

### 3. Compile the Program

Compile `main.cpp` using a compatible C++ compiler.

### 4. Run the Application

After launching the program, use the menu:

```text
[1] Register New User
[2] Login
[3] Exit
```

Register an account first, then use the same credentials to test the login functionality.

---

## 📌 Project Highlights

This project provides practical experience with:

* C++ programming
* Functions
* File input/output
* Authentication logic
* User registration
* Login verification
* String processing
* Input validation
* Exception handling
* Password masking
* Windows console programming
* Menu-driven applications

---

## 🔮 Future Improvements

The system could be further improved by adding:

* Password hashing
* Encrypted credential storage
* Stronger password requirements
* Login attempt limits
* Account lockout
* Password recovery
* User profile management
* Database integration
* Multiple user roles
* Improved cross-platform compatibility
* A graphical user interface

---

## 🎓 Internship Information

**Internship:** C++ Programming Internship
**Organization:** CodeAlpha
**Task:** Task 2 — Login and Registration System

This project was developed as part of the practical programming tasks assigned during the **CodeAlpha C++ Programming Internship**.

The task provided practical experience in implementing registration and authentication logic using C++ and file handling.

---

## 👨‍💻 Author

**Sultan Shahzad Awan**

BS Artificial Intelligence Student
University of Central Punjab

### Profiles

* **LinkedIn:** [http://www.linkedin.com/in/sultanshahzadawan]
* **GitHub:** [https://github.com/5ultaan]

---

## ⭐ Acknowledgment

Thanks to **CodeAlpha** for providing the internship opportunity and project-based learning experience in C++ programming.

---

### 📌 Repository Information

**Repository:** `CodeAlpha_LoginAndRegistrationSystem`

**Project:** Login & Registration System
**Language:** C++
**Internship:** CodeAlpha C++ Programming Internship
**Task:** 2

