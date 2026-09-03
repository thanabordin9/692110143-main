#include <stdio.h>

int main() {
    int seconds;
    int hours, minutes, secs;

    printf("Input: ");
    scanf("%d", &seconds);

    // Calculate time
    hours = seconds / 3600;
    minutes = (seconds % 3600) / 60;
    secs = seconds % 60;

    // Display H:MM:SS format
    printf("Output: %d:%02d:%02d\n", hours, minutes, secs);

    return 0;
}