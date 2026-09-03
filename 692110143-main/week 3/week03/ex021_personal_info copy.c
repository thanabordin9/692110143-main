#include <stdio.h>
int main() {
// ประกาศและกาหนดค่าตัวแปร
char Name[6];
int age;
float gpa;
char FavoriteSubject[11];
// แสดงค่าและขนาด
printf("=== Enter Data ===\n");
printf("Name             :  ");
scanf("%s", Name);
printf("Age              :  ");
scanf("%d", &age);
printf("GPA              :  ");
scanf("%f", &gpa);
printf("Favorite Subject :  ");
scanf("%s", FavoriteSubject);
printf("=== Personal Info ===\n");
printf("┌──────────────────────────┐\n");
printf("Name             : %s\n", Name);
printf("Age              : %d years old\n", age);
printf("GPA              : %.2f\n", gpa);
printf("Favorite Subject : %s\n", FavoriteSubject);
printf("└──────────────────────────┘\n");
return 0;
}