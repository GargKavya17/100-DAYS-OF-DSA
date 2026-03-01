// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    struct Node* tail = head;
    int length = 1;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }
    tail->next = head; 
    k = k % length; 
    for (int i = 0; i < length - k; i++) {
        tail = tail->next; 
    }
    struct Node* newHead = tail->next; 
    tail->next = NULL; 
    return newHead;
}