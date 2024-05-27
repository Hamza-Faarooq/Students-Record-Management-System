int update_student(Student students[], int count, int id, const char *new_name, int new_age, float new_gpa) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            strncpy(students[i].name, new_name, MAX_NAME_LEN);
            students[i].age = new_age;
            students[i].gpa = new_gpa;
            return 0; // Success
        }
    }
    return -1; // Not found
}
