
//Convert an infix expression to postfix notation using stack.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Stack {
    char items[MAX];
    int top;
};
void initStack(struct Stack* s) {
    s->top = -1;
}
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}
int isEmpty(struct Stack* s) {
    return s->top == -1;
}
void push(struct Stack* s, char item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = item;
}
char pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return '\0'; 
    }
    return s->items[s->top--];
}
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    initStack(&s);
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char token = infix[i];
        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
            postfix[j++] = token; 
        } else if (token == '(') {
            push(&s, token); 
        } else if (token == ')') {
            while (!isEmpty(&s) && s.items[s.top] != '(') {
                postfix[j++] = pop(&s); 
            }
        } else { 
            while (!isEmpty(&s) && precedence(s.items[s.top]) >= precedence(token)) {
                postfix[j++] = pop(&s); 
            }
            push(&s, token); 
        }
        i++;
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s); 
    }
    postfix[j] = '\0'; 
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
