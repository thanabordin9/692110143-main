#include <stdio.h>

int main() {
    printf("10 / 3 = %d\n", 10 / 3);
    printf("10.0 / 3 = %.6f\n", 10.0 / 3);
    printf("(float)10 / 3 = %.6f\n", (float)10 / 3);
    printf("10 %% 3 = %d\n", 10 % 3);
    printf("-7 %% 3 = %d\n", -7 % 3);
    printf("7 %% -3 = %d\n", 7 % -3);

    return 0;
}