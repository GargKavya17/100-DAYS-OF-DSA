// Problem: Given integers a and b, compute a^b using recursion without using pow() function.

#include<stdio.h>
int power(int a, int b) {
    if (b == 0) return 1; 
    if (b < 0) return 1 / power(a, -b); 
    return a * power(a, b - 1); 
}
int main() {
    int a, b;
    printf("Enter the base (a): ");
    scanf("%d", &a);
    printf("Enter the exponent (b): ");
    scanf("%d", &b);
    
    int result = power(a, b);
    printf("%d raised to the power of %d is: %d\n", a, b, result);
    
    return 0;
}