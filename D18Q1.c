// Problem: Given an array of integers, rotate the array to the right by k positions.

#include <stdio.h>
void rotate(int* arr, int n, int k) {
    k = k % n; 
    int temp[n];

    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    for (int i = 0; i < n - k; i++) {
        temp[k + i] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}
int main() {
    int n = 5;
    int k = 2;
    int arr[5] = {1, 2, 3, 4, 5};

    rotate(arr, n, k);

    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}