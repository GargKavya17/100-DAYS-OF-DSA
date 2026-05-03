//Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.
#include <stdio.h>
#include <limits.h>

int canAllocate(int* pages, int n, int students, int limit) {
    int allocatedStudents = 1;
    int pagesCurrentStudent = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > limit) return 0;

        if (pagesCurrentStudent + pages[i] > limit) {
            allocatedStudents++;
            pagesCurrentStudent = pages[i];
            
            if (allocatedStudents > students) return 0;
        } else {
            pagesCurrentStudent += pages[i];
        }
    }
    return 1;
}

int allocateBooks(int* pages, int n, int m) {
    if (m > n) return -1;

    int low = 0;
    int high = 0;
    int result = -1;

    for (int i = 0; i < n; i++) {
        if (pages[i] > low) low = pages[i]; 
        high += pages[i];                  
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(pages, n, m, mid)) {
            result = mid;      
            high = mid - 1;    
        } else {
            low = mid + 1;     
        }
    }

    return result;
}

int main() {
    int pages[] = {12, 34, 67, 90};
    int m = 2;
    int n = sizeof(pages) / sizeof(pages[0]);

    int minMaxPages = allocateBooks(pages, n, m);
    printf("Minimum possible maximum pages: %d\n", minMaxPages);

    return 0;
}
