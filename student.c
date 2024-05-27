#include "student.h"
#include <stdio.h>
#include <string.h>

int add_student(Student students[], int *count, int id, const char *name, int age, float gpa) {
    if (*count >= MAX_STUDENTS) {
        return -1; // Array is full
    }
    students[*count].id = id;
    strncpy(students[*count].name, name, MAX_NAME_LEN);
    students[*count].age = age;
    students[*count].gpa = gpa;
    (*count)++;
    return 0; // Success
}
