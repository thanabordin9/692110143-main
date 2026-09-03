#include <stdio.h>
#include <math.h>

int main() {
    int attack;
    int defense;
    int hit_number;
    int base_damage;
    int damage;
    int enemy_hp = 500;

    printf("================================\n");
    printf("       COMBAT SIMULATOR\n");
    printf("================================\n\n");

    // Input
    printf("Player Attack : ");
    scanf("%d", &attack);

    printf("Enemy Defense : ");
    scanf("%d", &defense);

    printf("Hit Number    : ");
    scanf("%d", &hit_number);

    printf("\n--------------------------------\n");

    // Calculate base damage
    base_damage = attack - defense;

    // Check Critical Hit
    if (hit_number % 5 == 0) {
        damage = (int)ceil((float)base_damage * 1.5f);

        printf("Result        : *** CRITICAL HIT! ***\n");
        printf("Multiplier    : x1.5\n");
    }
    else {
        damage = base_damage;

        printf("Result        : Normal Hit\n");
    }

    // Reduce enemy HP
    enemy_hp = enemy_hp - damage;

    // Display result
    printf("Damage        : %d\n", damage);
    printf("Enemy HP      : %d / 500\n", enemy_hp);

    printf("--------------------------------\n");

    if (enemy_hp <= 0) {
        printf("Enemy Status  : DEFEATED!\n");
    }
    else {
        printf("Enemy Status  : Still Alive\n");
    }

    printf("================================\n");

    return 0;
}