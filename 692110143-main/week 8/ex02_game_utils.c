#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int clamp(int value, int min, int max);
float lerp(float a, float b, float t);
int randomRange(int min, int max);
float percentOf(int current, int total);

int main(void) {
    srand((unsigned int)time(NULL));

    int hp = 150;
    int safeHP = clamp(hp, 0, 100);
    printf("=== clamp ===\n");
    printf("expected = 100 | actual = %d\n", safeHP);
    printf("expected =   0 | actual = %d\n", clamp(-5, 0, 100));
    printf("expected =  50 | actual = %d\n", clamp(50, 0, 100));
    printf("hp เดิม = %d\n", hp);

    float t = 0.5f;
    float pos = lerp(0, 100, t);
    printf("\n=== lerp ===\n");
    printf("expected =  50.00 | actual = %.2f\n", pos);
    printf("expected =   0.00 | actual = %.2f\n", lerp(0, 100, 0.0f));
    printf("expected = 100.00 | actual = %.2f\n", lerp(0, 100, 1.0f));
    printf("t ใน main = %.2f\n", t);

    int diceMin = 1;
    printf("\n=== randomRange ===\n");
    for (int i = 0; i < 5; i++) {
        printf("expected = 1-6 | actual dice roll = %d\n",
               randomRange(diceMin, 6));
    }
    printf("diceMin เดิม = %d\n", diceMin);

    int score = 35;
    int total = 100;
    float percent = percentOf(score, total);
    printf("\n=== percentOf ===\n");
    printf("expected = 35.0%% | actual = %.1f%%\n", percent);
    printf("score/total เดิม = %d/%d\n", score, total);

    return 0;
}

int clamp(int value, int min, int max) {
    if (value > max) value = max;
    if (value < min) value = min;
    return value;
}

float lerp(float a, float b, float t) {
    float result = a + (b - a) * t;
    return result;
}

int randomRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

float percentOf(int current, int total) {
    return (float)current / total * 100.0f;
}
