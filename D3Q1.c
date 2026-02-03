// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

#include <stdio.h>
void main(){
    int n, k, i, comparisons = 0, found_index = -1;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &k);
    for(i = 0; i < n; i++){
        comparisons++;
        if(arr[i] == k){
            found_index = i;
            break;
        }
    }
    if(found_index != -1){
        printf("Element %d found at index %d\n", k, found_index);
    } else {
        printf("Element %d not found in the array\n", k);
    }
    printf("Number of comparisons made: %d\n", comparisons);
}