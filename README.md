# 📚 Library Management System

A console-based Library Management System written in **C**, using binary file I/O for persistent data storage. The system supports three user roles — Admin, Employee, and Student — each with a dedicated set of operations.

---

## 🚀 Features

### 👤 Student
- View personal profile on login
- Browse the full book catalogue
- Issue an available book
- Return a previously issued book
- View details of a specific book

### 🧑‍💼 Employee
- Add and remove students
- View the full student list and individual student details
- Add and remove books
- View the full book list and individual book details

### 🔐 Admin
- Secured login with username + PIN
- Add and remove employees
- View the full employee list and individual employee details

---

## 🗂️ Project Structure

```
├── main.c          # Entry point; handles login flow and menu routing
├── book.c/.h       # Book CRUD operations and issue/return logic
├── student.c/.h    # Student CRUD operations and book tracking
├── employee.c/.h   # Employee CRUD operations
```

### Data Files (auto-generated at runtime)
```
book.dat            # Stores book records
Student.dat         # Stores student records
emp.dat             # Stores employee records
```

---

## ⚙️ Getting Started

### Prerequisites
- GCC compiler (or any C99-compatible compiler)

### Compile

```bash
gcc main.c book.c student.c employee.c -o library
```

### Run

```bash
./library
```

---

## 🔑 Default Admin Credentials

| Field    | Value   |
|----------|---------|
| Username | `ADMIN` |
| Password | `1234`  |

> ⚠️ Change these credentials in `main.c` before deploying.

---

## 🛠️ Technologies Used

| Technology | Purpose |
|------------|---------|
| C (C99)    | Core language |
| Binary File I/O (`fread`/`fwrite`) | Persistent data storage via `.dat` files |
| C Structs  | Fixed-size record representation |
| `string.h` (`strcpy`, `strcmp`) | String operations |
| Copy-and-replace pattern | In-place record deletion and updates |

---

## 📐 Architecture

The project follows a **modular, multi-file architecture**. Each entity (book, student, employee) has its own `.c` implementation file and a corresponding `.h` header, keeping concerns separated. `main.c` is responsible solely for user interaction and control flow.

Data is persisted as raw binary structs written to `.dat` files. Since binary files don't support in-place deletion, all update and remove operations use a **copy-and-replace pattern**: records are filtered into a temporary file, the original is deleted, and the temp file is renamed.

---

## ⚠️ Known Limitations

- No duplicate serial number or ID validation on insert
- Admin credentials are hardcoded in source
- A student can issue multiple books without restriction
- No encryption or secure storage for any data files
- Single-user, single-session; no concurrency support

---

## 🔮 Potential Improvements

- Add input validation for duplicate IDs and serial numbers
- Implement a book limit per student
- Replace hardcoded admin credentials with a hashed config
- Migrate storage to SQLite for more robust querying
- Add a search/filter feature for books and students

---

## 📄 License

This project is intended for educational purposes.
