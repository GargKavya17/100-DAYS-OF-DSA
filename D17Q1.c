// Problem: Write a program to find the maximum and minimum values present in a given array of integers.

#include <stdio.h>
int main() {
    int n = 5;
    int arr[5] = {3, 1, 4, 1, 5};

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}