// Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.
#include <stdio.h>

int integerSqrt(int x) {
    if (x < 2) return x;

    int left = 1, right = x / 2;
    int ans;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check mid <= x/mid to avoid overflow (same as mid*mid <= x)
        if (mid <= x / mid) {
            ans = mid;      // Store potential answer
            left = mid + 1; // Try searching for a larger value
        } else {
            right = mid - 1; // Mid is too large
        }
    }

    return ans;
}

int main() {
    int num = 10;
    printf("The integer square root of %d is %d\n", num, integerSqrt(num));
    return 0;
}