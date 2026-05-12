// Problem: For each element, count how many smaller elements appear on right side.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Element;

void merge(Element* arr, int left, int mid, int right, int* count, Element* temp) {
    int i = left;     
    int j = mid + 1;   
    int k = left;      
    int rightCount = 0; 

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            // Element from right is smaller
            rightCount++;
            temp[k++] = arr[j++];
        } else {
            // Element from left is smaller or equal
            // Add the current rightCount to this element's total
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Element* arr, int left, int right, int* count, Element* temp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, count, temp);
        mergeSort(arr, mid + 1, right, count, temp);
        merge(arr, left, mid, right, count, temp);
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* count = (int*)calloc(numsSize, sizeof(int));
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    Element* temp = (Element*)malloc(numsSize * sizeof(Element));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, numsSize - 1, count, temp);

    free(arr);
    free(temp);
    return count;
}