#include <stdio.h>

void getInput(int *p, const char *label) {
    // รับค่าเก็บในตัวแปรที่ p ชี้อยู่
    printf("%s: ", label);
    scanf("%d", p);
}

void swap(int *a, int *b) {
    // สลับค่าผ่าน pointer
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int a, b;
    getInput(&a, "a");
    getInput(&b, "b");
    swap(&a, &b);
    printf("a=%d, b=%d\n", a, b);

    return 0;
}
