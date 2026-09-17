#include <stdio.h>

int main(void) {
    int x;
    printf("x: ");
    scanf("%d", &x);

    // เก็บที่อยู่ของ x
    int *ptr = &x;
    printf("x     = %d\n", x);
    printf("&x    = %p\n", (void *)&x);
    printf("ptr   = %p\n", (void *)ptr);
    printf("*ptr  = %d\n", *ptr);

    // เปลี่ยนค่า x ผ่าน pointer
    *ptr = 100;
    printf("x after modifying via pointer = %d\n", x);

    return 0;
}
