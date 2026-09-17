#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int *dice) {
    // เก็บผลลูกเต๋าผ่าน pointer
    *dice = rand() % 6 + 1;
}

void getGuess(int *guess) {
    do {
        printf("Guess the number (1-6): ");
        scanf("%d", guess);
    } while (*guess < 1 || *guess > 6);
}

void nextRound(int *round) {
    (*round)++;
    printf("\n--- Round %d ---\n", *round);
}

void checkGuess(int dice, int guess, int *score) {
    printf("Dice: %d\n", dice);
    if (dice == guess) {
        printf("Correct! +3 points\n");
        *score += 3;
    } else if (abs(dice - guess) == 1) {
        printf("Close! +1 point\n");
        *score += 1;
    } else {
        printf("Incorrect! No points\n");
    }
}

void displayScore(const int *score) {
    // อ่านคะแนนอย่างเดียว
    printf("Current score: %d\n", *score);
}

void askPlayAgain(int *keepPlaying) {
    char answer;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &answer);
    *keepPlaying = (answer == 'y' || answer == 'Y');
}

int main(void) {
    srand((unsigned)time(NULL));
    int score = 0;
    int round = 0;
    int dice, guess, keepPlaying;

    // ใช้ pointer เดียวเก็บคะแนนข้ามรอบ
    int *pScore = &score;

    printf("Welcome to the Dice Guessing Game!\n");

    do {
        nextRound(&round);
        rollDice(&dice);
        getGuess(&guess);
        checkGuess(dice, guess, pScore);
        displayScore(pScore);
        askPlayAgain(&keepPlaying);
    } while (keepPlaying);

    printf("\nGame Over! Played %d round(s) — Your final score: %d\n", round, score);
    return 0;
}
