//Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

#include <stdio.h>

int isPossible(int boards[], int n, int k, long long limit) {
    int paintersUsed = 1;
    long long currentBoardSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentBoardSum + boards[i] <= limit) {
            currentBoardSum += boards[i];
        } else {
            paintersUsed++;
            currentBoardSum = boards[i];
            if (paintersUsed > k) return 0; 
        }
    }
    return 1;
}

long long solve(int boards[], int n, int k) {
    long long low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    return result;
}