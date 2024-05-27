#include "student.h"
#include <stdio.h>
#include <stdlib.h>

void print_menu() {
    printf("Student Records Management System\n");
    printf("1. Add Student\n");
    printf("2. Search Student\n");
    printf("3. Update Student\n");
    printf("4. Delete Student\n");
    printf("5. Sort Students\n");
    printf("6. Save Students\n");
    printf("7. Load Students\n");
    printf("8. Exit\n");
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice, id, age, result;
    float gpa;
    char name[MAX_NAME_LEN];
    char filename[100];

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter GPA: ");
                scanf("%f", &gpa);
                result = add_student(students, &count, id, name, age, gpa);
                if (result == 0) {
                    printf("Student added successfully.\n");
                } else {
                    printf("Failed to add student. Array is full.\n");
                }
                break;
            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                result = search_student(students, 0, count - 1, id);
                if (result != -1) {
                    printf("Student found: ID=%d, Name=%s, Age=%d, GPA=%.2f\n", students[result].id, students[result].name, students[result].age, students[result].gpa);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 3:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter new Name: ");
                scanf("%s", name);
                printf("Enter new Age: ");
                scanf("%d", &age);
                printf("Enter new GPA: ");
                scanf("%f", &gpa);
                result = update_student(students, count, id, name, age, gpa);
                if (result == 0) {
                    printf("Student updated successfully.\n");
                } else {
                    printf("Failed to update student. Student not found.\n");
                }
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                result = delete_student(students, &count, id);
                if (result == 0) {
                    printf("Student deleted successfully.\n");
                } else {
                    printf("Failed to delete student. Student not found.\n");
                }
                break;
            case 5:
                sort_students(students, 0, count - 1);
                printf("Students sorted successfully.\n");
                break;
            case 6:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                save_students(filename, students, count);
                printf("Students saved successfully.\n");
                break;
            case 7:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                load_students(filename, students, &count);
                printf("Students loaded successfully.\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
