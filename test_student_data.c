#include "student.h"
#include <assert.h>
#include <string.h>

void test_add_student() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int result = add_student(students, &count, 1, "Alice", 20, 3.5);
    assert(result == 0);
    assert(count == 1);
    assert(students[0].id == 1);
    assert(strcmp(students[0].name, "Alice") == 0);
    assert(students[0].age == 20);
    assert(students[0].gpa == 3.5);
}

void test_search_student() {
    Student students[MAX_STUDENTS];
    int count = 0;
    add_student(students, &count, 1, "Alice", 20, 3.5);
    add_student(students, &count, 2, "Bob", 21, 3.6);
    int index = search_student(students, 0, count - 1, 2);
    assert(index == 1);
    index = search_student(students, 0, count - 1, 3);
    assert(index == -1);
}

void test_update_student() {
    Student students[MAX_STUDENTS];
    int count = 0;
    add_student(students, &count, 1, "Alice", 20, 3.5);
    int result = update_student(students, count, 1, "Alicia", 21, 3.8);
    assert(result == 0);
    assert(strcmp(students[0].name, "Alicia") == 0);
    assert(students[0].age == 21);
    assert(students[0].gpa == 3.8);
    result = update_student(students, count, 2, "Bob", 22, 3.7);
    assert(result == -1);
}

void test_delete_student() {
    Student students[MAX_STUDENTS];
    int count = 0;
    add_student(students, &count, 1, "Alice", 20, 3.5);
    add_student(students, &count, 2, "Bob", 21, 3.6);
    int result = delete_student(students, &count, 1);
    assert(result == 0);
    assert(count == 1);
    assert(students[0].id == 2);
    result = delete_student(students, &count, 3);
    assert(result == -1);
}

void test_sort_students() {
    Student students[MAX_STUDENTS];
    int count = 0;
    add_student(students, &count, 3, "Charlie", 22, 3.2);
    add_student(students, &count, 1, "Alice", 20, 3.5);
    add_student(students, &count, 2, "Bob", 21, 3.6);
    sort_students(students, 0, count - 1);
    assert(students[0].id == 1);
    assert(students[1].id == 2);
    assert(students[2].id == 3);
}

void test_save_load_students() {
    Student students[MAX_STUDENTS];
    int count = 0;
    add_student(students, &count, 1, "Alice", 20, 3.5);
    add_student(students, &count, 2, "Bob", 21, 3.6);
    save_students("students.dat", students, count);

    Student loaded_students[MAX_STUDENTS];
    int loaded_count = 0;
    load_students("students.dat", loaded_students, &loaded_count);
    assert(loaded_count == 2);
    assert(loaded_students[0].id == 1);
    assert(strcmp(loaded_students[0].name, "Alice") == 0);
    assert(loaded_students[0].age == 20);
    assert(loaded_students[0].gpa == 3.5);
    assert(loaded_students[1].id == 2);
    assert(strcmp(loaded_students[1].name, "Bob") == 0);
    assert(loaded_students[1].age == 21);
    assert(loaded_students[1].gpa == 3.6);
}

int main() {
    test_add_student();
    test_search_student();
    test_update_student();
    test_delete_student();
    test_sort_students();
    test_save_load_students();
    printf("All tests passed!\n");
    return 0;
}
