#include <stdio.h>

#define MAX_LEN 200

int wordCount(const char *str) {
    int count = 0;
    int inWord = 0;

    // เดิน pointer จนถึงท้ายข้อความ
    while (*str != '\0') {
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

int main(void) {
    char text[MAX_LEN];

    printf("Enter text (spaces allowed): ");
    fgets(text, MAX_LEN, stdin);

    // ลบ newline ที่ fgets เก็บไว้
    char *p = text;
    while (*p != '\0') p++;
    if (p != text && *(p - 1) == '\n') *(p - 1) = '\0';

    printf("wordCount(\"%s\") = %d\n", text, wordCount(text));
    return 0;
}
