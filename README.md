# Library Management System

This is a simple C++ console application for managing a library's book inventory. It allows users to add, display, search, and delete books, with support for tracking multiple copies and automatic ISBN generation.

## Features

- **Add Book:**
  - Enter book name, author, and number of copies.
  - Automatically generates a unique 13-digit ISBN for each book.
- **Display Books:**
  - Lists all books with their name, author, number of copies, and ISBN.
- **Search Book:**
  - Search for a book by name and view its details (author, copies, ISBN).
- **Delete Book:**
  - Remove a book from the library by name.
- **Book Copies:**
  - Track how many copies of each book are available.

## How It Works

1. On startup, the program presents a menu:
    - Add a book
    - Display all books
    - Search for a book
    - Delete a book
    - Exit
2. When adding a book, the user is prompted for the book's name, author, and number of copies. The program generates a random 13-digit ISBN.
3. Books are stored in an array with a maximum of 100 entries.
4. All book operations (add, display, search, delete) are handled via menu options.

## Example Usage

```
Library Management System
1. Add a book to the library
2. Display all books in the library
3. Search a book from the library
4. Delete a book from the library
5. Exit program
Enter your choice: 1
Enter the name of the book: The Great Gatsby
Enter the author's name: F. Scott Fitzgerald
Enter the number of copies: 3
Generated ISBN (13-digit): 1234567890123
```

## Requirements

- C++ compiler (e.g., g++, MSVC)
- Windows or any platform supporting standard C++

## How to Compile and Run

1. Open a terminal in the project directory.
2. Compile:
   - `g++ Library_management_system.cpp -o Library_management_system.exe`
3. Run:
   - `Library_management_system.exe`

## File Structure

- `Library_management_system.cpp` - Main source code
- `Library_management_system.exe` - Compiled executable
- `README.md` - Project documentation

## License

This project is open source and free to use for educational purposes.
