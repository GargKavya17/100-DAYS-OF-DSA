#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Node;

void merge(Node* arr, int left, int mid, int right, int* res, Node* temp) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int right_smaller_count = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            right_smaller_count++;
            temp[k++] = arr[j++];
        } else {
            res[arr[i].index] += right_smaller_count;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        res[arr[i].index] += right_smaller_count;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void solve(Node* arr, int left, int right, int* res, Node* temp) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    solve(arr, left, mid, res, temp);
    solve(arr, mid + 1, right, res, temp);
    merge(arr, left, mid, right, res, temp);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (numsSize == 0) return NULL;

    int* res = (int*)calloc(numsSize, sizeof(int));
    Node* arr = (Node*)malloc(numsSize * sizeof(Node));
    Node* temp = (Node*)malloc(numsSize * sizeof(Node));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    solve(arr, 0, numsSize - 1, res, temp);

    free(arr);
    free(temp);
    return res;
}