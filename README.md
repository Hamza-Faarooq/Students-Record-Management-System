# Students-Record-Management-System


## Description
The Student Records Management System is a command-line application developed in C that allows users to manage student records. This system provides functionalities to add, search, update, delete, sort, save, and load student records. It demonstrates the use of fundamental C programming concepts including structures, arrays, recursion, strings, and file handling.

## Features
- **Add Student**: Add a new student record with a unique ID, name, age, and GPA.
- **Search Student**: Search for a student record by ID using a recursive binary search algorithm.
- **Update Student**: Update an existing student's details by ID.
- **Delete Student**: Remove a student record by ID.
- **Sort Students**: Sort the student records by ID using a recursive quicksort algorithm.
- **Save Students**: Save all current student records to a file.
- **Load Students**: Load student records from a file into the system.

## Installation and Compilation

### Prerequisites
- GCC compiler

### Building the Project
1. Clone the repository:
    ```sh
    git clone <your-repo-url>
    cd student-records-management
    ```
2. Use the provided Makefile to build the project:
    ```sh
    make
    ```

### Running the Program
To start the Student Records Management System, run the compiled program:
```sh
./student_records
