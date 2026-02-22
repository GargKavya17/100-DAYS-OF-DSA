// Problem: Count Nodes in Linked List
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
int countNodes(struct ListNode *head) {
    int count = 0;
    struct ListNode *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}