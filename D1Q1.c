// Insert an Element in an Array
// Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

#include<stdio.h>
void main(){
    int n, pos, x, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n+1];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to insert (1 to %d): ", n+1);
    scanf("%d", &pos);
    printf("Enter the element to insert: ");
    scanf("%d", &x);

    for(i = n; i >= pos; i--){
        arr[i] = arr[i-1];
    }

    arr[pos-1] = x;

    printf("Array after insertion:\n");
    for(i = 0; i <= n; i++){
        printf("%d ", arr[i]);
    }
}