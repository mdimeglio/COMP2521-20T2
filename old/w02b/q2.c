#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Develop an algorithm to determine if a character array of length n encodes a palindrome — that is, it reads the same forward and backward. For example, racecar is a palindrome.

int isPalindrome(char *string);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (isPalindrome(argv[1])) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return EXIT_SUCCESS;
}

int isPalindrome(char *string) {
    int len = strlen(string);
    int i = 0;
    while (i < len - 1 - i) {
        if (string[i] != string[len - 1 - i]) {
            return 0;
        }
        i++;
    }
    return 1;
}



















// int isPalindrome(char *string) {
//     int i = 0;
//     int j = strlen(string) - 1;
//     while (j >= 0) {
//         if (string[i] != string[j]) {
//             return 0;
//         }
//         i++;
//         j--;
//     }
//     return 1;
// }

// int isPalindrome(char *string) {
//     int length = strlen(string);
//     int isPalindrome = 1;
//     for (int i = 0; i < length/2 + 1; i++) {
//         if (string[i] != string[length - i - 1]) {
//             isPalindrome = 0;
//         }
//     }
//     return isPalindrome;
// }