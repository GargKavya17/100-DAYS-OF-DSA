// Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.
#include <stdio.h>

// Smallest index i where nums[i] >= x
int lowerBound(int* nums, int numsSize, int x) {
    int low = 0, high = numsSize - 1;
    int ans = numsSize;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Smallest index i where nums[i] > x
int upperBound(int* nums, int numsSize, int x) {
    int low = 0, high = numsSize - 1;
    int ans = numsSize;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int nums[] = {1, 2, 4, 4, 4, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 4;

    int lb = lowerBound(nums, n, target);
    int ub = upperBound(nums, n, target);

    printf("Array: ");
    for(int i = 0; i < n; i++) printf("%d ", nums[i]);
    
    printf("\n\nTarget: %d", target);
    printf("\nLower Bound (index of first 4): %d", lb);
    printf("\nUpper Bound (index of first element > 4): %d", ub);
    printf("\nFrequency of %d: %d\n", target, ub - lb);

    return 0;
}