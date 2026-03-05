#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int evalRPN(char ** tokens, int tokensSize) {
    int* stack = (int*)malloc(sizeof(int) * tokensSize);
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* s = tokens[i];

        if ((s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/') && strlen(s) == 1) {
            int val2 = stack[top--]; 
            int val1 = stack[top--]; 
            
            switch (s[0]) {
                case '+': stack[++top] = val1 + val2; break;
                case '-': stack[++top] = val1 - val2; break;
                case '*': stack[++top] = val1 * val2; break;
                case '/': stack[++top] = val1 / val2; break;
            }
        } else {
            stack[++top] = atoi(s);
        }
    }

    int result = stack[0];
    free(stack);
    return result;
}