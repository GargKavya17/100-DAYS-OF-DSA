// Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

#include <stdio.h>
#include <string.h>

char firstNonRepeating(char* s) {
    int count[26] = {0};
    int n = strlen(s);

    // Step 1: Fill the frequency array
    // We subtract 'a' to map 'a'-'z' to indices 0-25
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[] = "geeksforgeeks";
    char result = firstNonRepeating(s);
    
    printf("First non-repeating character: %c\n", result);
    
    return 0;
}