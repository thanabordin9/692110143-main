#include <stdio.h>

#define MAX_N 20

void minMax(int arr[], int n, int *min, int *max) {
    // เก็บค่าต่ำสุดและสูงสุดผ่าน pointer
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

int main(void) {
    int n;
    int arr[MAX_N], lo, hi;

    printf("n (max %d): ", MAX_N);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_N) {
        return 1;
    }

    // เก็บข้อมูลลง array
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    minMax(arr, n, &lo, &hi);
    printf("lo=%d, hi=%d\n", lo, hi);

    return 0;
}
