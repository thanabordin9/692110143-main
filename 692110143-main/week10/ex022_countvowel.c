#include <stdio.h>
#include <ctype.h>

#define MAX 50

int countVowel(const char *t) {
    int count = 0;

    // เดิน pointer ตรวจสระทีละตัว
    while (*t != '\0') {
        char c = toupper((unsigned char)*t);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
        t++;
    }

    return count;
}

int main(void) {
    char text[MAX];

    printf("Enter text: ");
    scanf("%49s", text);

    printf("Text : [%s] has %d vowels\n", text, countVowel(text));
    return 0;
}
