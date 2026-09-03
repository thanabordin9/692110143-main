#include <stdio.h>
int main() {
// ประกาศและกาหนดค่าตัวแปร
char Name[50];
int Max_HP;
int Attack_Power;  
int Defense;
int Level;
// แสดงค่าและขนาด
printf("=== Create Character ===\n");
printf("Name                   :");
scanf("%s", Name);
printf("Max HP                 :");
scanf("%d", &Max_HP);
printf("Attack Power           :");
scanf("%d", &Attack_Power);
printf("Defense                :");
scanf("%d", &Defense);
printf("Level                  :");
scanf("%d", &Level);
printf("=== Character Summary ===\n");
printf("Name                   : %s                        \n", Name);
printf("Level                  : %d                      \n", Level);
printf("HP                     : %d                        \n", Max_HP);
printf("ATK                    : %d                      \n", Attack_Power);
printf("DEF                    : %d                      \n", Defense);

return 0;
}