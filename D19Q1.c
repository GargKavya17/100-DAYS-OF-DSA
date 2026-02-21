// Given an array of integers, find two elements whose sum is closest to zero.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void findClosest(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare); 

    int L = 0, R = n - 1;
    int min_sum = INT_MAX;
    int final_l, final_r;

    while (L < R) {
        int sum = arr[L] + arr[R];

        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            final_l = arr[L];
            final_r = arr[R];
        }

        if (sum < 0) L++;      
        else if (sum > 0) R--; 
        else break;            
    }

    printf("Closest pair: %d, %d\n", final_l, final_r);
}

int main() {
    int data[] = {1, 60, -10, 70, -80, 85};
    findClosest(data, 6);
    return 0;
}