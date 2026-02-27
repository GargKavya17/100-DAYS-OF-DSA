// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
int countOccurrences(int key) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(10);
    insertAtEnd(30);
    int key = 10;
    int occurrences = countOccurrences(key);
    printf("Element %d occurs %d times in the linked list.\n", key, occurrences);
    return 0;
}