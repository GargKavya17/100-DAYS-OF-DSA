// Problem: Implement push and pop operations on a stack and verify stack operations.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1; 
    }
    return stack[top--];
}
int main() {
    push(10);
    push(20);
    push(30);
    printf("Popped element: %d\n", pop()); 
    printf("Popped element: %d\n", pop()); 
    printf("Popped element: %d\n", pop()); 
    printf("Popped element: %d\n", pop()); 
    return 0;
}