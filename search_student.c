int search_student(Student students[], int start, int end, int id) {
    if (start > end) {
        return -1; // Not found
    }
    int mid = (start + end) / 2;
    if (students[mid].id == id) {
        return mid; // Found
    } else if (students[mid].id > id) {
        return search_student(students, start, mid - 1, id);
    } else {
        return search_student(students, mid + 1, end, id);
    }
}
