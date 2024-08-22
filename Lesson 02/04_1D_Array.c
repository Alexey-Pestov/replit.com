#include <stdio.h>

int main() {
int numbers[5];
for (int i = 0; i < 5; i++) {
scanf("%d", &numbers[i]);
}

int sum = 0;
for (int i = 0; i < 5; i++) {
sum += numbers[i];
}

printf("The sum is %d", sum);
return 0;
}

// gcc program_004.c -o P1
// ./P1