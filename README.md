# Mini Search Engine

A **C++ Mini Search Engine** built using **Object-Oriented Programming (OOP), Data Structures, and SQL** for indexing, searching, and storing word frequencies across documents. This project demonstrates strong algorithmic thinking, C++ programming, and basic database integration with SQLite.

---

## Features

- **Document Indexing:**  
  Build an index of multiple text documents using **Binary Search Trees (BST)** and **Linked Lists**.
  
- **Word Search:**  
  Efficiently search for keywords across indexed documents, displaying frequency per document.

- **Case-Insensitive Search:**  
  Handles words in a case-insensitive manner (e.g., `C++`, `c++`).

- **SQL Integration:**  
  Uses **SQLite** to:
  - Store documents in a database table.
  - Track word frequencies per document.
  - Maintain search history.

- **Optimized Search:**  
  Words in documents are cleaned and normalized, supporting `+` symbols (e.g., `C++`) and alphanumeric characters.

---

## Data Structures Used

- **Binary Search Tree (BST):** For storing unique words efficiently.
- **Linked List:** For storing documents and word frequencies.
- **Vector & String Manipulation:** For tokenization and processing input text.

---

## Technologies Used

- **Language:** C++  
- **Database:** SQLite (via `sqlite3.h` and `sqlite3.dll`)  
- **OOP Concepts:** Classes, encapsulation, modular design  
- **Data Structures:** BST, Linked List, Vector  

---

## Files in the Project

- `main.cpp` — Entry point, handles user input and queries  
- `SearchEngine.h` — Main class managing indexing, search, and database operations  
- `DatabaseManager.h` — Handles SQLite database connection and table creation  
- `WordNode.h` — Node structure for words in BST  
- `DocNode.h` — Node structure for documents and word frequency  

> **Note:** SQLite precompiled binaries (`sqlite3.dll`) are **not included**. You need to install or link SQLite on your system.

---


## How to Compile

```bash
g++ main.cpp -o MiniSearchEngine.exe -lsqlite3
```

### On Linux / Mac:
./MiniSearchEngine.exe

### On Windows:
.\MiniSearchEngine.exe
