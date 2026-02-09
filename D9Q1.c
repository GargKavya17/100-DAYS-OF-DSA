// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

#include <stdio.h>
#include <string.h>

void reverseString(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    char temp;

    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

    int main() {
    char word[50];
     printf("Enter the word: ");
    scanf("%s", word); 
    printf("Original: %s\n", word);
    reverseString(word);
    printf("Reversed: %s\n", word);
    
    return 0;
}