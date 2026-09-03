#include <stdio.h>
int main() {
// ประกาศและกาหนดค่าตัวแปร
char Name[50];
int age;
float gpa;
char FavoriteSubject[50];
// แสดงค่าและขนาด
printf("==PERSONALCARD===\n");
printf("Name                   :");
scanf("%s", Name);
printf("Age                    :");
scanf("%d", &age);
printf("GPA                    :");
scanf("%f", &gpa);
printf("Favorite Subject       :"); 
scanf("%s", FavoriteSubject);
printf("==PERSONALCARD===\n");
printf("┌────────────────────────────────────────────────────────────┐\n");
printf("│ Name                   : %-10s                        │\n", Name);
printf("│ Age                    : %-10d years old              │\n", age);
printf("│ GPA                    : %-10f                        │\n", gpa);
printf("│ Favorite Subject       : %-10s                        │\n", FavoriteSubject);
printf("└────────────────────────────────────────────────────────────┘\n");

return 0;
}