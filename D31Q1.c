#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->top++;
        s->items[s->top] = value;
        printf("Pushed %d\n", value);
    }
}

void pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("Popped %d\n", s->items[s->top]);
        s->top--;
    }
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    pop(&s);
    display(&s);

    return 0;
}