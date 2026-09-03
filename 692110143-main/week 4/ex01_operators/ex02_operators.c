#include <stdio.h>

int main() {
    int x = 5;

    // x++
    printf("Statement: x++\n");
    printf("Result: %d\n", x++);
    printf("x after: %d\n\n", x);

    // Reset x
    x = 5;

    // ++x
    printf("Statement: ++x\n");
    printf("Result: %d\n", ++x);
    printf("x after: %d\n", x);

    return 0;
}