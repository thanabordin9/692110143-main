#include <stdio.h>

#define MAX_LEN 200

int wordCount(const char *str);

int main(void) {
    char text[MAX_LEN];

    printf("Enter text (spaces allowed): ");
    fgets(text, MAX_LEN, stdin);

    int len = 0;
    while (text[len] != '\0') {
        len++;
    }

    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    printf("wordCount(\"%s\") = %d\n", text, wordCount(text));

    return 0;
}

int wordCount(const char *str) {
    int count = 0;
    int inWord = 0;

    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }

        str++;
    }

    return count;
}
