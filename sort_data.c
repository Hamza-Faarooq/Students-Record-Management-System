void sort_students(Student students[], int start, int end) {
    if (start < end) {
        int pivot = partition(students, start, end);
        sort_students(students, start, pivot - 1);
        sort_students(students, pivot + 1, end);
    }
}

int partition(Student students[], int start, int end) {
    int pivot = students[end].id;
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (students[j].id <= pivot) {
            i++;
            Student temp = students[i];
            students[i] = students[j];
            students[j] = temp;
        }
    }
    Student temp = students[i + 1];
    students[i + 1] = students[end];
    students[end] = temp;
    return i + 1;
}
