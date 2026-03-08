#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char ** tokens, int tokensSize) {
    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* s = tokens[i];

        if ((strlen(s) == 1) && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')) {
            int b = stack[top--];
            int a = stack[top--]; 
            
            switch (s[0]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break; 
            }
        } else {
            stack[++top] = atoi(s);
        }
    }

    int result = stack[top];
    free(stack);
    return result;
}