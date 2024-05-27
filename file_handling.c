#include "student.h"
#include <stdio.h>

void save_students(const char *filename, Student students[], int count) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return;
    }
    fwrite(&count, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
}

void load_students(const char *filename, Student students[], int *count) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }
    fread(count, sizeof(int), 1, file);
    fread(students, sizeof(Student), *count, file);
    fclose(file);
}
