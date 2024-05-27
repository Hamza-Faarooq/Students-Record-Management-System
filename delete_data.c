int delete_student(Student students[], int *count, int id) {
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            return 0; // Success
        }
    }
    return -1; // Not found
}
