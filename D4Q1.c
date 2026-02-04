// Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.
#include <stdio.h>
void main(){
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int left = 0, right = n - 1, temp;
    while(left < right){
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
    printf("Reversed array:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}