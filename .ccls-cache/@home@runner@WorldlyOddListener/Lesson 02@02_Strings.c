#include <stdio.h>

int main() {
char name[100];
int age;

printf("Enter name and age: ");
scanf("%s %d", &name, &age);

if (age < 0 || age > 100) {
printf("Wrong input\n");
} else {
printf("Name: %s, age: %d\n", name, age);
}

return 0;
}