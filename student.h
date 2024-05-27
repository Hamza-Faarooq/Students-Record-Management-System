#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LEN 50
#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

#endif
